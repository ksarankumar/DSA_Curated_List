class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        if(nums.empty() || nums.size() == 0)
            return 0;
        
        int n = nums.size();
        
        unordered_map<int,int> mp; // to store <prefixsumMod,freqency>
        mp[0] = 1; //init map : we've seen a zero prefixSumMod with frequency 1 at the start
        
        int prefixSum = 0;
        int count = 0;
        
        for(int i=0; i<n; i++)
        {
            //compute the prefix sum
            prefixSum = prefixSum + nums[i];
            
            // sum[i,j] = PSA[j] - PSA[i-1] , sum is divisable by k => (PSA[j] - PSA[i-1])%k = 0 => PSA[j]%k = PSA[i-1]%k
            
            int prefixSumMod = prefixSum % k;
            
            //handle negative numbers by adding k ; -3 % 5 = -3 -> -3+5 = 2
            
            if(prefixSumMod < 0)
                prefixSumMod = prefixSumMod + k;
            
            //check in the map , if prefixsumMod exists
            
            if(mp.find(prefixSumMod) != mp.end())
            {
                //increment the count by that much frequency
                count = count + mp[prefixSumMod];
            }
            
            //add to the map and increase the frequncy
            
            mp[prefixSumMod]++;
            
        }
        
        
        return count;
    }
};