class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if(nums.size()==0) return 0;
        // int left=0;
        // int right=1;
        // for(right=1;right<nums.size();right++){
        //     if(nums[left]!=nums[right]) left++;
        //     nums[left]=nums[right];
        // }
        // return left+1;
        // again a approach using an unordered_map can be done
        unordered_map<int,int>mpp;
        // took an extra vector to take the elements out from it 
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mpp[nums[i]]==0)
                ans.push_back(nums[i]);
            mpp[nums[i]]++;
        }
        nums=ans;
        return ans.size();
    }
};