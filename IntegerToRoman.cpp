/*
Integer to Roman
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
题意理解：
1、罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）。
    eg. I, II, III, IV, V, VI, VII, VIII, IX, X, XI,....,XX,..XXX...XL...LX...LXX..
2、左减右加逻辑，以及右加不能超过三位，左减只能有1位。
*/

/**
 * Solution:
 * two vector(hash) + string
 * time : O(d)
 * space : O(1)
 */ 

string intToRoman(int num) {
    if (num <= 0) return string();
    vector<int> integer({1,4,5,9,10,40,50,90,100,400,500,900,1000});
    vector<string> roman({"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"});
    string res = "";
    // bug : from end(big) to start(small)!!!!
    //for (int i = 0; i < integer.size() && num; ++i) {
    for (int i = integer.size() - 1; i >= 0 && num; --i) {
        int r = num / integer[i];
        if (r) {
            while (r--) res += roman[i];
            num = num % integer[i];
        }
    }
    /* // more concise
    for (int i = integer.size() - 1; i >= 0; --i) {
        while (integer[i] <= num) {
            res += roman[i];
            num -= integer[i];
        }
    }
    return res;
    */
    return res;
}
