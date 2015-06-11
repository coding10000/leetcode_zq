/*
String to Integer (atoi)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.
Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
(去掉字符串前面的空字符，从第一个非空字符开始。)
（判断正负号）
The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.
（遇到非数字字符之后就返回）
If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.
（没有有效数字的话返回0）
If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
（越界，返回INT_MAX，INT_MIN）
*/

int myAtoi(string str) {

}
