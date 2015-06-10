/*
Roman to Integer
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

/*
Solution:
1. hash table + string
*/

int romanToInt(string s) {
    unordered_map<char, int> dict({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i < s.size() - 1 && dict[s[i]] < dict[s[i + 1]]) {
            res -= dict[s[i]];
        } else {
            res += dict[s[i]];
        }
    }
    return res;
}
