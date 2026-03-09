#ifndef UTILS_H
#define UTILS_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

void ensureDir(const std::string& path);
cv::Mat loadImage(const std::string& path);
void saveImage(const std::string& path, const cv::Mat& img);
std::vector<std::string> listImages(const std::string& folder);

#endif
