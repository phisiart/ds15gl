﻿#include "dsMap.h"
#include <iostream>

GLfloat DSMap::grid_size = 10.0f;

// 从数组初始化一张地图
void DSMap::init(size_t x_max,size_t y_max,char* data) {
   this->x_max=x_max;
   this->y_max=y_max;
   if(data==NULL){
	  this->data = new char[x_max*y_max];
	  for(int i =0;i<x_max*y_max;i++){
		this->data[i]=0;
	  }
	  return;
   }
   strcpy(this->data,data);
}

DSMap::~DSMap() {
    delete[] data;
}

void DSMap::renderGrid() {
    //glPushAttrib(GL_LIGHTING | GL_TEXTURE_2D | GL_POLYGON_MODE); // 测试不良
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glLineWidth(1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glColor4d(1, 1, 1, 0.2);
    glPushMatrix();
    GLfloat x = - grid_size * x_max / 2;
    GLfloat y;
    for (size_t x_index = 0; x_index < x_max; ++x_index) {
        y = - grid_size * y_max / 2;
        for (size_t y_index = 0; y_index < y_max; ++y_index) {
            glBegin(GL_POLYGON);
            {
                glVertex3f(x,             y,             0.0f);
                glVertex3f(x + grid_size, y,             0.0f);
                glVertex3f(x + grid_size, y + grid_size, 0.0f);
                glVertex3f(x,             y + grid_size, 0.0f);
            }
            glEnd();
            y += grid_size;
        }
        x += grid_size;
    }
    glPopMatrix();
    glPopAttrib();
}

void DSMap::getCoords(
    size_t x_index,
    size_t y_index,
    GLfloat* px,
    GLfloat* py
)  const {
    *px = grid_size * (- (GLfloat)x_max / 2 + x_index + 0.5f);
    *py = grid_size * (- (GLfloat)y_max / 2 + y_index + 0.5f);
}

