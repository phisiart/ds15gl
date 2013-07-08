#include "dsStatusBar.h"
#include "dstools.h"
#include "dsText.h"
#include <sstream>
#include <iomanip>

DSStatusBar::DSStatusBar() : width(200) {}


DSStatusBar::~DSStatusBar() {}

void DSStatusBar::show() {
	
	// ����ͶӰ��ʽΪ 2D ƽ��ͶӰ
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, width, 0, window_height, 0.01, 1000);	
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	glViewport(window_width - width, 0, width, window_height);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	gluLookAt(0.0, 0.0, 200.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glColor3d(1.0, 1.0, 1.0);



	//fillRectange2D(0,0,width,window_height);

	//���ﻭС��ͼ��ս���������״̬��Ϣ
	//����
	glPushMatrix();
	glTranslatef(width / 2, width / 2, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);	

	

	glutSolidTeapot(50);
	glPopMatrix();
	
	// ������������дһ���۾�λ��
	glRasterPos2d(8.0, 8.0);
	std::ostringstream os;
	// os.unsetf(std::scientific);
	os << "(" << std::fixed << std::setprecision(2) << eye[0] << ", " << eye[1] << ", " << eye[2] << ")";
	drawString(os.str().c_str());
	
	glRasterPos2d(40.0, 24.0);
	drawString("Eye position");

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	//�ص�͸��ͶӰ
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void DSStatusBar::setSize(int width, int height){
	window_height = height;
	window_width = width;
}