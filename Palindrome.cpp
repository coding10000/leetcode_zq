/**
Solution: Palindrome Number
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

class Solution {
public:
    bool isPalindrome(int x) {
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
};

/** 
 * bug
 * line 32:  d = d / 100; every time. d should be divided by 100, not 10
 * line 24: if we can use /, then don't use *, because it can be overflow
 *          while (d * 10 <= x) // TLE
 *          while (d <= x / 10) // right
 */
