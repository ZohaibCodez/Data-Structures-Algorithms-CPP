# 🎯 Counting Squares Around a Point - Complete Beginner's Guide

## 📚 Table of Contents
1. [The Simple Story](#the-simple-story)
2. [Understanding the Problem Step-by-Step](#understanding-the-problem-step-by-step)
3. [Visual Examples with Diagrams](#visual-examples-with-diagrams)
4. [Deep Dive: How the Pattern Works](#deep-dive-how-the-pattern-works)
5. [The Algorithm Explained](#the-algorithm-explained)
6. [Code Walkthrough](#code-walkthrough)
7. [Tracing Through Examples](#tracing-through-examples)
8. [Practice Problems](#practice-problems)
9. [Common Mistakes & Tips](#common-mistakes--tips)
10. [FAQ & Further Learning](#faq--further-learning)

---

## 🌟 The Simple Story

Imagine you're playing a video game on a **2048 × 2048 pixel screen**. Someone draws magical squares on this screen that follow a special fractal pattern (like a snowflake that repeats itself at different scales). 

Now, you click somewhere on the screen at point **(x, y)**. Your mission? **Count how many of these magical squares your click landed inside!**

Think of it like dropping a dart on a dartboard with multiple overlapping circles. We need to count how many circles the dart pierced through! 🎯

---

## 🎓 Understanding the Problem Step-by-Step

### 🔹 Step 1: What Makes a Square "Special"?

In normal life, a square of "size 5" means 5×5 units. But here's the twist in our problem:

**A square of size `k` has sides of length `2k + 1` units**

Let's see why this matters:

| Size (k) | Side Length Formula | Actual Length | Why? |
|----------|-------------------|---------------|------|
| 1 | 2(1) + 1 | 3 units | Smallest possible square |
| 2 | 2(2) + 1 | 5 units | Can have a center point |
| 3 | 2(3) + 1 | 7 units | Always odd = has center |
| 4 | 2(4) + 1 | 9 units | Center point exists |
| 5 | 2(5) + 1 | 11 units | Pattern continues... |

**🎯 Key Insight:** Why odd numbers? Because every square needs a **unique center point**! 

```
Size 1 (3×3):        Size 2 (5×5):
■ ■ ■                ■ ■ ■ ■ ■
■ ● ■                ■ ■ ■ ■ ■
■ ■ ■                ■ ■ ● ■ ■
                     ■ ■ ■ ■ ■
● = Center           ■ ■ ■ ■ ■
```

---

### 🔹 Step 2: Understanding the Screen

```
Screen Dimensions: 2048 × 2048 pixels

Coordinate System:
(0,0) ────────────────────────► X-axis (2048, 0)
  │
  │
  │  The screen is like a
  │  huge graph paper
  │
  ▼
Y-axis
(0,2048)                    (2048, 2048)
```

**Important:** The **center** of our screen is at position **(1024, 1024)**.
- Why 1024? Because 2048 ÷ 2 = 1024

---

### 🔹 Step 3: The Fractal Pattern (The Magic!)

This is where things get really interesting! The squares follow a **recursive pattern**:

#### 🟦 Level 1: The Main Boss Square
- Size = **k** (whatever we input)
- Center = **(1024, 1024)** — right in the middle of screen
- This is the BIGGEST square

#### 🟦 Level 2: Four Corner Guards
If k > 1, the main square spawns **4 smaller squares**:
- Size = **k ÷ 2** (integer division)
- Positioned at the **four corners** of the main square
- Each corner guard is exactly **half the size** of the parent

#### 🟦 Level 3, 4, 5... : The Pattern Repeats!
Each of those 4 squares, if size > 1, spawns 4 MORE squares at their corners!

**This continues until we reach size 1** (the smallest possible square).

---

### 🔹 Step 4: Visual Pattern Breakdown

Let's see how a size k=4 square creates its children:

```
Parent Square (k=4, center at 10,10):

     6   7   8   9  10  11  12  13  14
 6   ╔═══════════════════════════════╗
 7   ║   ┌───┐               ┌───┐   ║
 8   ║   │ ◆ │              │ ◆ │   ║ ← Child squares (size 2)
 9   ║   └───┘               └───┘   ║
10   ║               ●               ║ ← Parent center (size 4)
11   ║                               ║
12   ║   ┌───┐                ┌───┐  ║ ← Child squares (size 2)
13   ║   │ ◆ │               │ ◆ │  ║
13   ║   └───┘                └───┘  ║
14   ╚═══════════════════════════════╝

Legend:
╔═══╗ = Parent square boundaries
┌───┐ = Child square boundaries
● = Parent center at (10, 10)
◆ = Child centers at corners
```

**The 4 Children:**
1. **Top-Left** child: center at (6, 6) → that's (10-4, 10-4)
2. **Top-Right** child: center at (14, 6) → that's (10+4, 10-4)
3. **Bottom-Left** child: center at (6, 14) → that's (10-4, 10+4)
4. **Bottom-Right** child: center at (14, 14) → that's (10+4, 10+4)

**Formula:** If parent center is (cx, cy) with size k, children are at:
- (cx - k, cy - k) ← Top-Left
- (cx + k, cy - k) ← Top-Right
- (cx - k, cy + k) ← Bottom-Left
- (cx + k, cy + k) ← Bottom-Right

---

## 🖼️ Visual Examples with Diagrams

### Example 1: k=500, point=(113, 941) → Output: 5

Let's understand why 5 squares contain this point:

```
Screen: 2048 × 2048
Main square: size 500, center (1024, 1024)

Step-by-step visualization:
                    (524, 524) to (1524, 1524)
                    ┌─────────────────────┐
                    │   Main Square       │
                    │   Size 500          │
                    │                     │
Point (113, 941)    │        ●(1024,1024) │
is OUTSIDE ─────→   │                     │
the main square     │                     │
                    └─────────────────────┘

Wait! The output is 5, not 0!
```

**The Trick:** Even though the main square centered at (1024, 1024) might not directly contain (113, 941), the **recursive children squares** spread out and can reach that point!

```
Level 1: Main Square (k=500, center 1024, 1024)
  ├─ Extends from: x=[524 to 1524], y=[524 to 1524]
  ├─ Does it contain (113, 941)? Let's check:
  │   x: 113 < 524? YES (outside left boundary)
  └─ This square does NOT contain the point ❌

Level 2: Four children (k=250)
  ├─ Top-Left (center: 524, 524)
  │   ├─ Extends: x=[274 to 774], y=[274 to 774]
  │   └─ Contains (113, 941)? NO (113 < 274, 941 > 774) ❌
  │
  ├─ Bottom-Left (center: 524, 1524)
  │   └─ Extends: x=[274 to 774], y=[1274 to 1774]
  │   └─ Contains (113, 941)? NO (113 < 274) ❌
  
Continue recursing...
Eventually 5 squares contain the point!
```

---

### Example 2: k=300, point=(100, 200) → Output: 0

```
Main Square (k=300):
  Center: (1024, 1024)
  Boundaries: x=[724 to 1324], y=[724 to 1324]
  
Point: (100, 200)
  
Check:
  x: 100 < 724? YES (way outside!)
  y: 200 < 724? YES (way outside!)
  
Result: Point is OUTSIDE main square
  
Rule: If a point is outside the main square,
      it's outside ALL child squares too!
      
Answer: 0 squares contain this point ✅
```

---

### Example 3: k=300, point=(1024, 1024) → Output: 1

```
Main Square (k=300):
  Center: (1024, 1024)
  Point: (1024, 1024) ← SAME as center!
  
  Contains point? YES! ✓ count = 1
  
Child Squares (k=150):
  Child positions: (1024±300, 1024±300)
  
  Top-Left: (724, 724)
  Range: [724-150 to 724+150] = [574 to 874] for both x and y
  
Does (1024, 1024) fit in [574, 874]? NO! 1024 > 874

All 4 children DON'T contain (1024, 1024)!

Final answer: Only the main square contains it = 1 ✅
```

---

## 🧠 Deep Dive: How the Pattern Works

### The Fractal Tree Structure

```
                    Main Square (k)
                         │
         ┌───────────────┼───────────────┐
         │               │               │
    Top-Left        Top-Right       Bottom-Left     Bottom-Right
    (k/2)            (k/2)            (k/2)           (k/2)
         │               │               │               │
    ┌────┴────┐     ┌────┴────┐     ┌────┴────┐     ┌────┴────┐
       4 more         4 more          4 more          4 more
       squares        squares         squares         squares
```

This is called a **Quadtree** in computer science!

---

### Mathematical Formula Breakdown

#### 1️⃣ **Finding Square Boundaries**

Given:
- Center: (cx, cy)
- Size: k

The square extends **k units** in all four directions:

```cpp
left   = cx - k     // Move k units left from center
right  = cx + k     // Move k units right from center
top    = cy - k     // Move k units up from center
bottom = cy + k     // Move k units down from center
```

**Total width/height = (cx + k) - (cx - k) = 2k**

But we count points inclusively, so: **2k + 1 points total** ✓

---

#### 2️⃣ **Checking if Point is Inside**

For point (px, py) to be inside the square:

```
Must satisfy ALL four conditions:
  px >= left   (not too far left)
  px <= right  (not too far right)
  py >= top    (not too high)
  py <= bottom (not too low)
```

**Visual:**
```
        top (cy - k)
            │
    left ───┼─── right
   (cx-k)   │   (cx+k)
            │
        bottom (cy + k)

Point (px, py) must be in shaded region:
        
    ┌───────────┐ ← top
    │           │
    │  (px,py)  │ ✓ Inside if within bounds
    │           │
    └───────────┘ ← bottom
```

---

#### 3️⃣ **Child Square Positioning**

Parent square (size k, center cx, cy) creates 4 children (size k/2):

| Child | X-coordinate | Y-coordinate | Direction |
|-------|-------------|--------------|-----------|
| Top-Left | cx - k | cy - k | ↖ |
| Top-Right | cx + k | cy - k | ↗ |
| Bottom-Left | cx - k | cy + k | ↙ |
| Bottom-Right | cx + k | cy + k | ↘ |

**Why distance k and not k/2?**

Because each child is size k/2, so it extends k/2 units in each direction. To position it at the corner, its center must be k units away (so its inner edge touches the parent's center).

```
Parent size k, child size k/2:

Parent edge is at cx ± k
Child center should be at: cx ± k
Child will extend: (cx ± k) ± k/2

Example: k=4, child k/2=2
  Parent right edge: cx + 4
  Child center: cx + 4
  Child extends: (cx+4-2) to (cx+4+2) = (cx+2) to (cx+6)
  
This places the child at the corner! ✓
```

---

#### 4️⃣ **Integer Division Magic**

In C++, dividing integers automatically rounds down:

```cpp
int k = 9;
int child = k / 2;  // Result: 4 (not 4.5!)

Examples:
  500 / 2 = 250
  250 / 2 = 125
  125 / 2 = 62
  62 / 2 = 31
  31 / 2 = 15
  15 / 2 = 7
  7 / 2 = 3
  3 / 2 = 1
  1 / 2 = 0 ← Stops here!
```

This natural halving creates the fractal pattern!

---

## 💻 The Algorithm Explained

### The Recursive Strategy (Simple Version)

```
To count squares containing point (px, py):

1. Start with the main square (size k, center 1024, 1024)

2. For each square:
   a) Check if point is inside this square
   b) If YES: count it!
   c) If square size > 1:
      - Create 4 smaller squares at corners
      - Recursively count for each child
   
3. Add up all the counts
```

### The Recursive Strategy (Detailed Version)

```
countSquares(k, cx, cy, px, py):
    
    ┌─ Step 1: Validation ─────────────────┐
    │ If k < 1 or k > 512:                 │
    │   Return 0 (invalid size)            │
    └──────────────────────────────────────┘
    
    ┌─ Step 2: Calculate Boundaries ──────┐
    │ left = cx - k                        │
    │ right = cx + k                       │
    │ top = cy - k                         │
    │ bottom = cy + k                      │
    └──────────────────────────────────────┘
    
    ┌─ Step 3: Check Containment ─────────┐
    │ If (px >= left AND px <= right       │
    │     AND py >= top AND py <= bottom): │
    │   count = 1                          │
    │ Else:                                │
    │   count = 0                          │
    └──────────────────────────────────────┘
    
    ┌─ Step 4: Base Case ─────────────────┐
    │ If k == 1:                           │
    │   Return count (no children)         │
    └──────────────────────────────────────┘
    
    ┌─ Step 5: Recursive Case ────────────┐
    │ newSize = k / 2                      │
    │                                      │
    │ count += countSquares(newSize,       │
    │            cx-k, cy-k, px, py)       │ Top-Left
    │                                      │
    │ count += countSquares(newSize,       │
    │            cx+k, cy-k, px, py)       │ Top-Right
    │                                      │
    │ count += countSquares(newSize,       │
    │            cx-k, cy+k, px, py)       │ Bottom-Left
    │                                      │
    │ count += countSquares(newSize,       │
    │            cx+k, cy+k, px, py)       │ Bottom-Right
    └──────────────────────────────────────┘
    
    ┌─ Step 6: Return Total ──────────────┐
    │ Return count                         │
    └──────────────────────────────────────┘
```

---

### Why Recursion Works Here

Think of Russian Matryoshka dolls:

```
🪆 Biggest Doll (k=8)
  └─ Contains 4 medium dolls (k=4)
      └─ Each contains 4 small dolls (k=2)
          └─ Each contains 4 tiny dolls (k=1)
              └─ BASE CASE: Can't open further!
```

Each "doll" (square) can contain other "dolls" (smaller squares). We check each one to see if our point is inside it!

---

## 📝 Code Walkthrough

```cpp
#include <iostream>
using namespace std;

int countSquares(int k, int cx, int cy, int px, int py)
{
    // STEP 1: Initialize counter
    int count = 0;
    
    // STEP 2: Validation - ensure k is within valid range
    // Why? Because k=512 gives side=1025, larger won't fit in 2048×2048 grid
    if (k < 1 || k > 512)
        return count;  // Return 0 for invalid input
    
    // STEP 3: Calculate side length (for reference, not used in logic)
    // Side = 2k+1 ensures odd number for a center point
    int side = (2 * k) + 1;
    
    // STEP 4: Calculate square boundaries
    // Square extends k units in all directions from center
    int top = cy - k;      // Upper boundary (y-coordinate)
    int bottom = cy + k;   // Lower boundary (y-coordinate)
    int left = cx - k;     // Left boundary (x-coordinate)
    int right = cx + k;    // Right boundary (x-coordinate)
    
    // VISUAL:
    //     (cx, cy-k) ← top
    //          │
    // (cx-k, cy) ─┼─ (cx+k, cy) ← left and right
    //          │
    //     (cx, cy+k) ← bottom
    
    // STEP 5: Check if point (px, py) is inside this square
    // Point must satisfy ALL four conditions:
    //   1. px >= left (not too far left)
    //   2. px <= right (not too far right)
    //   3. py >= top (not too high up)
    //   4. py <= bottom (not too low down)
    if (px >= left && px <= right && py >= top && py <= bottom)
    {
        count = 1;  // ✓ This square contains the point!
    }
    // If any condition fails, count stays 0
    
    // STEP 6: Base case - smallest possible square
    // If k=1, this square has no children, so return current count
    if (k == 1)
        return count;
    
    // STEP 7: Recursive case - this square has 4 children
    // Each child has size = k/2 (integer division)
    int newSize = k / 2;
    
    // Example: k=8 → newSize=4
    //          k=7 → newSize=3
    //          k=3 → newSize=1
    //          k=1 → newSize=0 (but we already returned above!)
    
    // STEP 8: Recursively count squares in all 4 corners
    
    // Top-Left child square
    // Center is at (cx-k, cy-k) - k units left and up
    count += countSquares(newSize, cx - k, cy - k, px, py);
    
    // Top-Right child square
    // Center is at (cx+k, cy-k) - k units right and up
    count += countSquares(newSize, cx + k, cy - k, px, py);
    
    // Bottom-Left child square
    // Center is at (cx-k, cy+k) - k units left and down
    count += countSquares(newSize, cx - k, cy + k, px, py);
    
    // Bottom-Right child square
    // Center is at (cx+k, cy+k) - k units right and down
    count += countSquares(newSize, cx + k, cy + k, px, py);
    
    // STEP 9: Return total count
    // This includes:
    //   - Current square (0 or 1)
    //   - All children's counts
    //   - All grandchildren's counts
    //   - ... and so on recursively
    return count;
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;  // Read input: size and point coordinates
    
    // Start recursion from main square:
    //   - Size: k
    //   - Center: (1024, 1024) - middle of 2048×2048 screen
    //   - Point to check: (x, y)
    cout << countSquares(k, 1024, 1024, x, y) << endl;
    
    return 0;
}
```

---

### 🔍 Line-by-Line Deep Dive

#### Understanding Boundary Calculation

```cpp
int top = cy - k;
int bottom = cy + k;
int left = cx - k;
int right = cx + k;
```

**Concrete Example:** Center (1024, 1024), size k=500

```
top    = 1024 - 500 = 524
bottom = 1024 + 500 = 1524
left   = 1024 - 500 = 524
right  = 1024 + 500 = 1524

Square covers:
  X: from 524 to 1524 (that's 1001 values: 524, 525, ..., 1524)
  Y: from 524 to 1524 (that's 1001 values)
  
Total points: 1001 × 1001 ✓
Formula check: 2k+1 = 2(500)+1 = 1001 ✓✓
```

---

#### Understanding Point Containment

```cpp
if (px >= left && px <= right && py >= top && py <= bottom)
```

**Why use `>=` and `<=` (not `>` and `<`)?**

Because points **on the boundary** are considered inside!

```
Example: Point (524, 1000), square left boundary = 524

Using >=: 524 >= 524? YES ✓ (point is on edge, counts as inside)
Using > : 524 >  524? NO ✗ (would exclude boundary points)

Problem says: "point on border is considered surrounded"
So we MUST use >= and <= !
```

---

#### Understanding Child Positions

```cpp
count += countSquares(newSize, cx - k, cy - k, px, py);  // Top-Left
```

**Visual Explanation:**

```
Parent: size k=8, center (20, 20)

Parent boundaries:
  left=12, right=28, top=12, bottom=28
  
  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28
12 ┌───────────────────────────────────────────────────────────────┐
13 │                                                               │
14 │     ┌─────────┐                       ┌─────────┐             │
15 │     │ TL child│                       │ TR child│             │
16 │     │  (12,12)│                       │  (28,12)│             │
17 │     │         │                       │         │             │
18 │     └─────────┘                       └─────────┘             │
19 │                                                               │
20 │                         ●(20,20)                              │ ← Parent center
21 │                                                               │
22 │     ┌─────────┐                       ┌─────────┐             │
23 │     │ BL child│                       │ BR child│             │
24 │     │  (12,28)│                       │  (28,28)│             │
25 │     │         │                       │         │             │
26 │     └─────────┘                       └─────────┘             │
27 │                                                               │
28 └───────────────────────────────────────────────────────────────┘

Child size: k/2 = 8/2 = 4

Top-Left child:
  Center: (cx-k, cy-k) = (20-8, 20-8) = (12, 12) ✓
  Boundaries: [8 to 16] in both x and y

Top-Right child:
  Center: (cx+k, cy-k) = (20+8, 20-8) = (28, 12) ✓
  Boundaries: [24 to 32] in both x and y
```

**Key Insight:** We move by **k units** (not k/2) because:
- Child size is k/2
- Child extends k/2 units from its center
- To place child's inner edge at parent's center, child's center must be k units away!

---

## 🎯 Tracing Through Examples

### 🟢 Example 1: k=2, point=(1024, 1024)

```
CALL 1: countSquares(2, 1024, 1024, 1024, 1024)
│
├─ k=2, center=(1024,1024), point=(1024,1024)
├─ Boundaries: left=1022, right=1026, top=1022, bottom=1026
├─ Check: 1024 in [1022,1026]? YES for both x and y ✓
├─ count = 1
├─ k != 1, so recurse with newSize = 2/2 = 1
│
├─ CALL 2: countSquares(1, 1022, 1022, 1024, 1024)  [Top-Left]
│  ├─ Boundaries: left=1021, right=1023, top=1021, bottom=1023
│  ├─ Check: 1024 in [1021,1023]? NO (1024 > 1023) ✗
│  ├─ count = 0
│  └─ k=1, return 0
│
├─ CALL 3: countSquares(1, 1026, 1022, 1024, 1024)  [Top-Right]
│  ├─ Boundaries: left=1025, right=1027, top=1021, bottom=1023
│  ├─ Check: 1024 in [1025,1027]? NO (1024 < 1025) ✗
│  ├─ count = 0
│  └─ k=1, return 0
│
├─ CALL 4: countSquares(1, 1022, 1026, 1024, 1024)  [Bottom-Left]
│  └─ return 0
│
├─ CALL 5: countSquares(1, 1026, 1026, 1024, 1024)  [Bottom-Right]
│  └─ return 0
│
└─ Total: 1 + 0 + 0 + 0 + 0 = 1 ✓

OUTPUT: 1
```

**Why only 1?** The main square contains the point, but all 4 child squares are positioned at corners and DON'T contain the center point!

---

### 🔴 Example 2: k=300, point=(100, 200)

```
CALL 1: countSquares(300, 1024, 1024, 100, 200)
│
├─ k=300, center=(1024,1024), point=(100,200)
├─ Boundaries: left=724, right=1324, top=724, bottom=1324
├─ Check x: 100 >= 724? NO ✗
├─ Point is outside main square!
├─ count = 0
├─ But still need to check children...
│
├─ CALL 2: countSquares(150, 724, 724, 100, 200)  [Top-Left]
│  ├─ Boundaries: left=574, right=874, top=574, bottom=874
│  ├─ Check x: 100 >= 574? NO ✗
│  ├─ count = 0
│  ├─ Recurse to children (size 75)...
│  │   └─ All children also don't contain point
│  └─ return 0
│
├─ CALL 3, 4, 5: Similar - all return 0
│
└─ Total: 0 + 0 + 0 + 0 + 0 = 0 ✓

OUTPUT: 0
```

---

### 🟡 Example 3: k=4, point=(10, 10)

```
CALL 1: countSquares(4, 10, 10, 10, 10)
│
├─ Center at (10,10), point at (10,10) - EXACT MATCH!
├─ Boundaries: left=6, right=14, top=6, bottom=14
├─ Check: 10 in [6,14]? YES for both x and y ✓
├─ count = 1
├─ newSize = 4/2 = 2
│
├─ CALL 2: countSquares(2, 6, 6, 10, 10)  [Top-Left]
│  ├─ Center (6,6), boundaries: left=4, right=8, top=4, bottom=8
│  ├─ Check: 10 in [4,8]? NO (10 > 8) ✗
│  └─ Total: 0
│
├─ CALL 3: countSquares(2, 14, 6, 10, 10)  [Top-Right]
│  └─ Total: 0
│
├─ CALL 4: countSquares(2, 6, 14, 10, 10)  [Bottom-Left]
│  └─ Total: 0
│
├─ CALL 5: countSquares(2, 14, 14, 10, 10)  [Bottom-Right]
│  └─ Total: 0
│
└─ Final Total: 1 + 0 + 0 + 0 + 0 = 1 ✓

OUTPUT: 1
```

---

### 🟣 Example 4: k=4, point=(6, 6) → Expected Output: 2

```
CALL 1: countSquares(4, 10, 10, 6, 6)
│
├─ Main square: center (10,10), size 4
├─ Boundaries: left=6, right=14, top=6, bottom=14
├─ Check: 6 in [6,14]? YES (on the boundary!) ✓
├─ count = 1
├─ newSize = 4/2 = 2
│
├─ CALL 2: countSquares(2, 6, 6, 6, 6)  [Top-Left]
│  │
│  ├─ Child square: center (6,6), size 2
│  ├─ Boundaries: left=4, right=8, top=4, bottom=8
│  ├─ Check: 6 in [4,8]? YES ✓
│  ├─ count = 1  🎯 FOUND ANOTHER ONE!
│  ├─ newSize = 2/2 = 1
│  │
│  ├─ CALL 2a: countSquares(1, 4, 4, 6, 6)  [TL of TL]
│  │  ├─ Boundaries: [3,5]×[3,5]
│  │  ├─ Check: 6 in [3,5]? NO (6 > 5) ✗
│  │  └─ return 0
│  │
│  ├─ CALL 2b: countSquares(1, 8, 4, 6, 6)  [TR of TL]
│  │  └─ return 0
│  │
│  ├─ CALL 2c: countSquares(1, 4, 8, 6, 6)  [BL of TL]
│  │  └─ return 0
│  │
│  ├─ CALL 2d: countSquares(1, 8, 8, 6, 6)  [BR of TL]
│  │  └─ return 0
│  │
│  └─ Subtotal: 1 + 0 + 0 + 0 + 0 = 1
│
├─ CALL 3: countSquares(2, 14, 6, 6, 6)  [Top-Right]
│  └─ return 0
│
├─ CALL 4: countSquares(2, 6, 14, 6, 6)  [Bottom-Left]
│  └─ return 0
│
├─ CALL 5: countSquares(2, 14, 14, 6, 6)  [Bottom-Right]
│  └─ return 0
│
└─ Final Total: 1 + 1 + 0 + 0 + 0 = 2 ✓

OUTPUT: 2
```

**Analysis:** Point (6,6) is contained by:
1. ✓ Main square (size 4, center 10,10)
2. ✓ Top-left child (size 2, center 6,6) — point is exactly at this square's center!

---

### 🔵 Example 5: Tracing the Recursion Tree

Let's visualize the call tree for k=4, point=(6,6):

```
                    countSquares(4, 10, 10)
                            │
                         count=1 ✓
                            │
            ┌───────────────┼───────────────┬───────────────┐
            │               │               │               │
    CS(2,6,6)        CS(2,14,6)      CS(2,6,14)     CS(2,14,14)
    count=1 ✓        count=0         count=0         count=0
       │
   ┌───┴───┬────┬────┐
   │       │    │    │
CS(1,4,4) CS(1,8,4) CS(1,4,8) CS(1,8,8)
count=0   count=0    count=0    count=0

Final count: 1 + 1 + 0 + 0 + 0 = 2

Legend:
CS = countSquares
Numbers in () = (size, cx, cy) - we always check same point (6,6)
✓ = This square contains the point
```

---

## 🧪 Practice Problems

### 🎓 Problem 1: Manual Trace (Easy)

**Question:** Manually trace `countSquares(2, 1024, 1024, 1023, 1023)`

**Think about:**
- Does the main square (size 2) contain point (1023, 1023)?
- What about the 4 child squares (size 1)?

<details>
<summary>Click to see solution</summary>

```
Main Square (size 2, center 1024, 1024):
  Boundaries: [1022, 1026] × [1022, 1026]
  Point (1023, 1023): 
    1023 in [1022, 1026]? YES ✓
  count = 1

Top-Left Child (size 1, center 1022, 1022):
  Boundaries: [1021, 1023] × [1021, 1023]
  Point (1023, 1023):
    1023 in [1021, 1023]? YES ✓
  count = 1

Top-Right Child (size 1, center 1026, 1022):
  Boundaries: [1025, 1027] × [1021, 1023]
  Point (1023, 1023):
    1023 in [1025, 1027]? NO ✗
  count = 0

Bottom-Left Child (size 1, center 1022, 1026):
  Boundaries: [1021, 1023] × [1025, 1027]
  Point (1023, 1023):
    1023 in [1025, 1027] for y? NO ✗
  count = 0

Bottom-Right Child (size 1, center 1026, 1026):
  count = 0

Total: 1 + 1 + 0 + 0 + 0 = 2
```

**Answer: 2 squares contain the point**
</details>

---

### 🎓 Problem 2: Predict the Output (Medium)

For each input, predict the output:

a) `k=1, point=(1024, 1024)` → ?  
b) `k=8, point=(1024, 1024)` → ?  
c) `k=512, point=(1024, 1024)` → ?  
d) `k=512, point=(512, 512)` → ?

<details>
<summary>Click to see answers</summary>

a) **Answer: 1**
   - Only one square of size 1 exists (no children)
   
b) **Answer: 1**
   - Main square contains center
   - All children are at corners, don't contain center
   
c) **Answer: 1**
   - Same logic - center point only in main square
   
d) **Answer: It depends!**
   - Need to trace through the recursion
   - Point (512, 512) is exactly 512 units away from center (1024, 1024)
   - It's on the boundary of the main square!
</details>

---

### 🎓 Problem 3: Modify the Code (Medium)

**Task:** Modify the code to print all squares that contain the point (not just count them).

**Output format:** For each square, print: `Size: k, Center: (cx, cy)`

<details>
<summary>Click to see solution</summary>

```cpp
void printSquares(int k, int cx, int cy, int px, int py)
{
    if (k < 1 || k > 512)
        return;
    
    int left = cx - k;
    int right = cx + k;
    int top = cy - k;
    int bottom = cy + k;
    
    // Check and print if point is inside
    if (px >= left && px <= right && py >= top && py <= bottom)
    {
        cout << "Size: " << k << ", Center: (" << cx << ", " << cy << ")" << endl;
    }
    
    if (k == 1)
        return;
    
    int newSize = k / 2;
    
    printSquares(newSize, cx - k, cy - k, px, py);
    printSquares(newSize, cx + k, cy - k, px, py);
    printSquares(newSize, cx - k, cy + k, px, py);
    printSquares(newSize, cx + k, cy + k, px, py);
}
```
</details>

---

### 🎓 Problem 4: Find the Pattern (Hard)

**Question:** For a point exactly at the center (1024, 1024), what's the output for different values of k?

Try: k = 1, 2, 4, 8, 16, 32, 64, 128, 256, 512

Do you see a pattern?

<details>
<summary>Click to see answer</summary>

**Answer:** All return 1!

**Why?** The center point (1024, 1024) is:
- ✓ Always in the main square (any k)
- ✗ Never in any child square (they're all at corners)

No matter how big k is, only the main square contains the exact center!
</details>

---

### 🎓 Problem 5: Complexity Analysis (Hard)

**Question:** What is the time complexity of this algorithm?

Consider:
- How many recursive calls are made?
- What's the maximum depth of recursion?
- For k=512, how many total squares exist?

<details>
<summary>Click to see analysis</summary>

**Time Complexity: O(4^d)** where d = log₂(k)

**Explanation:**
- Each call makes 4 recursive calls
- Recursion depth = log₂(k) levels
- Total calls = 1 + 4 + 16 + 64 + ... + 4^d

For k = 512:
- d = log₂(512) = 9
- Maximum calls = 4^9 = 262,144

**Space Complexity: O(d) = O(log k)**
- Recursion stack depth
- For k=512, max depth = 9

**Optimization Note:** We can prune branches early! If a point is outside a square, we don't need to check its children.

```cpp
// Add this optimization:
if (!(px >= left && px <= right && py >= top && py <= bottom))
{
    return 0;  // Point outside, no need to check children!
}
```

This drastically reduces calls in practice!
</details>

---

### 🎓 Problem 6: Boundary Cases (Expert)

Test these edge cases:

a) `k=512, point=(0, 0)` (top-left corner of screen)  
b) `k=512, point=(2048, 2048)` (bottom-right corner)  
c) `k=512, point=(512, 1024)` (left edge of main square)  
d) `k=1, point=(1025, 1025)` (just outside size-1 square)

