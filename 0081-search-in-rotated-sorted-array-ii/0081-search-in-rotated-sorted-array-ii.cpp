class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        
         int n = nums.size();
        int low = 0;
        int high = n-1;
        
        while(low <= high)
        {
            
            while(low < high && nums[low] == nums[low+1])
                low = low +1;
            
            while(low < high && nums[high] ==  nums[high-1])
                high = high -1;
            
            
            int mid = low + (high - low)/2;
            
            
            if(nums[mid] == target)
                return true;
            
            
            
            //if mid is left side sorted --> asc order 
            
            if(nums[low] <= nums[mid]) 
            {
                
                //if target lies in that half - left to mid

                if(nums[low] <= target && target<= nums[mid])
                {
                    //eliminate the right half and keep on seraching in left half
                    high = mid -1 ;
                }
                else
                {
                    low = mid +1 ;
                }
                
            } 
            else // if mid is right sorted
            {
                // if target lies in that half - mid to high
                if(nums[mid]<= target && target <= nums[high])
                {
                    //eliminate the left half , we want to go in the right half
                     
                    low = mid+1;
                    
                }
                else
                {
                    high = mid -1;
                }
                
            }
            
            
        }
        
        return false;
        
    }
};