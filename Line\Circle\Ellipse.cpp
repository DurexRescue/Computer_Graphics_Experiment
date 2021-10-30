#include<GL/glut.h>
#include<iostream>
#include<gl/gl.h>
#include<windows.h>
using namespace std;

void bresenham_line(int x0, int y0, int x1, int y1);
void bresenham_circle(int r);
void bresenham_ellipse(int a, int b);

void initial()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50, 50, -50, 50);
}
void display()
{

	int x0 = 0;					//直线数据
	int y0 = 0;
	int x1 = 40;//5 8
	int y1 = 64;
	int r = 20;					//圆的半径

	int a = 16;						//椭圆长短轴
	int b = 9;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);				//x轴
	glVertex2i(-50, 0);
	glVertex2i(50, 0);
	glEnd();

	glBegin(GL_LINES);				//y轴
	glVertex2i(0, 50);
	glVertex2i(0, -50);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);	   //BH算法
	glPointSize(2.0);
	glBegin(GL_POINTS);
	bresenham_line(x0,y0,x1,y1);
	bresenham_circle(r);
	bresenham_ellipse(a, b);
	glEnd();
	glFlush();
}
void setPixel(GLint xCoord, GLint yCoord)
{
	glVertex2i(xCoord, yCoord);
}
void bresenham_ellipse(int a, int b)
{
	int d;
	int x = 0;
	int y = b;
	d = b * b + a * a * (-b + 0.25);
	while (2 * a * a * (y - 0.5) > 2 * b * b * (x + 1))
	{
		if (d >= 0)
		{
			setPixel(x, y);
			setPixel(x, -y);
			setPixel(-x, -y);
			setPixel(-x, y);
			d = d + b * b * (2 * x + 3) + a * a * (-2 * y + 2);
			x++;
			y--;
		}
		else
		{
			setPixel(x, y);
			setPixel(x, -y);
			setPixel(-x, -y);
			setPixel(-x, y);
			d = d + b * b * (2 * x + 3);
			x++;
		}
	}
	d = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
	while (y != 0)
	{
		if (d >= 0)
		{
			setPixel(x, y);
			setPixel(x, -y);
			setPixel(-x, -y);
			setPixel(-x, y);
			d = d + a * a * (-2 * y + 3);
			y--;
		}
		else
		{
			cout << "(" << x << "," << y << ")" << endl;
			setPixel(x, y);
			setPixel(x, -y);
			setPixel(-x, -y);
			setPixel(-x, y);
			d = b * b * (2 * x + 2) + a * a * (-2 * y + 3);
			x++;
			y--;
		}
	}
}
void bresenham_circle(int r)
{
	int d;
	int x = 0;
	int y = r;
	d = 1 - r;
	while (x <= y)
	{
		if (d >= 0)
		{
			cout << "(" << x << "," << y << ")" << endl;
			setPixel(x, y);
			setPixel(y, x);
			setPixel(x, -y);
			setPixel(y, -x);
			setPixel(-x, -y);
			setPixel(-y, -x);
			setPixel(-x, y);
			setPixel(-y, x);
			d = d + 2 * x - 2 * y + 5;
			x++;
			y--;
		}
		else
		{
			cout << "(" << x << "," << y << ")" << endl;
			setPixel(x, y);
			setPixel(y, x);
			setPixel(x, -y);
			setPixel(y, -x);
			setPixel(-x, -y);
			setPixel(-y, -x);
			setPixel(-x, y);
			setPixel(-y, x);
			x++;

			d = d + 2 * x + 3;
		}
	}
}
void bresenham_line(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d;
	int x = x0;
	int y = y0;
	if (dy >= dx)						//y为最大迁移方向
	{
		d = 2 * dx - dy;			//d初始值
		while (y <= y1)
		{
			cout << "(" << x << "," << y << ")" << endl;
			setPixel(x, y);
			y++;
			if (d > 0)
			{
				x++;
				d = d + 2 * dx - 2 * dy;
			}
			else
			{
				d = d + 2 * dx;
			}
		}
	}
	else                                //x为最大迁移方向
	{
		d = dx - 2 * dy;
		while (x <= x1)
		{
			setPixel(x, y);
			x++;
			if (d > 0)
			{
				y++;
				d = d - 2 * dy;
			}
			else
			{
				d = d + 2 * dx - 2 * dy;
			}
		}
	}
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("实验一");
	glutDisplayFunc(&display);
	initial();
	glutMainLoop();
	return 0;
}
