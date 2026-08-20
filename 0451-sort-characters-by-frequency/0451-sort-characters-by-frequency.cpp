class Solution {
public:
    static bool comperator(pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    }

    string frequencySort(string s) {
        vector<int>freq(256,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }

        vector<pair<char,int>>arr;
        for(int i=0;i<256;i++){
            if(freq[i]>0){
                arr.push_back({char(i),freq[i]});
            }
        }
        sort(arr.begin(),arr.end(),comperator);

        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=string(arr[i].second,arr[i].first);
        }
        return ans;
    }
};