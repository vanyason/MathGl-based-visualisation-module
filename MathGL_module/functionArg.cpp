//
// Created by ivan on 5/6/18.
//

#include "functionArg.h"

FunctionArg::FunctionArg(double v0, double v1, double h) :
        v0(v0),
        v1(v1),
        h(h),
        N(((v1 - v0) / h) + 1.3) // 1.3 to round value
{
    if (N <= 0 || h > (v1 - v0) || v0 > v1)
        throw std::invalid_argument("Invalid parameters:\n"
                                    "h should be less than v1 - v0,\n"
                                    "v0 should be < v1");
}
FunctionArg::FunctionArg(double v0, double v1, int N) :
        v0(v0),
        v1(v1),
        N(N),
        h((v1 - v0) / (N - 1))
{
    if (N <= 1 || v0 > v1)
        throw std::invalid_argument("Invalid parameters:\n"
                                    "N should be > 1,\n"
                                    "v0 should be < v1");
}