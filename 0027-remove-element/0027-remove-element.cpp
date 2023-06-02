class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int res = 0; //this will be used to swap the elements to res idx , also this will be and len of array after removal of elements
        
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            //when ever we see a number , which is not the val , we place it int the idx res
            
            if(nums[i]!= val)
            {
                nums[res] = nums[i];
                res++;
            }
        }
        
        return res;
        
    }
};