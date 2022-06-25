class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      // if (nums.size() == 1) return true;
        int cnt = 0;
        for(int i=0;i<nums.size()-1;i++){
             if(cnt>1) return false;
            if(nums[i]>nums[i+1])
            {
                if(i==0 or nums[i-1]<=nums[i+1])
                    nums[i]=nums[i+1];
                else
                    nums[i+1]=nums[i];
                cnt++;
            }
        }
        if(cnt<=1) return true;
        return false;
    }
};