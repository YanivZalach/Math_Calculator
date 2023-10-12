#include <cstddef>
#include <iostream>
#include <string>
#include "clean.h"

// For Debugging
#define DEBUG 0
#if DEBUG == 1
#define LOG(x) std::cout<<x<<std::endl
#else
#define LOG(x)
#endif

int clean_string(std::string &str) {
	// No spaces, and make shore all the chars are valid
	// The clean string
    std::string newStr = "";
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
			// We don't want to include space in the clean string
            continue;
        } else if ((str[i] >= '0' && str[i] <= '9')||(str[i]=='/' ||str[i]=='+' ||str[i]=='-' ||str[i]=='*' ||str[i]=='(' ||str[i]==')')) {
            newStr += str[i];
        } else {
            std::cout << "Error: Invalid character '" << str[i] << "'" << std::endl;
			return 1;
        }
    }
    str = newStr;  // Assign the cleaned string back to the original string.
	return 0;
}

int closer(std::string &str){
	if(str[0] == '-') {
		str = '0'+str;	
	} else if(str[0] == '+') {
		str.erase(str.begin()); // Erase the first character
	} else if(str[0] == '*' || str[0] == '/'){
		std::cout<<"Error: Can't start a math exasperation with '"<<str[0]<<"'"<<std::endl;
		return 1;
	}

    if (!((str.back() >= '0' && str.back() <= '9')||(str.back() == ')'))){
		std::cout<<"Error: Can't end a math exasperation with '"<<str.back()<<"'"<<std::endl;
		return 1;
	}
	return 0;
}

int closed_brackets(std::string &str){
	// Make shore all the brackets are closed
	// A counter will be added 1 on every '(' and subtracted 1 on ')'. If counter < 0 at the operation we have more ')' then '(', and if at the end we don't have counter == 0 not all the brackets are closed
	int counter = 0;
	LOG("Counter Log:");
	for(size_t i=0;i<str.length();i++){
		// Update counter
		LOG(counter);
		if(str[i] == '('){
			counter++;
		} else if (str[i] == ')') {
			counter--;
		}
		// Check if counter < 0
		if (counter < 0) {
			std::cout<<"Error: Check your brackets in the exasperation"<<std::endl;
			return 1;
		}
	}
	if (counter == 0) {
		// All good
		return 0;
	}
	// Not good
	std::cout<<"Error: Check your brackets in the exasperation"<<std::endl;
	return 1;
}

int num_size_chack(std::string &str){
	// Checking there isn't a number above the MAX_DIG number of digits
	int digit_counter = 0;
	for(size_t i = 0; i<str.length();i++){
		if (str[i]<='9' && str[i] >='0') {
			// One more digit
			digit_counter++;
		} else if (digit_counter > MAX_DIG) {
			// Too big
			std::cout<<"Error: Number with more then "<<MAX_DIG<<" digits"<<std::endl;
			return 1;
		} else {
			// Not a digit
			digit_counter = 0;
		}
	}
	// All good
	return 0;
}

void edge_case(std::string &str) {
	// Fix the string after he pass throw the clean_string function
	bool did_a_fix_happend = 0;
	do {
		LOG("In the loop");
		did_a_fix_happend = 0;
    	std::string newStr = "";
		// Fix `-` and no number buffer it
		for (size_t i = 0; i <str.length()-1; i++) {
			if(str[i]=='(' && str[i+1] == '-'){
				LOG("(- -> (0-");
				newStr+= "(0";
				did_a_fix_happend = 1;
			} else if((str[i]=='-' && str[i+1] == '+')||(str[i]=='+' && str[i+1] == '-')){
				LOG("+- -> -");
				did_a_fix_happend = 1;
				newStr+='-';
				i++;
			} else if((str[i]=='-' && str[i+1] == '(')){
				LOG("-( -> -1*(");
				did_a_fix_happend = 1;
				newStr+= "-1*(";
				i++;
			} else if((str[i]=='-' && str[i+1] == '-')||(str[i]=='+' && str[i+1] == '+')){
				LOG("-- -> + / ++ -> +");
				did_a_fix_happend = 1;
				newStr+= '+';
				i++;
			} else if(str[i]=='*' && str[i+1] == '-') {
				LOG("*- ->*(0-1)*");
				did_a_fix_happend = 1;
				newStr+="*(0-1)*";
				i++;
			} else if(str[i]=='/' && str[i+1] == '-' ) {
				LOG("/- -> *(0-1)/");
				did_a_fix_happend = 1;
				newStr+="*(0-1)/";
				i++;
			} else if(( str[i] >= '0' && str[i] <='9') && str[i+1] == '(' ){
				LOG("number( -> number*(");
				did_a_fix_happend = 1;
				newStr+= str[i];
				newStr+= '*';
            } else {
                newStr += str[i];
            }
		   LOG(newStr);
		}
		if (did_a_fix_happend) {
           newStr += str.back(); // Append the last character
           str = newStr; // Assign the cleaned string back to the original string.
        }
	}while (did_a_fix_happend);
	// If fix happened we way need to do anther one
}
