class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp1;
        for(char c : magazine){
            mpp1[c]++;
        }
        for(char c : ransomNote){
            if(mpp1[c] == 0){
                return false;
            }
            mpp1[c]--;
        }
        return true;   
    }
};