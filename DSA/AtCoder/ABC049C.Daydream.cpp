/*
====================================================================
AtCoder ABC049C - Daydream
====================================================================

Given a string S, determine if it can be formed by concatenating
any combination of the words: "dream", "dreamer", "erase", "eraser"
in any order any number of times.

Constraints:
1 <= |S| <= 10^5
S consists of lowercase English letters.

Input format:
S

Example 1:
Input: erasedream
Output: YES

Example 2:
Input: dreameraser
Output: YES

Example 3:
Input: dreamerer
Output: NO
====================================================================
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    while(s.length()!=0){
        if(s.substr(s.length()-2,2) == "er"){
            if(s.length() >= 7 && s.substr(s.length()-7,7) == "dreamer"){
                s = s.substr(0, s.length()-7);
            }
            else if(s.length() >= 6 && s.substr(s.length()-6,6) == "eraser"){
                s = s.substr(0, s.length()-6);
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
        else{
            if(s.length() >= 5 && (s.substr(s.length()-5,5) == "dream" || s.substr(s.length()-5,5) == "erase")){
                s = s.substr(0, s.length()-5);
            }
            else{
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}

/*
====================================================================
SOLUTION IN MY WORDS
====================================================================

First instinct was to build T forward and check against S, but the
problem with matching from the left is ambiguity - if S starts with
"dream" you don't know if it's "dream" or the start of "dreamer".
You'd have to look ahead every time.

From the right the ambiguity disappears. "dreamer" and "eraser"
both end in "er", "dream" ends in "am", "erase" ends in "se". So
checking the last 2 characters tells you which branch you're in,
then you check the full word.

Algorithm: loop while S is not empty. Check the last 2 characters.
If "er", try to peel "dreamer" first (length 7), then "eraser"
(length 6). If neither matches, print NO and exit. If not "er",
try to peel "dream" or "erase" (both length 5). If neither matches,
print NO and exit. If S becomes empty, print YES.

Longer words must be checked before shorter ones. If S ends with
"dreamer" and you check "dream" first, you peel "dream" and leave
"er" which matches nothing, giving wrong answer NO.

First submission got RE on 2 test cases. The bug was unsigned
integer underflow. s.length() returns an unsigned type. If S has
length 2 and you compute s.length()-7, instead of getting -5 you
get a huge positive number (unsigned wraparound). substr then tries
to access that index and crashes. Fix was to check s.length() >= 7
before the dreamer substr and s.length() >= 6 before the eraser
substr. If S is shorter than the word being checked it can't
possibly match anyway, so going to the NO branch is correct.

Also learned that s.length() returns an unsigned integer, so
subtracting from it when the result would be negative causes
wraparound to a huge positive number, not a negative number. Always
guard against this with a length check before doing s.length()-n.

====================================================================
COMPLEXITY
====================================================================

1. TIME COMPLEXITY:

Each iteration of the while loop peels off at least 5 characters
from S (minimum word length is 5). So the loop runs at most
|S|/5 times.

Each iteration does a constant number of substr calls, each O(L)
where L is the word length (at most 7), so O(1) per iteration.

Total: O(|S|)

2. SPACE COMPLEXITY:

s -> O(|S|), shrinks each iteration but starts at |S|
No other containers.

Total: O(|S|)

3. COMMON MISTAKES PEOPLE MAKE ON THIS PROBLEM:

- Matching from the left instead of the right - creates ambiguity
  between "dream" and "dreamer", "erase" and "eraser" since one
  is a prefix of the other.

- Checking shorter words before longer ones - peeling "dream" from
  "dreamer" leaves "er" which matches nothing, giving wrong NO.

- Unsigned underflow on s.length()-n when s is shorter than n -
  s.length() is unsigned, subtraction wraps to huge positive,
  substr crashes with RE. Fix with length check before substr.

- Not returning after printing NO - loop continues after NO,
  potentially printing YES afterwards too.
*/