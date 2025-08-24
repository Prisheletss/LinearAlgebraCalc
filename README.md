# solution.cpp
`solution.cpp` -- is the main file, it contains 3 examples of implification of project:

### solving SLAE (systems of linear algebraic equasions)

```cpp
Matrix<int> coeffs = {
    {2, -2, 3, 3},
    {3, 1, -2, -1},
    {2, 1, 3, -1},
    {-2, -1, -2, 1}
};
vector<int> values = { -8, 2, -7, 5 };

vector<double> ans = calculate(coeffs, values);

print(ans);

// -1 3 -2 2
```

This is equivalent to the following SLAE:

$$
\begin{cases}
2x + -2y + 3z + 3w = -8 \\
3x + y - 2z - w = 2 \\
2x + y + 3z - w = -7 \\
-2x - y - 2z + w = 5 
\end{cases}
$$

with solution:

$$
x = -1; \\ y = 3; \\ z = -2; \\ w = 2
$$


### operations on matrices

```cpp
Matrix<int> m = { 
    {1, 2}, 
    {3, 4}, 
    {5, 6} 
};
Matrix<int> n = { 
    {1, 2, 3}, 
    {4, 5, 6}
};

Matrix<int> ans = m * n;

print(m * n);

// 9 12 15
// 19 26 33
// 29 40 51
```

This is equivalent to the sequence:

$$
\begin{pmatrix}
1 & 2 \\
3 & 4 \\
5 & 6
\end{pmatrix} *
\begin{pmatrix}
1 & 2 & 3 \\
4 & 5 & 6
\end{pmatrix} =
\begin{pmatrix}
9 & 12 & 15 \\
19 & 26 & 33 \\
29 & 40 & 51
\end{pmatrix}
$$


### calculating the inverse matrix 
(4x4 and more takes too long to calculate)

```cpp
Matrix<int> m = { 
    {1, 2, 2}, 
    {3, 1, 1},
    {2, 1, 2}
};

Matrix<double> invers = m.inverse();
print(invers);

// -0.2  0.4  0
//  0.8  0.4 -1
// -0.2 -0.6  1
```

This is equivalent to the sequence:

$$
\begin{pmatrix}
1 & 2 & 2 \\
3 & 1 & 1 \\
2 & 1 & 2
\end{pmatrix}
^{-1} = 
\begin{pmatrix}
-0.2 & 0.4 & 0 \\
0.8 & 0.4 & -1 \\
-0.2 & -0.6 & 1
\end{pmatrix}
$$



# Matrix.h
`Matrix.h` -- is a file that contains the implementation of the **Matrix class** class and the **calculate function**. 

## Class Matrix

In class Matrix definided 19 public and 2 private methods, and one single private field

The whole class revolves around this `vector<vector<T>> matrix` field, where `T` -- is a `template typename` of this Class. It can be `int`, `short`, `float`, `double` or their `unsigned` versions

The methods of the Matrix class can be divided into the following categories:
+ initializers
+ redactors
+ investigators
+ calculators

### Initializers

`Matrix()`:
```cpp
Matrix m;
```
___

`Matrix(initializer_list<vector<T>> input)`:
```cpp
Matrix m = {
    {1, 2}, 
    {3, 4}
};
```
___

`Matrix(Matrix* input)`:
```cpp
Matrix m = { {1, 2}, {3, 4} };
Matrix n = m;
```
___

`Matrix(int height, int width)`:
```cpp
Matrix m(2, 3);
print(m);
//  0 0
//  0 0
```


### Redactors

In this topic we will look at the application of functions over m:
```cpp
Matrix m = { {1, 2}, {3, 4} };
```
\
`void add_row(vector<T> row)` 
```cpp
m.add_row( {5, 6} );
// 1 2
// 3 4
// 5 6
```
___


`void add_column(vector<T> column)`
```cpp
m.add_columt( {7, 8} );
// 1 2 7
// 3 4 8
```
___

`void remove_row(int index)`
```cpp
m.remove_row(0);
// 3 4
```
___

`void remove_column(int index)`
```cpp
m.remove_column(1);
// 1
// 3
```


### investigators

In this topic we will look at the application of functions over m:
```cpp
Matrix m = { {1, 2}, {3, 4} };
```

`vector<int> rank()`
```cpp
vector<int> r = m.rank();
// 2 2 -- height and width
```
___

`vector<T> get_row(int index)`
```cpp
vector<int> row = m.get_row(1);
// 1 2
```
___

`vector<T> get_column(int index)`
```cpp
vector<int> column = m.get_column(0);
// 1 3
```
___

`vector<T>* operator [](int index)` 
```cpp
vectir<int> row = *(m[0]);
// 1 2
```
___

`private void print()` 
```cpp
this->print();
// 1 2
// 3 4
```
___

`private int index_converter(int index, int type)` \
need to be able to take negative indices, and to check for out of bounds


### calculators
largest category

In this topic we will look at the application of functions over m, n and v:
```cpp
Matrix m = { {1, 2}, {3, 4} };
Matrix n = { {1, 0}, {0, 2} };
vector<int> v = {5, -1};
```

`vector<T> operator *(vector<T> other)`
```cpp
vector<int> u = n * v;
// 5 -2
```
___

`int det()`
```cpp
int d = m.det();
// -2
```
___

`Matrix<T> minor(int y, int x)`
```cpp
Matrix<int> m11 = m.minor(1, 1);
// 4
```
___

`Matrix<double> inverse()`
```cpp
Matrix inv = n.inverse();
// 1  0
// 0 0.5
```
___

`Matrix<T> operator +(Matrix<T> other)`
```cpp
Matrix a = m + n;
// 2 2
// 3 6
```
___

`Matrix<T> operator *(T other)`
```cpp
Matrix a = n * 0.5f;
// 0.5 0
//  0  1
```
___

`Matrix<T> operator *(Matrix<T> other)`
```cpp
Matrix a = m * n;
// 1 4
// 3 8
```


## calculator function
`vector<double> calculate(Matrix<T> coeffs, vector<T> values)`

[This function is intended for solving SLAE](https://github.com/Prisheletss/LinearAlgebraCalc/tree/main?tab=readme-ov-file#solving-slae-systems-of-linear-algebraic-equasions)



# Functions.h
`Functions.h` -- is a file, that containing functions for printing vectors and matrices to the screen

`void print(Matrix<T> matrix)`
```cpp
Matrix<int> a = { {1, 2}, {3, 4} };
print(a);
// 1 2
// 3 4
```
___

`void print(vector<T> vect)`
```cpp
vector<string> s = {"Hello", "\b,", "World", "\b!"};
print(s);
// Hello, world!
```