What should each output?

---

## ⚠️ Common Mistakes & Tips

### ❌ Mistake 1: Wrong Child Position

```cpp
// WRONG!
count += countSquares(newSize, cx - newSize, cy - newSize, px, py);

// Correct!
count += countSquares(newSize, cx - k, cy - k, px, py);
```

**Why?** Children are distance **k** from parent center, not distance **newSize**!

---

### ❌ Mistake 2: Boundary Check Operators

```cpp
// WRONG! (excludes boundaries)
if (px > left && px < right && py > top && py < bottom)

// Correct! (includes boundaries)
if (px >= left && px <= right && py >= top && py <= bottom)
```

**Problem statement:** "A point on the border is considered surrounded"

---

### ❌ Mistake 3: Forgetting Base Case

```cpp
// WRONG! (infinite recursion when k=1)
int countSquares(int k, ...) {
    // ... check containment
    
    int newSize = k / 2;
    // Always recurse - BUG!
    count += countSquares(newSize, ...);
}

// Correct!
if (k == 1)
    return count;  // Stop recursion!
```

---

### ❌ Mistake 4: Using Float Division

```cpp
// WRONG! (newSize becomes floating point)
double newSize = k / 2.0;

// Correct! (integer division)
int newSize = k / 2;
```

**Why integer division?** Because we need discrete square sizes (1, 2, 3, ...), not fractions!

