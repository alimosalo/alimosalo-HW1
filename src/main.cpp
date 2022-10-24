#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "regression.h"



int main(void)
{
    Data a{regression::read_database("fish.txt")};
    std::vector <double> theta{1,2,3,4};
    regression::cost_function(a,theta);
} 
