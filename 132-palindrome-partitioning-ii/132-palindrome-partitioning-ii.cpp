class Solution {
public:
    vector<int> dp;
	int isPali(string &s,int l,int r){
		while(l<r){
			if(s[l++]!=s[r--]) return false;
		}
		return true;
	}
	int solve(string &s,int pos,int n){
		if(pos>=n  || isPali(s,pos,n)) return 0;
		if(dp[pos]!=-1) return dp[pos];
		int ans=0,tmp=INT_MAX;
		for(int i=pos;i<n;i++){
			if(isPali(s,pos,i)){
				ans=1+solve(s,i+1,n);
				tmp=min(tmp,ans);
			}
		}
		return dp[pos] = tmp;
	}
	int minCut(string s) {
		dp.assign(s.size(),-1);
		return solve(s,0,s.size())-1;
    }
};