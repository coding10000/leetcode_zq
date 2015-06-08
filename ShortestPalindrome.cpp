/*
Quesition: Shortest Palindrome 
Total Accepted: 1985 Total Submissions: 12378
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

/**
 * Solution:
 * 1. find the longest palindrome from s[0], then reverse the left string and add it to the string first(TLE)
 * 2. why???? ->-<-
 */ 
string shortestPalindrome(string s) {
    return shortestPalindrome_1(s);
}
// time : O(n^2)
// sapce : O(1)
// TLE
string shortestPalindrome_1(string s) {
    int end = longestPalindrome(s);
    string addingStr = s.substr(end);
    reverse(addingStr.begin(), addingStr.end());
    return addingStr + s;
}
int longestPalindrome(const string& s) {
    int end = s.size() - 1;
    int i = 0;
    int j = end;
    while (i <= j) {
        if (s[i] == s[j]) {
            ++i;
            --j;
        } else {
            --end;
            i = 0;
            j = end;
        }
    }
    return end + 1;
}
/**
 *bug
 * void reverse (BidirectionalIterator first, BidirectionalIterator last); reverse function's use method
 * directly revese(s.begin(), s.end()), no return value, same as sort()
 * TLE
 */ 
 // time : O(n)
 // space : O(n)
string shortestPalindrome_2(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + "#" + r;
    vector<int> p(t.size(), 0);
    for (int i = 1; i < t.size(); ++i) {
        int j = p[i - 1];
        while (j > 0 && t[i] != t[j]) j = p[j - 1];
        p[i] = (j += t[i] == t[j]);
    }
    return r.substr(0, s.size() - p[t.size() - 1]) + s;  
}
