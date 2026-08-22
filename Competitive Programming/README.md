# DSA

DSA stands for **Data Structures and Algorithms**.

## Index

- [What Is Data](#what-is-data)
- [What Is a Data Structure](#what-is-a-data-structure)
- [What Is an Algorithm](#what-is-an-algorithm)
- [What Is DSA (Combined)](#what-is-dsa-combined)
- [A Little History](#a-little-history)
- [Complexity — Time and Space](#complexity--time-and-space)
- [Big O Notation](#big-o-notation)
- [How To Actually Calculate Complexity](#how-to-actually-calculate-complexity)
- [Common Complexity Classes](#common-complexity-classes)

## What Is Data

Data is just information — numbers, characters, values — stored somewhere in memory so a program can use it. On its own, raw data doesn't have any particular shape or organization.

## What Is a Data Structure

A data structure is a **way of arranging and storing data** so that it can be used efficiently for a particular kind of problem.

Simple idea:

```text
Data = raw information.
Data structure = an organized way to store that information.
```

Different structures make different operations fast or slow. An array is great for accessing something by position instantly, but bad for inserting in the middle. A linked list is the opposite. Picking the right structure for the right job is half of problem-solving in CP.

## What Is an Algorithm

An algorithm is a **finite, step-by-step procedure** to solve a problem or complete a task. It must be:

- Well-defined (no guesswork, no ambiguity in the steps)
- Finite (it has to actually end, not run forever)
- Effective (each step is something that can actually be carried out)

Simple idea:

```text
Algorithm = a recipe. Follow the steps in order, get the result.
```

## What Is DSA (Combined)

**Data Structures** = how you organize/store the data.
**Algorithms** = the steps you take to process that data.

They're almost always discussed together because the data structure you pick directly affects how fast (or slow) your algorithm can be. A sorting algorithm behaves very differently on an array versus a linked list. Choosing the structure *is* part of designing the algorithm.

## A Little History

Both halves of "DSA" are old, older than computers themselves in one case.

- The word **algorithm** comes from **al-Khwārizmī**, a 9th-century Persian mathematician <cite index="13-1">who popularized doing math with step-by-step procedures using decimal notation — the approach was called "algorism," which is where the word "algorithm" eventually came from.</cite>
- The world's <cite index="14-1">first algorithm designed to run on a machine was written by Ada Lovelace in the 1840s, for Charles Babbage's proposed mechanical computer, the Analytical Engine — before electronic computers even existed.</cite>
- Modern **data structures and algorithms as a formal computing discipline** trace back to <cite index="19-1">Alan Turing's 1936 paper describing a universal machine capable of carrying out any algorithm, which laid the groundwork for computer science as a field.</cite>
- <cite index="13-1">Through the 1950s and 60s, most of the data structures and algorithms studied today were formalized — arrays, linked lists, binary search trees, hash maps, stacks, and sorting algorithms like merge sort (credited to John von Neumann).</cite>
- <cite index="19-1">Through the 60s and 70s, more advanced structures (hash tables, BSTs) and algorithms (quicksort, mergesort) were developed, forming the backbone of modern computing and eventually becoming central to technical interviews and competitive programming.</cite>

---

## Complexity — Time and Space

**Time complexity** measures how the **number of operations** a piece of code performs grows as the input size (`n`) grows. It is *not* a literal stopwatch measurement of seconds — it's about the **growth trend**, i.e., "if I double the input, does my code's work roughly double, roughly stay the same, roughly quadruple, or explode?"

**Space complexity** measures how the **extra memory** a piece of code needs (beyond the input itself) grows as `n` grows. A fixed number of variables (however many times their *values* change) does not count — what counts is whether you need *more memory slots* (a new array, a new container, extra storage per element) as input grows.

Simple idea:

```text
Time complexity  -> how work scales with input size.
Space complexity -> how extra memory scales with input size.
Both ignore raw constants and hardware speed — they measure trend, not seconds.
```

## Big O Notation

Big O is the notation used to express complexity — it describes the **worst-case upper bound** on how an algorithm's time (or space) grows relative to input size `n`.

Key rules of Big O:

1. **Drop constants.** `O(2n)` becomes `O(n)`. Whether the loop runs `n` times or `n-1` times or `2n` times, for large `n` the difference is insignificant — only the shape of growth matters.
2. **Keep only the dominant term.** If a function does `O(1) + O(1) + O(n) + O(1)` worth of work across different lines, the total is just `O(n)` — the fastest-growing term swallows the smaller ones as `n` gets large.
3. **Worst case, by default.** Unless stated otherwise, Big O describes the worst-case scenario — the most operations a piece of code could possibly do for a given `n`.
4. **One variable's operation is O(1), a loop over n items is O(n), a loop over a loop is O(n²), and so on** — the exponent/degree grows with how many "layers" of iteration scale with input size.


## How To Actually Calculate Complexity

### PART 1 — General Rules (apply to ANY code, loop or recursive)

**Time — building blocks:**

1. **Any single operation** (assignment, arithmetic, comparison, one array/vector index access `arr[i]`, `.size()` on an STL container) → **O(1)**.
2. **One loop scanning n items once, O(1) work per iteration** → **O(n)**. Holds even with an `if` checked every iteration whose body also runs up to n times worst case — sums to `O(n)+O(n)=O(2n)→O(n)`.
3. **Two+ separate loops, one after another, not nested** → **added**: `O(n)+O(m) → O(n+m)`. Only *nested* loops multiply.
4. **Loop nested inside a loop, both scaling with n** → **O(n²)**. Three nested → O(n³).
5. **Inner loop's range depends on outer loop's position** (e.g. `for j = i to n`) → total iterations sum to ~n²/2 → still **O(n²)**.
6. **Loop that halves/divides the problem by a constant factor each time** (binary search, or a plain `while(n>1) n=n/2`) → **O(log n)**.
7. **Loop scanning n items where each item does a halving-style or sorting step** → **O(n log n)**. Treat a built-in efficient `sort()` as a known O(n log n) cost.
8. **Multiple independent inputs of different sizes** → keep separate: **O(n + m)**, don't collapse to one variable unless guaranteed equal.
9. **Two pointers moving through one array once** (from both ends, or fast/slow) → still a single pass, **O(n)**, not O(n²) — nothing is nested.
10. **Amortized cost** — an operation usually O(1) but occasionally O(n) (e.g. vector's `push_back` on resize) → total over n calls is **O(n) overall, O(1) amortized per call**, not O(n²). A loop calling such an operation n times is still O(n) total.
11. **Best / Average / Worst case can genuinely differ for the same code** (quicksort: O(n log n) average, O(n²) worst case if pivot choice is unlucky; hash map lookup: O(1) average, O(n) worst case on collisions). Default to worst case unless stated otherwise — but know it isn't always the only meaningful number.
12. **Graph/tree traversal** — "n" often isn't one shrinking number; complexity is usually stated in terms of vertices and edges: **O(V + E)** for a full traversal (BFS/DFS) touching every vertex and edge once.
13. **Recursion with memoization / DP** — complexity is **(number of distinct subproblems) × (work per subproblem, excluding recursive calls)** — NOT branching^depth. This is because each unique subproblem is computed once and reused, collapsing what would otherwise be exponential repeated work.
14. **Known data structure operations, treated as trusted building blocks** once learned, rather than re-derived each time: balanced BST insert/search ~O(log n), hash map insert/lookup ~O(1) average, heap push/pop ~O(log n).

**Space — building blocks:**

1. **Fixed number of variables**, regardless of value changes, as long as the *count* doesn't grow with n → **O(1)**.
2. **New array/vector/set/map/string holding ~one entry per input element** → **O(n)**.
3. **Modifying input in-place, no new container** → doesn't add to space complexity.
4. **2D array/grid sized around input** (n×n or n×m) → **O(n²)** or **O(n·m)**.
5. **New structure whose size depends on something other than n directly** (e.g. output sized by results found) → express in its own terms, don't assume O(n).
6. **Recursion's own extra space = call stack depth** (how many calls are simultaneously waiting, not total calls made) — generally how far down you go before hitting the base case.
7. **Memoization adds its own space** — the cache/table storing subproblem results, on top of whatever stack depth exists, e.g. O(n) for a 1D memo array, O(n×m) for a 2D one.

---

### PART 2 — Methods (HOW to actually apply the rules above)

**Method A — Iterative code (loops, straight-line):** read top to bottom, assign each line/block a complexity using Part 1's rules, add them up, simplify with Big O (drop constants, keep the dominant term). This is direct — no equation-solving needed, just reading and summing.

**Method B — Brute-force / manual counting (verification tool, any code):** actually run or hand-trace the code for small inputs (n=1,2,3,4...), count real operations or calls, and look for a numeric pattern (e.g. 1,3,7,15 → 2ⁿ-1). This doesn't replace proper analysis, but it's the fastest way to catch a wrong assumption — if your formula-based answer doesn't match what you count by hand on a small case, one of them is wrong.

**Method C — Recursion, via recurrence relations (for plain recursive code, no memoization):**
1. Define `T(n)` = cost of running the function on input size n.
2. Read the code, assign cost to each part in terms of T: each recursive call → `T(smaller size)`; everything else → O(1), or Part 1's rules if a loop exists inside.
3. Sum it up into a recurrence: `T(n) = a·T(n/b) + f(n)` or `T(n) = a·T(n-c) + f(n)`, where `a`=calls per invocation, `n/b` or `n-c`=how much smaller, `f(n)`=extra work per call.
4. Write the base case, e.g. `T(1)=O(1)`.
5. Solve via substitution/unrolling: plug the rule into itself repeatedly, spot the pattern, generalize to "after k substitutions," solve for k reaching the base case, substitute back, apply Big O.
6. Cross-check with Method B on small n.

   **Shortcuts once you recognize the shape:** `a` calls, fixed subtraction, no extra per-call work → O(aⁿ). 1 call, divide by constant, O(1) extra work → O(log n). `a` calls on n/b plus O(n^d) extra work → Master Theorem, often O(n log n) when balanced (merge sort). 1 call, shrink by 1, O(n) extra work per call → O(n²).

   **When calls are unequal size or condition-dependent** (Fibonacci-style `f(n-1)+f(n-2)`, or backtracking): a clean formula won't fit — draw the recursion tree, bound the total leaf calls instead. Still generally exponential for unequal-but-similar splits; backtracking needs per-problem reasoning about how pruning cuts the tree.

---

### Worked Examples

**1. Single loop — Remove Duplicates from Sorted Array:**
```c
int n = nums.size();  int j = 0;             // O(1) each
for (int i = 1; i < n; i++)
    if (nums[i] != nums[j]) { j++; nums[j] = nums[i]; }
return j + 1;
```
Method A: O(1)+O(1)+O(n)+O(1) → **O(n)** time, **O(1)** space.

**2. Nested loop — checking all pairs:**
```c
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        // O(1) work
```
Method A: n×n → **O(n²)** time, **O(1)** space.

**3. Two pointers — single pass:**
```c
int i = 0, j = n-1;
while (i < j) { /* O(1) work */ i++; j--; }
```
Method A + rule 9: one combined pass → **O(n)**, not O(n²).

**4. Recursive, uniform branching — Tower of Hanoi:**
```c
void toh(int n, ...) {
    if (n == 1) { print; return; }
    toh(n-1, ...); print; toh(n-1, ...);
}
```
Method C: `T(n) = 2·T(n-1) + O(1)` → substitution → `T(n)=2^(n-1)·c + 2^(n-1)-1` → **O(2ⁿ)**. Cross-checked (Method B) via brute count 1,3,7,15 → 2ⁿ-1, and the aⁿ shortcut. Space: stack depth n → **O(n)**.

## Common Complexity Classes

From fastest to slowest, in increasing order of growth as `n` gets large:

```text
O(1)        Constant     - doesn't depend on input size at all
O(log n)    Logarithmic  - cuts problem size down repeatedly (e.g. binary search)
O(n)        Linear       - one full pass through the input
O(n log n)  Linearithmic - a pass combined with a log-time step (e.g. efficient sorting)
O(n²)       Quadratic    - nested loop over the input (loop inside a loop)
O(n³)       Cubic        - triple nested loop
O(2ⁿ)       Exponential  - roughly doubles with every additional input element (brute force subsets)
O(n!)       Factorial    - every possible ordering (brute force permutations)
```