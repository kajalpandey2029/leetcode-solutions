class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ans = false;
        unordered_map<int,int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){
                ans = true;
            }
        }
        return ans;   
    }
};