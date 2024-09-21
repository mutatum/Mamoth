// src/optimization/OptimizationAlgorithm.hpp
#ifndef OPTIMIZATION_ALGORITHM_HPP
#define OPTIMIZATION_ALGORITHM_HPP

class OptimizationAlgorithm
{
public:
    virtual void optimize() = 0;
    virtual ~OptimizationAlgorithm() {}
};

#endif // OPTIMIZATION_ALGORITHM_HPP
