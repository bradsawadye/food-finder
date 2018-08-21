//
//  Restaurant.h
//  Food_finder
//
//  Created by The brad on 2017/05/16.
//  Copyright © 2017 The Brad. All rights reserved.
//

#ifndef Restaurant_h
#define Restaurant_h
#include <string>
#include <list>
#include <cstdio>
#include <sstream>

using namespace std;


class Restaurant {

    string _name;
    string _cuisine;
    double _price;
    Restaurant(){}
    
public:
    Restaurant(const string & name, const string & cuisine, const double & price) : _name(name), _cuisine(cuisine), _price(price) {};
    
    //getter methods
    
    const string & getname()    const{ return _name;}
    const string & getcuisine() const{ return _cuisine;}
    const double & getprice()   const{ return _price;}
    
    //setter methods
    void setname(const string & name)       { _name = name;}
    void setcuisine(const string & cuisine) { _cuisine = cuisine;}
    void setprice(const double & price)     { _price = price;}
    
    //class methods
    static list<Restaurant> savedrestaurants ( const char * file) {
        
         list<Restaurant> list;
        const int buffersize = 128;
        char buf[buffersize];
        //Read file 
        FILE * fs = fopen(file,"r");
        while (fgets(buf, buffersize, fs)) {
            string stri(buf);
            //cout<<stri.size()<<endl;
            double price;
            size_t commapoint = stri.rfind(",");
            string name_cuisine = stri.substr(0,commapoint);
        
            size_t ncommapoint = stri.find(",");
            string name = name_cuisine.substr(0, ncommapoint);
            //cout<<name_cuisine.size()<<endl;
            //cout<<name.size()<<endl;
            string cuisine = name_cuisine.substr(ncommapoint+ 1, name_cuisine.size()-1);
            
            string sprice = stri.substr(1 + commapoint, stri.size() - 1);
            stringstream(sprice) >> price;
            list.push_back(Restaurant(name, cuisine, price));
        }
        
        fclose(fs);
        return list;
    }
    

    
    
private:
    bool does_file_exist(const char * file) {
        if (file) {}
            return false;
        
    }

};

#endif /* Restaurant_h */
