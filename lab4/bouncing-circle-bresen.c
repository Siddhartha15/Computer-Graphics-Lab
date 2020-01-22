#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 
#define pi 3.142857 

int refreshMillis = 30; 
int windowWidth  = 640;     // Windowed mode's width
int windowHeight = 480;     // Windowed mode's height

 
 int r = 100;   // Radius of the bouncing ball
int xc= 320;         // Ball's center (x, y) position
int yc = 240;
// int ballXMax, ballXMin, ballYMax, ballYMin; // Ball's center (x, y) bounds
// int xSpeed = 0;      // Ball's speed in x and y directions
// int ySpeed = 1;
int f=0;
void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   gluOrtho2D(0, 640, 0, 480); 

} 

void drawCircle(int xc, int yc, int x, int y) 
{ 
   
   glBegin(GL_POINTS);
   glVertex2i(xc+x, yc+y); 
   glVertex2i(xc-x, yc+y); 
   glVertex2i(xc+x, yc-y); 
   glVertex2i(xc-x, yc-y); 
   glVertex2i(xc+y, yc+x); 
   glVertex2i(xc-y, yc+x); 
   glVertex2i(xc+y, yc-x); 
   glVertex2i(xc-y, yc-x); 
   glEnd();
} 

void bresenCircle(int xc,int yc)
{
   glClear(GL_COLOR_BUFFER_BIT);
   int x = 0, y = r; 
   int d = 3 - 2 * r; 
   drawCircle(xc, yc, x, y); 
   while (y >= x) 
   { 
      x++; 
      if (d > 0) 
      { 
         y--; 
         d = d + 4 * (x - y) + 10; 
      } 
      else
         d = d + 4 * x + 6; 
      drawCircle(xc, yc, x, y); 
      // delay(50); 
   } 
}
void display (void) 
{ 
  
   bresenCircle(xc,yc);

    // if(f == 0)
    // {
    //   if(yc == 480 - r)
    //   {
    //     yc--;
    //     f=1;
    //   }
    //   else
    //       yc++;
    // }
    // else
    // {
    //   if(yc == r)
    //   {
    //     yc++;
    //     f=0;
    //   }
    //   else
    //     yc--;
    // }
} 
void Timer(int value) {
   glutPostRedisplay();    // Post a paint request to activate display()
   glutTimerFunc(refreshMillis, Timer, 0); // subsequent timer call at milliseconds
}
int main (int argc, char** argv) 
{ 

   glutInit(&argc, argv); 
   glutInitDisplayMode( GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(640, 480); 
   glutInitWindowPosition(0, 0); 
      myInit(); 
   // Giving name to window 
   glutCreateWindow("Bouncing Circle Drawing"); 
   
   glutDisplayFunc(display);
   glutTimerFunc(0, Timer, 0); 

   
   glutMainLoop(); 
   return 0;
} 
   