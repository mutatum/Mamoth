#pragma once
#include <functional>
#include <vector>

enum class DiffMethod
{
    Forward,
    Backward,
    Central
};

class Functional
{
public:
    Functional(std::function<double(const std::vector<double>&)> func);

    std::vector<double> differentiate(const std::vector<double> &x, DiffMethod method, double h) const;

private:
    std::function<double(const std::vector<double> &)> func_;
    double differentiate_single(const std::vector<double> &x, std::size_t i, DiffMethod method, double h) const;
    double forward_difference(const std::vector<double> &x, const std::vector<double> &x_plus_h, double h) const;
    double backward_difference(const std::vector<double> &x, const std::vector<double> &x_minus_h, double h) const;
    double central_difference(const std::vector<double> &x_plus_h, const std::vector<double> &x_minus_h, double h) const;
};
