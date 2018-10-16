/**============================================================================
 * @file         test.cpp
 * Author      : Rishabh Choudhary, Akash Atharv
 * Version     : 1.0
 * @Copyright  : MIT License
 * Copyright 2018 Rishabh Choudhary, Akash Atharv
 * @brief        test file for unit testing
 *============================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../include/imageProcessor.hpp"
#include "../include/lanes.hpp"
#include <gtest/gtest.h>

std::string testHeading(int frameNumber)
{
      lanes img;
      cv::Mat originalImage;
      cv::Mat maskImage;
      cv::Mat frame;
      cv::Mat separateImage;
      std::vector<cv::Vec4i> lines;
      std::vector<cv::Point> rightPts;
      std::vector<cv::Point> leftPts;
      std::vector<cv::Point> outputLines;

      cv::VideoCapture cap("../data/Vehicle Detection Raw Video.mp4");
      cap.set(cv::CAP_PROP_POS_FRAMES, frameNumber);
      cap.read(frame);
      img.setOriginalImage(frame);
      img.rgbToGray(frame);
      img.noiseFilter(img.getGrayImage());
      img.edgeDetector(img.getNoiseImage());
      cv::Mat mask = cv::Mat::zeros(img.getEgdeImage().size(), img.getEgdeImage().type());
      cv::Point pts[4] = {
        cv::Point(0, 831),
        cv::Point(629, 465),
        cv::Point(756, 472),
        cv::Point(1195, 711)
    };
      cv::fillConvexPoly(mask, pts, 4, cv::Scalar(255, 0, 0));
      cv::bitwise_and(img.getEgdeImage(), mask, maskImage);
      img.grayToRGB(img.getEgdeImage());
      lines = img.houghTransform(maskImage, img.getHoughImage());
      separateImage = img.lineSeparation(lines, img.getEgdeImage());
      outputLines = img.fitLine(rightPts, leftPts);
      return(img.prediction);
}

TEST(LaneHeadingTest, Vehicle_go_straight) {
      EXPECT_EQ(testHeading(100),"Straight");
}

TEST(LaneHeadingTest, Vehicle_right_turn) {
      EXPECT_EQ(testHeading(600),"Right Turn");
}

TEST(LaneHeadingTest, Vehicle_left_turn) {
      EXPECT_EQ(testHeading(1),"Left Turn");
}



