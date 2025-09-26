# Polynomial ADT (Lab 01) ✳️

Learn and practice an Abstract Data Type for univariate polynomials in C++. This lab focuses on representing a polynomial, adding terms, pretty-printing, arithmetic, and simple calculus operations.

---

## 🎯 What You'll Learn

- Representing a polynomial as arrays of coefficients and exponents
- Dynamic memory growth for polynomial degree management
- Operator overloading for arithmetic and evaluation
- Derivative and antiderivative basics

---

## 🧱 Files

```
Lab_01/
├─ polynomial_adt.h   # Polynomial class (includes a demo main())
└─ README.md          # This file
```

Note: A small demo `main()` currently lives inside `polynomial_adt.h` for quick testing.

---

## 🧩 Polynomial API (from `polynomial_adt.h`)

- addTerm(int coefficient, int power)
- getCoefficient(int power) -> int
- setCoefficient(int newCoefficient, int power)
- operator()(int x) -> float            // evaluate P(x)
- operator+(const Polynomial&) -> Polynomial
- operator-(const Polynomial&) -> Polynomial
- derivative() -> Polynomial
- antiDerivative() -> Polynomial        // basic integer division version
- clear()                               // set all coefficients to 0 up to current degree
- operator<<(ostream&, const Polynomial&) // print like 3x^2+2x+1

Implementation details:
- Internally uses dynamic arrays `coefficients[]` and `exponents[]`.
- Auto-resizes capacity when adding higher-power terms.

---

## 🔧 Quick Start

### Build & Run (Windows / MinGW or similar)
```bash
g++ -std=c++17 polynomial_adt.h -o poly_demo
./poly_demo
```

If you prefer a separate `main.cpp`, include `polynomial_adt.h` there and compile the `.cpp` instead.

---

## 🔍 Usage Examples

### Create and print
```cpp
Polynomial p;
p.addTerm(2, 2);  // 2x^2
p.addTerm(3, 1);  // 3x
p.addTerm(1, 0);  // +1
cout << p << "\n";  // 2x^2+3x+1
```

### Evaluate P(x)
```cpp
cout << p(2) << "\n"; // 2*(2^2) + 3*(2) + 1 = 15
```

### Add / Subtract
```cpp
Polynomial a, b;
a.addTerm(1, 1);        // x
b.addTerm(4, 1);        // 4x
Polynomial s = a + b;   // 5x
Polynomial d = b - a;   // 3x
cout << s << "\n" << d << "\n";
```

### Derivative
```cpp
// p = 2x^2 + 3x + 1 → p' = 4x + 3
Polynomial dp = p.derivative();
cout << dp << "\n"; // 4x+3
```

---

## ⚠️ Notes & Limitations

- antiDerivative() uses integer division for coefficients; it’s a minimal educational version.
- addToCoefficient(int coefficient, int power) currently increments by `power` (educational stub); prefer `setCoefficient` or `addTerm` for correctness.
- The internal demo `main()` is for quick checks; move it to a `.cpp` for production-style structure.

---

## 📚 Learning Objectives

- Understand polynomial representation and memory growth strategies
- Practice operator overloading and class design in C++
- Implement and reason about derivative/antiderivative transformations

---

## ✅ Checklist

- [ ] Build and run the demo
- [ ] Create your own polynomials and evaluate at multiple x values
- [ ] Verify addition and subtraction with manual calculations
- [ ] Implement improvements (see below)

---

## 🔮 Suggested Improvements

- Use `double` for coefficients and return types to avoid integer division in integrals
- Add multiplication of polynomials
- Add input parser (e.g., from string like "2x^2+3x+1")
- Move demo `main()` into a separate `main.cpp`
- Implement copy/move semantics explicitly (Rule of 5)

---

Happy Coding! 🚀


