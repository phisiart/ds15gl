﻿#ifndef _DSTOOLS_H
#define _DSTOOLS_H

#include <GL/glut.h>
#include "dsVector.h"
#include "dsTexture.h"
#include "dsLight.h"
#include "dsVector2f.h"
#include "dsTextManager.h"
#include "dsModel.h"

extern GLdouble eye_sphere[3];
extern GLdouble up[3];
extern GLdouble center[3];
extern GLdouble eye[3];

extern int window_width;
extern int window_height;
extern int status_bar_width;

//extern MD2Model model;

// extern DSString str;
extern dsTextManager dstext;
extern dsTextManager dstext_small;

extern const char* font_file_name;
extern const int font_height;
extern const int font_height_small;

void dsSet();
void dsSpecialKeys(int key, int x, int y);
void dsKeys(unsigned char key, int x, int y);
//void dsMouseFunc(int key,int x,int y,int);
//void dsPassiveMonitionFunc(int x,int y);

// 显示一个三维坐标系，xyz 轴分别为红绿蓝
void dsShowAxes();

void drawRectange2D(int x,int y,int width,int length);
void fillRectange2D(int x,int y,int width,int length);

#endif
