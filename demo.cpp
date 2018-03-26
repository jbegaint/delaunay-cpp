#include <vector>

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "delaunay.hpp"

using namespace delaunay;

namespace context {
std::vector<Point<float>> points;
} /* namespace context */

void displayMe()
{
  /* Draw points. */
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glBegin(GL_POINTS);
  for (auto const& p : context::points) {
    glVertex2i(p.x, p.y);
  }
  glEnd();

  const auto triangulation = triangulate(context::points);

  /* Draw lines. */
  glBegin(GL_LINES);
  for (auto const& e : triangulation.edges) {
    glVertex2i(e.p0.x, e.p0.y);
    glVertex2i(e.p1.x, e.p1.y);
  }
  glEnd();

  glutSwapBuffers();
}

void mouse_callback(int button, int state, int x, int y)
{
  y = glutGet(GLUT_WINDOW_HEIGHT) - y;
  switch (button) {
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_UP) {
        context::points.push_back({x, y});
      }
      break;
    case GLUT_MIDDLE_BUTTON:
      context::points.clear();
      break;
    case GLUT_RIGHT_BUTTON:
      /* Find closest point (with threshold). */
      auto it = context::points.begin();
      auto it_best = context::points.end();
      int best_dist = 100; /* min dist */
      for (; it != context::points.end(); ++it) {
        const auto dist = (it->x - x) * (it->x - x) + (it->y - y) * (it->y - y);
        if (dist < best_dist) {
          it_best = it;
          best_dist = dist;
        }
      }
      if (it_best != context::points.end()) {
        context::points.erase(it_best);
      }
      break;
  }
  displayMe();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Delaunay Triangulation demo");
  glClearColor(0, 0, 0, 0);
  glPointSize(5);

  glutMouseFunc(mouse_callback);

  gluOrtho2D(0.0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
  glutDisplayFunc(displayMe);
  glutMainLoop();

  return 0;
}
