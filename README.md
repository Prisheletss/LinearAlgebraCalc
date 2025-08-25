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

<table>
    <thread>
        <tr>
            <th scope="col">Function</th>
            <th scope="col">Example</th>
        </tr>
    </thread>
    <tbody>
        <tr>
            <th scope="row"><code>Matrix()</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; m;
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix(initializer_list&lt;vector&lt;T&gt;&gt; input)</code></th>
            <td><pre><code class="cpp">
Matrix&lt;int&gt; m = { 
    {1, 2}, 
    {3, 4} 
};
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix(Matrix* input)</code></th>
            <td><pre><code class="cpp">
Matrix&lt;int&gt; m = { {1, 2}, {3, 4} };
Matrix&lt;int&gt; n = m;
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix(int height, int width)</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; m(2, 3);
print(m);
//  0 0
//  0 0
            </code></pre></td>
        </tr>
    </tbody>
</table>


### Redactors

In this topic we will look at the application of functions over m:
```cpp
Matrix<int> m = { {1, 2}, {3, 4} };
```

<table>
    <thread>
        <tr>
            <th scope="col">Function</th>
            <th scope="col">Example</th>
        </tr>
    </thread>
    <tbody>
        <tr>
            <th scope="row"><code>void add_row(vector&lt;T&gt; row)</code></th>
            <td><pre><code class="language-cpp">
m.add_row( {5, 6} );
// 1 2
// 3 4
// 5 6
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>void add_column(vector&lt;T&gt; column)</code></th>
            <td><pre><code class="language-cpp">
m.add_columt( {7, 8} );
// 1 2 7
// 3 4 8
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>void remove_row(int index)</code></th>
            <td><pre><code class="language-cpp">
m.remove_row(0);
// 3 4
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>void remove_column(int index)</code></th>
            <td><pre><code class="language-cpp">
m.remove_column(1);
// 1
// 3
            </code></pre></td>
        </tr>
    </tbody>
</table>


### investigators

In this topic we will look at the application of functions over m:
```cpp
Matrix m = { {1, 2}, {3, 4} };
```

<table>
    <thread>
        <tr>
            <th scope="col">Function</th>
            <th scope="col">Example</th>
        </tr>
    </thread>
    <tbody>
        <tr>
            <th scope="row"><code>vector&lt;int&gt; rank()</code></th>
            <td><pre><code class="language-cpp">
vector&lt;int&gt; r = m.rank();
// 2 2 -- height and width
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>vector&lt;T&gt; get_row(int index)</code></th>
            <td><pre><code class="language-cpp">
vector&lt;int&gt; row = m.get_row(1);
// 1 2
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>vector&lt;T&gt; get_column(int index)</code></th>
            <td><pre><code class="language-cpp">
vector&lt;int&gt; column = m.get_column(0);
// 1 3
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>vector&lt;T&gt;* operator [](int index)</code></th>
            <td><pre><code class="language-cpp">
vector&lt;int&gt; row = *(m[0]);
// 1 2
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>private void print()</code></th>
            <td><pre><code class="language-cpp">
this->print();
// 1 2
// 3 4
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>private int index_converter(int index, int type)</code></th>
            <td><pre><code class="language-cpp">
int index = index_converter(-1);
// 1
            </code></pre></td>
        </tr>
    </tbody>
</table>


need to be able to take negative indices, and to check for out of bounds


### calculators

In this topic we will look at the application of functions over m, n and v:
```cpp
Matrix m = { {1, 2}, {3, 4} };
Matrix n = { {1, 0}, {0, 2} };
vector<int> v = {5, -1};
```

<table>
    <thread>
        <tr>
            <th scope="col">Function</th>
            <th scope="col">Example</th>
        </tr>
    </thread>
    <tbody>
        <tr>
            <th scope="row"><code>vector&lt;T> operator *(vector&lt;T&gt; other)</code></th>
            <td><pre><code class="language-cpp">
vector&lt;int&gt; u = n * v;
// 5 -2
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>int det()</code></th>
            <td><pre><code class="language-cpp">
int d = m.det();
// -2
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>int det()</code></th>
            <td><pre><code class="language-cpp">
int d = m.det();
// -2
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix&lt;T&gt; minor(int y, int x)</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; m11 = m.minor(1, 1);
// 4
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix&lt;double&gt; inverse()</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; inv = n.inverse();
// 1  0
// 0 0.5
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix&lt;T&gt; operator +(Matrix&lt;T&gt; other)</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; a = m + n;
// 2 2
// 3 6
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix&lt;T&gt; operator *(T other)</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; a = n * 0.5f;
// 0.5 0
//  0  1
            </code></pre></td>
        </tr>
        <tr>
            <th scope="row"><code>Matrix&lt;T&gt; operator *(Matrix&lt;T&gt; other)</code></th>
            <td><pre><code class="language-cpp">
Matrix&lt;int&gt; a = m * n;
// 1 4
// 3 8
            </code></pre></td>
        </tr>
    </tbody>
</table>


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
