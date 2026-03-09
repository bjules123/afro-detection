#ifndef PIPELINE_H
#define PIPELINE_H

#include <opencv2/opencv.hpp>

struct Result {
    cv::Mat gray;
    cv::Mat smoothed;
    cv::Mat edges;
    cv::Mat otsu;
    cv::Mat final_mask;
    cv::Mat overlay;
};

Result runPipeline(const cv::Mat& input);

#endif
