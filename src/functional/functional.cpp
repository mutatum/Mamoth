#pragma once
#include "functional.hpp"
#include <stdexcept>

Functional::Functional(std::function<double(const std::vector<double>&)> func) : func_(func) {}

// Differentiate method using enum-based method selection for vector of doubles
std::vector<double> Functional::differentiate(const std::vector<double> &x, DiffMethod method = DiffMethod::Central, double h = 1e-5) const
{
    std::vector<double> derivatives(x.size());
    for (std::size_t i = 0; i < x.size(); ++i)
    {
        derivatives[i] = differentiate_single(x, i, method, h);
    }
    return derivatives;
}

// Differentiate for a single variable in the vector (partial derivative)
double Functional::differentiate_single(const std::vector<double> &x, std::size_t i, DiffMethod method, double h) const
{
    std::vector<double> x_plus_h = x, x_minus_h = x;
    x_plus_h[i] += h; // Modify the i-th element for forward/backward/central difference
    x_minus_h[i] -= h;

    switch (method)
    {
    case DiffMethod::Forward:
        return forward_difference(x, x_plus_h, h);
    case DiffMethod::Backward:
        return backward_difference(x, x_minus_h, h);
    case DiffMethod::Central:
        return central_difference(x_plus_h, x_minus_h, h);
    default:
        throw std::invalid_argument("Unknown differentiation method");
    }
}

// Forward difference method
double Functional::forward_difference(const std::vector<double> &x, const std::vector<double> &x_plus_h, double h) const
{
    return (func_(x_plus_h) - func_(x)) / h;
}

// Backward difference method
double Functional::backward_difference(const std::vector<double> &x, const std::vector<double> &x_minus_h, double h) const
{
    return (func_(x) - func_(x_minus_h)) / h;
}

// Central difference method
double Functional::central_difference(const std::vector<double> &x_plus_h, const std::vector<double> &x_minus_h, double h) const
{
    return (func_(x_plus_h) - func_(x_minus_h)) / (2 * h);
}