---

### ✅ Tip 1: Draw It Out!

When debugging, draw the squares on paper:

```
Example: k=2, center (5,5)

   3   4   5   6   7
3  ■   ■   ■   ■   ■
4  ■   ■   ■   ■   ■
5  ■   ■   ●   ■   ■  ← Main center
6  ■   ■   ■   ■   ■
7  ■   ■   ■   ■   ■

Children (size 1):
  (3,3) (7,3)
  (3,7) (7,7)
```

---

### ✅ Tip 2: Add Debug Prints

```cpp
void countSquares(int k, int cx, int cy, int px, int py, int depth = 0)
{
    string indent(depth * 2, ' ');
    cout << indent << "Checking: k=" << k << " center=(" << cx << "," << cy << ")" << endl;
    
    // ... rest of code
    
    if (contained)
        cout << indent << "✓ CONTAINS point!" << endl;
    else
        cout << indent << "✗ Outside" << endl;
}
```

---

### ✅ Tip 3: Test with Small Values First

Before testing k=500, try:
- k=1 (simplest case)
- k=2 (one level of recursion)
- k=4 (two levels)

Build confidence gradually!

---

### ✅ Tip 4: Understand the Coordinate System

```
Computer graphics coordinates:
  (0,0) is TOP-LEFT
  Y increases DOWNWARD
  X increases RIGHTWARD

Math coordinates:
  (0,0) is BOTTOM-LEFT
  Y increases UPWARD
  X increases RIGHTWARD

Our problem uses COMPUTER GRAPHICS style!
```

