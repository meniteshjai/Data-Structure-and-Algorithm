class Solution {
public:
    string reorganizeString(string s) {
        int map[256]={0};
        for(int i=0;s[i];i++){
            map[s[i]]++;
        }
        char max_freq_char;
        int max_freq=INT_MIN;
        for(int i='a';i<='z';i++){
            if(map[i]>max_freq){
                max_freq=map[i];
                max_freq_char=i;
            }
        }
        if(max_freq>(s.size()+1)/2)
            return "";
        int index=0;
        while(max_freq >0 && index <s.size()){
            s[index]=max_freq_char;
            max_freq--;
            index +=2;
        }
        map[max_freq_char]=0;
        for(int i='a';i<='z';i++){
            while(map[i]>0){
                index=index>=s.size()?1:index;
                s[index]=i;
                map[i]--;
                index +=2;
            }
        }
        return s;
    }
};