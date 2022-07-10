class Solution {
public:
    int minPairSum(vector<int>& nums) {
     sort(nums.begin(),nums.end(),greater<int>());  
        cout<<endl;
         int ans=0;
        vector<int>res;
        int l=0,r=nums.size()-1;
        while(l<r){
            res.push_back(nums[l]+nums[r]);
            l++;
            r--;
        }
        // cout<<endl;
        return *max_element(res.begin(),res.end());
    }
};