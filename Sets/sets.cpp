#include <iostream>
#include <vector>
using namespace std;

class Set {
    vector<int> v;
    int size;
    
public:
    Set() {
        size = 0;
    }
        
    bool empty() {
        if(size == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    void add(int d) {
        if (size == 0) {
            v.push_back(d);
            size++;
        } else {
            if(!contains(d)) {
                v.push_back(d);
                size++;
            }
        }
    }
    
    void remove(int d) {
        int i = 0;
        while(v[i] != d && i <= size) i++;
            
        if(v[i] == d) {
            v.erase(v.begin()+i);
        }
    }
    
    int getSize() {
        return size;
    }
    
    vector<int> getData() {
        return v;
    }
    
    bool contains(int d) {
        int i = 0;
        while(v[i] != d && i <= size) i++;
            
        if(v[i] == d) return true;
        else return false;
    }
    
    Set union_(Set set2) {
        Set result = Set();
        for(int i = 0; i < size; i++) {
            result.add(v[i]);
        }
        
        vector<int> v2 = set2.getData();
        for(int i = 0; i < set2.getSize(); i++) {
            result.add(v2[i]);
        }
        
        return result;
    }
    
    Set intersection(Set set2) {
        Set result = Set();
        vector<int> v2 = set2.getData();
        
        if(size <= set2.getSize()) {
            for(int i = 0; i < size; i++) {
                if(set2.contains(v[i])) {
                    result.add(v[i]);
                }
            }
        } else {
           for(int i = 0; i < set2.getSize(); i++) {
                if(contains(v2[i])) {
                    result.add(v2[i]);
                }
            } 
        }
        
        return result;
    }
    
    Set A_B(Set set2) {
        Set result = Set();
        
        for(int i = 0; i < size; i++) {
            if(!set2.contains(v[i])) {
                result.add(v[i]);
            }
        }
        
        return result;
    }
    
    void print() {
        for(int x: v) {
            cout << x << ", ";
        }
        cout << endl;
    }
};

int main() {
    Set set1 = Set();
    Set set2 = Set();
    
    set1.add(200);
    set1.add(130);
    set1.add(160);
    set1.print();
    
    set2.add(200);
    set2.add(150);
    set2.add(180);
    set2.add(160);
    set2.print();
    
   // Set set3 = set1.union_(set2);
   // Set set3 = set1.intersection(set2);
   // Set set3 = set1.A_B(set2);
    Set set3 = set2.A_B(set1);
    set3.print();

    return 0;
}