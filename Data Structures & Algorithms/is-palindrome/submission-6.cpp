class Solution {
public:
    bool isPalindrome(string s) {
        string ref;
        for(int i=0; i<s.size(); i++){
            if(s[i]<48 || (s[i]>57 && s[i]<65 ) || (s[i]>90 && s[i]<97) || s[i]>122){
                continue;
            }else{
                ref.push_back(s[i]);
            }
        }
        for (int i=0; i<ref.size(); i++){
            ref[i]=tolower(static_cast<unsigned char>(ref[i]));
        }
        for(int i=0; i<ref.size(); i++){
            cout<<ref[i];
        }
        int i=0; int j=ref.size()-1;
        bool ans=true;
        while(i<=j){
            if(ref[i]!=ref[j]){
                ans=false;
                break;
            }
            i++;
            j--;
        }
        return ans;
    }
};
