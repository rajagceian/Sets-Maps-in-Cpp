//**************** method - 1 ***************
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

//******************* method - 2 *******
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        vector <int> freq_s(26),freq_t(26);
        for(char c : s){
            freq_s[c - 'a']++;
        }
        for(char c : t){
            freq_t[c - 'a']++;
        }
        return freq_s == freq_t;
    }
};
