/**
Question: valid palindrome
Total Accepted: 55154 Total Submissions: 250988 
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
 */ 

/**
 * in : string, maybe empty? include all ASCII characters?
 * out : 
 * range :
 * sapce : extra space?
 * other : empty string is a palindrome
 */ 

/**
 * Solution 
 * 1. compare from two sides to center
 * 
 */ 
 
bool isPalindrome(string s) {
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            while (start <= end && !isalnum(s[start])) ++start;
            while (start <= end && !isalnum(s[end])) --end;
            if (start <= end && tolower(s[start]) != tolower(s[end])) return false;
            ++start;
            --end;
        }
        return true;
    }
}
/**bug
 * judge alphanumeric: int isalnum ( int c ); Check if character is alphanumeric
 * upper to lower:int tolower ( int c );Convert uppercase letter to lowercase 
 *                int toupper ( int c ); Convert lowercase letter to uppercase
 * line 40 : in the last, forget to return true!!!
 */ 
