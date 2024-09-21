// src/optimization/OptimizationAlgorithm.hpp
#pragma once

class OptimizationAlgorithm
{
public:
    virtual void optimize() = 0;
    virtual ~OptimizationAlgorithm() {}
};
