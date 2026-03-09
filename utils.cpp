#include "utils.h"
#include <filesystem>
#include <algorithm>
#include <stdexcept>

namespace fs = std::filesystem;

void ensureDir(const std::string& path) {
    if (!fs::exists(path))
        fs::create_directories(path);
}

cv::Mat loadImage(const std::string& path) {
    cv::Mat img = cv::imread(path);
    if (img.empty())
        throw std::runtime_error("Failed to load image: " + path);
    return img;
}

void saveImage(const std::string& path, const cv::Mat& img) {
    cv::imwrite(path, img);
}

std::vector<std::string> listImages(const std::string& folder) {
    if (!fs::exists(folder))
        throw std::runtime_error("Folder not found: " + folder);

    std::vector<std::string> files;
    std::vector<std::string> exts = {
        ".jpg",".jpeg",".png",".bmp",".tif",".tiff",".webp"
    };

    for (auto& e : fs::directory_iterator(folder)) {
        if (!e.is_regular_file()) continue;
        std::string ext = e.path().extension().string();
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        if (std::find(exts.begin(), exts.end(), ext) != exts.end())
            files.push_back(e.path().string());
    }

    std::sort(files.begin(), files.end());
    return files;
}
