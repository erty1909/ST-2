// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "../include/circle.h"
#include "../include/tasks.h"

// Circle class tests
TEST(CircleTest, Constructor) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5.0 * 5.0);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 2.0 * 2.0);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    double newFerence = 10.0;
    c.setFerence(newFerence);
    EXPECT_DOUBLE_EQ(c.getFerence(), newFerence);
    EXPECT_DOUBLE_EQ(c.getRadius(), newFerence / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * pow(newFerence / (2 * M_PI), 2));
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    double newArea = 10.0;
    c.setArea(newArea);
    EXPECT_DOUBLE_EQ(c.getArea(), newArea);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(newArea / M_PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * sqrt(newArea / M_PI));
}

TEST(CircleTest, NegativeRadius) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeArea) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e6 * 1e6);
}

TEST(CircleTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e-6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e-6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e-6 * 1e-6);
}

TEST(CircleTest, PrecisionTest) {
    Circle c(1.0);
    double expectedArea = M_PI;
    double actualArea = c.getArea();
    EXPECT_NEAR(actualArea, expectedArea, 1e-10);
}

TEST(CircleTest, ChainUpdates) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(c.getFerence());
    c.setArea(c.getArea());
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
}

// Earth and Rope problem tests
TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateEarthRopeGap();
    EXPECT_GT(gap, 0.0);
    EXPECT_LT(gap, 1.0); // Gap should be less than 1 meter
}

TEST(EarthRopeTest, GapConsistency) {
    double gap1 = calculateEarthRopeGap();
    double gap2 = calculateEarthRopeGap();
    EXPECT_DOUBLE_EQ(gap1, gap2);
}

TEST(EarthRopeTest, PrecisionGap) {
    double gap = calculateEarthRopeGap();
    double expectedGap = 1.0 / (2 * M_PI);
    EXPECT_NEAR(gap, expectedGap, 1e-10);
}

// Pool problem tests
TEST(PoolTest, PathCost) {
    PoolCosts costs = calculatePoolCosts();
    EXPECT_GT(costs.pathCost, 0.0);
    EXPECT_GT(costs.fenceCost, 0.0);
    EXPECT_GT(costs.totalCost, costs.pathCost);
    EXPECT_GT(costs.totalCost, costs.fenceCost);
}

TEST(PoolTest, CostConsistency) {
    PoolCosts costs1 = calculatePoolCosts();
    PoolCosts costs2 = calculatePoolCosts();
    EXPECT_DOUBLE_EQ(costs1.pathCost, costs2.pathCost);
    EXPECT_DOUBLE_EQ(costs1.fenceCost, costs2.fenceCost);
    EXPECT_DOUBLE_EQ(costs1.totalCost, costs2.totalCost);
}

TEST(PoolTest, TotalCostCalculation) {
    PoolCosts costs = calculatePoolCosts();
    EXPECT_DOUBLE_EQ(costs.totalCost, costs.pathCost + costs.fenceCost);
}

TEST(PoolTest, PathAreaCalculation) {
    Circle pool(3.0);
    Circle poolWithPath(4.0);
    double expectedPathArea = poolWithPath.getArea() - pool.getArea();
    PoolCosts costs = calculatePoolCosts();
    EXPECT_DOUBLE_EQ(costs.pathCost, expectedPathArea * 1000.0);
}

TEST(PoolTest, FenceLengthCalculation) {
    Circle poolWithPath(4.0);
    double expectedFenceLength = poolWithPath.getFerence();
    PoolCosts costs = calculatePoolCosts();
    EXPECT_DOUBLE_EQ(costs.fenceCost, expectedFenceLength * 2000.0);
}

TEST(PoolTest, CostPrecision) {
    PoolCosts costs = calculatePoolCosts();
    double expectedPathArea = M_PI * (4.0 * 4.0 - 3.0 * 3.0);
    double expectedPathCost = expectedPathArea * 1000.0;
    EXPECT_NEAR(costs.pathCost, expectedPathCost, 1e-10);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
