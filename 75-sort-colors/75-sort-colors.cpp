class Solution {
public:
    void sortColors(vector<int>& a) {
        vector<int>v(3,0);
        int n=a.size();
        for(int i=0;i<n;i++){
            v[a[i]]++;}
        int j=0;
        int p=0;
        while(j!=3){
            if(v[j]!=0){
                a[p]=j;
                v[j]-=1;
                p+=1;
        }
            else{
                j+=1;
        }
    }
    }
};