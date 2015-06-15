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
 
 int strStrKMP(string haystack, string needle) {
  
 }
