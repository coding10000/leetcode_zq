/*
Question: Longest Consecutive Sequence 
Total Accepted: 40425 Total Submissions: 137755 
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

/*
Solution:(8:26 - 8:41)
    1. hash table, space O(n), time : O(n)
        all elements store in a hash table, then loop: from every element, find its all consective elements, return max length
*/

int longestConsecutive(vector<int> &nums) {
    unordered_set<int> sets;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        sets.insert(nums[i]);
    }
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        if (sets.count(nums[i])) {
            int len = 0;
            int left = nums[i];
            while (sets.count(left)) {
                sets.erase(left);
                --left;
                ++len;
            }
            int right = nums[i] + 1;
            while (sets.count(right)) {
                sets.erase(right);
                ++right;
                ++len;
            }
            maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}
