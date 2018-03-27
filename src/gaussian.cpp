//
// Created by Mingjie Ma on 27/03/2018.
//

#include "gaussian.h"

Gaussian::Gaussian(const Mat &mat, int range = DEFAULT_FILTER_SIZE) {
    _range = range;
    _mat = mat;
}

Mat Gaussian::apply() {
    return _mat;
}

