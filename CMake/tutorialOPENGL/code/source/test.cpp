#include "test.h"

void theCube() {
  // set the colors in order R,G,B as floats from 0.0 to 1.0
  glColor3f(0.3,0.2,0.7);
  // set the size of the cube
  glutSolidCube(0.4);
}

void display() {
  // rotate the perspective by 40 degrees 
  // around the direction defined by vector from (0,0,0) to (1,1,0)
  glRotatef(40,1,1,0);
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
