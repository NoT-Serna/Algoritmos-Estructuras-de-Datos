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

//Problema 3

void printMovies(vector<pair<string,int>>& m){
     for (const auto& movie : m) {
        cout << movie.first << " (" << movie.second << ")" << endl;
    }
     cout<<endl;
}

void OrderMovie(vector<pair<string,int>>& m){
    int temp, j;
    for(j=0; j<m.size(); j++){
      for(int i = 0; i<m.size()-1; i++){
        if(m[i].second > m[i+1].second){
          swap(m[i],m[i+1]);
        }
      }
    }
}

int SearchMovie(vector<pair<string,int>>& m, int size, int section[], int paritions, int search){
    int k = search/1000;
    int i = section[k];
    int j = section[k+1];
    while(i<j && m[i].second != search){
        i++;
    }
    if(i<j){
      cout << "Movie Found: " << m[i].first << " (" << m[i].second << ")" << endl;
      return i;

    }else{
      cout<<"Movie Not Found";
      return -1;
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

    vector<pair<string,int>> movies;
        // Add movies to the vector using push_back
    movies.push_back(make_pair("The Shawshank Redemption", 9));
    movies.push_back(make_pair("The Godfather", 10));
    movies.push_back(make_pair("The Dark Knight", 10));
    movies.push_back(make_pair("Pulp Fiction", 8));
    movies.push_back(make_pair("The Flash", 6));
    movies.push_back(make_pair("Star Wars Ep:8", 5));
    movies.push_back(make_pair("American Sniper", 9));
    movies.push_back(make_pair("The Conjuring", 5));
    movies.push_back(make_pair("The Lord of the Rings: The Return of the King", 8));

    // Display the movies
    cout << "----Movies in the vector:-----" << endl;
    printMovies(movies);
    OrderMovie(movies);
    cout <<"----Movies Rating----" <<endl;
    printMovies(movies);

    
    int section[] = {0,3,5};
    // Movie Index Search
    int index = SearchMovie(movies,8,section,3, 6);

    if(index !=-1){

    }else{

    }




    
    cout<<endl;
    //Problema 2
    /*
    bubble_sort(vec);
    PairSum(vec,8);
    print(vec);
    */
    
    
    
    
    /*
    cout<<binary(16,0.35);
    */
    return 0;
}
