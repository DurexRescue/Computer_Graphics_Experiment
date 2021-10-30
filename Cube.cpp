#include <gl/glut.h>  //������ذ�

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  //�����ɫ������
    glColor3f(1, 0, 1);   //������ɫ
    glLoadIdentity();   //��վ���
    glTranslatef(0, 0, -5); //�������е�������z�Ḻ�����ƶ�5����λ��
    glRotatef(40, 0, 1, 0);//��ת����
    glScalef(1, 2, 1);  //�����任
    glutWireCube(2.0); //����������
    glFlush();   //ˢ�´�������ʾ��ǰ����ͼ��
}
void init(void)
{
    glClearColor(0, 0, 0, 0);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLfloat)w, (GLfloat)h); 
    glMatrixMode(GL_PROJECTION);  //ָ����һ�������ǵ�ǰ����
    glLoadIdentity();
    gluPerspective(60, 1, 1.5, 20);   //����͸��ͶӰ����(fovy,aspect,zNear,zFar);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("ʵ���");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

