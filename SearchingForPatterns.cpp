/*
Background: search word in text
1. Naive Pattern Searching
2. KMP
*/

// naive pattern searching( |word| <= |text|)
// time : O(n2 * (n1 - n2 + 1))
int countOccur(const string& text, const string& word) {
    int count = 0;
    int n1 = text.size();
    int n2 = word.size();
    for (int i = 0; i < n1 - n2 + 1; ++i) {
        if (text[i] == word[0]) {
            int j = 0;
            for (j = 0; j < n2; ++j) {
                if (word[j] != text[i + j]) break; 
            }
            if (j == n2) ++count;
        }
    }
    return count;
}
/*
Analysis:
What is the best case?
The best case occurs when the first character of the pattern is not present in text at all.

txt[]  = "AABCCAADDEE"
pat[] = "FAA"
The number of comparisons in best case is O(n).

What is the worst case ?
The worst case of Naive Pattern Searching occurs in following scenarios.
1) When all characters of the text and pattern are same.

txt[] = "AAAAAAAAAAAAAAAAAA"
pat[] = "AAAAA".
2) Worst case also occurs when only the last character is different.

txt[] = "AAAAAAAAAAAAAAAAAB"
pat[] = "AAAAB"
Number of comparisons in worst case is O(m*(n-m+1)). 
*/

// KMP （可以参考:http://blog.csdn.net/v_july_v/article/details/7041827, great and clear!!!）
// Time complexity of KMP algorithm is O(n) in worst case.
