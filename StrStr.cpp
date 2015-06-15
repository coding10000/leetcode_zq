/**
Implement strStr() Total Accepted: 54256 Total Submissions: 244390 My Submissions Question Solution 
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. 
If you still see your function signature returns a char * or String, 
please click the reload button  to reset your code definition.
 * 
 */ 
 
 /*
 1. naive method: two pointers from start to end, traversal
 2. KMP : getNext + match
 */
 
 int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    // trick : modify if (haystack.empty()) return -1; as if (haystack.size() < needle.size()) return -1;
    if (haystack.size() < needle.size()) return -1;
    int n1 = haystack.size();
    int n2 = needle.size();
    for (int i = 0; i + n2 - 1 < n1; ++i) {
        int j = 0;
        while (j < n2 && haystack[i + j] < needle[j]) ++j;
        if (j == n2) return i;
    }
    return -1;
 }
 
    void getNext(const string& s, vector<int>& next) {
        next[1] = 0;
        int k = 0; // prefix length
        for (int i = 2; i <= s.size(); ++i) {
            // opotimize
            //if (s[i - 1] == s[next[i - 1]]) next[i - 1] = next[next[i - 1]];
            // compare current char(即 max suffix's next char) and max prefix's next char
                // (1) not equal, recursively find the previous max prefix
            while (k > 0 && s[i - 1] != s[k]) {
                k = next[k];
            }
                // (2) equal, ++k(that is, prefix's length++) 
            if (s[i - 1] == s[k]) {
                ++k;
            }
            // next array i-th position's prefix length is k
            next[i] = k;
        }
    }

    int strStrKMP(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.size() < needle.size()) return -1;
        int n1 = haystack.size();
        int n2 = needle.size();
        vector<int> next(n2 + 1, 0);
        getNext(needle, next);
        int i = 0; // current string position
        int j = 0; // mathced length
        while (i < n1) {
            // match, ++i, ++j
            while (j < n2 && haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            // j == 0 represents no common prefix, move to next char(++i)
            if (j == 0) {
                ++i;
            }
            // j == n2 reprensents find a mathed position, return
            if (j == n2) {
                return i - j;
            }
            // j != n2 && j != 0, jump to the max prefix
            j = next[j];
        }
        return -1;
    }
