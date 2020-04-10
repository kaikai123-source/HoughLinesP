
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	cv::Mat mat_gray;
	cv::Mat mat_binary;
	cv::Mat mat_canny;
	Mat src;
	src= cv::imread("D:\\2.png");
	mat_gray = cv::imread("D:\\2.png", 0);


	cv::Mat elementRect;
	elementRect = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	cv::morphologyEx(mat_gray, mat_gray, cv::MORPH_CLOSE, elementRect);

	cv::threshold(mat_gray, mat_binary, 125, 255.0, cv::THRESH_BINARY);

	
	cv::Canny(mat_binary, mat_canny, 50, 125, 3);


	std::vector<cv::Vec4i> lines;
	HoughLinesP(mat_canny, lines, 1, CV_PI / 180, 20, 2, 50);
	/*
	Point pt1, pt2;
	pt1.x = lines[0][0];
	pt1.y = lines[0][1];
	pt2.x = lines[0][2];
	pt2.y = lines[0][3];
		line(mat_gray, pt1, pt2, Scalar(0, 255, 55), 1, CV_AA);
	*/
	for (size_t i = 0; i < lines.size(); i++)
	{
		cv::Vec4i& linex = lines[i];
		line(src, cv::Point(linex[0], linex[1]), cv::Point(linex[2], linex[3]), cv::Scalar(0, 255, 55), 1);
	}


	cv::imshow("src", src);

	cv::imshow("dst", mat_canny);
	cv::waitKey(0);


	return 0;
}


