class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set <string> us;
        int n = words.size();
        for(string s : words){
            string revS = s;
            reverse(revS.begin(), revS.end());
            if(us.find(s) == us.end() && us.find(revS) == us.end()){
                us.insert(s);
            }
        }
        return n - us.size();
    }
};
