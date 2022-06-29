class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
                        [] (auto &a, auto &b) {
                            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; 
                        });
        for (int i = people.size() - 2; i >= 0; --i){
            rotate(people.begin() + i, people.begin() + i + 1, people.begin() + i + 1 + people[i][1]);
        }
        return people;
    }
};