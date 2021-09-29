#include "encrypt.hpp"

#include <opencv2/opencv.hpp>

#include "Byte.hpp"

void writeBit(cv::Mat &image, int position, bool bit)
{
    const auto &[Point, channel] = translatePos(image, position);
    cv::Vec3b &Pixel = image.at<cv::Vec3b>(Point);
    if (Pixel[channel] % 2)
        Pixel[channel] += (int)bit - 1;
    else
        Pixel[channel] += (int)bit;
}

std::pair<cv::Point, int> translatePos(cv::Mat &image, int position)
{
    return {cv::Point((position / 3) % image.cols, (position / 3) / image.cols),
            position % 3};
}

void encryptImage(cv::Mat &image, std::string message)
{
    int position{0};
    for (char c : message)
    {
        for (bool bit : toByte(c))
        {
            writeBit(image, position, bit);
            position++;
        }
    }
}
