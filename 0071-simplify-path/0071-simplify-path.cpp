class Solution {
public:

    // Time: O(N)
    // Space: O(N)
    string simplifyPath(string path) {
        vector<string> str_stack;
        stringstream ss(path);
        string curr_str;
        while (getline(ss, curr_str, '/')) {
            if (curr_str == "." || curr_str.empty()) {
                continue;
            } else if (curr_str == "..") {
                if (!str_stack.empty()) {
                    str_stack.pop_back();
                }
            } else {                            // valid directory name
                str_stack.push_back(curr_str);
            }
        }

        string simplified_path = "";
        for (string& curr_str : str_stack) {
            simplified_path += "/" + curr_str;
        }

        return simplified_path.empty() ? "/" : simplified_path;
    }
};