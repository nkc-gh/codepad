/*
====================================================================
Codeforces 208A - Dubstep
====================================================================
 
+------------------------------------------------------------------+
| Difficulty  - 900                                                |
| Date of Submission - 26 November 2026 21:21                      |
| Tags - strings                                                   |
+------------------------------------------------------------------+
 
A song's words are separated by one or more "WUB"s. WUBs may also
appear at the start and end. Given the full dubstep string, recover
the original words separated by spaces.
 
Input:
Single non-empty string of uppercase letters, length <= 200.
No real word contains "WUB". At least one real word guaranteed.
 
Output:
Original words separated by spaces.
 
Example:
Input: WUBWUBABCWUB           ->  Output: ABC
Input: WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
->  Output: WE ARE THE CHAMPIONS MY FRIEND
 
====================================================================
*/
 
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s;
    cin >> s;
 
    string output = "";
 
    for(int i=0 ; i<s.length() ; i++){
        if(s.substr(i, 3) == "WUB"){
            i += 2;
            if(output != "" && i+1 < s.length() && s.substr(i+1, 3) != "WUB"){
                output += " ";
            }
        }
        else{
            output += s[i];
        }
    }
 
    cout << output;
    return 0;
}
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Iterated through the string. When WUB is found, skip 3 chars (i+=2,
loop does +1). When a real char is found, add it to output.
 
Space logic: after skipping a WUB, add a space only if:
1. output is not empty (not at the start)
2. i+1 is in bounds
3. the next thing is NOT another WUB (consecutive WUBs = one separator)
Condition order matters: bounds check (i+1 < s.length()) comes before
substr call to avoid out-of-bounds access — C++ evaluates left to right
so substr only runs if bounds check passes.
 
Key insight: space is added after the WUB is processed, not when the
next real char is found. The lookahead s.substr(i+1, 3) != "WUB"
ensures consecutive WUBs produce only one space.
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY: O(N) — each character visited at most once
2. SPACE COMPLEXITY: O(N) — output string
====================================================================
*/