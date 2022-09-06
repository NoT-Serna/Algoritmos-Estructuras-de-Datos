#include <iostream>
using namespace std;
void selection_sort(int v[], int* vaux, int n){
    int min = 100000;
    for(int i=0; i < n; i++) {
        for(int j=0; j<n; j++){
            if(min > n) {
                min = j;
            } else if(v[j] < v[min]) {
                min = j;
            }
        }
        vaux[i] = v[min];
        v[min] = 100000;
        min = 100000;
    }

}

void double_select_sort(vector<int>& v) {
  int x_temp, i_min, i_max;
  int len = v.size();

  for (int i = 0; i < len/2; i++) {
    i_min = i;
    i_max = i;
    for (int j = i; j < len-i; j++) {
      if (v.at(j) < v.at(i_min)) i_min = j;
      if (v.at(j) > v.at(i_max)) i_max = j;
    }
    x_temp = v.at(i);
    v.at(i) = v.at(i_min);
    v.at(i_min) = x_temp;
    
    x_temp = v.at(len-i-1);
    v.at(len-i-1) = v.at(i_max);
    v.at(i_max) = x_temp;
  }
}

int main() {

    int vector[] = {2,3,5,3,6,8,9,12};
    int v_ordenado[10];
    selection_sort(vector, v_ordenado, 8);
    
    for(int i = 0; i < 8; i++) {
        cout << v_ordenado[i] << endl;
    }
    
    return 0;
}
