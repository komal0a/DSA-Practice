class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<pair<string,int>>qt;//word,length
        qt.push({beginWord,1});

        while(!qt.empty()){
            string word=qt.front().first;
            int len=qt.front().second;
            qt.pop();
            if(word==endWord)return len;
            for(int i=0; i<word.length();i++){
                for(char c='a';c<='z';c++){
                string str=word;
                str[i]=c;
                if(st.find(str)!=st.end()){
                    //found word
                    qt.push({str,len+1});
                    st.erase(str);
                }else continue;

                }
            }   
        }return 0;
    }
};