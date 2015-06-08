/*
Longest Substring Without Repeating Characters 
Total Accepted: 68720 Total Submissions: 331327
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

/**
 * Solution:
 * 1. two pointer: start, end + hash table; time : O(n), space : O(n)
 * 2. 遇到字母的不重复问题，可以立即想到ASCII数组：vector<bool> exist(256, false);==> O(n)
 * 3. same as 2, use vector<int> exist(256, -1), be faster
 */ 
int lengthOfLongestSubstring(string s) {
    //return lengthOfLongestSubstring_1(s);
    return lengthOfLongestSubstring_2(s);
} 

// time : O(2*n)
// space : O(n)
// 涉及hash map的删除操作, 两次遍历，最慢
int lengthOfLongestSubstring_1(string s) {
    int longestLen = 0;
    int start = 0;
    int end = start;
    unordered_map<char, int> chars;
    for (end = start; end < s.size(); ++end) {
        if (chars.count(s[end])) {
            int index = chars[s[end]];
            for (int i = start; i <= index; ++i) {
                chars.erase(s[i]);
            }
            start = index + 1;
        }
        chars[s[end]] = end;
        longestLen = max(longestLen, end - start + 1);
    }
    return longestLen;
}
/**
 * bug:
 * line 30: longestLen is written wrong
 * 
 */ 

// time : O(2*n)
// space : (1)
// no erase hash table operation, twice traversal, so it will be faster
int lengthOfLongestSubstring_2(string s) {
    vector<bool> exist(256, false);
    int longestLen = 0;
    for (int start = 0, end = 0; end < s.size(); ++end) {
        if (exist[s[end]]) {
            while (s[start] != s[end]) {
                exist[s[start]] = false;
                ++start;
            }
            ++start;
        }
        exist[s[end]] = true;
        longestLen = max(longestLen, end - start + 1);
    }
    return longestLen;
}

/**
 * bug: 一定要认认真真跑一遍测试再去提交
 * line 53-56：while loop, it should be set exist[s[start]] = false, then ++start
 *             no need start < end condition
 */ 
 
 // time : O(n)
 // sapce : O(1)
 // only once traversal, fasest
 int lengthOfLongestSubstring_3(string s) {
     int longestLen = 0;
     vector<int> exist(256, -1);
     for (int start = 0, end = start; end < s.size(); ++end) {
         if (exist[s[end]] >= start) {
             start = exist[s[end]] + 1;
         }
         exist[s[end]] = end;
         longestLen = max(longestLen, end - start + 1);
     }
     return longestLen;
 }
