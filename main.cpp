#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

// Cleaning the string
#include "clean.h"
// Calculating
#include "math.h"
// Range of calculating
#include "braces.h"


// For Debugging
#define DEBUG 0
#if DEBUG == 1
#define LOG(x, y) std::cout << y << " -> " << x << std::endl
#define LOG_V(x, y) std::cout << y << " -> "; \
	for(auto i = x.begin(); i != x.end(); i++) { \
        std::cout << *i << " "; \
    }\
	std::cout<<std::endl;
#else
#define LOG(x, y)
#define LOG_V(x, y)
#endif

int main(){

	// Input
	std::string expre = "";
	std::cout<<"Math exasperation: ";
	std::getline(std::cin >> std::ws,expre);
	LOG(expre,"Input");

	// Checks on the string
	if (expre == "") {
		std::cout<<"Error: Must put an math exasperation"<<std::endl;	
		return 1;
	}
	if (clean_string(expre) == 1) {
		return 1;
	}
	LOG(expre,"Cleaning the string");
	if (closed_brackets(expre) == 1){
		return 1;
	}
	LOG(expre,"Brackets as it should");
	if (closer(expre) == 1) {
		return 1;
	}	
	LOG(expre,"Closer");
	edge_case(expre);
	LOG(expre, "More then 3 digits");
	if (expre.length()<3) {
		std::cout<<"Error: Exasperation must be more then 3 digits"<<std::endl;
		return 1;
	}
	LOG(expre,"Fix spelling");
	if (num_size_chack(expre) == 1) {
		return 1;
	}
	LOG(expre, "Check numbers size");

	// String to Vector
	std::vector<double> expre_v = str_to_vector(expre);
	std::vector<double> calc;
	LOG_V(expre_v, "Str to Vec");

	// Calculating

	// Vector of braces
	std::vector<int> brace_loc;
	// By the order of math
	do {
		// Clearing the Vector
		calc.clear();
		// Indexes to operate in
		brace_loc = start_and_finish_ind(expre_v);
		// What part do we calculate
		if (brace_loc.size() == 0) {
			calc = expre_v;
		} else {
			for(int i = brace_loc[0]+1 ; i<brace_loc[1]; i++){
				calc.push_back(expre_v[i]);
			}
		}

		bool finished_calc = false;
		frac_do(calc);
		LOG_V(calc, "Frac");
		if (size_vector(calc) == 0) {
			LOG(calc[0], ">>>");
			finished_calc = true;
		}
		if (!finished_calc) {
			mul_do(calc);
			LOG_V(calc, "Mul");
			if (size_vector(calc) == 0) {
				LOG(calc[0], ">>>");
				finished_calc = true;
			}
		}
		if (!finished_calc) {
			add_do(calc);
			LOG_V(calc, "Add");
			if (size_vector(calc) == 0) {
				LOG(calc[0], ">>>");
				finished_calc = true;
			}
		}

		
		if (brace_loc.size() == 0) {
			// No braces
			expre_v = calc;
		} else {
			std::vector<double> temp;
			// Before the braces
			for(int i=0; i<brace_loc[0];i++){
				temp.push_back(expre_v[i]);
			}
			// The result of the braces
			temp.push_back(calc[0]);
			// After the braces
			for(size_t i=brace_loc[1]+1; i<expre_v.size();i++){
				temp.push_back(expre_v[i]);
			}
			expre_v = temp;
		}

	}while ( brace_loc.size() != 0);

	// Printing the result
	std::cout<<">> "<<expre_v[0]<<std::endl;


 	return 0;
}

