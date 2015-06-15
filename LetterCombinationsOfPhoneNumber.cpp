/*
Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
see in https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order（字典序）, your answer could be in any order you want.
*/

/*
understanding:
    Combinations problem use generally backtracking.
    exclude 1 and 0, only 2-9
*/

/*
Solution: hash table + dfs/backtracking
   hash table : [2: abc, 3: def, ...]
   1. hash + dfs :
        cur : previous number's result. res : add into now number's result(before loop, res.clear())
   2. hash + backtracking :
        2 3 
      /
    a     b   c
  /       /   /
  def   def   def
*/

unordered_map<char, string> dict{{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
void combinations_1(const string& digits, int start, vector<string>& cur, vector<string>& res) {
    if (start == digits.size()) return;
    string match = dict[digits[start]];
    res.clear();
    for (int i = 0; i < match.size(); ++i) {
        if (cur.empty()) res.push_back(string{match[i]});
        for (int j = 0; j < cur.size(); ++j) {
            res.push_back(cur[j] + match[i]);
        }
    }
    cur = res;
    combinations_1(digits, start + 1, cur, res);
}
vector<string> letterCombinations_1(string digits) {
    vector<string> res;
    vector<string> cur;
    combinations_1(digits, 0, cur, res);
    return res;
}

void combinations_2(const string& digits, int start, string cur, vector<string>& res) {
    if (start == digits.size()) {
        res.push_back(cur);
        return;
    }
    string letter = dict[digits[start]];
    for (int i = 0; i < letter.size(); ++i) {
        combinations_2(digits, start + 1, cur + letter[i], res);
    }
}
vector<string> letterCombinations_2(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    combinations_2(digits, 0, "", res);
    return res;
}
vector<string> letterCombinations(string digits) {
    return letterCombinations_2(digits);
}
