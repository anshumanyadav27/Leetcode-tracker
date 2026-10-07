class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string str = q.front();
            q.pop();

            int count = 0;
            bool valid = true;

            for (char c : str) {
                if (c == '(')
                    count++;
                else if (c == ')') {
                    count--;
                    if (count < 0) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && count == 0) {
                ans.push_back(str);
                found = true;
            }

            if (found)
                continue;

            for (int i = 0; i < str.size(); i++) {
                if (str[i] != '(' && str[i] != ')')
                    continue;

                string temp = str.substr(0, i) + str.substr(i + 1);

                if (visited.find(temp) == visited.end()) {
                    visited.insert(temp);
                    q.push(temp);
                }
            }
        }

        return ans;
    }
};