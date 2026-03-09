# Afro-Textured Hair Detection Pipeline

Computer vision pipeline for detecting and segmenting afro-textured hairstyles using **C++ and OpenCV**.

This project processes images through multiple image-processing stages to identify hair regions and generate a final segmentation mask and overlay visualization.

The goal is to demonstrate a full **classical computer vision pipeline** including preprocessing, edge detection, thresholding, and mask generation.

---

## Example Results

The pipeline generates intermediate processing stages and final segmentation overlays.

Example outputs include:

- grayscale conversion
- smoothing / noise reduction
- edge detection
- refined edges
- Otsu thresholding
- final hair mask
- overlay visualization on the original image

Results are saved in the `output/` directory.

---

## Project Structure


afro-detection/
├── main.cpp
├── makefile
├── pipeline.cpp
├── pipeline.h
├── utils.cpp
├── utils.h
├── data/
│ └── images/ # input test images
├── output/ # pipeline outputs and visualizations


---

## Pipeline Steps

1. Convert image to grayscale  
2. Apply smoothing filter to reduce noise  
3. Detect edges  
4. Refine edge detection  
5. Apply Otsu thresholding  
6. Generate segmentation mask  
7. Overlay detected hair region onto original image

Each stage is saved as an intermediate output for debugging and visualization.

---

## Technologies Used

- **C++**
- **OpenCV**
- **Makefile build system**

This project focuses on **classical computer vision techniques** rather than deep learning models.

---

## Build

Compile the project using the Makefile:

```bash
make
Run

Execute the program:

./main

The program will process the images inside data/images/ and generate results in the output/ folder.

Motivation

Afro-textured hairstyles are often underrepresented in computer vision datasets and algorithms.
This project explores classical image-processing techniques for detecting complex hair textures and shapes.

Future Improvements

integrate deep learning segmentation models

improve robustness across lighting conditions

expand dataset diversity

real-time detection pipeline