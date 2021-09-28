#pragma once

#include <opencv2/opencv.hpp>
#include <string>

char decryptByte(cv::Mat &image, int position);

std::string decryptImage(cv::Mat &image);
