class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int i=0;
        bool found=false;

        while(i<s.size()){
            if(s[i]==' '){
                i++;
            }
            else{
                break;
            }
        }

        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-')
                found=true;
            
            i++;
        }

        while(i<s.size()){
            if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' ||s[i]=='9'){
                if(ans>(INT_MAX-(s[i]-'0'))/10){
                    if(found)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
                ans=ans*10+(s[i]-'0');
            }
            else{
                break;
            }
            i++;
        }

        if(found)
            return -ans;
        
        else
        return ans;
    }
};