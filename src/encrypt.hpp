#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <utility>

#include "Byte.hpp"

void writeBit(cv::Mat &image, int position, bool bit);

std::pair<cv::Point, int> translatePos(cv::Mat &image, int position);

void encryptImage(cv::Mat &image, std::string message);
