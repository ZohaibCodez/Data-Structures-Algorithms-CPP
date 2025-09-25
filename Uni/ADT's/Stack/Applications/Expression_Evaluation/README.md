# Expression Evaluation 🧮

## What is Expression Evaluation?

After converting expressions to **Postfix** or **Prefix** form, we need to **calculate** their actual values! This is where expression evaluation comes in - it's like having a calculator that understands these special notations.

## Why Evaluate Postfix/Prefix?

### 🚫 Problems with Infix Evaluation:
- **Complex**: Need to handle precedence rules (`*` before `+`)
- **Brackets**: Must find matching brackets first
- **Multiple passes**: May need to read expression several times

### ✅ Benefits of Postfix/Prefix Evaluation:
- **Simple**: Just use a stack!
- **One pass**: Read expression only once
- **No brackets**: Precedence is built into the order
- **Fast**: Perfect for computers

---

## 📤 Postfix Expression Evaluation

**File**: `postfix_evaluation.cpp`

### How Postfix Works:
Think of postfix like **instructions for a calculator**:
- Numbers go into memory (stack)
- Operators take numbers from memory and calculate

### Algorithm Steps:
1. **Create a stack** for numbers
2. **Scan LEFT to RIGHT**:
   - **Number**: Push onto stack
   - **Operator**: Pop two numbers, calculate, push result back
3. **Final result**: Last number remaining in stack

### Step-by-Step Example: `2 3 4 * +`

```
Expression: 2 3 4 * +
Goal: Calculate the result

Step 1: '2' → Number → Push to stack → Stack: [2]
Step 2: '3' → Number → Push to stack → Stack: [2, 3]  
Step 3: '4' → Number → Push to stack → Stack: [2, 3, 4]
Step 4: '*' → Operator → Pop 4 and 3 → Calculate 3*4=12 → Push 12 → Stack: [2, 12]
Step 5: '+' → Operator → Pop 12 and 2 → Calculate 2+12=14 → Push 14 → Stack: [14]

Final Result: 14
```

### 🎯 Key Point - Order Matters!
```
When we see '*':
- First pop gives us the SECOND operand (4)
- Second pop gives us the FIRST operand (3)  
- Calculate: 3 * 4 = 12 (not 4 * 3!)
```

### More Examples:
| Postfix | Step-by-Step | Result |
|---------|--------------|--------|
| `23+` | Push 2, Push 3, Pop 3&2, 2+3=5 | **5** |
| `53-` | Push 5, Push 3, Pop 3&5, 5-3=2 | **2** |
| `23*4+` | 2, 3, 2*3=6, 4, 6+4=10 | **10** |

---

## 📥 Prefix Expression Evaluation

**File**: `prefix_evaluation.cpp`

### How Prefix Works:
Similar to postfix, but we **start from the RIGHT side**!

### Algorithm Steps:
1. **Create a stack** for numbers
2. **Scan RIGHT to LEFT** ⬅️:
   - **Number**: Push onto stack
   - **Operator**: Pop two numbers, calculate, push result back
3. **Final result**: Last number remaining in stack

### Step-by-Step Example: `+ * 2 3 4`

```
Expression: + * 2 3 4
Goal: Calculate the result
Scan RIGHT TO LEFT: 4 → 3 → 2 → * → +

Step 1: '4' → Number → Push to stack → Stack: [4]
Step 2: '3' → Number → Push to stack → Stack: [4, 3]
Step 3: '2' → Number → Push to stack → Stack: [4, 3, 2]  
Step 4: '*' → Operator → Pop 2 and 3 → Calculate 2*3=6 → Push 6 → Stack: [4, 6]
Step 5: '+' → Operator → Pop 6 and 4 → Calculate 6+4=10 → Push 10 → Stack: [10]

Final Result: 10
```

### 🎯 Why Right-to-Left?
In prefix `+ 2 3`:
- The operator `+` needs operands `2` and `3`
- We must see the operands BEFORE we can apply the operator
- Reading right-to-left ensures operands are ready when we reach the operator

### Comparison:
| Infix | Postfix | Prefix | Result |
|-------|---------|--------|---------|
| `2 + 3` | `2 3 +` | `+ 2 3` | **5** |
| `(2 + 3) * 4` | `2 3 + 4 *` | `* + 2 3 4` | **20** |
| `2 + 3 * 4` | `2 3 4 * +` | `+ 2 * 3 4` | **14** |

---

## 🎯 Key Concepts

### Stack Behavior:
```
Stack works like a stack of plates:
- PUSH: Add plate to top
- POP: Remove plate from top  
- LIFO: Last In, First Out
```

### Operand Order (Important!):
```
For operation A - B:
- First pop gives us B (second operand)
- Second pop gives us A (first operand)
- Calculate A - B (not B - A!)

Example in postfix "52-":
- Pop 2 (second operand)
- Pop 5 (first operand)  
- Calculate 5 - 2 = 3
```

### Algorithm Efficiency:
- **Time Complexity**: O(n) - Look at each character once
- **Space Complexity**: O(n) - Stack can hold up to n/2 operands
- **One Pass**: No need to re-read the expression

---

## 🧮 Tracing Examples

Let's trace through some examples:

### Postfix: `234*+5-`
```
2 → Stack: [2]
3 → Stack: [2, 3]
4 → Stack: [2, 3, 4]
* → Pop 4,3 → 3*4=12 → Stack: [2, 12]
+ → Pop 12,2 → 2+12=14 → Stack: [14]
5 → Stack: [14, 5]
- → Pop 5,14 → 14-5=9 → Stack: [9]
Result: 9
```

### Prefix: `-+*2345` (scan right-to-left)
```
5 → Stack: [5]
4 → Stack: [5, 4]  
3 → Stack: [5, 4, 3]
2 → Stack: [5, 4, 3, 2]
* → Pop 2,3 → 2*3=6 → Stack: [5, 4, 6]
+ → Pop 6,4 → 6+4=10 → Stack: [5, 10]  
- → Pop 10,5 → 10-5=5 → Stack: [5]
Result: 5
```

---

## 🚀 How to Run

```bash
# Postfix Evaluation
g++ -o postfix_eval postfix_evaluation.cpp
./postfix_eval

# Prefix Evaluation
g++ -o prefix_eval prefix_evaluation.cpp  
./prefix_eval
```

---

## 🎮 Try These Examples

Test your understanding by tracing through these:

**Postfix:**
- `23+4*` → Should give ?
- `52/3+` → Should give ?
- `123+-` → Should give ?

**Prefix:**
- `*+234` → Should give ?
- `/+234` → Should give ?
- `-+234` → Should give ?

<details>
<summary>Click for answers</summary>

**Postfix:**
- `23+4*` → (2+3)*4 = 20
- `52/3+` → (5/2)+3 = 2+3 = 5 (integer division)
- `123+-` → 1+(2-3) = 1+(-1) = 0

**Prefix:**
- `*+234` → (2+3)*4 = 20  
- `/+234` → (2+3)/4 = 5/4 = 1 (integer division)
- `-+234` → (2+3)-4 = 1

</details>

---

## 🧠 What You'll Learn

After this section, you'll master:
1. **How to evaluate postfix expressions** using a stack
2. **How to evaluate prefix expressions** using right-to-left scanning
3. **Why postfix/prefix are easier** for computers than infix
4. **Operand order importance** when popping from stack
5. **Stack-based algorithm design** for expression processing

**Congratulations!** 🎉 You now understand the complete journey from bracket validation to expression evaluation!