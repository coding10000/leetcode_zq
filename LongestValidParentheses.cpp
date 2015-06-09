/*
Longest Valid Parentheses 
Total Accepted: 36208 Total Submissions: 174246
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
Solution: (22:37-
    1. stack: time O(n), space O(n), **push the length of last valid parentheses into stack**
    2. DP
    3. stack
*/


int longestValidParentheses(string s) {

}

// time O(n)
// sapce O(n)
// idea: push the length of last valid parentheses into stack
    //  c = '(' : st.push(prev), len = 0;
    //  c = ')' : if st.empty() --> len = 0; else len = st.top() + 2, st.pop()
int longestValidParentheses_1(string s) {
    int longestLen = 0;
    int prevLen = 0;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            s.push(prevLen);
            prevLen = 0;
        } else if (!st.empty()) {
            prevLen = st.top() + 2;
            longestLen = max(longestLen, prevLen);
        } else {
            prevLen = 0;
        }
    }
    return longestLen;
}

/**
 * bug :
 * 1. prevLen = 
 */ 
