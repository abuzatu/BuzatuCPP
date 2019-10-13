#include "test.h"

// our cube
void theCube() {
  // set the colors in order R,G,B as floats from 0.0 to 1.0
  glColor3f(1.0,1.0,1.0);
  // set the size of the cube
  glutSolidCube(0.4);
}

// function that draws the grid
void drawGrid() {
  // draw one line 40 times
  // the first 20 times, translated in the z axis, towards viewer, out of screen
  // each line horizontal going left to right)
  // the next 20 times, rotate with 270 degrees around the y vertical axis
  // translate towards the right
  // each line horizontal going from far to close to the reader
  
  // so a for loop 40 times
  for (int i=0; i!=40; i++) {
    glPushMatrix();
    if (i<20) {
      // translate along the z axis, by unit of i
      glTranslatef(0,0,i); 
    } else {
      // first translate by a unit i along the x axis
      glTranslatef(i-20,0,0);
      // then rotate by 270 degrees (or -90 degrees) along the y axis
      glRotatef(-90,0,1,0);

    }
    
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glLineWidth(1);
    glVertex3f(0,-0.1,0);
    glVertex3f(19,-0.1,0);
    glEnd();
    glPopMatrix();
  }
  
}

// function that shows what is displayed at one time
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  // translate to left and closer to us
  glTranslatef(-13,+0,-45);
  // rotate the perspective by 40 degrees 
  // around the direction defined by vector from (0,0,0) to (1,1,0)
  glRotatef(40,1,1,0);
  drawGrid();
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
  init();
  glutMainLoop();
  return 0;
}
