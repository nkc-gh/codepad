/*
====================================================================
Codeforces 282A - Bit++ (Difficulty - 800)
====================================================================

Bit++ has exactly one variable x, starting at 0. A statement is
exactly one operation (++ or --) and the variable X, written
without spaces, in either order (++X or X++ both mean increment;
--X or X-- both mean decrement). Given n statements, execute them
all and find the final value of x.

Constraints:
1 <= n <= 150
Each statement is exactly 3 characters: some order of "++"/"--"
and "X".

Example 1:
Input: n=1 / ++X
Output: 1

Example 2:
Input: n=2 / X++ / --X
Output: 0
(X++ increments x to 1, --X decrements it back to 0)
====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int x = 0;
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        
        if(s == "X++" || s == "++X"){
            x++;
        }
        else{
            x--;
        }
    }
    
    cout << x << endl;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

Key realization needed up front: the problem states the operation
and variable "can be written in any order," meaning X++ and ++X are
functionally identical here (unlike real C++, where pre- and post-
increment differ in when they return a value) - the position of X
carries no meaning, only whether ++ or -- is present matters.

First attempt wrote the condition as
if(s == "X++" || "++X"). This compiled without error but always
executed x++ regardless of the actual statement, including on
decrement statements. Root cause: operator precedence makes this
parse as (s == "X++") || ("++X") - the second operand is a bare
string literal, completely disconnected from any comparison to s.

Worked through why this compiles and what it does: a string literal
like "++X" has type const char* (a pointer to where that literal is
stored in memory), not std::string. When C++ needs a bool (as in an
if condition) but is given a pointer, it implicitly converts via a
simple rule: any non-null pointer becomes true, only nullptr becomes
false. Since a string literal is always stored somewhere in memory,
it's never null, so it always evaluates to true - unconditionally,
regardless of its actual text content or of what s is.

Traced the practical effect: whenever s=="X++" is true, the || short
-circuits and never even evaluates the second operand - true by
coincidence. But whenever s=="X++" is false (e.g. s is "--X"), the
first operand is false, so || evaluates the second operand, "++X",
which converts to true regardless - making the WHOLE condition true
via false || true = true. Net effect: the condition is true on every
single statement, so x++ fired unconditionally and the else branch
(x--) never ran at all, no matter the actual input.

This isn't a compiler bug or oversight - pointer-to-bool conversion
is a legitimate, well-defined C++ feature, most commonly used for
null-checking, e.g. if(ptr) as shorthand for if(ptr != nullptr) when
checking whether a pointer returned by new/malloc/a lookup function
is valid before dereferencing it. The footgun is that this same
conversion rule applies uniformly to ANY pointer-like expression in
a boolean context, including a bare string literal accidentally left
disconnected from a real comparison - the compiler has no way to
distinguish "intentional null-check" from "forgot to write s==".

Fixed by writing both sides of the || as complete, independent
comparisons against s: s == "X++" || s == "++X". Each side now
genuinely depends on s's actual contents, so the condition is true
only when s actually matches one of the two increment forms, and
correctly falls to the else branch (decrement) otherwise. The lesson
generalizes: in C++, each side of a logical operator must be a
fully self-contained boolean expression - you cannot share a
comparison target implicitly across || or && the way natural
language ("if s is this or that") might suggest.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> n                    -> O(1)
for loop, n statements       -> O(n) iterations
    cin >> s                 -> O(1), fixed length 3 string
    string comparisons        -> O(1) each, fixed length 3
    x++/x--                   -> O(1)

Total: O(n), with n <= 150 this is trivially fast.

2. SPACE COMPLEXITY:

x, n, i -> O(1) fixed variables
s -> O(1), fixed length 3 string, re-declared each iteration but
     never grows

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Writing if(s == "X++" || "++X") instead of
  if(s == "X++" || s == "++X") - the bare string literal on the
  right side of || silently converts to true via pointer-to-bool
  conversion (any non-null pointer is true), making the whole
  condition always true regardless of input, with no compiler error
  to flag the mistake.

- Assuming X++ and ++X (or X-- and --X) behave differently, by
  analogy to real C++ pre/post-increment semantics - in this
  problem they are explicitly defined to mean the same thing, since
  the operation and variable can appear in either order with no
  semantic difference.

- Trying to parse out the position of the "X" character instead of
  just comparing the whole 3-character statement directly against
  the four possible exact strings ("++X", "X++", "--X", "X--") -
  direct string comparison is simpler and sufficient given the
  fixed, small statement format.
*/