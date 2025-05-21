// Copyright 2025 UNN-CS

#include "circle.h"
#include <cmath>
#include <cstdint>
#include <stdexcept>

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    radius = r;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f) {
    if (f < 0) {
        throw std::invalid_argument("Не может быть отрицательной");
    }
    ference = f;
    updateRadiusFromFerence();
    updateArea();
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Площадь не может быть отрицательной");
    }
    area = a;
    updateRadiusFromArea();
    updateFerence();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::updateFerence() {
    ference = 2 * M_PI * radius;
}

void Circle::updateArea() {
    area = M_PI * radius * radius;
}

void Circle::updateRadiusFromFerence() {
    radius = ference / (2 * M_PI);
}

void Circle::updateRadiusFromArea() {
    radius = sqrt(area / M_PI);
}