---

## 🎓 Key Takeaways

### 🔑 Core Concepts

1. **Fractal Recursion**: Same pattern repeats at different scales
2. **Quadtree Structure**: Each square has 4 children
3. **Boundary Mathematics**: Understanding coordinate ranges
4. **Integer Division**: Natural for discrete sizes
5. **Base Case**: Always stop at k=1

---

### 🔑 Why This Problem is Important

This pattern appears in:

- **Computer Graphics**: Quadtrees for spatial indexing
- **Image Compression**: Recursive image subdivision
- **Game Development**: Collision detection, spatial partitioning
- **Geographic Information Systems**: Map tiling (Google Maps!)
- **Scientific Computing**: Adaptive mesh refinement

---

### 🔑 Related Data Structures

**Quadtree:**
```
        Root
      /  |  \  \
    NW  NE SW  SE
   /|\\ /|\\ /|\\ /|\\
  ... ... ... ...
```

Each node has 4 children (NW, NE, SW, SE)  
Our problem is a complete quadtree!

**Octree:** 3D version (8 children)  
**Binary Tree:** 1D version (2 children)

---

## ❓ Frequently Asked Questions

### Q1: Why is the main square always centered at (1024, 1024)?

**A:** Because the screen is 2048×2048, and the center is at 2048/2 = 1024 for both x and y. The problem specifies the largest square should be centered on the screen.

