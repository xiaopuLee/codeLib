#include <iostream>
#include <glog/logging.h>

#include "point.h"

int main()
{
    FLAGS_log_dir = "./log";
    google::InitGoogleLogging("myLog");

    LOG(INFO) << "start to log";

    Point point(5, 12);
    LOG(INFO) << "the x of the point : " << point.getX();
    LOG(INFO) << "the y of the point : " << point.getY();

    LOG_IF(INFO, point.getX() >= 5) << "the x of the point is bigger than 5";

    LOG(INFO) << "start to use log every : ";

    for(int id=0; id!=100; ++id)
    {
        LOG_EVERY_N(INFO, 10) << "current index : " << google::COUNTER;
    }

    LOG(INFO) << "start to use log first ";
    
    for(int id=0; id!=100; ++id)
    {
        LOG_FIRST_N(INFO, 10) << "current index : " << google::COUNTER;
    }


    CHECK(point.getLength() == 169);

    Point *p = &point;

    CHECK_NOTNULL(p);


    double x = 3.21, y = 3.1, epsilon = 0.1;

    //CHECK_NEAR(y, x, epsilon);
    //CHECK_DOUBLE_EQ(x, y);
    
    //CHECK_EQ(1.2, 1.21) << "1.2 is different from 1.21";

    const char alpha[] = "alpha";
    const char  beta[] = "beta";

    CHECK_STREQ(alpha, beta) << "const char str are not equal";
    CHECK_STRNE(alpha, beta) << "const char str are equal";





    return 0;
}
