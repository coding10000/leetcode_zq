/*
Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
understanding : matching problem, about parantheses, so generally use stack
right cases
// ()[]{}
// ({[]})
// (){[]}
wrong cases:
// )[]{}
// (]
// (  一定要注意
*/

/*
Solution:
    1. hash_table + stack, if s[i] in hash table, pop stack; else push stack
    2. not use hash table, use a match function to judge(more time compexity, not flexible)
*/

bool isValid_1(string s) {
    unordered_map<char, char> map({{')','('}, {'}', '{'}, {']', '['}});
    stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (map.count(s[i])) {
            // more concise
            if (stk.empty() || stk.top() != map[s[i]]) return false;
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }
    return stk.empty();
}

// bug:
// line 37 : modify return true; to return stk.empty();
// forget to consider the case : '{}[](' before all is right, but less a matching ')'
// 解题之前 多与  面试官沟通， 一定要要求面试官多举一些例子

bool isMatch(char a, char b) {
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    if (a == '(' && b == ')') return true;
    return false;
}

bool isValid_2(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stk.push(s[i]);
        } else {
            if (stk.empty() || !isMatch(stk.top(), s[i])) return false;
            stk.pop();
        }
    }
    return stk.empty();
}
