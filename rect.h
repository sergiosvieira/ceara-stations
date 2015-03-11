#ifndef __MRECT__
#define __MRECT__

#include <cmath>

#define PI 3.14159265

typedef struct Point
{
    float x;
    float y;
    Point(float a_x, float a_y):
          x(a_x), y(a_y){}
    Point():
          x(0.f), y(0.f){}
} Point;

typedef struct MRect
{
    Point topLeft;
    float width;
    float height;
    MRect(float a_top, float a_left,
         float a_width, float a_height)
    {
        topLeft.x = a_top;
        topLeft.y = a_left;
        width = a_width;
        height = a_height;
    }
} MRect;

void transformPointBetweenRects(Point& a_destinyPoint, const Point& a_sourcePoint,
                                MRect& a_source, MRect& a_destiny)
{
    float ratioX = (a_sourcePoint.x - a_source.topLeft.x) / a_source.width;
    float ratioY = -(a_sourcePoint.y - a_source.topLeft.y) / a_source.height;

    a_destinyPoint.x = a_destiny.topLeft.x + a_destiny.width * ratioX;
    a_destinyPoint.y = a_destiny.topLeft.y + a_destiny.height * ratioY;
}

void translate(Point& a_translatedPoint,
               Point& a_point,
               float a_x,
               float a_y)
{
    a_translatedPoint.x = a_point.x + a_x;
    a_translatedPoint.y = a_point.y + a_y;
}

void scale(Point& a_scaledPoint,
           Point& a_point,
           float a_scaleX,
           float a_scaleY)
{
    a_scaledPoint.x = a_point.x * a_scaleX;
    a_scaledPoint.y = a_point.y * a_scaleY;
}

void rotate(Point& a_rotatedPoint,
            Point& a_point,
            float a_degree)
{
    float aux = a_degree * PI / 180.f;

    a_rotatedPoint.x = cos(aux) * a_point.x - sin(aux) * a_point.y;
    a_rotatedPoint.y = sin(aux) * a_point.x + cos(aux) * a_point.y;
}

#endif /** __MRECT__ **/
