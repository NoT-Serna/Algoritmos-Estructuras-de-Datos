#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


//Binary search
//Problema 1
/*
double binary(int n, float x){
    int low  = 0;
    int high = n;
    while((high-low) > x){
      int mid = (low + high) /2;
        if((pow(mid,2) - n) < x){
          return mid;
        } else{
          if(pow(mid,2) > n){
            high = mid;
          }else{
            low = mid;
          }
          mid = (low+high)/2;
        }
    }
  }
*/
  void print(vector<int>&v){
    for(int i = 0; i<10; i++){
        cout<<v.at(i)<<" ";
    }
}


    
    
//Problema 2


void bubble_sort(vector<int>& v) {
    int temp, j;
    for (j = 0; j < v.size(); j++) {
        for (int i = 0; i < v.size() - 1; i++) {
            if (v.at(i) > v.at(i + 1)) {
                temp = v.at(i);
                v.at(i) = v.at(i + 1);
                v.at(i + 1) = temp; // Corrected assignment here
            }
        }
    }
}

void PairSum(vector<int>&v , int obj){
    vector<pair<int,int>> pairs;
    for(size_t i = 0; i < v.size(); i++){
        for(size_t j = i+1; j< v.size(); j++){
            if(v.at(i) + v.at(j) == obj){
                pairs.push_back(make_pair(v.at(i), v.at(j)));
            }
        }
    }
    for(const auto& pair: pairs){
        cout<< "(" << pair.first << ", "<< pair.second <<")"<< endl;
    }
}






int main() {
    
    
    vector<int> vec;
    int random = 10;
    for(int i = 0; i<10; i++){
        vec.push_back(rand()% random);
    }
    
    print(vec);
    
    cout<<endl;
    //Problema 2
    bubble_sort(vec);
    PairSum(vec,8);
    print(vec);
    
    
    
    
    /*
    cout<<binary(16,0.35);
    */
    return 0;
}
