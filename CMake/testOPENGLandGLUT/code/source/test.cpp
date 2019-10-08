#include "test.h"
#include "GLUT/glut.h"

constexpr unsigned int WIDTH = 640;
constexpr unsigned int HEIGHT = 480;
uint8_t data[HEIGHT * WIDTH * 3];
std::mutex lock;

void display() {
  std::lock_guard<std::mutex> frame_lock(lock);
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, data);
  glutSwapBuffers();
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  std::cout<<"Test: hello world with OPENGL and GLUT!"<<std::endl;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutCreateWindow("GLUT");
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
