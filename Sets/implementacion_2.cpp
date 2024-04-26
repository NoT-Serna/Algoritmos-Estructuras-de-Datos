#include <iostream>
#include <set>
using namespace std;

// Problema 3 Función para encontrar dos números que sumen un número dado
pair<int, int> PairSum(const set<int>& A, int target_sum) {
    set<int> seen;

    for (int num : A) {
        int complement = target_sum - num;
        if (seen.find(complement) != seen.end()) {
            return make_pair(num, complement);
        }
        seen.insert(num);
    }

    // Si no se encuentra ninguna pareja
    return make_pair(-1, -1);
}

int main() {

    //Problema 3
    int arr[] = {2, 7, 11, 15};
    set<int> set_1(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int target_sum = 9; // Número dado

    pair<int, int> result = PairSum(set_1, target_sum);
    if (result.first != -1 && result.second != -1) {
        cout << "Los números que suman " << target_sum << " son: " << result.first << " y " << result.second << endl;
    } else {
        cout << "No hay solución para la suma " << target_sum << endl;
    }

    //Problema 4



    return 0;
}
