#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "regression.h"
#include "book_inventory.h"
#include "gtest/gtest.h"



int main(void)
{
 Books shoppinglist{};
Books a=book::read_database("inventory.txt");
std::string b=book::search(a,"Harry Potter and the Half-Blood Prince");
bool t=book::order(a,shoppinglist,b);
book::get_recipt(shoppinglist);


int h {1234};
std::cout<<std::size(h)<<std::endl;
}