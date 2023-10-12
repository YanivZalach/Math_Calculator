#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>
#include "math.h"

// For Debugging
#define DEBUG 0
#if DEBUG == 1
#define LOG(x) std::cout<<x<<std::endl
#define LOG_P(x,y) std::cout<<y<<"->"<<x<<std::endl
#else
#define LOG(x)
#define LOG_P(x,y)
#endif

// Is the size of the vector = 1
int size_vector(std::vector<double> &vec){
	return vec.size()==1 ? 0 : 1;
}

// Actions
double add(double &x, double &y){
	return x+y;
}
double sub(double &x, double &y){
	return x-y;
}
double mul(double &x, double &y){
	return x*y;
}
double frac(double &x, double &y){
	return x/y;
}

std::vector<double> str_to_vector(std::string &str){
	LOG("Str to Vector");
	// Returned vector
	std::vector<double> v;
	// Checking if there is a ( at the start of the expression - base on clean.cpp/closer this can be the only char at the start
	size_t i = 0;
	if (str[0] == '('){
		LOG("Pushed first (");
		// Use .at because we don't change a thing
		v.push_back(OPERATION.at('('));
		i = 1;
	}
	// The numbers contain the minus
	double number = 0;
	bool minus = false;
	for(;i<str.length();i++){
	    if (str[i] >= '0' && str[i] <= '9') {
        	// If the current character is a digit, build a number
			number = number * 10 + (str[i] - '0');
        } else {
			// If the current character is not a digit - push the current number
			if (!minus) {
				v.push_back(number);
				LOG(number);
			} else {
				v.push_back(-number);
				LOG(-number);
			}
			// Reset the number
            number = 0;
			// Reset the minus flag
			minus = false;
			while(i<str.length()&&(!(str[i] >= '0' && str[i] <= '9'))){
	            // Push the operator - as many as we need
				// Minus sign
				if (str[i] == '-') {
					minus = true;
					v.push_back(OPERATION.at('+'));
					LOG("- -> +");
				}
				else{
					v.push_back(OPERATION.at(str[i]));
					LOG(str[i]);
				}
				i++;
			}
			i--;
        }
	}
    // If there's a final number in the string, add it to the tree
	if (number != 0) {
		if (!minus) {
			v.push_back(number);
			LOG(number);
		} else {
			v.push_back(-number);
			LOG(-number);
		}
	}
	// 0 at the end
	if (str.back() == '0' && (!(str[str.length()-2]<=9 && str[str.length()-2]>=0))){
		v.push_back(0);
		LOG(0);
	}
	return v;
}

void result(std::vector<double> &calc,char &oper,double (*act)(double &,double &)) {

	bool run_again = false;
	do{
		// Restarting
		run_again = false;
		// New vector to build on
		std::vector<double> new_vec;

		if (calc[1] != OPERATION.at(oper)){
			LOG_P(calc[0],1);
		    new_vec.push_back(calc[0]);
		}
		// To make shore we don't do actions we don't need
		bool made_calc_before = false;
    	for (size_t i = 1; i < calc.size()-1; i++) {
    	    if (calc[i] == OPERATION.at(oper)){
				// I am an OPERATION but not the one before me and after me
				if (!made_calc_before) {
		            // Handle action
					LOG_P(act(calc[i-1],calc[i+1]),2);
					new_vec.push_back(act(calc[i-1],calc[i+1]));
		            i +=1;
					// We make a calculation
					made_calc_before = true;
					// Must check we did all we need
					run_again = true;
				}else{
					made_calc_before = false;
					LOG_P(calc[i],3);
					new_vec.push_back(calc[i]);
				}
    	    } else if (calc[i+1] == OPERATION.at(oper) && !made_calc_before) {
				// The next one is an operator and i am not
				continue;
			}else {
    		        // Push elements onto the new_vec vector
					LOG_P(calc[i],4);
    		        new_vec.push_back(calc[i]);
    		    }
    		}

		// Is the last char an operator
		bool last_is_action = false;
		for (const auto& pair : OPERATION){
			if (calc[calc.size()-2] == pair.second) {
				last_is_action = true;
				break;
			}
		}
		if (last_is_action){
			LOG_P(calc[calc.size()-1],5);
    		new_vec.push_back(calc[calc.size()-1]);
		}
		calc = new_vec;
		LOG("Run");
		// Is the size is 1
		if (calc.size()==1) {
			return;
		}
	}while(run_again);
}

// The actions that will do on the vector
void add_do(std::vector<double> &calc){
	char c_action = '+';
	double (*f_action)(double &,double &) = &add;
	result(calc,c_action,f_action);
}
void mul_do(std::vector<double> &calc){
	char c_action = '*';
	double (*f_action)(double &,double &) = &mul;
	result(calc,c_action,f_action);
}
void frac_do(std::vector<double> &calc){
	char c_action = '/';
	double (*f_action)(double &,double &) = &frac;
	result(calc,c_action,f_action);
}
