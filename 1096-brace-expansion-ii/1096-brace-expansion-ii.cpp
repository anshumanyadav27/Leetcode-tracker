class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> result;
        set<string> current;
        current.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                for (auto x : current)
                    result.insert(x);

                current.clear();
                current.insert("");
                i++;
            }
            else if (s[i] == '{') {
                i++;

                set<string> temp = solve(s, i);

                i++; // skip '}'

                set<string> newCurrent;

                for (auto a : current) {
                    for (auto b : temp) {
                        newCurrent.insert(a + b);
                    }
                }

                current = newCurrent;
            }
            else {
                string ch = "";
                ch += s[i];

                set<string> newCurrent;

                for (auto x : current) {
                    newCurrent.insert(x + ch);
                }

                current = newCurrent;
                i++;
            }
        }

        for (auto x : current)
            result.insert(x);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        vector<string> result;

        for (auto x : ans)
            result.push_back(x);

        return result;
    }
};