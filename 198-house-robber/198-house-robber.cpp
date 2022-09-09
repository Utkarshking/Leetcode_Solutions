class Solution {
    int f(int ind,vector<int>&arr,int dp[]){
        // time complexiy -->O(N)
        // space complexity -->O(N)
        
        if(ind==0) return arr[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=arr[ind]+f(ind-2,arr,dp);
        int non_pick=0+f(ind-1,arr,dp);
        return dp[ind]=max(pick,non_pick);
        
        // timc complexity --<O(N^2)
        // space complexity -->O(N)
        // if(ind==0) return arr[ind];
        // if(ind<0) return 0;
        // int pick=arr[ind]+f(ind-2,arr);
        // int nonpick=0+f(ind-1,arr);
        // return max(pick,nonpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return f(n-1,nums,dp);
    }
};