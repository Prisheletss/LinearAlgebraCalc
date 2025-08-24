// this so very long line contains exactly 100 absolutly different characters in a one little rowww


# ifndef MATRIX_H
# define MATRIX_H


# include <stdexcept>
# include <iostream>
# include <vector>
using namespace std;



template<typename T>
class Matrix {
public:
    Matrix() {}
    Matrix(initializer_list<vector<T>> input) : matrix(input) {}
    Matrix(Matrix* input) {
        Matrix other = *input;
        int len = other.rank()[0];
        for (int i = 0; i < len; i++) { matrix.push_back(other.get_row(i)); }
    }
    Matrix(int height, int width) {
        vector<T> row(width);
        for (int i = 0; i < height; i++) { matrix.push_back(row); }
    }

    void add_row(vector<T> row) {
        if (matrix.size() == 0) { matrix.push_back(row); }
        else if (row.size() != matrix[0].size()) { throw runtime_error("incorrect row size"); }
        else { matrix.push_back(row); }
    }


    void add_column(vector<T> column) {
        int len = matrix.size();

        if (len == 0) {
            len = column.size();
            for (int i = 0; i < len; i++) {
                matrix.push_back({});
            }
        }

        else if (column.size() != len) {
            throw runtime_error("incorrect column size");
        }

        for (int i = 0; i < len; i++) {
            matrix[i].push_back(column[i]);
        }
    }


    void remove_row(int index) {
        index = index_converter(index, 1);
        auto first = matrix.cbegin();
        matrix.erase(first + index);
    }


    void remove_column(int index) {
        index = index_converter(index, 1);
        for (auto& row : matrix) {
            auto first = row.cbegin();
            row.erase(first + index);
        }
    }


    vector<int> rank() {
        vector<int> ans;
        ans.push_back(matrix.size());
        ans.push_back(matrix[0].size());
        return ans;
    }


    vector<T> get_row(int index) {
        index = index_converter(index, 0);
        return matrix[index];
    }


    vector<T> get_column(int index) {
        index = index_converter(index, 1);
        vector<T> ans; int len = matrix.size();
        for (int i = 0; i < len; i++) { ans.push_back(matrix[i][index]); }
        return ans;
    }


    vector<T>* operator [](int index) {
        index = index_converter(index, 0);
        return &matrix[index];
    }


    vector<T> operator *(vector<T> other) {
        vector<int> r = rank();
        int len = other.size();
        if (r[1] != len) { throw runtime_error("incorrect sizes"); }

        vector<T> ans; T num;
        for (int i = 0; i < r[0]; i++) {
            num = 0;
            for (int j = 0; j < len; j++) {
                num += matrix[i][j] * other[j];
            }
            ans.push_back(num);
        }

        return ans;
    }


    int det() {
        vector<int> r = rank(), column;
        int h = r[0], w = r[1];
        if (h != w) { return 0; }
        else if (h == 1) { return matrix[0][0]; }
        else if (h == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }

        Matrix<T> minored;
        T ans = 0, t = -1;

        for (int i = 0; i < w; i++) {
            minored = minor(0, i);
            if (matrix[0][i] != 0) {
                ans += matrix[0][i] * minored.det() * t;
            }
            t *= -1;
        }

        return ans;
    }


    Matrix<T> minor(int y, int x) {
        Matrix<T> minored;

        for (int i = 0; i < rank()[0]; i++) {
            if (i != y) { minored.add_row(matrix[i]); }
        }

        minored.remove_column(x);
        return minored;
    }

    
    Matrix<double> inverse() {
        vector<int> r = rank();
        if (r[0] != r[1]) { throw runtime_error("matrix must be square"); }

        int len = r[0];
        Matrix<T> diagonal(len*len, len*len);
        vector<int> result;
        vector<T>* row;
        for (int i = 0; i < len*len; i++) {
            row = diagonal[i];
            for (int j = 0; j < len; j++) {
                (*row)[(i % len) + j * len] = matrix[i / len][j];
            }
            
            if ((i % (len + 1)) == 0) { result.push_back(1); }
            else { result.push_back(0); }
        }

        vector<double> values = calculate(diagonal, result);
        Matrix<double> ans(len, len);
        vector<double>* row_2;
        for (int i = 0; i < len * len; i++) {
            row_2 = ans[i / len];
            (*row_2)[i % len] = values[i];
        }

        return ans;
    }


    Matrix<T> operator +(Matrix<T> other) {
        vector<int> r1 = rank(), r2 = other.rank();
        if ((r1[0] != r2[0]) || (r1[1] != r2[1])) { 
            throw runtime_error("different-sized matrixes"); 
        }

        vector<T> row;
        Matrix<T> ans;
        for (int i = 0; i < r1[0]; i++) {
            row = *other[i];
            for (int j = 0; j < r1[1]; j++) {
                row[j] += matrix[i][j];
            }
            ans.add_row(row);
        }

        return ans;
    }


    Matrix<T> operator *(T other) {
        vector<int> len = rank(), row;
        Matrix<T> ans;

        for (int i = 0; i < len[0]; i++) {
            row = matrix[i];
            for (int j = 0; j < len[1]; j++) {
                row[j] *= other;
            }
            ans.add_row(row);
        }

        return ans;
    }


    Matrix<T> operator *(Matrix<T> other) {
        vector<int> r1 = rank(), r2 = other.rank();
        if (r1[1] != r2[0]) { throw runtime_error("different-sized matrixes"); }

        vector<T> row, column;
        Matrix<T> t = this, ans;
        for (int i = 0; i < r2[1]; i++) {
            column = other.get_column(i);
            row = t * column;
            ans.add_column(row);
        }

        return ans;
    }



private:
    vector<vector<T>> matrix;

    void print() {
        for (auto row : matrix) {
            for (T num : row) { cout << num << " "; }
            cout << endl;
        }
    }

    int index_converter(int index, int type) {
        int len = rank()[type];

        if ((index <= -len) || (index >= len)) { throw runtime_error("index error"); }
        else if (index < 0) { index += len; }

        return index;
    }
};



template<typename T>
vector<double> calculate(Matrix<T> coeffs, vector<T> values) {
    int det = coeffs.det(), d; double num;
    int len = coeffs.rank()[0];
    vector<double> ans;
    Matrix<T> midway;

    for (int i = 0; i < len; i++) {
        midway = {};
        for (int j = 0; j < len; j++) {
            if (j != i) { midway.add_column(coeffs.get_column(j)); }
            else { midway.add_column(values); }
        }
        d = midway.det();
        num = static_cast<float>(d) / det;
        ans.push_back(num);
    }

    return ans;
}



#endif // MATRIX_H