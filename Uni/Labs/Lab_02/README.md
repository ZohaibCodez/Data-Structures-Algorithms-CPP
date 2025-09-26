# Lab 02 - Advanced Data Structures & File I/O 📊

This lab explores three fundamental computer science concepts: **mathematical series generation**, **multi-dimensional array implementation**, and **file I/O performance optimization**. Each task builds essential skills for data manipulation and system programming.

---

## 🎯 What You'll Learn

1. **Mathematical Pattern Generation** - Creating complex series formulas
2. **N-Dimensional Array Implementation** - Building custom array data structures
3. **File I/O Performance** - Understanding buffered vs unbuffered operations

---

## 📁 Project Structure

```
Lab_02/
├── Task_01/
│   └── Task_01.cpp          # Mathematical series generator
├── Task_02/
│   └── NDArray.cpp          # N-dimensional array implementation
├── Task_03/
│   └── Task_03.cpp          # File I/O performance comparison
└── README.md                # This file
```

---

## 📖 Task 01: Mathematical Series Generator 🧮

**File**: `Task_01/Task_01.cpp`

### What It Does
Generates a mathematical series pattern that follows the formula:
```
I1*U2U3U4...Un + I2*U3U4...Un + I3*U4...Un + ... + In-1*Un + In
```

### Example Output
For `n = 4`:
```
I1*U2U3U4 + I2*U3U4 + I3*U4 + I4
```

### Key Features
- **Pattern Recognition**: Understands mathematical series structure
- **String Concatenation**: Builds complex expressions dynamically
- **Loop Control**: Manages nested loops for series generation

### Usage
```cpp
printND(5);  // Generates series up to I5
```

### Learning Objectives
- Mathematical pattern generation
- String manipulation in C++
- Algorithm design for series

---

## 📖 Task 02: N-Dimensional Array Implementation 📦

**File**: `Task_02/NDArray.cpp`

### What It Does
Implements a **generic N-dimensional array** class that can handle arrays of any dimension (1D, 2D, 3D, etc.) with proper memory management and indexing.

### Key Features
- **Generic Template**: Works with any data type (`int`, `double`, `char`, etc.)
- **Dynamic Memory**: Automatically manages memory allocation
- **Multi-dimensional Indexing**: Converts N-dimensional indices to flat array index
- **Bounds Checking**: Validates indices to prevent out-of-bounds access
- **Exception Handling**: Throws meaningful errors for invalid operations

### API Overview
```cpp
template <typename T>
class NDArray {
    // Constructor: NDArray(int ndim, T* dimensions)
    int calculateIndex(int* indexset);    // Convert N-D index to flat index
    void setValue(int* indexset, T val);  // Set value at N-D position
    T getValue(int* indexset);            // Get value from N-D position
    int size();                           // Total number of elements
};
```

### Example Usage
```cpp
// Create a 3D array: 5×3×10
int dims[3] = {5, 3, 10};
NDArray<int> arr(3, dims);

// Set value at position (4, 2, 8)
int indices[3] = {4, 2, 8};
arr.setValue(indices, 123);

// Get value back
int value = arr.getValue(indices);  // Returns 123
```

### Memory Layout
The array stores data in **row-major order** (C-style):
```
3D Array [2][3][4] in memory:
[0,0,0] [0,0,1] [0,0,2] [0,0,3] [0,1,0] [0,1,1] ... [1,2,3]
```

### Learning Objectives
- Template programming in C++
- Memory management and dynamic allocation
- Multi-dimensional array indexing mathematics
- Exception handling and error management

---

## 📖 Task 03: File I/O Performance Analysis 📁

**File**: `Task_03/Task_03.cpp`

### What It Does
Compares the performance difference between **buffered** and **unbuffered** file I/O operations by writing and reading 1 million student records.

### Key Features
- **Performance Timing**: Uses Windows API for precise timing measurements
- **Binary File Operations**: Demonstrates efficient binary I/O
- **Buffer Management**: Shows impact of buffering on I/O performance
- **Student Record Structure**: Simple data structure for testing

### Student Structure
```cpp
struct Student {
    int roll;           // Student roll number
    char name[30];      // Student name (fixed size)
};
```

### Performance Comparison
The program measures and compares:

1. **Unbuffered Writing**: Write one record at a time
2. **Buffered Writing**: Write in batches of 10,000 records
3. **Unbuffered Reading**: Read one record at a time
4. **Buffered Reading**: Read in batches of 10,000 records

### Expected Results
- **Buffered operations** are significantly faster
- **Writing** is generally faster than reading
- **Batch processing** reduces system call overhead

### Learning Objectives
- File I/O performance optimization
- Buffer management strategies
- System programming concepts
- Performance measurement techniques

---

## 🚀 How to Run

### Task 01: Series Generator
```bash
cd Task_01
g++ -o series Task_01.cpp
./series
```

### Task 02: NDArray
```bash
cd Task_02
g++ -o ndarray NDArray.cpp
./ndarray
```

