#include "decrypt.hpp"

#include <opencv2/opencv.hpp>

#include "encrypt.hpp"

const int twopow[]{128, 64, 32, 16, 8, 4, 2, 1};

char decryptByte(cv::Mat &image, int position)
{
    int res{0};

    for (int i = 0; i < 8; i++)
    {
        int pos = position * 8 + i;
        const auto &[Point, channel] = translatePos(image, pos);
        res += twopow[i] * (image.at<cv::Vec3b>(Point)[channel] % 2);
    }

    return (char)res;
}

std::string decryptImage(cv::Mat &image)
{
    int position{0};
    std::string res;
    do
    {
        res += decryptByte(image, position);
        position++;
    } while (res.back());

    res.pop_back();
    return res;
}
