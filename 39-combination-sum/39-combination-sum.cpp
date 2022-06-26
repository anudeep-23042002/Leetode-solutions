class Solution {
public:
    void solve(vector<int> &A, int sum,vector<vector<int>>&v,vector<int>&d,int j){
         if(sum==0){
             v.push_back(d);
             return;
         }
        if(sum<0){
            return;
        }
         for(int i=j;i<A.size();i++){
             if(A[i]<=sum){
                 d.push_back(A[i]);
                 solve(A,sum-A[i],v,d,i);
                 d.pop_back();
             }
         }
        
         return;
    }
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        vector<vector<int>>v;
        vector<int>d;
        sort(A.begin(),A.end());
        solve(A,B,v,d,0);
        return v;
    }
};