#include <iostream>
#include <array>
#include <string>
#include <vector>
#include "regression.h"
#include "gtest/gtest.h"



int main(void)
{
   // Data a {regression::read_database("fish.txt")};
    // std::vector <double> theta{0,0,0,0};
    //     for(size_t i{};i<10;i++)
    //     {
    //      std::cout<<theta[1]<<std::endl;
    //      theta =regression::update(a,theta,1e-7);
    //      std::cout<<theta[0]<<std::endl;

    
    //     }
        





    Data a {regression::read_database("fish.txt")};
    std::vector<double> b{0,0,0,0};
    std::vector <double>all=regression::linear_regression(a,b,1e-7);
     std::cout<<all[0]<<std::endl;
    

} 
