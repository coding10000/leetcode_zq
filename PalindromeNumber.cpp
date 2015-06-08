/**
Question: Palindrome Number
Total Accepted: 59657 Total Submissions: 200513
Determine whether an integer is a palindrome. Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem.
*/

/**
in: int, positive or negative, range
out:
space: without extra sapce
other limit: 
*/

/**
 * Solution
 * 1. first counting the digits of the number, then compare from two sides to center
 * 2. Reverse the number, then check to see if x == reverse(x).
 * 3. Recursion (interesting but a little hard to understand).
 */ 

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome_1(x);
        // return isPalindrome_2(x);
        // return isPalindrome_3(x);
};

//time : O(d)
//extra space : O(1) 
bool isPalindrome_1(int x) {
        if (x < 0) return false;
        int d = 1;
        while (d <= x / 10) {
            d = d * 10;
        }
        while (x) {
            if (x / d != x % 10) {
                return false;
            }
            x = (x % d) / 10;
            d = d / 100;
        }
        return true;
    }
}
/** 
 * solution 1 bug
 * line 39:  d = d / 100; every time. d should be divided by 100, not 10
 * line 47: if we can use /, then don't use *, because it can be overflow
 *          while (d * 10 <= x) // TLE
 *          while (d <= x / 10) // right
 */
// time : O(d)
// space : O(1)
bool isPalindrome_2(int x) {
    if (x < 0) return false;
    return x == reverse(x);
}
int reverse(int x) {
    long long res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x = x / 10;
    }
    if (res >= INT_MAX) return -1;
    return res;
}
/**
 * Solution 2 bug
 * use long long res, avoiding overflow
 */ 
 bool isPalindrome_3(int x, int& y) {
    if (x < 0) return false;
    if (x == 0) return true;
    if (isPalindrome_3(x / 10, y) && x % 10 == y % 10) {
        y = y / 10;
        return true;;
    }
    return false;
}
