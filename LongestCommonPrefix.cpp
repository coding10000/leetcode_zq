/*
Longest Common Prefix 
Total Accepted: 50128 Total Submissions: 194829
Write a function to find the longest common prefix string amongst an array of strings.
*/

/*
Solution: (21:36-)
    1. use a string to compare with others, then find a min common substring
    2. more concise
*/

// more concise code
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty() || strs[0].empty()) {
        return string();
    }
    for (int i = 0; i < strs[0].size(); ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                return strs[0].substr(0, i);       
            }
        }
    }
    return strs[0];
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty() || strs[0].empty()) {
        return string();
    }
    int end = 0;
    for (int i = 0; i < strs[0].size(); ++i) {
        bool isExit = false;
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                isExit = true;
                break;
            }
        }
        if (isExit) break;
        end = i;
    }
    return strs[0].substr(0, end + 1);
}

/**
 * bug:
 * line 15: init, end = -1, not end = 0(表示默认第一个字符就是公共前缀);--> 一定要仔细！！！
 */ 
