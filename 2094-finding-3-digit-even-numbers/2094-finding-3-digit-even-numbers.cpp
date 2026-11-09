class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        vector<int> ans;
        for(int d : digits) {
            freq[d]++;
        }
        for(int i = 100; i <= 998; i += 2) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;
            freq[a]--;
            freq[b]--;
            freq[c]--;
            if(freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0) {
                ans.push_back(i);
            }
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }
        return ans;
    }
};