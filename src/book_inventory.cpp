#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "gtest/gtest.h"
#include <iomanip>
#include "book_inventory.h"
// struct Book
// {
//     std::string title;
//     std::string author;
//     float cost ;
//     std::string isbn;
//     std::string language_code ;
//     int num_pages;
//     std::string publisher ;
//     int count ;
// };
// using Books=std::vector<Book>;


namespace book{
    Books read_database(std::string filepath)
    {
        long unsigned int counter{0};

        Books book_recorder;

        Book helper;

        std::ifstream iff{filepath};

        if(!iff)
            std::cout<<"nothing is found here"<<std::endl;
        else
        {
            std::stringstream s1;

            std::stringstream s2;

            std::stringstream s3;

            std::string entry{}; 

            std::vector<std::string> support;

            std::stringstream instead_file ; 

            while(getline(iff,entry))
                support.push_back(entry);
            long unsigned int i{0};
            while(i<support.size())
            {
                instead_file<<support[i];
                std::string rm {};
                getline(instead_file,rm,',');   
                getline(instead_file,helper.title,',');
                getline(instead_file,helper.author,',');
                std::string cost;
                getline(instead_file,cost,','); 
                s1<<cost ;
                s1>>helper.cost;
                std::stringstream().swap(s1);
                getline(instead_file,helper.isbn,',');
                getline(instead_file,helper.language_code,',');
                std::string num_pages{};
                getline(instead_file,num_pages,',') ;
                s2<<num_pages;
                s2>>helper.num_pages;
                std::stringstream().swap(s2);
                getline(instead_file,helper.publisher,','); 
                std::string count{};
                getline(instead_file,count,','); 
                s3<<count ;
                s3>>helper.count;
                std::stringstream().swap(s3);
                book_recorder.push_back(helper);
                std::stringstream().swap(instead_file);
                i++ ;
                
            }   
        
        }
        iff.close();
        return book_recorder;
    }
    std::string search(Books inventory,std::string title)
    {
        size_t i{};
        bool t = false;
        std::string isbn{};
        for(auto& x:inventory)
        {   
            if(x.title==title)
                return x.isbn ; 
        }
        
        return "none";
    }
    bool order(Books inventory, Books& shopinglist, std::string isbn)
    {
        
        
        if(isbn=="none"){return false;}

        
        int counter{0};
        int counter2{0};
        for(auto x:inventory)
            if(x.isbn == isbn)
                shopinglist.push_back(x) ;
                shopinglist[counter].count --;
                std::abort;
            counter++;
        
        
        return true; 
    
    }
    double get_recipt(const Books& shopinglist){
        std::cout<<std::string(54,'*')<<std::endl;
        
        std::cout<<'|'<<std::setw(6)<<"title"<<std::setw(15)<<'|';        
        std::cout<<std::setw(6)<<"isbn"<<std::setw(10)<<'|'; 
        std::cout<<std::setw(6)<<"cost"<<std::setw(9)<<'|'<<std::endl;
        for(auto x:shopinglist) 
        {   int a{static_cast <int>(x.title.size())};

            int b{std::abs(21-a)};

            if(x.title.size()>17)
                std::cout<<'|'<<x.title.substr(0,17)<<"..."<<'|'; 
            else
            {
                std::cout<<'|'<<x.title<<std::setw(b)<<'|';
            }
            std::cout<<std::setw(6)<<x.isbn<<std::setw(7)<<'|'; 
            std::cout<<std::setw(6)<<x.cost<<'$'<<std::setw(8)<<'|'<<std::endl; 
        }
        std::cout<<std::string(54,'*')<<std::endl;
        return 0 ; 
        

    }


}




    

