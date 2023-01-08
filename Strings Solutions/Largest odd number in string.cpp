class Solution {
public:
    string largestOddNumber(string num) {
        int len=num.length(), pos=-1;
        for(int i=len-1; i>=0; i--){
            if((int)(num[i]-'0')%2!=0){
                pos=i;
                break;
            }
        }
        if(pos==-1)return "";
        return num.substr(0, pos+1);
    }
};