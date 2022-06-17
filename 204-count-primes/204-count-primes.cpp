class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool>v(n+1,true);
        v[1]=false;
        v[2]=true;
        v[3]=true;
        for (int i=2; i*i<=n;i++) {
			if (v[i]){
				for (int j=i*i; j<=n; j+=i) {
					v[j]=false;
				}
			}
		}
        for(int i=1;i<n;i++){
            if(v[i]){
                count++;
            }
        }
        return count;
    }
};