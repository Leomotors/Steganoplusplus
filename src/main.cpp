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

    if (std::string(argv[2]).starts_with("--stdin"))
    {
        std::string message2 = "";
        std::string temp;
        while (std::getline(std::cin, temp))
            message2 += temp + '\n';
        message2.pop_back();
        message2 += (char)0;
        if (message2.size())
            message = message2;
    }

    encryptImage(image, message);

    cv::imwrite("Output.png", image);
}
