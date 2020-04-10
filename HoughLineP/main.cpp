
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main()
{
	cv::Mat mat_gray;
	cv::Mat mat_binary;
	cv::Mat mat_canny;

	
	mat_gray = cv::imread("D:\\2.png", 0);


	cv::Mat elementRect;
	elementRect = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	cv::morphologyEx(mat_gray, mat_gray, cv::MORPH_CLOSE, elementRect);

	cv::threshold(mat_gray, mat_binary, 125, 255.0, cv::THRESH_BINARY);

	
	cv::Canny(mat_binary, mat_canny, 50, 125, 3);


	std::vector<cv::Vec4i> lines;
	HoughLinesP(mat_canny, lines, 1, CV_PI / 180, 100, 10, 50);

	
	for (size_t i = 0; i < lines.size(); i++)
	{
		cv::Vec4i& linex = lines[i];
		/*
		int dx = linex[2] - linex[0];
		int dy = linex[2] - linex[1];
		double angle = atan2(double(dy), dx) * 180 / CV_PI;
		*/

		line(mat_gray, cv::Point(linex[0], linex[1]), cv::Point(linex[2], linex[3]), cv::Scalar(255, 0, 0), 1);
	}


	cv::imshow("gray", mat_gray);

	cv::imshow("dst", mat_canny);
	cv::waitKey(0);


	return 0;
}


