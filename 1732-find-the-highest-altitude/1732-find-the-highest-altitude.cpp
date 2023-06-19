class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int ans = 0;
        
        int altitudeGain = 0;
        
        int n = gain.size();
        
        for(int i=0; i<n; i++)
        {   
            altitudeGain = altitudeGain + gain[i];
            ans = max(ans,altitudeGain);
        }
        
        return ans;
        
    }
};