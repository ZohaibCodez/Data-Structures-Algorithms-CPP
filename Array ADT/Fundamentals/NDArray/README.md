# 🧮 NDArray Implementation in C++

This folder contains a **basic NDArray (N-Dimensional Array) implementation in C++**.  
Think of it as a **custom version of NumPy arrays** (like in Python), but written from scratch in C++.  

The goal is **learning how multi-dimensional arrays work internally** —  
how data is stored, how we can access it, and how libraries like NumPy or TensorFlow manage memory.

---

## 🏫 Imagine This Example

- A **1D array** → like a line of boxes → `[10, 20, 30]`  
- A **2D array** → like a grid (matrix) →  
```
10 20 30
40 50 60
````
- A **3D array** → like a cube (stack of grids).  

But in memory, the computer **does not store a grid or cube**.  
It only knows how to store things in a **1D flat line of memory**.  
Our job is to **pretend that flat line looks multi-dimensional** using *math (strides)*.

---

## 🚀 Features of This Code
- You can create an array with **any number of dimensions**.  
- Memory is stored in **one flat block**, but accessed as if multi-dimensional.  
- You can **get or set values** safely with error-checking.  
- You can **fill the whole array** with one value.  
- It has **copy constructor and assignment operator** (so copying works correctly).  
- Handles **invalid inputs** (e.g., negative sizes, wrong indices).  

---

## 📖 How It Works (Step by Step)

### 1. Storing Dimensions
When you create an NDArray, you pass the shape.  
Example:  
```cpp
int dims[] = {3, 3};
NDArray<int> matrix(dims, 2);
````

This means: **2D array with 3 rows and 3 columns** → like a grid.

* `dimensions = [3, 3]`
* `ndim = 2` (because it has 2 dimensions).

---

### 2. Strides (The Magic Trick ✨)

Strides tell us **how far to move in memory** when you go one step in a dimension.

For `[3, 3]`:

* stride\[1] = 1 (move 1 step to go across a row).
* stride\[0] = 3 (skip 3 items to go to the next row).

So, index `[1, 2]` means:

```
= 1 * stride[0] + 2 * stride[1]
= 1 * 3 + 2 * 1
= 5
```

This means element `(1,2)` is stored at flat index `5` in memory.

---

### 3. Data Storage

All elements are kept in one array:

```
[1.5, 1.5, 1.5, 1.5, 1.5, ...]
```

But using strides, we can *pretend* it’s a matrix:

```
1.5 1.5 1.5
1.5 1.5 1.5
1.5 1.5 1.5
```

---

### 4. Access Functions

* `at(indices)` → returns reference, so you can read/write.
* `get(indices)` → returns value (read-only).
* `fill(value)` → fills entire array with given value.

Example:

```cpp
int idx[2] = {1, 2};
matrix.at(idx) = 9.9; // set element at (1,2)
cout << matrix.at(idx); // prints 9.9
```

---

## 🖥️ Example Program

```cpp
int main() {
    int dims2d[] = {3, 3};      // 3x3 matrix
    NDArray<double> matrix(dims2d, 2);

    matrix.fill(1.5);           // fill with 1.5

    cout << "Filled 2D matrix:\n";
    for (int i = 0; i < matrix.get_dimension(0); i++) {
        for (int j = 0; j < matrix.get_dimension(1); j++) {
            int idx[2] = {i, j};   // index = (i,j)
            cout << matrix.at(idx) << " ";
        }
        cout << endl;
    }
}
```

### ✅ Output

```
Filled 2D matrix:
1.5 1.5 1.5
1.5 1.5 1.5
1.5 1.5 1.5
```

---

## 🔮 Future Improvements

* Add `operator()` for cleaner access (`matrix(i,j)` instead of `at(idx)`).
* Add **reshape** function.
* Add **slicing** like Python (`matrix[0:2, 1:3]`).
* Add **iterators** for modern C++ loop support.
* Add **move constructor** (Rule of 5).

---

## 📚 Why This Matters

By building this from scratch, you learn:

* How arrays are **really stored in memory**.
* Why **strides** are important.
* How high-level libraries (NumPy, TensorFlow) are built.
* Stronger **C++ OOP and memory management skills**.

