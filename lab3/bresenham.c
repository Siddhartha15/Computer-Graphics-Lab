#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int  X1,Y1,X2,Y2;

void myInit (void) 
{ 
   glClearColor(0.0, 0.0, 0.0, 1.0); 
   glColor3f(0.0, 1.0, 0.0); 
   glPointSize(1.0); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluOrtho2D(-780, 780, -420, 420); 
} 

void display (void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT); 
   
   int err=0;
   int x,y;

   for (x = X1, y = Y1; x <= X2; x++) 
   { 
      glBegin(GL_POINTS);
      glVertex2i(x,y);
      glEnd();
      
      if((2*(err+(Y2-Y1))) < (X2-X1))
            err+=(Y2-Y1);
      else
      {
         y++;
         err+=(Y2-Y1)-(X2-X1);
      }
   }

   glFlush(); 
} 

int main (int argc, char** argv) 
{ 
    printf("Enter the value of x1 : ");
   scanf("%d",&X1);
   printf("Enter the value of y1 : ");
   scanf("%d",&Y1);
   printf("Enter the value of x2 : ");
   scanf("%d",&X2);
   printf("Enter the value of y2 : ");
   scanf("%d",&Y2);

   glutInit(&argc, argv); 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   
   // giving window size in X- and Y- direction 
   glutInitWindowSize(1366, 768); 
   glutInitWindowPosition(0, 0); 
   
   // Giving name to window 
   glutCreateWindow("Circle Drawing"); 
   myInit(); 
   
   glutDisplayFunc(display); 
   glutMainLoop(); 
} 
   