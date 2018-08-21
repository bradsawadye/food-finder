//
//  Guide.h
//  Food_finder
//
//  Created by The brad on 2017/05/18.
//  Copyright © 2017 The Brad. All rights reserved.
//

#ifndef Guide_h
#define Guide_h
#include "Restaurant.h"
#include <iomanip>
#include <algorithm>

using namespace std;

class Guide {

private:
    static void formated_price(const double & price) {
        cout<<"$"<<setw(10)<<setprecision(4)<<price;
    }

    static void liststyled(const string & name, const string & cuisine, const double & price) {
        cout<<setfill(' ')<<setw(30)<<left<<name;
        //size_t dr = name.rfind(" ");
        //cout<<name.size()<<" ";
        cout<<setw(20)<<left<<cuisine;
        formated_price(price);
        printf("\n");
    }

public:
    static void restaurant_list(const char * file) {
        list<Restaurant> list = Restaurant::savedrestaurants(file);
        cout<<setfill(' ')<<setw(30)<<left<<"Restaurant Name";
        cout<<setw(20)<<left<<"Restaurant Cuisine";
        cout<<setw(11)<<left<<"Price"<<endl;
        cout<<setfill('_')<<setw(58)<<"_"<<"\n"<<endl;
        for (auto restaurant: list) {
            liststyled(restaurant.getname(), restaurant.getcuisine(), restaurant.getprice());
        }
        cout<<setfill('_')<<setw(58)<<"_"<<endl;
        list = {};
    }

     static void add_restaurant(const char * file) {

        string nam;
        string name;
        string cuisine;
        string price;
        //cout<<" "<<endl;
        //getline(cin, nam);

        cout<<"Enter Restaurant name: ";
       getline (cin, nam);
         //cout<<nam<<endl;
         name = nam;
        cout<<"Enter cuisine: ";
        getline (cin, nam);
         cuisine = nam;
         //cout<<nam<<endl;

         cout<<"Enter Price: ";
         getline(cin, nam);
         price = nam;
         //cout<<nam<<endl;


        string restaurant = name + "," + cuisine + "," + price + "\n";
         FILE * fs = fopen(file, "a");
         fputs(restaurant.c_str(), fs);
        fclose(fs);
         cout<< "Restaurant added to list"<<endl;
    }

    static void find_res(const string & name_or_cuisine,const char * file) {
       list<Restaurant> list = Restaurant::savedrestaurants(file);

        for (auto restaurant: list) {
            string _name = restaurant.getname();
            string _cuisine = restaurant.getcuisine();
            transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
            transform(_cuisine.begin(), _cuisine.end(), _cuisine.begin(), ::tolower);

            if (_name == name_or_cuisine) {
                cout<<"\nlist by restaurant name:\n"<<endl;
                liststyled(restaurant.getname(), restaurant.getcuisine(), restaurant.getprice());
            } else if(_cuisine == name_or_cuisine) {
                cout<<"\nList by cuisine:\n"<<endl;
                liststyled(restaurant.getname(), restaurant.getcuisine(), restaurant.getprice());
            }
        }
    }

    static void introduction() {
        cout<<setfill('*')<<setw(44)<<" WELCOME TO THE RESTAURANT APP ";
        cout<<setw(13)<<"*"<<endl;
        cout<<"\n\n"<<endl;
        cout<<"Actions that can be done are 'list' :- to list the restaurants \n'add' :- to add a restaurant\n'exit' :- to exit out the application"<<endl;

    }
    static void outro() {
        cout<<setfill('*')<<setw(34)<<right<<"BON APETIT"<<setw(23)<<"*"<<endl;
    }

public:
        void launch(const char * file) {
            string funct[2];
            string funcc = " ";
            while (funcc != "exit") {
                string func;
                getline(cin, func);
                transform(func.begin(), func.end(), func.begin(), ::tolower);
                    funcc = func;
                if(func.find(" ")){
                    funct[0] = func.substr(0,func.find(" "));
                    funct[1] = func.substr(func.find(" ") + 1, func.size());
                } else{ funct[0] = func;
                    funct[1] ="";
                }

                int gh = 0;
                if (funct[0] == "list"){
                    gh = 1;
                }else if (funct[0] == "find"){
                    gh = 3;
                }
                else if (funct[0] == "add"){
                    gh = 2;
                }else {gh = 0;}

                    if (funcc != "exit") {


                switch (gh) {
                    case 1:
                        restaurant_list(file);
                        break;

                    case 2:
                        add_restaurant(file);
                        break;
                    case 3:
                        find_res(funct[1], file);
                        break;

                    default:
                        puts("Enter operation to be done. Either List or add\nTo exit enter exit");
                        break;
                }
            }
        }
        }
};



#endif /* Guide_h */