---

### Q2: What if the point is exactly on the edge of a square?

**A:** The problem states: "If the point is on the border of a square, it is considered to be surrounded by that square." So we use `>=` and `<=` in our comparisons.

---

### Q3: Can squares overlap?

**A:** YES! The parent square and child squares overlap. That's why a single point can be inside multiple squares. That's the whole point of the problem!

---

### Q4: Why is maximum k = 512?

**A:** Because:
- Side length = 2k + 1
- For k=512: side = 1025
- Centered at 1024, extends ±512 → [512, 1536]
- This fits in [0, 2048] screen
  
Actually, k=512 is chosen because 512 = 2^9, making the recursion depth exactly 9 levels, which is clean for algorithm analysis!

---

### Q5: What happens if k is odd (like k=7)?

**A:** Integer division handles it:
- k=7 → k/2 = 3 (not 3.5)
- k=3 → k/2 = 1
- k=1 → stop (base case)

The pattern still works perfectly!

---

### Q6: How would I visualize this in a browser?

**A:** Here's a simple approach:

```javascript
function drawSquare(k, cx, cy, color) {
    const side = 2 * k + 1;
    ctx.strokeStyle = color;
    ctx.strokeRect(cx - k, cy - k, side, side);
    
    if (k > 1) {
        const newSize = Math.floor(k / 2);
        drawSquare(newSize, cx - k, cy - k, color);
        drawSquare(newSize, cx + k, cy - k, color);
        drawSquare(newSize, cx - k, cy + k, color);
        drawSquare(newSize, cx + k, cy + k, color);
    }
}
```

