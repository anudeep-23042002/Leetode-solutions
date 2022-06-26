class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> candidates, int i, int target, vector<int> temp, int n){
        if( i == n){
            if(target == 0) ans.push_back(temp);
            return;
        }
        if(target == 0) {
            ans.push_back(temp); 
            return;
        }
        
        if(target - candidates[i] >=0 ){
            temp.push_back(candidates[i]);
            solve(candidates, i+1, target - candidates[i], temp, n);
            temp.pop_back();
            int index = i;
            while(index < n-1){
                if(candidates[index] != candidates[index + 1]){
                    break;
                }
                index++;
            }
            solve(candidates, index+1, target, temp, n);
        }
        else{
            solve(candidates, i+1, target, temp, n);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, 0, target, temp, candidates.size());
        return ans;
    }
};

