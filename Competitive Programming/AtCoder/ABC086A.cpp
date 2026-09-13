/*
====================================================================
AtCoder ABC086A - Product
====================================================================

Given two positive integers a and b, determine whether their
product is even or odd.

Constraints:
1 <= a,b <= 10000
a and b are integers.

Input format:
a b

Example 1:
Input: 3 4
Output: Even
(3*4=12 is even)

Example 2:
Input: 1 21
Output: Odd
(1*21=21 is odd)
====================================================================
*/

#include <iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;

  if((a*b)%2==0){
    cout << "Even" << endl;
  }
  else{
    cout << "Odd" << endl;
  }

  return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

The logic itself was immediate - a product is even if at least one
factor is even, so checking (a*b)%2==0 directly captures that
without needing to check a and b individually. At these constraints
(max 10000*10000 = 10^8), there's no overflow risk with int either.

The actual bug was a compile error, not a logic error: first
attempt wrote cout << Even << endl; and cout << Odd << endl;
without quotes. Without quotes, Even and Odd are parsed as
identifiers (like variable or function names) rather than string
literals, so the compiler looks for a declared symbol called Even/
Odd and fails since none exists. Fixed by wrapping them in double
quotes ("Even", "Odd") so they're treated as string literals to
print, not as code to look up.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

cin >> a >> b        -> O(1)
a*b                   -> O(1), fits in int at these constraints
(a*b)%2==0            -> O(1)
cout << "Even"/"Odd"  -> O(1)

Total: O(1)

2. SPACE COMPLEXITY:

a, b -> O(1) fixed variables

Total: O(1)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Writing string literals without quotes (cout << Even instead of
  cout << "Even") - causes a compile-time error since the bare word
  is treated as an undeclared identifier, not text to print.

- Checking a%2==0 || b%2==0 instead of the simpler (a*b)%2==0 - not
  wrong, just an unnecessary extra step when the product's parity
  alone answers the question directly.

- Worrying about overflow on a*b - unnecessary at these specific
  constraints (a,b <= 10000), though worth keeping in mind as a
  general habit for problems with larger bounds.
*/