### Task 03: File I/O Performance
```bash
cd Task_03
g++ -o fileio Task_03.cpp
./fileio
```

**Note**: Task 03 requires Windows (uses `windows.h`). For Linux/Mac, replace timing code with `<chrono>`.

---

## 🧠 Key Concepts Explained

### 1. Mathematical Series (Task 01)
Understanding how to generate complex mathematical patterns programmatically, which is essential for:
- Algorithm design
- Mathematical modeling
- Pattern recognition

### 2. Multi-dimensional Arrays (Task 02)
Learning how high-level array operations work internally:
- **Index Calculation**: Converting N-D coordinates to flat memory addresses
- **Memory Layout**: Understanding row-major vs column-major storage
- **Template Programming**: Creating reusable, type-safe data structures

### 3. File I/O Performance (Task 03)
Understanding system-level I/O optimization:
- **Buffer Size Impact**: How buffer size affects performance
- **System Call Overhead**: Why batching operations is faster
- **Memory vs Disk Trade-offs**: Balancing memory usage with I/O speed

---

## 🎮 Try These Challenges

### Task 01 Extensions
- Modify the series to include coefficients: `2I1*3U2U3 + 4I2*5U3`
- Add support for different variable names
- Generate series in reverse order

### Task 02 Extensions
- Add `operator[]` for cleaner syntax: `arr[2][3][4]`
- Implement array slicing: `arr.slice(1, 3, 0, 2)`
- Add array operations: addition, multiplication
- Implement copy constructor and assignment operator

### Task 03 Extensions
- Test with different buffer sizes (1K, 10K, 100K)
- Compare with text file I/O
- Add compression/decompression timing
- Implement different data structures (larger records)

---

## 🔧 Common Issues & Solutions

### Task 01
- **Pattern Logic**: Double-check the series formula implementation
- **String Building**: Ensure proper concatenation order

### Task 02
- **Index Calculation**: Verify the row-major indexing formula
- **Memory Management**: Check for proper cleanup in destructor
- **Bounds Checking**: Test with invalid indices

### Task 03
- **File Permissions**: Ensure write permissions in current directory
- **Large Files**: Monitor disk space for 1M records
- **Timing Accuracy**: Use high-resolution timers for better measurements

---

## 📚 Real-World Applications

### Task 01: Mathematical Series
- **Scientific Computing**: Generating mathematical sequences
- **Data Analysis**: Pattern recognition algorithms
- **Cryptography**: Generating pseudo-random sequences

### Task 02: N-Dimensional Arrays
- **Machine Learning**: Tensor operations (like NumPy)
- **Image Processing**: Multi-dimensional pixel data
- **Scientific Simulation**: 3D/4D data structures
- **Database Systems**: Multi-dimensional indexing

### Task 03: File I/O Performance
- **Database Systems**: Optimizing data persistence
- **Web Servers**: Efficient file serving
- **Data Processing**: Large dataset handling
- **System Programming**: OS-level optimization

---

## 🎓 Learning Outcomes

After completing Lab 02, you'll understand:

1. **Algorithm Design**: How to break complex problems into manageable steps
2. **Data Structure Implementation**: Building custom containers from scratch
3. **Performance Optimization**: Understanding system-level I/O behavior
4. **Template Programming**: Creating reusable, type-safe code
5. **Memory Management**: Proper allocation and cleanup strategies

---

## 🔮 Next Steps

This lab prepares you for:
- **Advanced Data Structures**: Trees, graphs, hash tables
- **System Programming**: Operating system concepts
- **Performance Analysis**: Profiling and optimization
- **Scientific Computing**: High-performance numerical computing

---

## 🤝 Contributing

Found improvements or bugs? Here's how to contribute:

1. **Fork the repository**
2. **Create a feature branch**
3. **Add your improvements** with clear documentation
4. **Submit a pull request**

### What We'd Love to See:
- Additional test cases and examples
- Performance optimizations
- Cross-platform compatibility improvements
- Enhanced error handling

---

## 📞 Need Help?

- **📧 Email**: Create an issue in the GitHub repository
- **💬 Discussion**: Use GitHub Discussions for questions
- **📖 Documentation**: Check individual task files for detailed comments

---

## 📜 License & Credits

This educational project is designed to help students understand fundamental computer science concepts.

**Credits**:
- Implementation follows standard computer science algorithms
- Examples chosen for educational clarity
- Performance testing based on industry best practices

**License**: MIT - Feel free to use for educational purposes

---

## 🎯 Final Thoughts

Lab 02 bridges the gap between **theoretical computer science** and **practical programming**. By implementing these three tasks, you've gained hands-on experience with:

- **Mathematical modeling** in software
- **Custom data structure design**
- **System-level performance optimization**

These skills are essential for any serious software developer, whether you're building web applications, scientific software, or system-level programs.

**Keep exploring, keep building, and keep learning!** 🚀

---

*Happy Coding! 💻✨*