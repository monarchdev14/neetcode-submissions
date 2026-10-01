class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        unordered_set<char> mp;
        int max_len=0;
        int j=0;
        for(int i=0; i<s.size(); i++){
            while(mp.contains(s[i])){
                mp.erase(s[j]);
                j++;
            }
            mp.insert(s[i]);
            max_len=max(max_len, i-j+1);
        }
        return max_len;
    }
};
