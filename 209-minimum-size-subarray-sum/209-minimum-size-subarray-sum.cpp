class Solution {
public:
    bool blackBox(vector<int>&nums, int n, int target, int k) {
	//first find the first k size subarray sum
	int sum = 0;
	//sliding window problem solution
	for (int i = 0; i < k; i++) sum += nums[i];
	int maxi = sum;
	int l = 0;
	int r = k;
	while (r != n) {
		sum -= nums[l];
		l++;

		sum += nums[r];
		r++;
		maxi = max(maxi, sum);
	}
	return maxi >= target;
}
int minSubArrayLen(int target, vector<int>& nums) {
	int low = 1;
	int high = nums.size()+1;
	bool anspossible = false;
	while (low < high) {
		int mid = (low + high) / 2;
		if (blackBox(nums, nums.size(), target, mid) == true) {
			anspossible = true;
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	if (anspossible == true) return low;
	return 0;
}
};