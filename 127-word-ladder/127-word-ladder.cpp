class Solution {
public:
    bool diff(string a,string b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                count++;
            }
            if(count>1){
                return false;
            }
        }
        return true;
    }
    int ladderLength(string beginword, string endword, vector<string>& wordList) {
        if(beginword==endword){
            return 0;
        }
        int count=0;
        bool f=true;
        int n=wordList.size();
        vector<int>v(n,0);
        queue<string>q;
        for(int i=0;i<n;i++){
            if(wordList[i]==endword){
                f=false;
                break;
            }
            if(wordList[i]==beginword){
                q.push(beginword);
                v[i]=1;
            }
            
        }
        if(f){
            return 0;
        }
        if(q.empty()){
            q.push(beginword);
        }
        while(!q.empty()){
            int y=q.size();
            for(int s=0;s<y;s++){
                string a=q.front();
                q.pop();
                if(a==endword){
                    return count+1;
                }
                for(int i=0;i<n;i++){
                    if(v[i]==0 && diff(wordList[i],a)){
                        v[i]=1;
                        q.push(wordList[i]);
                    }
                }
            }
            count++;
        }
        return 0;
    }
};