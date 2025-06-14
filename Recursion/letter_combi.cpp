
// 17. Letter Combinations of a Phone Number
class Solution {
public:
   vector<string>result
   void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {
        
        if(idx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        
       char ch = digits[idx];//2 of 23
        string str = mp[ch];//abc
            
        for(int i = 0; i<str.length(); i++) {//abc, def
            
            //Do
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);//i+1. i is increased not idx, so that it goes to next
            temp.pop_back();
            
        }
        
    }


  vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        
        mp['2'] =  "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string temp = "";
        
        solve(0, digits, temp, mp);
        
        return result;
    }
};
//               ""
//        /      |       \
//      a        b        c
//    / | \     /|\      /|\
//  ad ae af bd be bf cd ce cf
