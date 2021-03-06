
#pragma once
#include <list>
#include "mat.h"
#include "color.h"
#include "imgproc.h"

class Matrix;


Mat32f read_img(const char* fname);
void write_rgb(const char* fname, const Mat32f& mat);
inline void write_rgb(const std::string s, const Mat32f& mat) { write_rgb(s.c_str(), mat); }



Mat32f hconcat(const std::list<Mat32f>& mats);
Mat32f vconcat(const std::list<Mat32f>& mats);

// interpolate color. return Color::NO if any of the neighbor is Color::NO
Color interpolate(const Mat32f& mat, float r, float c);

Mat32f crop(const Mat32f& mat);

Mat32f rgb2grey(const Mat32f& mat);

// get transform from p2 to p1
Matrix getPerspectiveTransform(const std::vector<Vec2D>& p1, const std::vector<Vec2D>& p2);
Matrix getAffineTransform(const std::vector<Vec2D>& p1, const std::vector<Vec2D>& p2);

void fill(Mat32f& mat, const Color& c);

template <typename T>
void resize(const Mat<T> &src, Mat<T> &dst);

