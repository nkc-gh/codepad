/*
====================================================================
LeetCode 2114 - Maximum Number of Words Found in Sentences
====================================================================
 
+------------------------------------------------------------------+
| Difficulty - Easy                                                |
| Date of Submission - 26 November 2026 16:54                      |
| Tags - Array, String                                             |
+------------------------------------------------------------------+
 
A sentence is a list of words separated by a single space with no
leading or trailing spaces. Given an array of strings sentences,
return the maximum number of words in a single sentence.
 
Constraints:
1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] consists of lowercase English letters and ' ' only.
No leading or trailing spaces. Words separated by single space.
 
Example 1:
Input: sentences = ["alice and bob love leetcode", "i think so too",
                    "this is great thanks very much"]
Output: 6
 
Example 2:
Input: sentences = ["please wait", "continue to fight", "continue to win"]
Output: 3
 
====================================================================
*/
 
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int word = 0;
        for(string s : sentences) {
            int words = 0;
            for(int i=0 ; i<s.length() ; i++){
                if(i==s.length()-1){
                    words++;
                    break;
                }
                if(s[i]==' ') words++;
            }
            if(word<words) word = words;
        }
 
        return word;
    }
};
 
/*
====================================================================
SOLUTION IN MY WORDS
====================================================================
 
Words = spaces + 1. Iterated each sentence character by character
counting spaces. Added 1 when reaching the last character to account
for the final word (which has no trailing space).
 
Used range-based for loop (for(string s : sentences)) for cleaner
iteration over the array.
 
Tracked global max using a single variable, updated after each sentence.
 
====================================================================
COMPLEXITY
====================================================================
 
1. TIME COMPLEXITY:
N = number of sentences, M = max length of a sentence
Inner loop runs M times per sentence: O(N*M)
 
2. SPACE COMPLEXITY: O(1) — no extra space used
====================================================================
*/