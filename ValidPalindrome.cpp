/*
Valid Palindrome 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

/*
understanding : 
1. only consider alphanumeric characters;
2. ignore cases
possible special case:
1. empty string ==> yes!
*/

/*
Solution : two pointers
*/

bool isPalindrome(string s) {
    if (s.empty()) return true;
    int start = 0;
    int end = s.size() - 1;
    while (start <= end) {
        while (start <= end && !isalnum(s[start])) ++start;
        while (start <= end && !isalnum(s[end])) --end;
        if (start > end) return true;
        if (tolower(s[start]) != tolower(s[end])) return false;
        ++start;
        --end;
    }
    return true;
}

// bug
// consider alphanumeric, not alpha
// line 29,30: modify isalpha as isalnum
