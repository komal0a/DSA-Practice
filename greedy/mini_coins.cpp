class Solution{
	public:
    int solve(vector<int>& coins, int amount,int i){
        if(i==0){
        if( amount % coins[0]==0)return  amount/coins[0];
        return 1e9;
    }
    

    int take=1e9;
    if(amount>=coins[i])
     take=1+solve(coins,amount-coins[i],i);

    int non_take=solve(coins,amount,i-1);

    

    return min(take,non_take);
}
	int MinimumCoins(vector<int>& coins, int amount) {
       int res= solve(coins,amount,coins.size()-1);
       return res>= 1e9 ? -1 :res;
    }
};