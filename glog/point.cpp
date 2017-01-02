#include "point.h"

#include <glog/logging.h>
Point::Point(int x, int y):
    x_(x),
    y_(y)
{
    LOG(INFO) << "init the point";
}


void Point::setX(int x)
{
    LOG(INFO) << "redefine the x";
    x_ = x;
}

void Point::setY(int y)
{
    LOG(INFO) << "redefine the y";
    y_ = y;
}

int Point::getLength()
{
    LOG(INFO) << "output the length";
    return x_*x_ + y_*y_;
}


int Point::getX()
{
    return x_;
}

int Point::getY()
{
    return y_;
}
