class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        //p[i] ^ p[i+1] = a[i+1] , sub i = i-1
        //p[i-1] ^ p[i] = a[i]
        
        int n = pref.size();
        
        vector<int> ans;
        
        ans.push_back(pref[0]);
        
        for(int i=1; i<n; i++)
        {
            ans.push_back(pref[i] ^ pref[i-1]);
        }
        
        return ans;
        
    }
};




    
