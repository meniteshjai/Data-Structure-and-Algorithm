class Solution {
public:
    string rotate(string &s){
        char temp=s[0];
        for(int i=0;i<s.size();i++){
            s[i]=s[i+1];
        }
        s[s.size()-1]=temp;
        return s;
    }
    bool rotateString(string s, string goal) {
        bool ans=false;
        for(int i=0;i<s.size();i++){
            if(rotate(s)==goal){
                ans=true;
            //    break;
            }
        }
        return ans;
    }
};