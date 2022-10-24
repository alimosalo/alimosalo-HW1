#ifndef REGRESSION_H
#define REGRESSION_H
using Data = std::vector <std::vector <double>> ;
namespace regression {
    Data read_database(std::string filepath);
    double hypothesis( std::vector <double>theta, std::vector<double>x);
    double cost_function(Data dataset,std::vector<double>theta);
    std::vector <double> update( Data dataset,  std::vector<double> theta,double lr);
}

#endif