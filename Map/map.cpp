#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Point {
    int x;
    int y;
    
public:
    Point(int px, int py) {
        x = px;
        y = py;
    }
    
    bool operator ==(const Point p) const {
        return this->x == p.x && this->y == p.y;
    }
    
    bool operator ==(const int d[]) const {
        return this->x == d[0] && this->y == d[1];
    }
};



template<typename K, typename V>
class Map {
    int size;
    vector<pair<K, V>> v;
    
public:
    Map() {
        size = 0;
    }    
    
    void add(K key, V value) {
        pair<K, V> p (key, value);
        v.push_back(p);
        size++;
    }
    
    V get(K key) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first == key) {
                return v[i].second;
            }
        }
        throw invalid_argument("No hay un elemento con esa clave en el mapa");
    }
    
    V get(int d[]) {
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first == d) {
                return v[i].second;
            }
        }
        throw invalid_argument("No hay un elemento con esa clave en el mapa");
    }

};

int main() {
    Map<Point, string> m;
    
    Point p1 = Point(12, 53);
    Point p2 = Point(21, 14);
    Point p3 = Point(34, 28);
    Point p4 = Point(23, 12);
    
    m.add(p1, "Verde");
    m.add(p2, "El más ");
    m.add(p3, "Grande");
    m.add(p4, ":D");
    
    cout << m.get({12, 53}) << endl;
    
    return 0;

}
