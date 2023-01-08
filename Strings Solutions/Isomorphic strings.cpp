class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>fmp;
        unordered_map<char, bool>smp;
        for(int i=0; i<s.length(); i++){
            if(((!smp[t[i]]) && ((fmp[s[i]] && fmp[s[i]] == t[i]) || (!fmp[s[i]]) )) || (smp[t[i]] && fmp[s[i]]==t[i])){
                fmp[s[i]]=t[i];
                smp[t[i]]=true;
            }else{
                return false;
            }
        }
        return true;
    }
};