class Solution {
public:
  static  bool sortcol(const vector<int>&v1,const vector<int>&v2){
       return v1[1]>v2[1];
     }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         for(auto it:boxTypes){
            for(auto vctr:it){
                cout<<vctr<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        sort(boxTypes.begin(),boxTypes.end(),sortcol);
        for(auto it:boxTypes){
            for(auto vctr:it){
                cout<<vctr<<" ";
            }
            cout<<endl;
        }
        int res=0;
       for(auto it:boxTypes){
           int unitsleft=min(truckSize,it[0]);
           res+=unitsleft*it[1];
           truckSize-=unitsleft;
       }
        return res;
    }
};