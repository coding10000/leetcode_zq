/*
Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
Solution:
  1. from end to start(比较容易错)
  2. reverse + add + reverse
*/

string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    string res;
    int r = 0;
    while (i >= 0 || j >= 0) {
        if (i >= 0) {
            r += a[i] - '0';
            --i;
        } 
        if (j >= 0) {
            r += b[j] - '0';
            --j;
        }
        // bug 1:
        // res = '0' + r % 2 + res;
        // 转换成字符之后才能加操作
        res = static_cast<char>('0' + r % 2) + res;
        r = r / 2;
    }
    res = static_cast<char>('0' + r % 2) + res;
    // bug2:
    // 最后一步去掉前面的所有0: 以防"0000"的前面全0情况
    int start = 0;
    while (res[start] == '0' && start < res.size() - 1) ++start;
    return res.substr(start);
}

// more concise
  string addBinary(string a, string b) {
      int i = a.size() - 1;
      int j = b.size() - 1;
      string res;
      int r = 0;
      while (i >= 0 || j >= 0) {
          if (i >= 0) {
              r += a[i] - '0';
              --i;
          } 
          if (j >= 0) {
              r += b[j] - '0';
              --j;
          }
          res = static_cast<char>('0' + r % 2) + res;
          r = r / 2;
      }
      if (r % 2) res = static_cast<char>('0' + r % 2) + res;
      if (res[0] == '0') return "0";
      return res;
  }


