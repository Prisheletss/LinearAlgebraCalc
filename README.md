# Main files
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
```
\>>>  ```-1 3 -2 2```

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
```
\>>>
```
9 12 15
19 26 33
29 40 51
```

This is equivalent to the sequence:

$$
\begin{pmatrix}
1 & 2 \\
3 & 4 \\
5 & 6
\end{pmatrix}
*
\begin{pmatrix}
1 & 2 & 3 \\
4 & 5 & 6
\end{pmatrix}
=
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
```
\>>>
```
-0.2  0.4  0
 0.8  0.4 -1
-0.2 -0.6  1
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

___

`Matrix.h` -- is a file that contains the implementation of the **Matrix** class and the **calculate function**. 

calculate(Matrix\<T> coeffs, vector\<T> values) is designed to solve SLAE, it takes a matrix of SLAE coefficients and a vector of row values
___

`Functions.h` -- is a file containing functions for printing vectors and matrices to the screen
