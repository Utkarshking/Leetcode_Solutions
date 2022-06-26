class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int maxi=0;
       int n = cardPoints.size();
        vector<int>cummulativesumfrombeg(n+1,0);
        vector<int>cummulativesumfromend(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
            cummulativesumfrombeg[i+1]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=cardPoints[i];
            cummulativesumfromend[i]=sum;
        }
        reverse(cummulativesumfromend.begin(),cummulativesumfromend.end());
        // int answer=0;
        for(int i=0;i<=k;i++){
            maxi=max(maxi,cummulativesumfrombeg[i]+cummulativesumfromend[k-i]);
        }
        return maxi;
    }
};