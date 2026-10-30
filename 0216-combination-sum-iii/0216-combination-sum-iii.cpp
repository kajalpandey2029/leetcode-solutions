class Solution {
public:
    vector<vector<int>> kajal;
    vector<int> p;
    void solve(int start, int k, int n){
        if(p.size() == k){
            if(n == 0){
                kajal.push_back(p);
            }
            return;
        }
        for(int i=start; i<=9; i++){
            if(i>n) break;
            p.push_back(i);
            solve(i+1, k, n-i);
            p.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return kajal;
    }
};