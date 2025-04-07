bool closeStrings(string word1, string word2) {
    if(word1.length() != word2.length()) return false;
    unordered_map<char, int> mp1, mp2;
    for(char c : word1) mp1[c]++;
    for(char c : word2) mp2[c]++;
    for(char c : word1) if(mp2.find(c) == mp2.end()) return false;

    unordered_map<int, int> freq1, freq2;
    for(auto& [k, v] : mp1) freq1[v]++;
    for(auto& [k, v] : mp2) freq2[v]++;

    return freq1 == freq2;
}
