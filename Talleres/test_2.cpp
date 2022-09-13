#include <iostream>
#include <vector>
#include <string>
using namespace std;

void select_sort(int v[], int len) {
  int x_temp, i_min;

  for (int i = 0; i < len; ++i) {
    i_min = i;
    for (int j = i; j < len; ++j) {
      if (v[j] < v[i_min]) i_min = j;
    }
    x_temp = v[i];
    v[i] = v[i_min];
    v[i_min] = x_temp;
  }
}

int main(){
    vector<string> vector;
    string words[] = {"abc","ab","xy","acbd","b"};
    vector.assign(words,words+5);
    
    int len[vector.size()];
    
    for(int i = 0;i<vector.size();i++){
            len[i] = vector.at(i).size();
    }
    select_sort(len,vector.size());

    for(int j = 0; j<vector.size();j++){
        if(vector.at(j).size()==len[0] || vector.at(j).size()==len[1]){
            cout<<vector.at(j)<<endl;
        }
    }
}
