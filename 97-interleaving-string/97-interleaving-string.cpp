class Solution {
public:
    unordered_map<string,bool>m;
    bool solve(string A, string B, string C,int a,int b,int c){
    string key=to_string(a)+"*"+to_string(b)+"*"+to_string(c);
    if(m.find(key)!=m.end()){
        return m[key];
    }
    if(c>=C.size()){
        if(a>=A.size() && b>=B.size()){
            return true;
        }
        else{
            return false;
        }
    }
    bool w=false,y=false;
    if(a<A.size() && A[a]==C[c]){
        w=solve(A,B,C,a+1,b,c+1);
    }
    if(w){
        return m[key]=w;
    }
    if(b<B.size() && B[b]==C[c]){
        y=solve(A,B,C,a,b+1,c+1);
    }
    return m[key]=y;
}
    bool isInterleave(string A, string B, string C) {
        if(A==""){
            return B==C;
        }
        if(B==""){
            return A==C;
        }
        if(C==""){
            return A=="" && B=="";
        }
        map<string,bool>m;
        return solve(A,B,C,0,0,0);
    }
};