#ifndef DSA_MANIPULATOR_H
# define DSA_MANIPULATOR_H

#include <vector>
#include <unordered_set>
#include <cstdio>
#include <iostream>

namespace dsa{
    template <typename T>
    class ManVector
    {
        private:
            std::vector<T> g_vec;
            int size = -1;

        public:
            ManVector(std::vector<T> &vec);
            T sumVector();
            T sequentialSearch(T item);
            T loopBinarySearch(T item);
            T recursiveBinarySearch(T item, int low, int high);
            T maxSubArraySum();
            T maxAppearingElement();
            double avgVector();
            void swap(int a, int b);
            void selectionSort();
            void quickSort();
            void rightRotate(int steps);
            void leftRotate(int steps);
            void reverseArray(int start, int end);
            void printDuplicates1();
            void printDuplicates2();
            void maxStockProfit();
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
    template <typename T>
    T ManVector<T>::sequentialSearch(T item){
        // Time complexity O(n) Space complexity O(1)
        for(int i = 0; i < this->size; i++){
            if(item == this->g_vec[i]){
                return i;
            }
        }
        return -1;
    }
    template <typename T>
    T ManVector<T>::loopBinarySearch(T item){
        // Time complexity O(log(n)) Space complexity O(1)
        int low = 0;
        int high = this->size - 1;
        int mid = low + (high - low) / 2; //To avoid overflow
        while(low <= high){
            if(item == this->g_vec[mid]){
                return mid;
            }
            else if(item < this->g_vec[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
    template <typename T>
    T ManVector<T>::recursiveBinarySearch(T item, int low, int high){
        // Time complexity O(log(n)) Space complexity O(log(n))
        int mid = low + (high - low) / 2;
        if(low > high){
            return -1;
        }
        if(item == this->g_vec[mid]){
            return mid;
        }
        else if(item < this->g_vec){
            return recursiveBinarySearch(item, low, mid - 1);
        }
        else{
            return recursiveBinarySearch(item, mid + 1, high);
        }
    }
    template <typename T>
    void ManVector<T>::leftRotate(int steps){
        int n = this->size();
        reverseArray(0, steps - 1);
        reverseArray(steps, n - 1);
        reverseArray(0, n - 1);
    }
    template <typename T>
    void ManVector<T>::rightRotate(int steps){
        int n = this->size();
        reverseArray(n - steps, n - 1);
        reverseArray(0, steps - 1);
        reverseArray(0, n - 1);
    }
    template <typename T>
    void ManVector<T>::reverseArray(int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            T temp = this->g_vec[i];
            this->g_vec[i] = this->g_vec[j];
            this->g_vec[j] = temp;
        }
    }
    template <typename T>
    T ManVector<T>::maxSubArraySum(){
        int max_sum = 0, current_max_sum = 0;
        for(auto n:this->g_vec){
            current_max_sum = current_max_sum + n;
            if(current_max_sum < 0){
                current_max_sum = 0;
            }
            if(current_max_sum > max_sum){
                max_sum = current_max_sum;
            }
        }
        return max_sum;
    }
    template <typename T>
    void ManVector<T>::selectionSort(){
        int size = this->size;
        int i, j, min, temp;
        for (i = 0; i < size - 1; i++){
            min = i;
            for (j = i + 1; j < size; j++){
                if (this->g_vec[j] < this->g_vec[min]){
                    min = j;
                }
            }
            temp = this->g_vec[i];
            this->g_vec[i] = this->g_vec[min];
            this->g_vec[min] = temp;
        }        
    }
    template <typename T>
    void ManVector<T>::swap(int a, int b){
        int temp = this->g_vec[a];
        this->g_vec[a] = this->g_vec[b];
        this->g_vec[b] = temp;
    }
    template <typename T>
    void ManVector<T>::quickSort(){
        int lower = 0; upper = this->size - 1;
        if (upper <= lower){
            return;
        }
        int pivot = this->g_vec[lower];
        int start = lower;
        int end = upper;
        while (lower < upper){
            while (arr[lower] <= pivot && lower < upper){
                lower++;
            }
            while (arr[upper] > pivot && lower <= upper){
                upper--;
            }
            if (lower < upper){
                swap(arr, upper, lower);
            }
        }
        swap(this->g_vec, upper, start); // upper is the pivot positionquickSortUtil(arr, start, upper - 1); // pivot -1 is the upper for left sub array.
        quickSortUtil(this->g_vec, upper + 1, end); // pivot + 1 is the lower for right sub array.
    }
    template <typename T>
    void ManVector<T>::printDuplicates1(){
        // Time complexity O(n.log(n))
        sort(this->g_vec.begin(), this->g_vec.end());
        std::cout<<"Repeating elements are ";
        for(int i = 1; i < this->size; i++){
            if(this->g_vec[i] == this->g_vec[i - 1]){
                std::cout << this->g_vec[i] << " ";
            }
        }
    }
    template <typename T>
    void ManVector<T>::printDuplicates2(){
        // Time complexity O(n)
        std::unordered_set<T> hs;
        std::cout << " Repeating elements are ";
        for (int i = 0; i < this->size; i++){
            if (std::find(hs.begin(), hs.end(), this->g_vec[i]) != hs.end()){
                std::cout << this->g_vec[i] << " ";
            }
            else{
                hs.insert(this->g_vec[i]);
            }
        }
    }

    template <typename T>
    T ManVector<T>::maxAppearingElement(){
        //Time complexity O(n.Log(n))
        T curr = this->g_vec[0], max_appearance = this->g_vec[0];
        int curr_count = 0, max_appearance_count = 0;
        sort(this->g_vec.begin(), this->g_vec.end());
        for(int i = 1; i < this->size; i++){
            if(this->g_vec[i] == this->g_vecp[i - 1]){
                curr_count++;
            }
            else{
                curr = this->g_vec[i];
                curr_count = 1;
            }
            if(curr_count > max_appearance_count){
                max_appearance = curr;
                max_appearance_count = curr_count;
            }
        }
        return max_appearance;
    }

    template <typename T>
    void ManVector<T>::maxStockProfit(){
        // Time complexity O(n) if Brute-Force O(n^2)
        int buy = 0, sell = 0;
        int curMin = 0;
        T currProfit = 0;
        T maxProfit = 0;
        for (int i = 0; i < this->size; i++){
            if (this->g_vec[i] < this->g_vec[curMin]){
                curMin = i;
                currProfit = this->g_vec[i] - this->g_vec[curMin];
            }
            if (currProfit > maxProfit){
                buy = curMin;
                sell = i;
                maxProfit = currProfit;
            }
        }
        std::cout<<"Purchase day is- " << buy << " at price " << this->g_vec[buy]<<std::endl;
        std::cout<<"Sell day is- " << sell << " at price " << this-g_vec[sell]<<std::endl;
    }

    class GeneralProblems
    {
        public:
            int factorial(int n);
            int fibonacci(int n);
            int sumOfNumberDigits(int n); 
            void towerOfHanoi(int num, char src, char dst, char tmp);           
            
    };
    int GeneralProblems::factorial(int n){
        if(n <= 1){return 1;}
        else{return n*factorial(n - 1);}
    }
    int GeneralProblems::fibonacci(int n){
        if(n <= 1){return 1;}
        else{return fibonacci(n - 1) + fibonacci(n - 2);}
    }
    int GeneralProblems::sumOfNumberDigits(int n){
        int sum = 0, remainder = 0;
        while(n != 0){
            remainder = n % 10;
            sum = sum + remainder;
            n = n / 10;
        }
        return sum;
    }
    void GeneralProblems::towerOfHanoi(int num, char src, char dst, char tmp){
        if(num < 1){
            return;
        }
        towerOfHanoi(num - 1, src, tmp, dst);
        std::cout<<"Move "<<num<<" disk from peg "<<src<<" to peg "<<dst<<std::endl;
        towerOfHanoi(num - 1, tmp, dst, src);
    }  
}

#endif
