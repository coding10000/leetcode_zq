/*
Question: Longest Palindromic Substring 
Total Accepted: 52444 Total Submissions: 252838
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

/*
Soluton:
1. brute force: search palindrome bound from i to two sides or from i, i + 1 to two sides   *****
2. dp, the method is same as palindrome partition II, but TLE
3. make less sapce O(n), other is same as 2.
4. same as 1, Time O(n^2), Space O(1) (actually much more efficient than 2 & 3)
5. Time O(n), Space O(n) (Manacher's Algorithm)  why????   ********
*/

string longestPalindrome(string s) {
	return longestPalindrome_1(s);
}

// time: O(n^2)
// space : O(1)
string longestPalindrome_1(string s) {
	string longestStr;
	for (int i = 0; i < s.size(); ++i) {
		searchLongestPalindrome(s, i, i, longestStr);
		searchLongestPalindrome(s, i, i + 1, longestStr);
	}
	return longestStr;
}
void searchLongestPalindrome(const string& s, int left, int right, string& longestStr) {
	int n = s.size();
	while (left >= 0 && right < n && s[left] == s[right]) {
		--left;
		++right;
	}
	++left;
	--right;
	if (longestStr.size() < (right - left + 1)) {
		longestStr = s.substr(left, right - left + 1);
	}
}
/**
 * bug:
 * in searchLongestPalindrome, it must be have (++left; --right) in the last, 
 * so make sure that left,right is the right bound of longest palindrome 
 */ 

// time : O(n^2)
// space : O(n^2)
string longestPalindrome_2(string s) {
	int n = s.size();
	int start = 0;
	int end = 0;
	vector<vector<bool> > isPalindrome(n, vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			isPalindrome[j][i] = s[i] == s[j] && (i - j < 2 || isPalindrome[j + 1][i - 1]);
			if (isPalindrome[j][i] && (i - j) > end - start) {
				start = j;
				end = i;
			}
		}
	}
	return s.substr(start, end - start + 1);
}
/**
 * bug : TLE
 */ 
 
 // time : O(n^2)
 // sapce ：O(n)
 string longestPalindrome_3(string s) {
 	int n = s.size();
 	pair<int, int> res(0, 0);
 	vector<vector<bool> > isPalindrome(2, vector<bool>(n, false));
 	int cur = 0;
 	int last = 1;
 	for (int i = n - 1; i >= 0; --i) {
 		cur = !cur;
 		last = !last;
 		for (int j = i; j < n; ++j) {
 			isPalindrome[cur][j] = s[i] == s[j] && (j - i < 2 || isPalindrome[last][j - 1]);
 			if (isPalindrome[cur][j] && j - i > res.second - res.first) {
 				res = make_pair(i, j);
 			}
 		}
 	}
 	return s.substr(res.first, res.second - res.first + 1);
 }
 /**
  * bug
  * TLE
  */ 
  
 // time : O(n^2)
 // space : O(1)
 string longestPalindrome_4(string s) {
    int N = s.size();
    pair<int, int> res = make_pair(0, 0); // start pos and length
    for (int i = 0; i < N; ++i) { // i represents the start position
        for (int j = 0; j <= 1; ++j) { // j represents odd or even
            bool isP = true;
            for (int k = 0; i-k >= 0 && i+j+k < N && isP; ++k) { // k represents 0...k(i, i + j)k ...0
                isP = s[i-k] == s[i+j+k];
                if (isP && j+1+k*2 > res.second)
                    res = make_pair(i-k, j+1+k*2);
            }
        }
    }
    return s.substr(res.first, res.second);
}

// time : O(n)
// space : O(n)
string method5(string s) {
    int N = s.size();
    int dp[2 * N + 1];
    int id = 0, mx = 0;
    for (int i = 0; i < 2 * N + 1; ++i)
    {
        int j = 2 * id - i;
        dp[i] = mx > i ? min(dp[j], mx - i) : 1;
        int left = i - dp[i], right = i + dp[i];
        for (; left >= 0 && right <= 2 * N; left--, right++)
        {
            if (left % 2 == 0 || s[left/2] == s[right/2]) // padding or char
                dp[i]++;
            else
                break;
        }
        if (i + dp[i] > mx)
        {
            id = i;
            mx = id + dp[id];
        }
    }
    int res = 0;
    for (int i = 1; i < 2 * N + 1; ++i)
        if (dp[i] > dp[res])
            res = i;
    return s.substr(res / 2 - (dp[res] - 1) / 2, dp[res] - 1);        
}
