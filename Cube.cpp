#include <gl/glut.h>  //引用相关包

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  //清空颜色缓冲区
    glColor3f(1, 0, 1);   //重置颜色
    glLoadIdentity();   //清空矩阵
    glTranslatef(0, 0, -5); //将场景中的物体沿z轴负方向移动5个单位长
    glRotatef(40, 0, 1, 0);//旋转函数
    glScalef(1, 2, 1);  //比例变换
    glutWireCube(2.0); //绘制立方体
    glFlush();   //刷新窗口以显示当前绘制图形
}
void init(void)
{
    glClearColor(0, 0, 0, 0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLfloat)w, (GLfloat)h); 
    glMatrixMode(GL_PROJECTION);  //指定哪一个矩阵是当前矩阵
    glLoadIdentity();
    gluPerspective(60, 1, 1.5, 20);   //创建透视投影矩阵(fovy,aspect,zNear,zFar);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("实验二");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

