// __define-ocg__
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1; // stores indices of '('
        stack<int> s2; // stores indices of '*'
        int varOcg = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                s1.push(i);
            else if (s[i] == '*')
                s2.push(i);
            else { // s[i] == ')'
                if (!s1.empty())
                    s1.pop();
                else if (!s2.empty())
                    s2.pop();
                else
                    return false;
            }
        }

        // Match remaining '(' with '*'
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() > s2.top()) return false; // '*' must be after '('
            s1.pop();
            s2.pop();
        }

        return s1.empty(); // if any unmatched '(' remain, return false
    }
};
