class Solution {
public:
    static bool comp(string a,string b){
        string p=a+b;
        string q=b+a;
        return stol(p)>stol(q);
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>v;
        for(int i=0;i<n;i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),comp);
        string s="";
        if(v[0][0]=='0'){
            return "0";
        }
        for(auto i:v){
            s=s+i;
        }
        return s;
    }
};