/*
Question: Palindrome Partitioning II 
Total Accepted: 31980 Total Submissions: 163570
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/*
Solution:
typical dynamic programming
function : cuts[i] = min{cuts[j] + str(j + 1...i)}
start state : cuts[0] = 1;
return state : return cuts[n]
*/

// time : O(n^2)
// space : O(n^2)
int minCut(string s) {
    int n = s.size();
    vector<int> cuts(n + 1, 0);
    cuts[0] = -1;
    vector<vector<bool> > canCut(n, vector<bool>(n, false));
    for (int i = 1; i <= n; ++i) {
        cuts[i] = i - 1;
        for (int j = i; j >= 1; --j) {
            // j...i
            canCut[j - 1][i - 1] = (s[i - 1] == s[j - 1]) && (i - j < 2 || canCut[j][i - 2]);
            if (canCut[j - 1][i - 1]) {
                cuts[i] = min(cuts[i], cuts[j - 1] + 1);
            }
        }
    }
    return cuts[n];
}
/**
 * bug:
 * init state : cuts[0] = -1, cuts[i] = i - 1. because the string of n length, its max cuts is n - 1
 * eg. a ==> 0; ab ==> 1
 */ 

// reduce extra space: O(n)
// ???
    int minCut_2(string s) {
        int n = s.size();
        vector<int> cuts(n + 1);
        vector<bool> canCut(n, true);
        cuts[n] = -1;
        for (int i = n - 1; i >= 0; --i) {
            cuts[i] = cuts[i + 1] + 1;
            for (int j = n - 1; j >= i; --j) {
                canCut[j] = (s[i] == s[j]) && (j - i < 2 || canCut[j - 1]);
                if (canCut[j]) {
                    cuts[i] = min(cuts[i], cuts[j + 1] + 1);
                }
            }
        }
        return cuts[0];
    } 
