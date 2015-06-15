/*
ZigZag Conversion 
The string "PAYPALISHIRING" is written in a zigzag pattern 
on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string 
and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/


string convert(string s, int numRows) {
    if (numRows == 0) return string();
    if (numRows == 1) return s;
    string res;
    int d = 2 * (numRows - 1);
    for (int i = 0; i < numRows; ++i) {
        int gap = d - 2 * i;
        for (int j = i; j < s.size(); j += d) {
            res.push_back(s[j]);
            if (gap == 0 || gap == d) continue;
            if (j + gap < s.size()) res.push_back(s[j + gap]);
        }
    }
    return res;
}

/**
 * bug: numRows == 0 and numRows == 1时会陷入死循环，必须特殊判断 
 */
