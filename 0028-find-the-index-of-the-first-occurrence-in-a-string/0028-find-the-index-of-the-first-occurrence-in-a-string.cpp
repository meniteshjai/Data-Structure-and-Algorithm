class Solution {
public:
    int strStr(string haystack, string needle) {
        // using librery function.

        // int index=haystack.find(needle);
        // return index;

        int id=-1;
        int i=0;
        int j=0;
        int st=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size()){
                    id=st;
                    break;
                }
            }
            else{
                st++;
                i=st;
                j=0;
            }
        }
        return id;
    }
};