---

## 📚 Further Learning

### Next Steps:

1. **Implement Iterative Version**: Can you solve without recursion?
2. **Optimize with Pruning**: Stop early if point is outside
3. **Visualize It**: Create an HTML/Canvas visualization
4. **3D Extension**: Extend to cubes in 3D space (octree)
5. **Distance Queries**: Find closest square to a point

---

### Practice Problems:

1. LeetCode: "Quad Tree" problems
2. LeetCode: "Number of Islands" (similar recursion)
3. CodeForces: Fractal pattern problems
4. Project Euler: Recursive geometry problems

---

## 🎨 Visual Summary

```
The Fractal Square Pattern:

Level 0:         ┌─────────┐
(k=8)            │         │
                 │    ●    │
                 │         │
                 └─────────┘

Level 1:         ┌───┬───┬───┐
(k=4)            ├───┼───┼───┤
                 ├───┼─●─┼───┤
                 ├───┼───┼───┤
                 └───┴───┴───┘

Level 2:         ┌─┬─┬─┬─┬─┬─┬─┐
(k=2)            ├─┼─┼─┼─┼─┼─┼─┤
                 ├─┼─┼─┼─┼─┼─┼─┤
                 ├─┼─┼─┼●┼─┼─┼─┤
                 ├─┼─┼─┼─┼─┼─┼─┤
                 ├─┼─┼─┼─┼─┼─┼─┤
                 ├─┼─┼─┼─┼─┼─┼─┤
                 └─┴─┴─┴─┴─┴─┴─┘

Each level doubles the resolution!
```

---

## 🏆 Final Challenge

**Can you solve this without recursion using a stack or queue?**

Think about:
- How would you store square information?
- What would you push onto the stack?
- When would you pop?

---

## 📌 Quick Reference Card

```
┌─────────────────────────────────────────┐
│ Fractal Squares Quick Reference         │
├─────────────────────────────────────────┤
│ Square size k → side length 2k+1        │
│ Main center: (1024, 1024)               │
│ Boundaries: center ± k                  │
│ Child size: k/2 (integer division)      │
│ Child positions: parent_center ± k      │
│ Base case: k == 1                       │
│ Point on boundary: INCLUDED             │
│ Max recursion depth: log₂(k)            │
│ Time complexity: O(4^log₂(k))           │
└─────────────────────────────────────────┘
```

---

**Happy Coding! 🖤**

*Remember: The best way to learn is by doing. Try modifying the code, break it, fix it, and understand why it works!*