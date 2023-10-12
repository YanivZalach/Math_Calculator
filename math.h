#pragma once

#include <map>
#include <string>
#include <vector>
#include <map>
#include <limits> // For max value

const double MAX_INT = std::numeric_limits<int>::max();
const double MIN_INT = std::numeric_limits<int>::min();
// Map of math operations - all the numbers are positive so we can use for the chars a negative number
const std::map<char, double> OPERATION = {
    {'+', MAX_INT},
    {'-', MAX_INT -1},
    {'*', MAX_INT -2},
    {'/', MAX_INT -3},
    {')', MAX_INT -4},
    {'(', MAX_INT -5}
};
// Check if size of vector is 1 - we finished
int size_vector(std::vector<double> &vec);

// Actions to do on the expression
double add(double &x, double &y);
double mul(double &x, double &y);
double frac(double &x, double &y);
// Making the string into a vector that we can work with
std::vector<double> str_to_vector(std::string &str);

// Result
void result(std::vector<double> &calc,char &oper,double (*act)(double &,double &));

// The actions that will do on the vector
void add_do(std::vector<double> &calc);
void mul_do(std::vector<double> &calc);
void frac_do(std::vector<double> &calc);
