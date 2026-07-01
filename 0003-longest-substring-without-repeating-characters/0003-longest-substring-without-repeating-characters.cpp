class Solution {
public:

    // Time: O(N)
    // Space: O(N)
    int lengthOfLongestSubstring(string str) {
        unordered_set<char> char_set;

        int str_len = str.length();
        int j = 0;
        int max_substr_len = 0;
        for (int i = 0; i < str_len; i++) {
            if (char_set.find(str[i]) != char_set.end()) {
                while (str[j] != str[i]) {
                    char_set.erase(str[j]);
                    j++;
                }

                char_set.erase(str[j]);
                j++;
            }

            char_set.insert(str[i]);
            max_substr_len = max(max_substr_len, i-j+1);
        }

        return max_substr_len;
    }
};