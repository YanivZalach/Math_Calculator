#pragma once

#include <iostream>

// Max digit for a input number
const int MAX_DIG = 8; // Based on the MAX_INT in the math.h file


// No spaces and none math chars
int clean_string(std::string &str);
// Start and End of the exasperation
int closer(std::string &str);
// Checking that all the brackets are closed
int closed_brackets(std::string &str);
// Check the sizes of the numbers
int num_size_chack(std::string &str);
// Fix problem with '-'
void edge_case(std::string &str);
