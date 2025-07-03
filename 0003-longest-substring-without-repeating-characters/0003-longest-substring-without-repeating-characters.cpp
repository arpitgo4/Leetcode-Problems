class Solution {
public:

    // Time: O(N)
    // Space: O(26) ~ O(1)

    int lengthOfLongestSubstring(string s) {
        unordered_multiset<char> char_set;

        int str_len = s.length();
        int max_substr_len = 0;
        int j = 0;
        for (int i = 0; i < str_len; i++) {
            char_set.insert(s[i]);
            while (j < i && char_set.count(s[i]) > 1) {
                char_set.erase(char_set.find(s[j]));
                j++;
            }

            max_substr_len = max(max_substr_len, i-j+1);
        }

        return max_substr_len;
    }
};