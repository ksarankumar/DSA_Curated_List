class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0, high = n-1;
        
        while( (low+1) <= n-2 && nums[low] < nums[low+1])
            low++;
        
        while( (high-1) >=1 && nums[high] < nums[high-1])
            high--;
        
        if(high == low)
            return low;
        else
            return -1;
        
    }
};