class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
     int n= hand.size();               
     if(n % groupSize  != 0)return false;
    
    map<int,int>mp;
    //  priority_queue<int, vector<int>, greater<int>>pq(hand.begin(),hand.end());//min_heap

    for(auto &it:hand){
        mp[it]++;
    }
    
    while(!mp.empty()){
        int cur=mp.begin()->first;

        for(int i=0; i<groupSize ;i++){
            int start=cur+i;
            if(mp[start]==0)return false;
            mp[start]--;
        
            if(mp[start]==0)mp.erase(start);
        }
    
    }

     return true;
    }
};

    //     vector<int>temp;
    //    while(!pq.empty()){
    //         int start=pq.top();
        
    //     for(int i=0; i<groupSize; i++){
    //         if(mp[start+i]==0)return false;
    //         mp[start+i]--;
    //         if(mp[start+i]==0 &&  )
    //     }
    //  }