#include "test.h"

void theCube() {
  glColor3f(1,1,1);
  glutSolidCube(0.4);
}

void display() {
  theCube();
  glutSwapBuffers();
}

int main(int argc, char **argv) {
  std::cout<<"Test: hello world with OPENGL and GLUT!"<<std::endl;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(800, 600);
  glutCreateWindow("");
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
