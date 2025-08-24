// this so very long line contains exactly 100 absolutly different characters in a one little rowww
# include <stdexcept>
# include <iostream>
# include <vector>
# include "Matrix.h"
using namespace std;


template<typename T>
void print(Matrix<T> matrix) {
    vector<int> r = matrix.rank();
    int h = r[0], w = r[1];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (*matrix[i])[j] << " ";
        }
        cout << endl;
    }
}


template<typename T>
void print(vector<T> vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}
