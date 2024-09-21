#pragma once
#include <functional>
#include <vector>

class Functional
{
public:
    // A functional taking a vector of variables and returning a double (the cost or objective value)
    using FunctionalType = std::function<double(const std::vector<double> &)>;

    // Constructor accepts any callable that matches the signature
    Functional(FunctionalType func) : objectiveFunction(func) {}

    // Evaluate the functional for a given set of variables
    double evaluate(const std::vector<double> &variables) const
    {
        return objectiveFunction(variables);
    }

private:
    FunctionalType objectiveFunction;
};
