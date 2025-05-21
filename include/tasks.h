// Copyright 2025 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

// Calculate the gap between Earth and rope after adding 1 meter
// Earth radius is 6378.1 km
double calculateEarthRopeGap();

// Calculate the cost of materials for pool path and fence
// Pool radius is 3m, path width is 1m
// Path cost is 1000 rubles per square meter
// Fence cost is 2000 rubles per linear meter
struct PoolCosts {
    double pathCost;
    double fenceCost;
    double totalCost;
};

PoolCosts calculatePoolCosts();

#endif  // INCLUDE_TASKS_H_
