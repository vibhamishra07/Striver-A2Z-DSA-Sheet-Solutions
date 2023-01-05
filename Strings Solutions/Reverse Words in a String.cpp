class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string ch="";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ' && ch!=""){
                st.push(ch);
                ch="";
            }else if(s[i]!=' '){
                ch+=s[i];
            }
            if(i==s.length()-1 && s[i]!=' '){
                st.push(ch);
                ch="";
            }
        }
        ch="";
        while(!st.empty()){
            ch+=st.top();

            //This is for not adding space after last word
            if(st.size()!=1){
                ch+=" ";
            }
            st.pop();
        }
        return ch;
    }
};