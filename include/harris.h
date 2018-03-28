//
// Created by Mingjie Ma on 27/03/2018.
//

#ifndef HARDCORE_HARRIS_CORNER_DETECTOR_HARRIS_H
#define HARDCORE_HARRIS_CORNER_DETECTOR_HARRIS_H

#include <opencv2/opencv.hpp>
#include <derivative.h>
#include <vector>

#define DEFAULT_HARRIS_K 0.02
#define DEFAULT_FILTER_SIZE 5
#define DEFAULT_SIGMA 2.5
#define DEFAULT_THRESHOLD 90000

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

    static vector<Point> non_maximum_suppression(Mat _mat, float _threshold = DEFAULT_THRESHOLD);
};


#endif //HARDCORE_HARRIS_CORNER_DETECTOR_HARRIS_H
