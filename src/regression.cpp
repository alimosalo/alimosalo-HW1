#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <sstream>
#include "regression.h"
#include "gtest/gtest.h"
using Data = std::vector <std::vector<double>>;
namespace regression{
Data read_database(std::string filepath)
{
    Data sub_fish;
    std::ifstream text(filepath);
    std::string variable{};
    std::stringstream sub_var{};
    std::string getter{};
    std::stringstream substitude;
    size_t i{0};
    while(getline(text,variable))
    {
        sub_fish.push_back(std::vector <double>());
        sub_fish[i].push_back(1);
        sub_var<<variable;
        while(getline(sub_var,getter,','))
        {
            double saver{};
            substitude<<getter ; 
            substitude >> saver ;
            sub_fish[i].push_back(saver);
            std::stringstream().swap(substitude);            

        }
        std::stringstream().swap(sub_var);
        i++;
    }    
    return sub_fish ; 

}
    double hypothesis( std::vector <double>theta, std::vector<double>x)
    {

        double a{};
        size_t i{};
        for(auto sub:x)
        {
            a+=sub*theta[i];
            i++;
        }
        return a ;
    }
    double cost_function( Data dataset, std::vector<double>theta)
    
    {   
        double cost{};
        double carrier{};
        for(size_t i{};i<dataset.size() ;++i)
        {
            carrier =(regression::hypothesis(theta,dataset[i])-dataset[i][4]);
            
            cost += std::pow(carrier,2);
            
        }
    
        return (cost)*(0.5) ;
    }
    std::vector <double> update( Data dataset,  std::vector<double> theta,double lr)
    {
        
        double carrier{};
        
        for(size_t i{};i<dataset.size();i++)
        {
            carrier =(regression::hypothesis(theta,dataset[i])-dataset[i][4]);
        }   
        
        for(size_t i{};i<dataset.size();++i)
        {
        for(size_t j{};j<4;j++)
        {
            theta[j] =theta[j] -lr*(carrier)*dataset[i][j];
            
            
        }
    
        }
        return theta ; 
    }
    std::vector <double> linear_regression( Data dataset ,std::vector<double> init_theta,double lr)
    {
        double cost1{regression::cost_function(dataset,init_theta)};
        double cost2{};
        for(size_t i{};i<1000;++i)
        {
        
        init_theta = regression::update(dataset,init_theta,lr);
        cost2=regression::cost_function(dataset,init_theta);
         std::cout<<i+1<<"->"<<"cost:  "<<std::setprecision(5)<<cost2;
         std::cout<<"   -reduced cost: "<<std::setprecision(5)<<cost1-cost2<<std::endl;
         cost1=cost2;
        }
        return init_theta;
    }
}