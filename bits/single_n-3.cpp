class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here
            int xorr=nums[0];
            int n= nums.size();
            for(int i=1;i<n;i++){
                xorr^=nums[i];
            }

            int rightmost=xorr& ~( xorr-1);
            int b1=0; int b2=0;
            for(int i=0; i<n;i++){
                if(nums[i] & rightmost){
                    b1^=nums[i];
                }
                else{
                    b2^=nums[i];
                }
            }
        if (b1 > b2) swap(b1, b2);
        return {b1, b2};
		}
};