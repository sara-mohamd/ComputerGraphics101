#include <GL/glut.h>

void dispaly()
{
  // clear frame buffer from colors and depth information
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glutSwapBuffers();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

  glutInitWindowPosition(50, 50);
  glutInitWindowSize(500, 500);
  glutCreateWindow("blank page");

  glClearColor(0.6, .4, 1.0, 0.0);
  glutDisplayFunc(dispaly);
  glutMainLoop();
}