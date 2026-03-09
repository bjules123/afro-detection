#include "pipeline.h"

Result runPipeline(const cv::Mat& input) {
    Result r;

    cv::cvtColor(input, r.gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(r.gray, r.smoothed, {5,5}, 0);

    cv::Canny(r.smoothed, r.edges, 50, 150);

    cv::threshold(
        r.smoothed,
        r.otsu,
        0,
        255,
        cv::THRESH_BINARY_INV | cv::THRESH_OTSU
    );

    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE, {3,3}
    );

    cv::morphologyEx(r.otsu, r.final_mask, cv::MORPH_CLOSE, kernel);

    r.overlay = input.clone();
    for (int y = 0; y < r.edges.rows; y++) {
        for (int x = 0; x < r.edges.cols; x++) {
            if (r.edges.at<uchar>(y,x) > 0) {
                r.overlay.at<cv::Vec3b>(y,x) = {0,255,0};
            }
        }
    }

    return r;
}
