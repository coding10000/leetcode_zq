/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example, 
Given s = "Hello World",
return 5.
*/

/*
understanding:
    1. only have upper/lower-case alphabets, empty space 
    2. last word doesn't exist, return 0
that is,
    words is split by empty space
for exmaple:
    '      ' all empty spaces ==> 0
    'hello world ' ==> 5, empty spaces in the end are not be calculated
*/


// bug:

// question description is not clear : int the end, the empty sapce string is not calculated

/*
Solution : from end to start, from the first empty space to end, the string is the last word
*/

int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    while (end >= 0 && s[end] == ' ') --end;
    int res = 0;
    while (end >= 0 && s[end] != ' ') {
        ++res;
        --end;
    }
    return res;
}
