
#include <GL/glut.h>
#include<math.h>
#include <stdio.h>
#include "Bai1.h"

#define PI 3.14159265358979324

#define M  80;

void drawFilledelipse()
{
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 1.0, 1.5);

	// ý 1 
	/*GLfloat step = PI / M;
	register int i;
	GLfloat angle, r;
	glBegin(GL_TRIANGLE_STRIP);
	for ( i = 0; i < 180; i++)
	{
		r = (i % 2 == 0 ? 2 : 5 );
		angle = i * step;
		glVertex3f(r * cos(angle), r * sin(angle), 0.0);
	}
	glEnd();*/



	//GLfloat step = PI / M;
	//register int i;
	//GLfloat angle, r;
	//glBegin(GL_TRIANGLE_STRIP);
	//for (i = 0; i < 180; i++)
	//{
	//	r = (i % 2 == 0 ? 2 : 5);
	//	angle = i * step;
	//	glVertex3f(r * cos(angle), 3 + r * sin(angle), -0.90);
	//}
	//glEnd();
	//glBegin(GL_TRIANGLE_STRIP);
	//for (i = 0; i < 180; i++)
	//{
	//	r = (i % 2 == 0 ? 2 : 5);
	//	angle = i * step;
	//	glVertex3f(r * cos(angle), - 5 + r * sin(angle), -0.90);
	//}
	//glEnd();


	// ý 3
	/*GLfloat step = PI / 10.0;
	register int i;
	GLfloat angle, r;
	glBegin(GL_TRIANGLE_STRIP);
	for ( i = 0; i < 180 ; i++)
	{
		r = (i % 2 == 0 ? 2 : 5 );
		angle = i * step;
		glVertex3f(r * cos(angle), r * sin(angle), 0.0);
	}
	glEnd();*/


	glFlush();
}




void Initialize(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 9.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
};
int main(int argc, char** argv) {

	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(676, 677);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Bai so 1");


	glutDisplayFunc(drawFilledelipse);

	glutReshapeFunc(Initialize);
	// chu trinh sử lý sự kiện của GLUT
	glutMainLoop();

	return 1;
}
