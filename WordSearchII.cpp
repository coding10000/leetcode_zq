/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. 
What kind of data structure could answer such query efficiently? 
Does a hash table work? Why or why not? How about a Trie? 
If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
*/

/*
Solution:
1. backtracking, dfs : TLE
2. 
*/

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  return findWords_1(board, words);
}
bool searchWord(vector<vector<char> >& board, const string& word, int row, int col, int len) {
    if (len == word.size()) return true;
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
    if (board[row][col] == '-' || board[row][col] != word[len]) return false;
    char tmp = board[row][col]; 
    // board 中间状态会被改变，所以不能用const
    board[row][col] = '-';
    bool up = searchWord(board, word, row - 1, col, len + 1);
    bool down = searchWord(board, word, row + 1, col, len + 1);
    bool left = searchWord(board, word, row, col - 1, len + 1);
    bool right = searchWord(board, word, row, col + 1, len + 1);
    // 一定要先恢复原来的值
    board[row][col] = tmp;
    // 然后再判断return true or false
    if (up || down || left || right) return true;
    return false;
}
vector<string> findWords_1(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() || board[0].empty() || words.empty()) {
        return vector<string>();
    }
    vector<string> res;
    for (int i = 0; i < words.size(); ++i) {
        // 要以board中的每个元素为初始值判断一遍：word 是否在board中
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (words[i][0] == board[r][c] && searchWord(board, words[i], r, c, 0)) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
    }
    return res;
}
