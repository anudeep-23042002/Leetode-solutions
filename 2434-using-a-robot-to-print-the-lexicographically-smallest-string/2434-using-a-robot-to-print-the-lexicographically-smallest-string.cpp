class Solution {
public:
    string smallindex(string s,int j,int n){
        char c=s[j];
        int r=j;
        for(int i=j;i<n;i++){
            if(s[i]=='a'){
                r=i;
                break;
            }
            else if(c>s[i]){
                c=s[i];
                r=i;
            }
        }
        return s.substr(j,r+1);
    }
    string robotWithString(string s) {
        string ans;
        stack<char> st;
        int n = s.size();
        vector<char> mi(n + 1, 'z');
        for (int i = n - 1; ~i; i--) mi[i] = min(mi[i + 1], s[i]);
        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            while (!st.empty() && st.top() <= mi[i + 1]) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};