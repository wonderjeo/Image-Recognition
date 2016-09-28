#pragma once

#include <iostream>
#include <windows.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace std;
using namespace cv;

void c_comi();
char c_comr();
void c_coms();
void c_comn();

int check_color(char c);
int check_shape(char c);
