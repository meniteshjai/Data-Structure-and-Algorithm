class Solution {
public:
    string check(string& s,int i,int j){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        i++;
        j--;
        return s.substr(i,j-i+1);
    }
    string longestPalindrome(string s) {
        string ans="";

        for(int centre=0;centre<s.size();centre++){
            
            string odd=check(s,centre,centre);
            
            string even="";

            if(centre+1<s.size()){
                even=check(s,centre,centre+1);
            }
            if(odd.length()> ans.length()){
                ans=odd;
            }
            if(even.length()>ans.length()){
                ans=even;
            }   
        } 
        return ans;  
    }
};