#include "../include/tasks.h"
#include "../include/circle.h"

double calculateEarthRopeGap() {
    const double EARTH_RADIUS = 6378.1 * 1000;
    const double ADDITIONAL_LENGTH = 1.0;

    Circle earth(EARTH_RADIUS);
    double originalFerence = earth.getFerence();
    double newFerence = originalFerence + ADDITIONAL_LENGTH;
    
    earth.setFerence(newFerence);
    double newRadius = earth.getRadius();
    
    return newRadius - EARTH_RADIUS;
}

PoolCosts calculatePoolCosts() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double PATH_COST_PER_SQM = 1000.0;
    const double FENCE_COST_PER_METER = 2000.0;

    Circle pool(POOL_RADIUS);
    Circle poolWithPath(POOL_RADIUS + PATH_WIDTH);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double pathCost = pathArea * PATH_COST_PER_SQM;
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * FENCE_COST_PER_METER;

    PoolCosts costs;
    costs.pathCost = pathCost;
    costs.fenceCost = fenceCost;
    costs.totalCost = pathCost + fenceCost;

    return costs;
} 