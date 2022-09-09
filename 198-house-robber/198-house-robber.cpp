class Solution {
    int f(int ind,vector<int>&arr,int dp[]){
        // time complexiy -->O(N)
        // space complexity -->O(N)
        // memoization
        if(ind==0) return arr[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=arr[ind]+f(ind-2,arr,dp);
        int non_pick=0+f(ind-1,arr,dp);
        return dp[ind]=max(pick,non_pick);
        
        // recursion
        // timc complexity --<O(N^2)
        // space complexity -->O(N)
        // if(ind==0) return arr[ind];
        // if(ind<0) return 0;
        // int pick=arr[ind]+f(ind-2,arr);
        // int nonpick=0+f(ind-1,arr);
        // return max(pick,nonpick);
    }
public:
    int rob(vector<int>& arr) {
        // int dp[n+1];
        // memset(dp,-1,sizeof(dp));
        // return f(n-1,nums,dp);

        // space optimisation
        int n=arr.size();
         int prev = arr[0];
        int prev2 =0;
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
    }
};