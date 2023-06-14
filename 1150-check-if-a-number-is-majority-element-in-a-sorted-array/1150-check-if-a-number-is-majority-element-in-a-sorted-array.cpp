class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        
        if(nums.empty() || nums.size() == 0)
            return false;
        
        int n = nums.size();
       
        //find the starting index of the target using binary search , if target not present then return -1
        
        int index = findFirstIndex(nums,target);
        
        if(index == -1)
            return false;
    
        // if the index + n/2 the element is taget , then we can surely say that the majority element . corner case : check for OOB for the index
        
        if( index + (n/2) < n && nums[index + n/2] == target)
        {
            return true;
        }
        else
            return false;
    }
    
    
      int findFirstIndex(vector<int>& nums, int target)
    {
     
        int low = 0;
        int high = nums.size()-1;
        int index = -1;
        
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[mid] >= target)
            {
                high = mid-1;
                index = mid;
            }
            else
            {
                low = mid+1;
            }
        }
          
        return index;
        
    }
    
  
};