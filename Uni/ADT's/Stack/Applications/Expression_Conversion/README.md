# Expression Conversion 🔄

## What is Expression Conversion?

Just like you can write the same sentence in different ways, math expressions can be written in different forms! We'll learn to convert between **Infix**, **Postfix**, and **Prefix** notations.

## 📝 The Three Notations

### 🎯 Infix (Normal Math)
**What we usually write**: `a + b * c`
- Operators are **between** operands
- Uses brackets to show precedence: `(a + b) * c`
- **Problem**: Needs rules for which operation to do first

### 📤 Postfix (Reverse Polish)
**Operators come after**: `a b c * +`
- No brackets needed!
- Easy for computers to calculate
- Also called **Reverse Polish Notation (RPN)**

### 📥 Prefix (Polish Notation)
**Operators come before**: `+ a * b c`
- No brackets needed!
- Also easy for computers
- Also called **Polish Notation**

### 🔄 Same Expression, Different Forms:
| Infix | Postfix | Prefix |
|-------|---------|--------|
| `a + b` | `a b +` | `+ a b` |
| `a + b * c` | `a b c * +` | `+ a * b c` |
| `(a + b) * c` | `a b + c *` | `* + a b c` |

---

## 🔄 Infix to Postfix Conversion

**File**: `infix_to_postfix.cpp`

### Why Convert?
- **Computers prefer postfix** because it's easier to calculate
- **No brackets needed** - precedence is built into the order
- **One pass calculation** - read once, calculate once

### Algorithm Steps:
1. **Create a stack** for operators
2. **Scan left to right**:
   - **Operand** (like `a`, `b`) → Add directly to output
   - **Operator** (like `+`, `*`) → Handle based on precedence
   - **`(`** → Push to stack
   - **`)`** → Pop until you find `(`

### Precedence Rules:
| Operator | Precedence | Example |
|----------|------------|---------|
| `^`, `$` | 3 (Highest) | `2^3 = 8` |
| `*`, `/`, `%` | 2 (Medium) | `2*3 = 6` |
| `+`, `-` | 1 (Lowest) | `2+3 = 5` |

### Step-by-Step Example: `a + b * c`

```
Input: a + b * c
Goal: Convert to postfix

Step 1: 'a' → Operand → Output: "a"
Step 2: '+' → Operator → Push to stack → Stack: [+]
Step 3: 'b' → Operand → Output: "ab" 
Step 4: '*' → Higher precedence than '+' → Push to stack → Stack: [+, *]
Step 5: 'c' → Operand → Output: "abc"
Step 6: End → Pop all operators → Output: "abc*+"

Result: a + b * c becomes abc*+
```

### 🧮 Why This Works:
- `*` has higher precedence than `+`
- So `b * c` should be calculated first
- `abc*+` means: multiply `b` and `c`, then add `a`

---

## 🔄 Infix to Prefix Conversion

We have **TWO methods** to convert infix to prefix:

### Method 1: Two Stack Approach
**File**: `infix_to_prefix_two_stack.cpp`

**Concept**: Use one stack for operators, another for building prefix expressions
- More complex but gives **exact manual result**
- Uses **two stacks**: operator stack + operand stack
- Builds prefix expressions step by step

### Method 2: One Stack Approach ⭐ 
**File**: `infix_to_prefix_one_stack.cpp`

**Concept**: Reverse → Apply postfix algorithm → Reverse again
1. **Reverse** the infix expression and swap `(` with `)`
2. **Apply postfix algorithm** on reversed string
3. **Reverse** the result to get prefix

### Step-by-Step Example: `(a + b) * c`

```
Original: (a + b) * c

Step 1: Reverse and swap brackets
(a + b) * c → c * )b + a(

Step 2: Apply postfix algorithm on "c * )b + a("
Result: cb a + *

Step 3: Reverse the result  
cb a + * → * + a b c

Final Prefix: * + a b c
```

### 🎯 Key Insight:
The one-stack method is **clever** because:
- Postfix puts operators **after** operands
- Prefix puts operators **before** operands  
- If we reverse everything twice, we flip the order!

---

## 🎯 Key Concepts

### Operator Precedence:
```
Expression: a + b * c
Without brackets: Do * first, then +
Result: a + (b * c)
Postfix: a b c * +
Prefix: + a * b c
```

### Associativity:
- **Left-to-right**: `a + b + c = (a + b) + c`
- **Right-to-left**: `a ^ b ^ c = a ^ (b ^ c)` (for exponentiation)

### Stack Usage:
- **Infix to Postfix**: Stack holds operators temporarily
- **Two-stack method**: One for operators, one for building expressions
- **One-stack method**: Same as postfix, but with reversed input

---

## 🚀 How to Run

```bash
# Infix to Postfix
g++ -o infix_postfix infix_to_postfix.cpp
./infix_postfix

# Infix to Prefix (Two Stack)
g++ -o infix_prefix_two infix_to_prefix_two_stack.cpp
./infix_prefix_two

# Infix to Prefix (One Stack)  
g++ -o infix_prefix_one infix_to_prefix_one_stack.cpp
./infix_prefix_one
```

---

## 🎮 Try These Examples

Test your understanding:

| Infix | Try to Convert | Postfix | Prefix |
|-------|---------------|---------|--------|
| `a + b` | ? | `ab+` | `+ab` |
| `a * b + c` | ? | `ab*c+` | `+*abc` |
| `(a + b) * c` | ? | `ab+c*` | `*+abc` |
| `a + b * c + d` | ? | `abc*+d+` | `++a*bcd` |

---

## 🧠 What You'll Learn

After this section, you'll understand:
1. **Three different ways** to write math expressions
2. **Why computers prefer postfix/prefix** over infix
3. **How stacks help in conversion** algorithms
4. **Operator precedence** and how it affects conversion
5. **Two different methods** for infix to prefix conversion

**Next**: Move to Expression Evaluation to learn how to calculate these converted expressions! →