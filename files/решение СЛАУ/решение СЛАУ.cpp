// this so very long line contains exactly 100 absolutly different characters in a one little rowww
# include <stdexcept>
# include <iostream>
# include <vector>
# include "Funktions.h"
# include "Matrix.h"
using namespace std;


int main()
{
    /*
    Matrix coeffs = {
        {2, -2, 3, 3},
        {3, 1, -2, -1},
        {2, 1, 3, -1},
        {-2, -1, -2, 1}
    };
    vector<int> values = { -8, 2, -7, 5 };

    calculate(coeffs, values);
    */
    /*
    Matrix m = { 
        {1, 2}, 
        {3, 4}//, 
        //{5, 6} 
    };
    Matrix n = { 
        {1, 2},//, 3}, 
        {3, 4}//, 1} 
    };
    vector<int> v = { 1, 2 };
    print(m * n);
    */

    Matrix<int> m = { 
        {1, 2, 2, 1}, 
        {4, 1, 1, 4},
        {2, 1, 2, 2},
        {1, 1, 1, 2}
    };

    Matrix<double> invers = m.inverse();
    print(invers);
}