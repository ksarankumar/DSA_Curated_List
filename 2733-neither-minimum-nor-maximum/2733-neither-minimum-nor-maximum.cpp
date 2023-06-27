class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        
        if(nums.empty() || nums.size() == 0)
            return -1;
        
        int n = nums.size();
        
        if(n<=2) //if we have single element or two elements 
            return -1 ; 
        
        int a = min(nums[0],nums[1]);
        int b = max(nums[0],nums[1]);
        int c = nums[2];
        
        if(a<c && c<b)   // a c b : c is in between a and b,c can't be maximum or minimum
            return c;
        
        //c a b 
        
        if(c<a)
            return a;
        
        //a b c
        
        if(b<c)
            return b;
        
        return -1;
        
    }
};