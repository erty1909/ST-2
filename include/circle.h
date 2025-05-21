// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
 private:
    double radius;
    double ference;
    double area;

    void updateFerence();
    void updateArea();
    void updateRadiusFromFerence();
    void updateRadiusFromArea();

 public:
    explicit Circle(double r);
    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);
    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif // INCLUDE_CIRCLE_H_
