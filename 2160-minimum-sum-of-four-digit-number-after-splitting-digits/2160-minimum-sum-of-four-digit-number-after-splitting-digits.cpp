class Solution {
public:
    int minimumSum(int n) {
        vector<int>digits(4,0);
        for (int i = 0; i < 4; ++i, n /= 10) digits[i] = n % 10; 
        sort(digits.begin(),digits.end());
        return 10*(digits[0]+digits[1])+digits[2]+digits[3];
    }
};