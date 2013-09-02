﻿#ifndef _DSMAP_H
#define _DSMAP_H

#include <GL/glut.h>

class DSMap {
public:
	DSMap(const char* fileName = "");
	~DSMap();
public:
	void getSize(int* pwidth = nullptr, int* pheight = nullptr) const {
        if (pwidth != nullptr) {
		    *pwidth = width;
        }
        if (pheight != nullptr) {
            *pheight = height;
        }
	}

	int getTile(size_t x, size_t y) const {
		//数组越界
		if (x < 0 || x >= width || y < 0 || y >= height)
			return 0;

		return data[y][x];
	}
    
    // 绘制地图网格
    void renderGrid();

    // 输入格子坐标，给出绘图实际坐标
    void getCoords(size_t x_index, size_t y_index, GLfloat* px, GLfloat* py) const;

private:
	size_t width;
	size_t height;
    GLfloat grid_size; // 地图每块的大小
	int** data;
};

#endif