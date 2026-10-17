class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int max_len=0;
        int i=0; int j=0;
        while(j<s.size()){
            freq[s[j]-'A']++;
            auto max_it=max_element(freq.begin(), freq.end());
            int checker=(j-i+1)-*max_it;
            if(checker>k && i<s.size()){
                while((j-i+1)-*max_element(freq.begin(), freq.end())>k){
                    freq[s[i]-'A']--;
                    i++;
                }
            }
            max_len=max(max_len, (j-i+1));
            j++;
        }
        return max_len;
    }
};
