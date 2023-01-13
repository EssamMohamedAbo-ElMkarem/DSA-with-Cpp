#ifndef DSA_MANIPULATOR_H
# define DSA_MANIPULATOR_H

#include <vector>
#include <cstdio>
#include <iostream>

namespace dsa{
    template <typename T>
    class ManVector
    {
        private:
            std::vector<T> g_vec;
            int size = 0;

        public:
            ManVector(std::vector<T> &vec);
            T sumVector();
            double avgVector();
            void printVector();
            
    };
    template <typename T>
    ManVector<T>::ManVector(std::vector<T> &vec){
        this->g_vec = vec;
        this->size = vec.size();
    }

    template <typename T>
    void ManVector<T>::printVector(){
        for(int i = 0; i < this->size; i++){
            std::cout << this->g_vec[i] << std::endl;
        }
    }
    template <typename T>
    T ManVector<T>::sumVector(){
        T sum = 0;
        for(int i = 0; i < this->size; i++){
            sum = sum + this->g_vec[i];
        }
        return sum;
    }
    template <typename T>
    double ManVector<T>::avgVector(){
        T sum = 0;
        for(int i = 0; i < this->size; i++){
            sum = sum + this->g_vec[i];
        }
        return (double)sum/(double)this->size;
    }
}

#endif
