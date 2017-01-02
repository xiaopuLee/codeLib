#pragma once

class Point
{
public:
    explicit Point(int x, int y);

public:
    void setX(int x);
    void setY(int y);

    int getLength();

    int getX();
    int getY();

    
private:
    int x_;
    int y_;
    
};
