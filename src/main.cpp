#include "renderer.cpp"
#include "point.cpp"


int main(int argc, char* argv[]) {
    Canvas canvas = Canvas(800, 600);
    canvas.initWindow();

    Point2D point1(1.f, 1.f); // TODO: Test the point logic is working correctly

    Camera camera(0.0, 0.0, 0.0);
    Viewport viewport(1.0, 1.0, 1.0);

    canvas.putPixel(0,0, Color(255,255,255));


    while (canvas.pollExit()) {
        canvas.render();
    }

    canvas.destroy();
    return 0;
}