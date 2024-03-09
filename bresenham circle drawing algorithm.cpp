#include <iostream>
#include <GL/glut.h>
using namespace std;

int xc = 200, yc = 200, r = 100;

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        setPixel(xc + x, yc + y);
        setPixel(xc - x, yc + y);
        setPixel(xc + x, yc - y);
        setPixel(xc - x, yc - y);
        setPixel(xc + y, yc + x);
        setPixel(xc - y, yc + x);
        setPixel(xc + y, yc - x);
        setPixel(xc - y, yc - x);

        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresenham Circle Drawing");

    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glOrtho(0, 400, 0, 400, -1, 1);

    glutDisplayFunc(drawCircle);
    glutMainLoop();

    return 0;
}
