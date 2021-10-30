#include <gl/glut.h>
void Initial()
{
	glEnable(GL_DEPTH_TEST);// 启用深度测试
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
void Display(void)
{
	static float Moon = 0.0f;// 月亮旋转角度
	static float Earth = 0.0f;// 地球旋转角度

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// 清除颜色缓存和深度缓存

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();// 保存矩阵
	glLoadIdentity();// 重置模型视图矩阵
	glTranslatef(0.0f, 0.0f, -250.0f);//向远移动场景

	glColor3f(255, 255, 0);
	glutSolidSphere(30.0f, 30, 17);//画太阳

	glColor3f(0, 0, 255);
	glRotatef(Earth, 0.0f, 1.0f, 0.0f);	//沿y=1旋转Earth角度
	glTranslatef(105.0f, 0.0f, 0.0f);
	glutSolidSphere(15.0f, 30, 17);//在距离太阳105处画半径为15的地球
	Earth += 5.0f;
	if (Earth > 360.0f)
		Earth = 0.0f;
	glColor3f(200, 200, 200);
	glRotatef(Moon, 0.0f, 1.0f, 0.0f);//沿着y=1旋转Moon角度
	glTranslatef(30.0f, 0.0f, 0.0f);
	glutSolidSphere(6.0f, 30, 17);//在距离地球30处画半径为6的月亮
	Moon += 15.0f;
	if (Moon > 360.0f)
		Moon = 0.0f;
	glPopMatrix();//还原矩阵
	glutSwapBuffers();//显示图像
}




void TimerFunc(int value)
{
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunc, 1);
}

void ChangeSize(int w, int h)
{
	if (h == 0)	h = 1;//防止被0除
	glViewport(0, 0, w, h);//设置视口大小
	GLfloat  fAspect = (GLfloat)w / (GLfloat)h;//计算屏幕比例
	glMatrixMode(GL_PROJECTION);//指定投影矩阵为当前矩阵
	glLoadIdentity();//把坐标系重置为视觉坐标，即屏幕中心
	gluPerspective(45.0f, fAspect, 1.0, 425.0);
	glMatrixMode(GL_MODELVIEW);//制定模型视图矩阵为当前矩阵
	glLoadIdentity();//把坐标系重置为视觉坐标，即屏幕中心
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("实验三");
	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(Display);
	glutTimerFunc(250, TimerFunc, 1);
	Initial();
	glutMainLoop();
	return 0;
}

