/*
* -------------------------------------------------------
* | Author: Essam Farouq                                |
* | Start Date: 11/1/2023                               |
* | End Date: NOT_DETERMINED_YET                        |
* -------------------------------------------------------
* 
* -------------------------------------------------------
* | Purpose: This project is intended to be used to     |
* | implement most common data structures and algorithms|
* | in a following SOLID principle, clean and efficient | 
* | code using C++ programming language.                |
* -------------------------------------------------------
*/

// cd "/home/xmagneto/Desktop/DSA in C++/" && g++ main.cpp mainlogic.cpp -o main && xterm -hold ./maim

// Problem cout not printing

#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include "mainlogic.hpp"

using namespace std;
int main(void){

    cout<<"Welcome to DSA PARADISE IN C++"<<endl;
    cout<<"choose the data structure you want to operate on"<<endl;
    cout<<"1. Vectors(dynamic sized arrays)"<<endl;

    unsigned short int choice; 
    cin>>choice;
   switch(choice){
        case 1:{
            inits::ArrayMainLogic<int> array_initializer;
            array_initializer.arrayInit();
            break;
        }
        case 99:{
            cout<<"Exiting!!"<<endl;
            exit(0);
            break;
        }
        case 747:{
            cout<<"Love wins!"<<endl;
            exit(0);
            break;
        }
        default:
            cout<<"Please, Enter a valid value.\n\n"<<endl;
            break;
        }
    return 0;
}