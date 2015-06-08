/*
Question: Palindrome Partitioning 
Total Accepted: 39958 Total Submissions: 150281 
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

/**
in : string, empty?
out :
range : 
space :
other: 
*/

/**
 * Solution:
 * 1. broute force, backtracking(generally, return all possible solutions using backtracking), use dfs implements.
 * 3. dp, 
 */ 
 
vector<vector<string>> partition(string s) {
    //return partition_1(s);
    return partition_2(s);
}
//time: a string of n length, it has (n - 1) cut position, so enumarate it(cut or not), time complexity is O(2^n)
/*一个长度为n 的字符串，有n -􀀀 1 个地方可以砍断，每个地方可断可不断，因此复杂度为O(2n􀀀1)*/
//space: 
vector<vector<string> > partition_1(string s) {
    vector<vector<string> > res;
    vector<string> cur;
    partitionBacktracking(s, 0, cur, res);
    return res;
}
void partitionBacktracking(const string& s, int start, vector<string> cur, vector<vector<string> >& res) {
    if (s.size() == start) {
        res.push_back(cur);
        return;
    }
    for (int i = start; i < s.size(); ++i) {
        string sub = s.substr(start, i - start + 1);
        if (validPalindrome(sub)) {
            cur.push_back(sub);
            partitionBacktracking(s, i + 1, cur, res);
            cur.pop_back();
        }
    }
}
bool validPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end) {
        if (s[start] != s[end]) return false;
        ++start;
        --end;
    }
    return true;
}
/**
 * bug:
 * line 55: validPalindrome function name is written wrong
 */ 
 
 //time: O(n^2)
 //space: O(n^2)
 // why ????
 /*
         vector<vector<string> > res[size];
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                if (dp[i][j] == false) continue;
                string word = s.substr(i, j - i + 1);
                if (j == size - 1) {
                    res[i].push_back(vector<string>{word});
                } else {
                    for (auto iter : res[j+1]) {
                        iter.insert(iter.begin(), word);
                        res[i].push_back(iter);
                    }
                }
            }
        }
        return res[0];
 */
vector<vector<string> > partition_2(string s) {
    if (s.empty()) {
        return vector<vector<string> >();
    }
    int n = s.size();
    vector<vector<bool> > isPalindrome(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            isPalinrome[j][i] = (s[i] == s[j]) && (i - j < 2 && isPalinrome[j + 1][i - 1]);
        }
    }
    vector<vector<string> > res[n];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (isPalinrome[i][j] == false) continue;
            string sub = s.substr(i, j - i + 1);
            if (j == n - 1) {
                res[i].push_back(vector<string>({word}));
            } else {
                for (auto iter : res[j + 1]) {
                    iter.insert(iter.begin(), word);
                    res[i].push_back(iter);
                }
            }
        }
    }
    return res[0];
}
