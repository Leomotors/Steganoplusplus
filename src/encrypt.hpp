#pragma once

#include <opencv2/opencv.hpp>
#include <utility>

#include "Byte.hpp"

void writeBit(cv::Mat &image, int position, bool bit);

std::pair<cv::Point, int> translatePos(cv::Mat &image, int position);
