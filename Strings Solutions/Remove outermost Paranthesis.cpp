class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s==""){
            return s;
        }
        string ans="";
        int count=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' && count++>0){
                ans+=s[i];
            }
            else if( s[i]==')' && count-->1){
                ans+=s[i];
            }
        }
        return ans;
    }
};