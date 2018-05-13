//
// Created by ivan on 5/6/18.
//

#ifndef MATHGL_MODULE_FUNCTIONARG_H
#define MATHGL_MODULE_FUNCTIONARG_H
#include <exception>
#include <iostream>
/**
 * Function argument struct. It analyses input,
 * calculates step and dots amount. This class helps to create
 * data arrays
 */
struct FunctionArg
{
    /**
     * Range:
     * V0 is for first value in the range,
     * V1 is for last value in the range
     */
    const double v0, v1;
    /**
     * Step
     */
    const double h;
    /**
     * Dots amount
     */
    const int N;
    /**
     * @param v0 - first value in the range
     * @param v1 - second value in the range
     * @param h - step
     * This constructor calculate N (dots amount)
     * and throws invalid_argument exception if
     * h > v1 - v0 or
     * v0 > v1
     */
    FunctionArg(double v0, double v1, double h);
    /**
     * @param v0 - first value in the range
     * @param v1 - second value in the range
     * @param N - dots amount
     * This constructor calculate h (step)
     * and throws invalid_argument exception if
     * N <= 1 or
     * v0 > v1
     */
    FunctionArg(double v0, double v1, int N);
};

#endif