#include "pipeline.h"
#include "utils.h"
#include <filesystem>
#include <iostream>

int main() {
    try {
        ensureDir("output");

        auto files = listImages("data/images");
        for (const auto& path : files) {
            cv::Mat img = loadImage(path);
            Result r = runPipeline(img);

            std::string base = "output/" +
                std::filesystem::path(path).stem().string();
            ensureDir(base);

            saveImage(base + "/1_gray.png", r.gray);
            saveImage(base + "/2_smoothed.png", r.smoothed);
            saveImage(base + "/3_edges.png", r.edges);
            saveImage(base + "/4_otsu.png", r.otsu);
            saveImage(base + "/5_final_mask.png", r.final_mask);
            saveImage(base + "/6_overlay.png", r.overlay);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
