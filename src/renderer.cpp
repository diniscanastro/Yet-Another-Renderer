#include "../include/renderer.h"

#include <cmath>
#include <vector>
#include <tuple>
#include <memory>

#include "../include/point.h"
#include "../include/color.h"
#include "../include/sphere.h"
#include "../include/viewport.h"
#include "../include/canvas.h"
#include "../include/light.h"

using namespace std;


class Renderer {
public:
    Canvas canvas;
    Viewport viewport;
    Point3D camera;
    Color background_color;

    // Scene elements
    vector<Sphere> spheres;
    vector<unique_ptr<Light>> lights;

    Renderer(): canvas(800, 800), viewport(1.0, 1.0, 1.0), camera(Point3D(0, 0, 0)), background_color(Color(255,255,255)) {
        setSceneElements();
    }
    ~Renderer() {canvas.destroy();}

    void setSceneElements() {
        spheres.push_back(Sphere(Point3D(0, -1, 3),1, Color(255,0,0), 500));
        spheres.push_back(Sphere(Point3D(2, 0, 4),1, Color(0,0,255), 500));
        spheres.push_back(Sphere(Point3D(-2, 0, 4),1, Color(0,255,0), 10));
        spheres.push_back(Sphere(Point3D(0, -5001, 0),5000, Color(255,255,0), 1000));


        lights.push_back(make_unique<AmbientLight>(0.2));
        lights.push_back(make_unique<PointLight>(0.6, Point3D(2, 1, 0)));
        lights.push_back(make_unique<DirectionalLight>(0.2, Point3D(1, 4, 4)));

    }

    void engageLoop() {
        while (canvas.pollExit()) {
            process();
            canvas.render();
        }
    }

    void process() {
        for (int x = -canvas.width/2; x < canvas.width/2; x++) {
            for (int y = -canvas.height/2 + 1; y <= canvas.height/2; y++) {
                Point3D point_D = canvasPixelToViewportPoint(x, y);
                Color color = traceRay(camera, point_D, 1, numeric_limits<double>::infinity());
                canvas.putPixel(x,y,color);
            }
        }
    }

    Color traceRay(const Point3D &camera, const Point3D &direction, const double t_min, const double t_max) {
        double closest_t = numeric_limits<double>::infinity();
        const Sphere* closest_sphere = nullptr;

        for (int i = 0; i < spheres.size(); i++) {
            double t1, t2;
            tie(t1, t2) = intersectRaySphere(camera, direction, spheres[i]);
            if (t1 > t_min && t1 < t_max) {
                if (t1 < closest_t) {
                    closest_t = t1;
                    closest_sphere = &spheres[i];
                }
            }
            if (t2 > t_min && t2 < t_max) {
                if (t2 < closest_t) {
                    closest_t = t2;
                    closest_sphere = &spheres[i];
                }
            }
        }

        if (closest_sphere == nullptr) {
            return background_color;
        }

        Point3D intersection = camera + (direction * closest_t);
        Point3D normal = (intersection - closest_sphere->center).normalize();
        return closest_sphere->color * computeLightIntensity(intersection, normal, -direction, closest_sphere->specular);

    }

    tuple<double, double> intersectRaySphere(const Point3D &camera, const Point3D &direction, const Sphere& sphere) {
        double r = sphere.radius;
        Point3D c_o = camera - sphere.center;

        double a = direction * direction;
        double b = 2 * (c_o * direction);
        double c = c_o * c_o - pow(r,2);

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            return make_tuple(numeric_limits<double>::infinity(), numeric_limits<double>::infinity());
        }

        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);
        return make_tuple(t1, t2);
    }

    double computeLightIntensity(const Point3D &point, const Point3D &normal, const Point3D &view, const int specularity) {
        double intensity = 0.0;
        for (int i = 0; i < lights.size(); i++) {
            intensity += lights[i]->calculateIntensityAtPoint(point, normal, view, specularity);
        }
        return intensity;
    }

    /*
    * Auxiliary functions
    */

    /*
     * Converts a pixel in the canvas to it's position in the viewport.
     */
    Point3D canvasPixelToViewportPoint(const int x, const int y) {
        float v_x = x * (viewport.width / canvas.width);
        float v_y = y * (viewport.height / canvas.height);
        float v_z = viewport.distance;

        return Point3D(v_x, v_y, v_z);
    }
};
