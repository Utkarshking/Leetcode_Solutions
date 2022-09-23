class Solution {
private:
    int f(vector<int>&arr){
         int prev = arr[0];
        int prev2 =0;
        int n=arr.size();
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
public:
    int rob(vector<int>& nums) {
        // we take two arrays
        // the first one will contain all the elements except the first element
        // the second one will contain all the elements except the last element
            vector<int>temp,temp1;
            int n=nums.size();
            int dp[1001]={0};
            if(n==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp.push_back(nums[i]);
            if(i!=n-1) temp1.push_back(nums[i]);
        }
        return max(f(temp),f(temp1));
        
        
    }
};