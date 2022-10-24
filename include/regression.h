#ifndef REGRESSION_H
#define REGRESSION_H
using Data = std::vector <std::vector <double>> ;
namespace regression {
    Data read_database(std::string );
    double hypothesis( std::vector <double>, std::vector<double>);
    double cost_function( Data ,std::vector<double>);
    std::vector <double> update( Data dataset,  std::vector<double> theta,double lr);
    std::vector <double> linear_regression( Data dataset ,std::vector<double> init_theta,double lr);
}

#endif