class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string st=strs[0];
        for(auto s: strs){
            int size;
            string myst;
            if(st.size()<=s.size()){
               size=st.size();
               myst=st;
            }else{
                myst=s;
            }
            int i=0;
            for(; i<size; i++){
                if(st[i]!=s[i]) break;
            }
            st=s.substr(0, i);
        }
        return st;
    }
};