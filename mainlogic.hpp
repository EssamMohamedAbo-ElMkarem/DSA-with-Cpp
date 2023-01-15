#ifndef MAINLOGIC_H
# define MAINLOGIC_H

#include <vector>
#include <iostream>
#include "mainlogic.hpp"
#include "dsa_manipulator.hpp"

using namespace std;
using namespace dsa;

namespace inits{
    template <typename T>
    class ArrayMainLogic
    {
        private:
            ManVector<T> *g_vec;

        public:
            ArrayMainLogic(){}
            void arrayInit();
            void arrayOperate();            
    };

    template <typename T>
    void ArrayMainLogic<T>::arrayInit(){
        cout<<"Enter the array size"<<endl;
        int arr_size;
        cin>>arr_size;
        cout<<"Enter the array elements"<<endl;
        vector<T> elements;
        while(arr_size != 0){
            T element;
            cin>>element;
            elements.push_back(element);
            arr_size--;
        }
        ManVector<T> vec(elements);
        this->g_vec = &vec;
        this->arrayOperate();
    }

    template <typename T>
    void ArrayMainLogic<T>::arrayOperate(){

        cout<<"Choose operation:\n1- Remove then Create new Array\n2- Print Array\n3- Calculate Sum\n4- Calculate Average\n99-Exit!"<<endl;
        unsigned short int inchoice; 
        cin>>inchoice;
        switch (inchoice) {
            case 1:
                cout<<"\n\n"<<endl;
                this->arrayInit();
                break;

            case 2:
                g_vec->printVector();
                this->arrayOperate();
                break;
            
            case 3:
                cout<<"Array Sum is:"<<g_vec->sumVector()<<endl;
                this->arrayOperate();
                break;
            
            case 4:
                cout<<"Array average is:"<<g_vec->avgVector()<<endl;
                this->arrayOperate();
                break;

            case 99:
                cout<<"Exiting!!"<<endl;
                exit(0);
                break;
            
            default:
                cout<<"Please, Enter a valid value.\n\n"<<endl;
                this->arrayOperate();
                break;
        }
    }
    class GeneralProblemsMainLogic
    {
        public:
            int pass;           
    };
}

#endif