class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long first = nums[0]; //here we store numbers instead of index
        
        long second = LONG_MIN; //we want to find the max , so init with min ,and we are not sure if there exist a second and third number
        long third = LONG_MIN;
        
        int n = nums.size();
        //start from the first index as usual
        for(int i=1; i<n; i++)
        {
            if(nums[i] > first) //first max it self got challanged
            {
                third = second;
                second = first;
                first = nums[i];
            }
            else if (nums[i] < first && nums[i] > second) //second max got challanged
            {
                third = second;
                second = nums[i];
            }
            else if(nums[i] < second && nums[i] > third) //third max got challanged
            {
                third = nums[i];
            }
        }
        
        
        //if there is no distinct third max element , return the first max element
        
        return third == LONG_MIN ? first : third;
        
    }
};