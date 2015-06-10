/*
Longest Valid Parentheses 
Total Accepted: 36208 Total Submissions: 174246
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
Solution: 
    brute force: start from i, find the longest valid palindrome, then get the max. O(n^2)
    1. stack: time O(n), space O(n), **push the length of last valid parentheses into stack**
    2. stack:
        // Traverse the string twice, taking O(n) time.
        // First time, mark all the matching parentheses as '*' (push the index of '(' into <stack>).
        // Second time, count the longest consecutive '*'.
    3. stack : maitain a valid string's start (same as Largest Rectangle in Histogram)
    4. DP: why?????
*/


int longestValidParentheses(string s) {

}

// time O(n)
// sapce O(n)
/* take some examples : 
    ((()))
    (()())
    (()(()())
    遇到(从0开始重新计算valid长度，否则在prevLen中累加valid长度
*/  
// idea: push the length of last valid parentheses into stack
    //  c = '(' : st.push(prev), len = 0;
    //  c = ')' : if st.empty() --> len = 0; else len += st.top() + 2, st.pop()
int longestValidParentheses_1(string s) {
    int longestLen = 0;
    int prevLen = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(prevLen);
            prevLen = 0;
        } else if (!st.empty()) {
            prevLen += st.top() + 2;
            st.pop();
            longestLen = max(longestLen, prevLen);
        } else {
            prevLen = 0;
        }
    }
    return longestLen;
}

// more efficient
int longestValidPalindrome_1(string s) {
    int res = 0;
    stack<int> st;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(count);
            count = 0;
        } else if (!st.empty()) {
            count += 1 + st.top();
            st.pop();
            res = max(res, count);
        } else {
            count = 0;
        }
    }
    return res * 2;
}
/**
 * bug :
 * 1. prevLen += s.top() + 2; (must)
 * 2. after s = ')', must use st.pop()
 */ 
 
int longestValidParentheses_2(string s) {
    // first travesal
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else if (!stk.empty()) {
            s[stk.top()] = '*';
            stk.pop();
            s[i] = '*';
        }
    }
    // second travesal 
    // find longest concecutive substring
    int global = 0;
    int local = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '*') {
            ++local;
        } else {
            global = max(global, local);
            local = 0;
        }
    }
    global = max(global, local); /******/
    return global;
}
/**
 * bug:
 * line 89: don't forget stk.pop()
 * line 105 : after second loop traversal, it must have global = max(global, local)
 */ 
 
 // idea ： same as largest rectangle in histogram
 // left(valid parlirome's left bound) i(right bound is current i)
 int longestValidParentheses_3(string s) {
     int res = 0;
     stack<int> pos;
     int start = 0;
     for (int i = 0; i < s.size(); ++i) {
         if (s[i] == '(') {
             pos.push(i);
         } else {
             if (pos.empty()) {
                 start = i + 1;
             } else {
                 pos.pop();
                 res = max(res, pos.empty() ? i - start + 1 : i - pos.top()); 
             }
         }
     }
     return res;
 }
 
// Dp Solution. By Andy.
int longestValidParentheses_4(string s) {
    int n = s.size();
    if(s.empty()) return 0;
    if(n<=1) return 0;
    int res = 0;
    vector<int> f(n,0);
    for(int i=n-2;i>=0;i--){
        int match = i + f[i+1] + 1;
        if(match<n&&s[i]=='('&&s[match]==')'){
            f[i]=f[i+1]+2;
            if(match+1<n) f[i]+=f[match+1];
        }
        res = max(res,f[i]);
    }
    return res;
}
 
 
