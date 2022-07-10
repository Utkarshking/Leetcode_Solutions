class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       vector<int>left(n+1,1);
        vector<int>right(n+1,1);
        // traverse from left to right to check the slope and also calculate the number 
        // of candies you have to offer
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        // similarly from right to left to check the slope and also calcultae the number of 
        // candies you have to offer 
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) 
                right[i]=right[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }   
};