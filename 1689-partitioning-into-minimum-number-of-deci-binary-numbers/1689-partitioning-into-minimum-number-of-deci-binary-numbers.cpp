class Solution {
public:
    int minPartitions(string n) {
        int ma=0;
        int m=n.size();
        for(int i=0;i<m;i++){
            ma=max(ma,n[i]-'0');
        }
        return ma;
    }
};