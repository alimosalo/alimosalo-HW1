#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "regression.h"
#include "book_inventory.h"




int main(void)
{

Books t{book::read_database("inventory.txt")};
Books neww{};
std::cout<<t[20].title<<std::endl;
std::string a{book::search(t,"Hatchet Jobs: Writings on Contemporary Fiction")};
std::cout<<a<<std::endl;
std::cout<<t[20].count<<std::endl;

book::order(t,neww,a);
std::cout<<t[20].count<<std::endl;
std::cout<<neww[0].count<<std::endl;

}