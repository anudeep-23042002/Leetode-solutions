class Solution {
public:
    static bool comp(vector<int>A,vector<int>B){
        return A[1]>B[1];
    }
    int maximumUnits(vector<vector<int>>& boxtypes, int trucksize) {
        sort(boxtypes.begin(),boxtypes.end(),comp);
        int ma=0,i=0;
        while(trucksize>=0 && i<boxtypes.size()){
            if(trucksize>=boxtypes[i][0]){
                ma=ma+(boxtypes[i][0]*boxtypes[i][1]);
                trucksize-=boxtypes[i][0];
            }
            else{
                ma=ma+(trucksize*boxtypes[i][1]);
                trucksize=0;
            }
            i++;
        }
        return ma;
    }
};