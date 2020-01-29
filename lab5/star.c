#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#define pi 3.142857 

int xc=0,yc=0;
void setCorrd(int x,int y)
{
  xc=x;
  yc=y;
}
void mouse(int button,int state,int x,int y)
{
  switch(button)
  {
  case GLUT_LEFT_BUTTON:
    if(state==GLUT_DOWN)
      {
        glutDestroyWindow(glutGetWindow());
      }
    break;
  case GLUT_MIDDLE_BUTTON:
    if(state==GLUT_DOWN)
    {
      glutIdleFunc(NULL);
    }
    break;
  case GLUT_RIGHT_BUTTON:
    if(state==GLUT_DOWN)
      {
        setCorrd(x,y);
        glutPostRedisplay();
      }
    break;
  default:
    break;
  }
}
void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(-780, 780, -420, 420); 
} 
void drawStar(int x, int y)
{
  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2i(x-10, y-10);
  glVertex2i(x+10, x-10);
  glVertex2i(x+0, y+20);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex2i(x-10, y+10);
  glVertex2i(x+10, y+10);
  glVertex2i(x+0, y-20);
  glEnd();
}
void display (void) 
{ 
  glClear(GL_COLOR_BUFFER_BIT); 
    drawStar(xc,yc);
  glFlush();
} 

int main (int argc, char** argv) 
{ 

   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(1366, 768); 
   glutInitWindowPosition(50, 50); 
   
   // Giving name to window 
   glutCreateWindow("Star"); 
   myInit(); 
   
   glutDisplayFunc(display); 
   glutMouseFunc(mouse);
   glutMainLoop(); 
} 
