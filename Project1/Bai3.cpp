///* Chương trình này minh họa việc sử dụng thư viện glut cho
//      giao tiếp với hệ thống cửa sổ */
//#include <GL/glut.h>
//#include<math.h>
//#include <stdio.h>
//
//
//
//
//#define LIN 1 /* line */
//#define REC 2 /* hình chữ nhật */
//#define TRI 3 /* tam giác  */
//#define POI 4 /* điểm */
//#define TEX 5 /* text */
//#define CIRCLE 6 /* hinh tron*/
//#define POLYLIN 7 /* Duong gap khuc*/
//#define PI 3.14159265358979324
//
//
//void mouse(int, int, int, int);
//void key(unsigned char, int, int);
//void display(void);
//void drawSquare(int, int);
//void myReshape(GLsizei, GLsizei);
//
//void myinit(void);
//
//void screen_box(int, int, int);
//void right_menu(int);
//void middle_menu(int);
//void color_menu(int);
//void pixel_menu(int);
//void fill_menu(int);
//int pick(int, int);
//
///* globals */
//
//GLsizei wh = 800, ww = 800; /*kích thước cửa sổ ban đầu */
//GLfloat size = 3.0;   /* nửa độ dài cạnh hình vuông */
//int draw_mode = 0; /* chế độ vẽ */
//int rx, ry; /*vị trí raster*/
//
//GLfloat r = 1.0, g = 1.0, b = 1.0; /* drawing color */
//int fill = 0; /* fill flag */
//
//// hàm vẽ hình vuông 
//void drawSquare(int x, int y)
//{
//
//	y = wh - y;
//	glColor3ub((char)rand() % 256, (char)rand() % 256, (char)rand() % 256);
//	glBegin(GL_POLYGON);
//	glVertex2f(x + size, y + size);
//	glVertex2f(x - size, y + size);
//	glVertex2f(x - size, y - size);
//	glVertex2f(x + size, y - size);
//	glEnd();
//}
//
//
///* định dạng lại thủ tục được gọi bất cứ khi nào cửa sổ được thay đổi kích thước
//   hoặc đã di chuyển */
//
//void myReshape(GLsizei w, GLsizei h)
//{
//
//	/*  điều chỉnh hộp cắt  */
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, (GLdouble)w, 0.0, (GLdouble)h, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	/* điều chỉnh chế độ xem và xóa */
//
//	glViewport(0, 0, w, h);
//	glClearColor(0.8, 0.8, 0.8, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	display();
//	glFlush();
//
//	/* thiết lập kích thước toàn cầu để sử dụng bằng thói quen vẽ */
//
//	ww = w;
//	wh = h;
//}
//
//void myinit(void)
//{
//
//	glViewport(0, 0, ww, wh);
//
//
//	/* Chọn cửa sổ cắt 2D để khớp với kích thước của cửa sổ X
//	   Lựa chọn này tránh phải chia tỷ lệ tọa độ đối tượng
//	   mỗi lần thay đổi kích thước cửa sổ */
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, (GLdouble)ww, 0.0, (GLdouble)wh, -1.0, 1.0);
//
//	/* đặt màu trong suốt thành màu đen và cửa sổ trong suốt */
//
//	glClearColor(0.8, 0.8, 0.8, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glFlush();
//}
//
//
//
//void mouse(int btn, int state, int x, int y)
//{
//	static int count;
//	int where;
//	static int xp[3], yp[3];
//	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		glPushAttrib(GL_ALL_ATTRIB_BITS);
//
//		where = pick(x, y);
//		glColor3f(r, g, b);
//		if (where != 0)
//		{
//			count = 0;
//			draw_mode = where;
//		}
//		else switch (draw_mode)
//		{
//			case(LIN):
//				if (count == 0)
//				{
//					count++;
//					xp[0] = x;
//					yp[0] = y;
//				}
//				else
//				{
//					glBegin(GL_LINES);
//					glVertex2i(x, wh - y);
//					glVertex2i(xp[0], wh - yp[0]);
//					glEnd();
//					draw_mode = 0;
//					count = 0;
//				}
//				break;
//			case(REC):
//				if (count == 0)
//				{
//					count++;
//					xp[0] = x;
//					yp[0] = y;
//				}
//				else
//				{
//					if (fill) glBegin(GL_POLYGON);
//					else glBegin(GL_LINE_LOOP);
//					glVertex2i(x, wh - y);
//					glVertex2i(x, wh - yp[0]);
//					glVertex2i(xp[0], wh - yp[0]);
//					glVertex2i(xp[0], wh - y);
//					glEnd();
//					draw_mode = 0;
//					count = 0;
//				}
//				break;
//			case (TRI):
//				switch (count)
//				{
//					case(0):
//						count++;
//						xp[0] = x;
//						yp[0] = y;
//						break;
//					case(1):
//						count++;
//						xp[1] = x;
//						yp[1] = y;
//						break;
//					case(2):
//						if (fill) glBegin(GL_POLYGON);
//						else glBegin(GL_LINE_LOOP);
//						glVertex2i(xp[0], wh - yp[0]);
//						glVertex2i(xp[1], wh - yp[1]);
//						glVertex2i(x, wh - y);
//						glEnd();
//						draw_mode = 0;
//						count = 0;
//				}
//				break;
//			case(POI):
//				{
//					drawSquare(x, y);
//					count++;
//				}
//				break;
//			case(TEX):
//				{
//					rx = x;
//					ry = wh - y;
//					glRasterPos2i(rx, ry);
//					count = 0;
//				}
//				break;
//			case(CIRCLE):
//				if (count == 0)
//				{
//					count++;
//					xp[0] = x;
//						yp[0] = y;
//				}
//				else
//				{
//					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//					glBegin(GL_POLYGON);
//
//					// Iterate through all the
//					// 360 degrees
//					for (int i = 0; i < 360; i++) {
//
//						// Find the angle
//						double t = i * PI / 180;
//
//						// sai vi tri 
//						glVertex2f(x + 50 * cos(t),
//							y + 50  * sin(t));
//					}
//
//					// Sets vertex
//					glEnd();
//					draw_mode = 0;
//					count = 0;
//				}
//			
//				break;
//			case(POLYLIN):
//				switch (count)
//				{
//				case(0):
//					count++;
//					xp[0] = x;
//					yp[0] = y;
//					break;
//				case(1):
//					count++;
//					xp[1] = x;
//					yp[1] = y;
//					break;
//				case(2):
//					count++;
//					xp[2] = x;
//					yp[2] = y;
//					break;
//				case(3):
//					glBegin(GL_LINE_STRIP);
//					glVertex2f(xp[0], wh - yp[0]);
//					glVertex2f(xp[1], wh - yp[1]);
//					glVertex2f(xp[2], wh - yp[2]);
//					glVertex2f(x, wh - y);
//					glEnd();
//					glutSwapBuffers();
//					draw_mode = 0;
//					count = 0;
//				}
//		}
//
//		glPopAttrib();
//		glFlush();
//	}
//}
//
//int pick(int x, int y)
//{
//	y = wh - y;
//	if (y < wh - ww / 10) return 0;
//	else if (x < ww / 10) return LIN;//80
//	else if (x < ww / 5) return REC; //160
//	else if (x < 3 * ww / 10) return TRI; //240
//	else if (x < 2 * ww / 5) return POI; //320
//	else if (x < ww / 2) return TEX; //400
//	else if (x < 3 * ww / 5) return CIRCLE; //480
//	else if (x < 7 * ww/ 10 ) return POLYLIN; //560
//	
//	else return 0;
//}
//
//void screen_box(int x, int y, int s)
//{
//	glBegin(GL_QUADS);
//	glVertex2i(x, y);
//	glVertex2i(x + s, y);
//	glVertex2i(x + s, y + s);
//	glVertex2i(x, y + s);
//	glEnd();
//}
//
//void right_menu(int id)
//{
//	if (id == 1) exit(0);
//	else display();
//}
//
//void middle_menu(int id)
//{
//
//}
//
//void color_menu(int id)
//{
//	if (id == 1) { r = 1.0; g = 0.0; b = 0.0; }
//	else if (id == 2) { r = 0.0; g = 1.0; b = 0.0; }
//	else if (id == 3) { r = 0.0; g = 0.0; b = 1.0; }
//	else if (id == 4) { r = 0.0; g = 1.0; b = 1.0; }
//	else if (id == 5) { r = 1.0; g = 0.0; b = 1.0; }
//	else if (id == 6) { r = 1.0; g = 1.0; b = 0.0; }
//	else if (id == 7) { r = 1.0; g = 1.0; b = 1.0; }
//	else if (id == 8) { r = 0.0; g = 0.0; b = 0.0; }
//}
//
//
//void pixel_menu(int id)
//{
//	if (id == 1) size = 2 * size;
//	else if (size > 1) size = size / 2;
//}
//
//void fill_menu(int id)
//{
//	if (id == 1) fill = 1;
//	else fill = 0;
//}
//
//void key(unsigned char k, int xx, int yy)
//{
//	if (draw_mode != TEX) return;
//	glColor3f(0.0, 0.0, 0.0);
//	glRasterPos2i(rx, ry);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, k);
//	/*glutStrokeCharacter(GLUT_STROKE_ROMAN,i); */
//	rx += glutBitmapWidth(GLUT_BITMAP_9_BY_15, k);
//
//}
//
//void display(void)
//{
//	int shift = 0;
//	glPushAttrib(GL_ALL_ATTRIB_BITS);
//	glClearColor(0.8, 0.8, 0.8, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//;
//	// Box 1 0.0 , 0.0 ,80
//	glColor3f(1.0, 1.0, 1.0);
//	screen_box(0, wh - ww / 10, ww / 10);
//	//Box 2 80 , 0.0 ,80
//	glColor3f(1.0, 0.0, 0.0);
//	screen_box(ww / 10, wh - ww / 10, ww / 10);
//	// Box 3 160, 0.0 ,80
//	glColor3f(0.0, 1.0, 0.0);
//	screen_box(ww / 5, wh - ww / 10, ww / 10);
//	//Box 4 240, 0.0 ,80
//	glColor3f(0.0, 0.0, 1.0);
//	screen_box(3 * ww / 10, wh - ww / 10, ww / 10);
//	//Box 5 320 , 0.0 ,80
//	glColor3f(1.0, 1.0, 0.0);
//	screen_box(2 * ww / 5, wh - ww / 10, ww / 10);
//	//Box 6 400 , 0.0 , 80
//	glColor3f(0.0, 0.5, 0.0);
//	screen_box(ww /2 , wh - ww / 10 , ww / 10);
//	//Box 7 480 , 0.0 , 80
//	glColor3f(0.0, 1.5, 1.0);
//	screen_box(3* ww / 5 , wh - ww / 10 , ww / 10);
//
//	glBegin(GL_LINES);
//	glVertex2i(wh / 40, wh - ww / 20);
//	glVertex2i(wh / 40 + ww / 20, wh - ww / 20);
//	glEnd();
//
//	glBegin(GL_TRIANGLES);
//	glVertex2i(ww / 5 + ww / 40, wh - ww / 10 + ww / 40);
//	glVertex2i(ww / 5 + ww / 20, wh - ww / 40);
//	glVertex2i(ww / 5 + 3 * ww / 40, wh - ww / 10 + ww / 40);
//	glEnd();
//
//	glPointSize(3.0);
//
//	glBegin(GL_POINTS);
//	glVertex2i(3 * ww / 10 + ww / 20, wh - ww / 20);
//	glEnd();
//
//	glRasterPos2i(2 * ww / 5, wh - ww / 20);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'A');
//	shift = glutBitmapWidth(GLUT_BITMAP_9_BY_15, 'A');
//	glRasterPos2i(2 * ww / 5 + shift, wh - ww / 20);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'B');
//	shift += glutBitmapWidth(GLUT_BITMAP_9_BY_15, 'B');
//	glRasterPos2i(2 * ww / 5 + shift, wh - ww / 20);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'C');
//
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glBegin(GL_POLYGON);
//
//	// Lặp qua tất cả các
//	// 360 độ
//	for (int i = 0; i < 360; i++) {
//		// tìm góc
//		double t = i * PI / 180;
//		// sai vi tri 
//		glVertex2f(ww - 360 + 30 * cos(t),
//			ww - 40 + 30 * sin(t));
//	}
//	glEnd();
//
//	glBegin(GL_LINE_STRIP);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex2f(ww - 310, ww - 60);
//	glVertex2f(ww - 290, ww - 30);
//	glVertex2f(ww - 280, ww - 60);
//	glVertex2f(ww - 270, ww - 30);
//	glVertex2f(ww - 250, ww - 60);
//	glEnd();
//
//
//	glFlush();
//	glPopAttrib();
//}
//
//
//int main(int argc, char** argv)
//{
//	int c_menu, p_menu, f_menu;
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("square");
//	glutDisplayFunc(display);
//	c_menu = glutCreateMenu(color_menu);
//	glutAddMenuEntry("Red", 1);
//	glutAddMenuEntry("Green", 2);
//	glutAddMenuEntry("Blue", 3);
//	glutAddMenuEntry("Cyan", 4);
//	glutAddMenuEntry("Magenta", 5);
//	glutAddMenuEntry("Yellow", 6);
//	glutAddMenuEntry("White", 7);
//	glutAddMenuEntry("Black", 8);
//	p_menu = glutCreateMenu(pixel_menu);
//	glutAddMenuEntry("increase pixel size", 1);
//	glutAddMenuEntry("decrease pixel size", 2);
//	f_menu = glutCreateMenu(fill_menu);
//	glutAddMenuEntry("fill on", 1);
//	glutAddMenuEntry("fill off", 2);
//	glutCreateMenu(right_menu);
//	glutAddMenuEntry("quit", 1);
//	glutAddMenuEntry("clear", 2);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	glutCreateMenu(middle_menu);
//	glutAddSubMenu("Colors", c_menu);
//	glutAddSubMenu("Pixel Size", p_menu);
//	glutAddSubMenu("Fill", f_menu);
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	//glutAttachMenu(GLUT_MIDDLE_BUTTON);
//	myinit();
//	glutReshapeFunc(myReshape);
//	glutKeyboardFunc(key);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//
//}
