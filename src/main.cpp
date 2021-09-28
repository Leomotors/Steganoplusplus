#include <iostream>
#include <opencv2/opencv.hpp>

#include "Byte.hpp"
#include "decrypt.hpp"
#include "encrypt.hpp"

int main(int argc, char *argv[])
{
    char *filename = argv[1];
    cv::Mat image = cv::imread(filename);

    if (argc <= 2)
    {
        std::string res = decryptImage(image);
        std::cout << res << "\n";
        return 0;
    }

    std::string message;
    for (int i = 2; i < argc; i++)
    {
        message += argv[i];
        message += ' ';
    }
    message[message.size() - 1] = (char)0;

    int position{0};
    for (char c : message)
    {
        for (bool bit : toByte(c))
        {
            writeBit(image, position, bit);
            position++;
        }
    }

    cv::imwrite("Output.png", image);
}
