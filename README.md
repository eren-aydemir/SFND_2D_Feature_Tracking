# SFND 2D Feature Tracking

<img src="images/keypoints.png" width="820" height="248" />

The idea of the camera course is to build a collision detection system - that's the overall goal for the Final Project. As a preparation for this, you will now build the feature tracking part and test various detector / descriptor combinations to see which ones perform best. This mid-term project consists of four parts:

* First, you will focus on loading images, setting up data structures and putting everything into a ring buffer to optimize memory load. 
* Then, you will integrate several keypoint detectors such as HARRIS, FAST, BRISK and SIFT and compare them with regard to number of keypoints and speed. 
* In the next part, you will then focus on descriptor extraction and matching using brute force and also the FLANN approach we discussed in the previous lesson. 
* In the last part, once the code framework is complete, you will test the various algorithms in different combinations and compare them with regard to some performance measures. 

See the classroom instruction and code comments for more details on each of these parts. Once you are finished with this project, the keypoint matching part will be set up and you can proceed to the next lesson, where the focus is on integrating Lidar points and on object detection using deep-learning. 

## Performance Evaluation

- Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.

Mean neighborhood sizes for each detector are given in below table. According to that table, FAST detector can detect largest number of keypoints where HARRIS detector detects the least. If one need to select top-3 detector from preceding vehicle in the traffic scenario as given here, FAST, BRISK and AKAZE are among the best.

Detector  |   #KP    |
----------|----------|
AKAZE	    |   167.00 |
----------|----------|
BRISK	    |   273.13 |
----------|----------|
FAST	     |   406.00 |
----------|----------|
HARRIS	   |   27.13  |
----------|----------|
ORB	      |   119.63 |
----------|----------|
SIFT	     |   137.88 |
----------|----------|
SHITOMASI |	 117.00  |
----------|----------|

- 	Count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, the BF approach is used with the descriptor distance ratio set to 0.8.

Mean matched keypoint numbers and mean matching times of all possible combinations of detectors and descriptors are given in excel sheet named "comparision.xls".

- Log the time it takes for keypoint detection and descriptor extraction. The results must be entered into a spreadsheet and based on this data, the TOP3 detector / descriptor combinations must be recommended as the best choice for our purpose of detecting keypoints on vehicles.

Logged time for keypoint detection and descriptor extraction has been entered into a spreadsheet found as "comparision.xls". According to results TOP3 combinations are;

Detector	  | Descriptor|	 Matcher	 | Selector  |
-----------|-----------|-----------|-----------|
FAST	      | BRIEF	    |  MAT_BF	  |  SEL_KNN |
-----------|-----------|-----------|-----------|
FAST	      | BRIEF	    |   MAT_BF	 |   SEL_NN |
-----------|-----------|-----------|-----------|
FAST	      | ORB	      |   MAT_BF	 |  SEL_NN |
-----------|-----------|-----------|-----------|

Other than FAST detector, other best combinations are;

Detector	  | Descriptor|	 Matcher	 | Selector  |
-----------|-----------|-----------|-----------|
BRISK	     | FREAK	     |   MAT_BF	|    SEL_KNN
-----------|-----------|-----------|-----------|
BRISK	     | BRIEF	     |   MAT_BF	  |  SEL_NN
-----------|-----------|-----------|-----------|
AKAZE	     | BRIEF	     |   MAT_FLANN	| SEL_NN
-----------|-----------|-----------|-----------|

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.1
  * This must be compiled from source using the `-D OPENCV_ENABLE_NONFREE=ON` cmake flag for testing the SIFT and SURF detectors.
  * The OpenCV 4.1.0 source code can be found [here](https://github.com/opencv/opencv/tree/4.1.0)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D_feature_tracking`.
