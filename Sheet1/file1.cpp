#include <GL/glut.h>

const int rowsNumber = 8;       // Number of rowsNumber
const int colsNumber = 8;       // Number of columns
const float squareSize = 0.25f; // Size of each square

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glClearColor(0.9f, 0.9f, 0.9f, 1.0f);

  for (int i = 0; i < rowsNumber; i++)
  {
    for (int j = 0; j < colsNumber; j++)
    {
      if ((i + j) % 2 == 0)
        glColor3f(1.0f, 1.0f, 1.0f); // White
      else
        glColor3f(0.0f, 0.0f, 0.0f); // Black

      glBegin(GL_QUADS);
      glVertex2f(j * squareSize, i * squareSize);
      glVertex2f((j + 1) * squareSize, i * squareSize);
      glVertex2f((j + 1) * squareSize, (i + 1) * squareSize);
      glVertex2f(j * squareSize, (i + 1) * squareSize);
      glEnd();
    }
  }

  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowSize(600, 600);

  glutInitWindowPosition(100, 100);

  glutCreateWindow("Sarah M. Farouq 221165");

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, colsNumber * squareSize, 0.0, rowsNumber * squareSize);

  glutDisplayFunc(display);

  glutMainLoop();

  return 0;
}
