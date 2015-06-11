/*
Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

/*
Solution: 整体思路是外层循环遍历n, 内层循环遍历当前字符串
1. 直接用string类型，intToChar ==> c + '0' (出了点小bug)
2. 使用stringstream
*/

string countAndSay_1(int n) {
    if (n <= 0) {
        return string();
    }
    sring res = "1";
    string prev;
    for (int i = 2; i <= n; ++i) {
        int c = 0;
        char key = ' ';
        prev = res;
        prev.push_back('#');
        for (int j = 0; j < prev.size(); ++j) {
            if (key == ' ') {
                key = prev[j];
                ++c;
            } else if (key == prev[j]) {
                ++c;
            } else {
                // bug
                res.push_back(c + '0');
                res.push_back(key);
                key = prev[j];
                c = 1;
            }
        }
    }
    return res;
}

/**
 * bug ;
 *                  // error : 这种写法表示 c(1) + '0' + key('1') = 49 + 49 = 98!!
                    // res += c + '0' + key;
                    // 即： string s = ""; s += 'c' ==> s = "c"; s += '1' + '1' ==> s = "b"(98)
                    // 每次只能+一个字符
 */ 
 
 // more concise code
    string countAndSay(int n) {
        if (n <= 0) {
            return string();
        }
        string res = "1";
        for (int i = 2; i <= n; ++i) {
            stringstream ss;
            int count = 1;
            res.push_back('#');
            for (int j = 1; j < res.size(); ++j) {
                if (res[j - 1] == res[j]) {
                    ++count;
                } else {
                    ss << count << res[j - 1];
                    count = 1;
                }
            }
            ss >> res;
        }
        return res;
    }
