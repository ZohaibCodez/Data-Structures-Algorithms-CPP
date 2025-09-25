# Bracket Validation 🔍

## What is Bracket Validation?

Imagine you're writing a math expression like `(2 + 3) * 4`. Every opening bracket `(` must have a matching closing bracket `)`. Bracket validation checks if all brackets are properly paired and in the right order!

## Why Do We Need This?

- **Programming**: Code with unmatched brackets won't compile
- **Math**: Expressions need proper grouping to be calculated correctly
- **Text Editors**: Help highlight matching brackets as you type

## 🏠 Homogeneous Brackets

**File**: `homogeneous_brackets.cpp`

### What does "Homogeneous" mean?
It means we only check **one type** of bracket: parentheses `( )`

### Examples:
- ✅ `(a+b)` → **VALID** (one opening, one closing)
- ✅ `((a+b)*c)` → **VALID** (nested brackets match)
- ❌ `(a+b` → **INVALID** (missing closing bracket)
- ❌ `a+b)` → **INVALID** (missing opening bracket)

### How It Works (Simple Steps):
1. **Create a stack** (like a stack of plates)
2. **Go through each character**:
   - See `(` → Put it on the stack
   - See `)` → Remove one `(` from stack
   - Other characters → Ignore them
3. **At the end**: If stack is empty, brackets are balanced!

```
Expression: (a+b)
Step 1: See '(' → Push to stack → Stack: ['(']
Step 2: See 'a' → Ignore → Stack: ['(']  
Step 3: See '+' → Ignore → Stack: ['(']
Step 4: See 'b' → Ignore → Stack: ['(']
Step 5: See ')' → Pop '(' → Stack: []
Result: Stack is empty → VALID! ✅
```

---

## 🌈 Heterogeneous Brackets

**File**: `heterogeneous_brackets.cpp`

### What does "Heterogeneous" mean?
It means we check **multiple types** of brackets: `( )`, `{ }`, and `[ ]`

### Examples:
- ✅ `{[(a+b)]}` → **VALID** (all brackets match their pairs)
- ✅ `(a+b)*{c+d}` → **VALID** (different types used separately)
- ❌ `(a+b]` → **INVALID** (wrong closing bracket)
- ❌ `{[}]` → **INVALID** (brackets are interleaved)

### Matching Rules:
| Opening | Closing | ✅ Match |
|---------|---------|----------|
| `(`     | `)`     | ✅ Yes   |
| `{`     | `}`     | ✅ Yes   |
| `[`     | `]`     | ✅ Yes   |
| `(`     | `}`     | ❌ No    |
| `{`     | `]`     | ❌ No    |

### How It Works:
Same as homogeneous, but now we need to check if the brackets **match each other**!

```
Expression: {[a+b]}
Step 1: See '{' → Push to stack → Stack: ['{']
Step 2: See '[' → Push to stack → Stack: ['{', '[']
Step 3: See 'a', '+', 'b' → Ignore
Step 4: See ']' → Pop '[' → They match! → Stack: ['{']
Step 5: See '}' → Pop '{' → They match! → Stack: []
Result: Stack is empty → VALID! ✅
```

---

## 🎯 Key Concepts

### What is a Stack?
Think of a **stack of plates**:
- You can only **add** plates to the top (PUSH)
- You can only **remove** plates from the top (POP)
- Last plate added is the first one removed (LIFO - Last In, First Out)

### Why Use Stack for Brackets?
- When we see `(`, we "remember" it by putting on stack
- When we see `)`, we check the most recent unmatched `(` (top of stack)
- This naturally handles **nested brackets** like `((()))`

### Algorithm Time Complexity:
- **Time**: O(n) - We look at each character once
- **Space**: O(n) - In worst case, stack holds all opening brackets

---

## 🚀 How to Run

```bash
# Compile homogeneous brackets
g++ -o homogeneous homogeneous_brackets.cpp

# Run it
./homogeneous

# Compile heterogeneous brackets  
g++ -o heterogeneous heterogeneous_brackets.cpp

# Run it
./heterogeneous
```

---

## 🎮 Try These Examples

Test your understanding with these expressions:

**Homogeneous:**
- `(((())))`
- `(a+b)*(c+d)`
- `((a+b)`
- `)a+b(`

**Heterogeneous:**
- `{[(a+b)*c]+d}`
- `([a+b)]`
- `{[a+b}]`
- `(){}[]`

---

## 🧠 What You'll Learn

After understanding this section, you'll know:
1. How to use **stacks** to solve matching problems
2. The difference between homogeneous and heterogeneous validation
3. How to trace through algorithms step-by-step
4. Why bracket validation is important in programming

**Next**: Move to Expression Conversion to learn how to change math expressions into different forms! →