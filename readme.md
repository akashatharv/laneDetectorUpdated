# Lane Detection
[![Build Status](https://travis-ci.org/rishchou/laneDetector.svg?branch=master)](https://travis-ci.org/rishchou/laneDetector)
[![Coverage Status](https://coveralls.io/repos/github/rishchou/laneDetector/badge.svg?branch=master)](https://coveralls.io/github/rishchou/laneDetector?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
---

## Authors

Sprint 1:
- Driver - Rishabh Choudhary
- Navigator - Akash Atharv

Sprint 2:
- Driver - Akash Atharv
- Navigator - Rishabh CHoudhary

## Project Overview

The project aims to design and develop Traffic lane detection and following for autonomous vehicles. Lane Detection technology is being used for various applications in the autonomous vehicular domain such as accident prevention and self driving cars. Self driving cars incoporate various aspects of technology such as perception, control and navigation/planning. 
This project focuses on the perception module to develop traffic lane detection and following using OpenCV with C++. We aim to develop a software infrastructure which is able to detect road lanes and signal the driver in case the car deviates from the designated lane. The lane detection  includes multiple computer vision alorithms implemented in a sequence to finally output the detected lanes given a input video/image of the road.

## Algorithm:
1. Convert input RGB image to grayscale Image to reduce processing time.
2. Apply a noise filter to the output image from previous step to filter out the noise.
3. Feed the noise filtered image to an edge detector (Canny edge detector) to detect the lines which form the boundary of lanes.
4. Mask the edge detected image to consider only region of Interest.
5. Apply hough transform to generate the location of all lines in the image.
6. Classify the lines as left and right using basic linear algebra.
7. Apply linear regression on left and right lines to generate only one line on each side of the lane.
8. Superimpose the output lines on the original Image to display the results.

## Activity diagram:

<p align="center">
  <img width="460" height="800" src="https://github.com/rishchou/laneDetector/blob/master/UML/revised/Activity_diagram.jpeg">
</p>

## Workflow

- First step of the process of lane detection is to capture individual frames from the video sample and then iterate the frames across the video while implementation of the lane detection functionality. This image depicts the first frame from the sample video which consists of multiple lanes, where our vehicle is running on the left most lane.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/originalImage.png">
</p>

- After the frame is acquired, the acquired image is coverted from BGR representation to a grayscale representation which gets rid of a lot of extra information which we do not require and this conversion is necessary for further processing of the frame.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20GrayScale%20Image.png">
</p>

- The next step is to remove any unwanted disturbances present in the surroundings which may hinder the performance of our program. This is achieved using the GaussianBlur function present in the OpenCV library which was chosen among lots of filters like Averaging, MedianBlur, BilateralBlur on the basis of their performance in our task. The GaussianBlur function removes noise from our system by smoothening the frame in smaller frames and iterating those frames throughout the image.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20Noise%20filtered%20Image.png">
</p>

- Since we have to detect lanes in our system, one of the most effective pre-processing techniques which can be used first hand to detect the corresponding lines in the frame is the Cannyedge detector function in OpenCV. The Canny edge detector function uses thresholdding pixel gradient values to detect the edges present in our system.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20Canny%20edge.png">
</p>

- Clearly, seen in the cannyedge detector output, a lot of unwanted edges are detected in the frame which are not required for lane detection. Since, the camera position of the video is fixed, we can therefore define a specific region in the frame called the Region of Interest which is preserved while other information is removed from the canny edge detector output by masking the frame.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20Region%20of%20interest.png">
</p>

- Now the next step in our pipeline, would beI to extract the lanes in our frame using the detected edges in our Region of Interest. This is done using HoughLinesP function present in the OpenCV library where other parameters are estimated by trial and error. The aforementioned function extracts and plots the houghlines on our processed frame as shown in the above figure.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20hough%20lines.png">
</p>

- As seen in the previous Hough transform function, a lot of unwanted lines were detected in the system. These lines are removed by thresholding their slopes (primarily to get rid of horizontal line). Now, the processed lines are regressed to form two separate lines which will correspond to the right and left lanes in our frame. This decision is made by differentiating the lines using their slope.

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20separated%20lines.png">
</p>

- Now the last step, is to draw the two regressed lines or lanes in the input frame and predict the lane turn. This prediction is done by calculating the point of intersection of the two lines and then comparing it with the centre of the origin of both lines. This heading is then also superimposed on the output image, completing the functionality of the program. 

<p align="center">
  <img width="660" height="400" src="https://github.com/rishchou/laneDetector/blob/master/data/Display%20output%20with%20prediction.png">
</p>


## SIP (Solo Iterative Process)
 
This project was developed following pair programming concepts and SIP. The estimated and completed tasks have been stored in the form of product backlog, Iteration backlog and work log to include the specifics of each task. The product backlog contains the set of all of the tasks to be completed for the given feature implementation. The iteration backlog includes tasks that were repeated over the course of Sprint.

The project will be completed in two week sprints as follows:
1. Sprint 1 will cover Phase 1 design and class definitions and stub implementations along with other setup tasks.
2. Sprint 2 will cover Phase 2 implement each class method functionality and unit testing for different input and output and end to end functionality implementation.

Detailed SIP Enactment with product backlog,iteration backlog and work log can be found at:
https://drive.google.com/open?id=183sKj2swdKSm_PcDJ1Mgq3aHfgy-bwtHUH6M_g_unfc

## To-do tasks for pair programming (Driver navigator discussion)
- [x] Update activity diagram 
- [x] Run cpplint and cppcheck (Sprint 2)
- [x] Add defect log and release backlog
- [x] Modify implementation pipeline using separate classes
- [x] Update UML diagram according to new implementation
- [x] Write Unit Tests and test the code
- [x] Run Valgrind to detect memory leaks
- [x] Generate Doxygen document
- [x] Make sure that the repository is updated with deliverables mentioned in Proposal

## Dependencies

The project is implemented using OpenCV library and C++ and cmake. OpenCV can be installed in the system using the following link.
https://docs.opencv.org/3.4.1/d2/de6/tutorial_py_setup_in_ubuntu.html


## Standard install via command-line
```
git clone --recursive https://github.com/rishchou/laneDetector
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/laneDetector ../data//Lane\ Detection\ Test\ Video\ 01.mp4
```

## Building for code coverage 
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/rishchou/laneDetector
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of lane detector

```
cd ~/workspace
mkdir -p laneDetector
cd laneDetector
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../laneDetector/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "laneDetector" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold laneDetector project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the laneDetector in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. laneDetector, cpp-test for unit testing)


## Debug


1. Set breakpoint in source file (i.e. double click in the left margin on the line you want 
the program to break).

2. In Eclipse, right click on the boilerplate-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. laneDetector).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.


- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project.

## Doxygen

Doxygen is a tool used for generating software reference documentation.

To install it use 
```
sudo apt install doxygen
```
To generate doxygen documentation after installation use 
```
doxygen ./Doxygen
```

## License
```
The MIT License

Copyright 2018 Rishabh Choudhary, Akash Atharv

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
