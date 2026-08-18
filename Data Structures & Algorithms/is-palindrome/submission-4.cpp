class Solution {
    char tolowerchar(char& x){
        if(x>='A' && x<='Z') return x+32;
        return x;
    }
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;

        while(i<=j){
            while(i<s.length() &&!(s[i]>='0' &&s[i]<='9')&& !(s[i]>='a'&&s[i]<='z') && !(s[i]>='A'&&s[i]<='Z')) i++;
            while(j>=0 &&!(s[j]>='0' &&s[j]<='9')&& !(s[j]>='a'&&s[j]<='z') && !(s[j]>='A'&&s[j]<='Z')) j--;
            if(tolowerchar(s[i])!=tolowerchar(s[j])){
                return false;
            }
                i++;
                j--;
        } 

        return true;
    }
};
