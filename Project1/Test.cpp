//
//#include <GL/glut.h>
//#include <stdlib.h>
//
//void display(void)
//{
//  
//    //glBegin(GL_POINTS);
//    //glBegin(GL_LINES);
//    //glBegin(GL_LINE_STRIP);
//    //glBegin(GL_LINE_LOOP );
//    //glBegin(GL_POLYGON);
//    //glBegin(GL_TRIANGLES );
//    //glBegin(GL_TRIANGLE_STRIP);
//
//
//    glClear(GL_COLOR_BUFFER_BIT);
//  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    glColor3f(1.0, 1.0, 1.0);
//    /*glBegin(GL_POLYGON);
//    glVertex3f(0.25, 0.25, 0.0);
//    glVertex3f(0.75, 0.25, 0.0);
//    glVertex3f(0.75, 0.75, 0.0);
//    glVertex3f(0.25, 0.75, 0.0);
//    glVertex3f(0.50, 0.75, 0.0);
//    glVertex3f(0.25, 0.50, 0.0);
//    glEnd();*/
//
//    //glBegin(GL_TRIANGLE_STRIP);
//  
//    //glVertex3f(0.20, 0.20, 0.0); //v0
//    //glVertex3f(0.30, 0.30, 0.0); // v4 
//    //glVertex3f(0.90, 0.20, 0.0); // v1
//
//    //glVertex3f(0.80 , 0.30 , 0.0); // v5
//    //glVertex3f(0.90, 0.90, 0.0); // v2
//    //glVertex3f(0.80, 0.80, 0.0); // v6
//
//    //glVertex3f(0.20, 0.90, 0.0); //v3
//    //glVertex3f(0.30 , 0.80 , 0.0); //v7
//    //glVertex3f(0.20 , 0.20 , 0.0); // v0
//    //glVertex3f(0.30, 0.30, 0.0); // v4 
//
//    //glEnd();
//
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(0.20, 0.20);
//
//
//    glVertex2f(0.20, 0.20); 
//    glVertex2f(0.30, 0.30);  
//    glVertex2f(0.80, 0.30);
//    glVertex2f(0.90, 0.20); // v1
//    glVertex2f(0.90, 0.90); // v2
//    glVertex2f(0.20, 0.90);  //
//
//    //glVertex2f(0.20, 0.90); // v3
//    //glVertex2f(0.30, 0.80);
//    //glVertex2f(0.30, 0.30);
//    //glVertex2f(0.30, 0.80); // v7 
//    //glVertex2f(0.20, 0.90);
//    glEnd();
//
//
//
//    
//    
//   
//    glFlush();
//}
//
//void init(void)
//{
//
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}
//
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(650, 650);
//    glutInitWindowPosition(200, 200);
//    glutCreateWindow("hello");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;   
//}
