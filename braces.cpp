#include <iostream>
#include <vector>

#include "braces.h"
#include "math.h"

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

// Finding the index for the brace to solve
int start_brace(std::vector<double> &v){
	int index = -1;// By default we return that there are no braces in the calculation
	// We start at the end because if we find '(' we know it OK to use it with no fear of anther braces in it
	for (int i = v.size()-1;i >= 0; i--) {
		if (v[i] == OPERATION.at('(')) {
			index = i;
			break;
		}
	}
	return index;
}

// The start and the finish index
std::vector<int> start_and_finish_ind(std::vector<double> &v){
	// The indexes
	std::vector<int> indexes;
	// Place of brace
	int index = start_brace(v);
	if (index == -1) {
		// Empty vector tell there is no braces
		LOG("[]", "Braces range");
		return indexes;
	}
	indexes.push_back(index);
	int end = v.size() - 1;
	for(size_t i = index;i<v.size();i++){
		if (v[i] == OPERATION.at(')')) {
			end = i;
			break;
		}
	}
	indexes.push_back(end);
	LOG_V(indexes, "Braces range");
	return indexes;
}

