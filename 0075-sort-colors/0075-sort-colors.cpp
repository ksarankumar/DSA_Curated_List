class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        
        while(mid <= high) // mid->high un known region , while there is a unknown region , examin nums[mid]
        {
            
            switch(nums[mid])
            {
                case 0:
                      swap(nums,mid,low);
                      low++;
                      mid++;
                    break;
                    
                case 1:
                      mid++;
                     break;
                    
                case 2:
                      swap(nums,high,mid);
                      high--;
                      break;
                    
            }
                        
            
        }
        
    }
    
    void swap (vector<int>& nums , int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};