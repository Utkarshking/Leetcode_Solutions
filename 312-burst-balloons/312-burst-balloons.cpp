class Solution {
    private:
        int func(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
            if(i>j) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
             int maxi=INT_MIN;
            for(int ind=i;ind<=j;ind++){
                int cost=arr[i-1]*arr[ind]*arr[j+1]+func(i,ind-1,arr,dp)+func(ind+1,j,arr,dp);
                maxi=max(maxi,cost);
            }
            return dp[i][j]=maxi;
        }
public:
    int maxCoins(vector<int>& nums) {
        int size=nums.size();
        nums.push_back(1);
        vector<vector<int>>dp(size+1,vector<int>(size+1,-1));
        nums.insert(nums.begin(),1);
        return func(1,size,nums,dp);
    }
};