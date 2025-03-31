class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map <int,int> mp;
        for(int ele : arr){
            mp[ele]++;
        }
        unordered_set <int> freq;
        for(auto &pair : mp){
            freq.insert(pair.second);
        }
        return mp.size() == freq.size();
    }
};
