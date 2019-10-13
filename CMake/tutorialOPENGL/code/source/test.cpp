#include "test.h"

// our cube
void theCube() {
  // set the colors in order R,G,B as floats from 0.0 to 1.0
  glColor3f(1.0,1.0,1.0);
  // set the size of the cube
  glutSolidCube(0.4);
}

// function that shows what is displayed at one time
void display() {
  // rotate the perspective by 40 degrees 
  // around the direction defined by vector from (0,0,0) to (1,1,0)
  glRotatef(40,1,1,0);
  theCube();
  glutSwapBuffers();
}


void init() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(35,1.0f,0.1f,1000);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.1,0.1,0.1,1);
}

int main(int argc, char **argv) {
  std::cout<<"Test: hello world with OPENGL and GLUT!"<<std::endl;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(800, 600);
  glutCreateWindow("");
  glutDisplayFunc(display);
  glutMainLoop();
  init();

  return 0;
}
