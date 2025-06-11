#include "canvas.cpp"


int main(int argc, char* argv[]) {
    Canvas canvas = Canvas(800, 600);
    canvas.initWindow();

    // Testing scalar multiplication
    for (int i = 0; i < 10; i++) {
        canvas.putPixel(i * 10, i * 10, Color(10, 10, 50) * i);
    }

    // Testing color add
    Color* base_color = new Color(0, 255, 0);
    for (int i = 0; i < 10; i++) {
        canvas.putPixel(i * -10, i * 10, Color(50 * i, 10 * i, 0) + base_color);
    }


    while (canvas.pollExit()) {
        canvas.render();
    }

    canvas.destroy();
    return 0;
}