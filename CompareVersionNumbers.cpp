/*
Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
Credits:
*/

/*
理解题意：考察string
    1. 末尾可能为0, .
    2. 1. = 1.0
    3. if version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
*/

/*
Solution :
1. my method, code is so lengthy
2. concise code : 二重循环，outer loop 循环整个串，inner loop循环一个个版本号
*/

int compareVersion_1(string version1, string version2) {
    if (version1[version1.size() - 1] != '.') version1.push_back('.');
    if (version2[version2.size() - 1] != '.') version2.push_back('.');
    // use stringstream, it can be easy to make string to in
    int i = 0;
    int j = 0;
    int end1 = version1.size() - 1;
    int end2 = version2.size() - 1;
    stringstream ss1;
    stringstream ss2;
    while (i <= end1 || j <= end2) {
        if (i > end1) {
            ss1 << '0';
            --i;
        }
        if (j > end2) {
            ss2 << '0';
            --j;
        }
        if (version1[i] == '.' && version2[j] == '.') {
            int v1 = 0, v2 = 0;
            ss1 >> v1;
            ss2 >> v2;
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
            ss1.clear();
            ss2.clear();
            ++i;
            ++j;
            continue;
        }
        if (version1[i] != '.') {
            ss1 << version1[i++];
        }
        if (version2[j] != '.') {
            ss2 << version2[j++];
        }
    }
    return 0;
}

int compareVersion_2(string version1, string version2) {
    int n1 = version1.size();
    int n2 = version2.size();
    int i = 0, j = 0;
    while (i < n1 || j < n2) {
        // 使用long long 防止溢出
        long long v1 = 0;
        while (i < n1 && version1[i] != '.') {
            v1 = v1 * 10 + version1[i++] - '0';
        }
        i++;
        long long v2 = 0;
        while (j < n2 && version2[j] != '.') {
            v2 = v2 * 10 + version2[j++] - '0';
        }
        j++;
        if (v1 > v2) return 1;
        if (v1 < v2) return -1;
    }
    return 0;
}
