// 93. Restore IP Addresses
class Solution {
public:
    void solve(vector<string>& path, vector<vector<string>>& temp, int n, string& s, int i) {
        if (path.size() > 4) return;

        if (path.size() == 4 && i == n) {
            temp.push_back(path);
            return;
        }

        for (int j = i; j < n && j - i < 3; j++) {
            string part = s.substr(i, j - i + 1);

            if ((part[0] == '0' && part.length() > 1) || stoi(part) > 255) continue;

            path.push_back(part);
            solve(path, temp, n, s, j + 1);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> path;
        vector<vector<string>> temp;
        vector<string> results;
        int n = s.length();

        solve(path, temp, n, s, 0);

        for (auto& part : temp) {
            string ip = part[0] + "." + part[1] + "." + part[2] + "." + part[3];
            results.push_back(ip);
        }
        return results;
    }
};
