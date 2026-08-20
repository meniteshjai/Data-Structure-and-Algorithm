class Solution {
public:
    int minutes(string &time){
        int hr=stoi(time.substr(0,2));
        int min=stoi(time.substr(3,2));
        return 60*hr+min;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>m;
        int mini=INT_MAX;

        for(int i=0;i<timePoints.size();i++){
            m.push_back(minutes(timePoints[i]));
        }
        sort(m.begin(),m.end());
        for(int i=0;i<m.size()-1;i++){
            mini=min(mini,m[i+1]-m[i]);
        }
        int i=0;
        int ans=m[i]+1440-m[m.size()-1];
        mini=min(mini,ans);
        return mini;
    }
};