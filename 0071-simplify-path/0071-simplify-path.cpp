class Solution {
public:

    // Time: O(N)
    // Space: O(N)
    string simplifyPath(string path) {
        stack<string> str_stack;
        string curr_str;
        for (int i = 0; i < path.length(); i++) {
            char curr_char = path[i];
            if (curr_char == '/') {
                if (curr_str != "") {
                    str_stack.push(curr_str);
                    curr_str = "";
                }
            } else {
                curr_str += curr_char;
            }
        }

        if (curr_str != "") {
            str_stack.push(curr_str);
        }

        int par_dir_cnt = 0;
        stack<string> ordering_stack;
        while (!str_stack.empty()) {
            string curr_str = str_stack.top();
            str_stack.pop();

            if (curr_str == "..") {
                par_dir_cnt++;
                continue;
            } else if (curr_str == ".") {
                continue;
            }

            if (par_dir_cnt != 0) {
                par_dir_cnt--;
                continue;
            }

            if (curr_str != "") {
                ordering_stack.push(curr_str);
            }
        }

        string simplified_path = "";
        while (!ordering_stack.empty()) {
            string curr_str = ordering_stack.top();
            ordering_stack.pop();

            simplified_path += "/" + curr_str;
        }

        return simplified_path == "" ? "/" : simplified_path;
    }
};