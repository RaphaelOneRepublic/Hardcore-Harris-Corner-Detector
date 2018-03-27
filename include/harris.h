//
// Created by Mingjie Ma on 27/03/2018.
//

#ifndef HARDCORE_HARRIS_CORNER_DETECTOR_HARRIS_H
#define HARDCORE_HARRIS_CORNER_DETECTOR_HARRIS_H

#include <opencv2/opencv.hpp>
#include <derivative.h>
#include <vector>

#define DEFAULT_HARRIS_K 0.04
#define DEFAULT_FILTER_SIZE 3
#define DEFAULT_SIGMA 1
#define DEFAULT_MAX_PERCENTAGE 0.05

using namespace cv;
using namespace std;

class Harris {
private:
    Mat _mat;
    float _k;
    int _radius;
    float _sigma;
public:
    explicit Harris(const Mat &img,
                    float k = DEFAULT_HARRIS_K,
                    int radius = DEFAULT_FILTER_SIZE,
                    float sigma = DEFAULT_SIGMA);
    Mat harris_response();
    static vector<Point> non_maximum_suppression(Mat _mat);
};


#endif //HARDCORE_HARRIS_CORNER_DETECTOR_HARRIS_H
