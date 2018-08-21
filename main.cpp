//
//  main.cpp
//  Food_finder

//  Created by The brad on 2017/05/16.
//  Copyright © 2017 The Brad. All rights reserved.
//

#include <iostream>
#include "Restaurant.h"
#include "Guide.h"
#include <list>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    //char srit;
    //cin>>srit;
    const char * fn = "test1.txt";
    /*list<Restaurant> ky  = Restaurant::savedrestaurants(fn);
    cout<< ky.size()<< endl;
    //char j[] = "ree,trr,ree";
    //char * pc = strtok(j, ",");
    //cout<< pc[1];
    for (auto h: ky){
        printf("%0.2f\n", h.getprice());
    }*/
    //Guide::restaurant_list(fn);
    //Guide::add_restaurant(fn);
    
    Guide guide = Guide();
    Guide::introduction();
    guide.launch(fn);
    Guide::outro();
    
    //const char * dr = "thr's ";
    
    //string drr = dr;
    //size_t com = dr.find(",");
    //*cout<<drr.size()<<endl;
    /*
    FILE * rs = fopen("test1.txt", "w");
    fputs("Papa's Place,Mexican,51.26\n", rs);
    fputs("Drake's,Chinese,61.29\n", rs);
    fputs("Papa,Indian,34.32\n", rs);
    fclose(rs);
    
    FILE * cf = fopen("test1.txt", "r");
    const int buffersize = 128;
    char buf[buffersize];
    //Read file
    while (fgets(buf, buffersize, cf)) {
        string stri(buf);
        cout<<stri.size()<<endl;
    }
    fclose(cf);
    
    //Restaurant Restaurant1 = Restaurant("brad's","grr", 23.00);
    //cout<< Restaurant1.getname().size()<<endl;
    */
    
    return 0;
}
