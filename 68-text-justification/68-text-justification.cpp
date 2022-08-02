class Solution {
public:
    string set(vector<string>v,int m,int ma){
        if(m-1==ma){
            string s="";
            int n=v.size();
            for(int i=0;i<n-1;i++){
                s=s+v[i]+' ';
            }
            s=s+v[n-1];
            return s;
        }
        int x=ma-m;
        int n=v.size()-1;
        if(n==0){
            string s="";
            s=s+v[0];
            ma-=(v[0].size());
            while(ma>0){
                s=s+' ';
                ma--;
            }
            return s;
        }
        int a=x%n;
        x=x/n;
        // cout<<x<<" "<<a<<" "<<m<<" "<<ma<<endl;
        string p="";
        for(int i=0;i<x;i++){
            p=p+' ';
        }
        string s="";
        for(int i=0;i<n;i++){
            s=s+v[i]+p+' ';
            if(a>=0){
                s=s+' ';
                a--;
            }
        }
        return s+v[n];
        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int m=0;
        vector<string>ans;
        vector<string>v;
        int y=0;
        for(int i=0;i<words.size();i++){
            int k=words[i].size();
            if(m-1==maxWidth){
                ans.push_back(set(v,m,maxWidth));
                v.clear();
                m=0;
            }
            else if((m+k-1)>=maxWidth){
                ans.push_back(set(v,m,maxWidth));
                v.clear();
                m=0;
            }
            v.push_back(words[i]);
            m+=(k+1);
        }
        int n=v.size();
        m=maxWidth;
        if(n>0){
            string s="";
            for(int i=0;i<n-1;i++){
                m=m-(v[i].size()+1);
                s=s+v[i]+' ';
            }
            s=s+v[n-1];
            m-=(v[n-1].size());
            while(m>0){
                s=s+' ';
                m--;
            }
            ans.push_back(s);
        }
        return ans;
    }
};