class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        // sort the array and compare the adjacent elements
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        // we need to maintain the sorting order also need to ensure that no
        // adjacent elements are same, if we compare prev element with curr
        // element , curr element should be strictly greater, otherwise we need
        // to make operation
        for (int i = 1; i < n; i++) // ith element is current and i-1 is prev
        {

            if (nums[i - 1] >= nums[i]) {
                // how many operations do we need to do : (nums[i-1] - nums[i])
                // + 1 operations to make it a different number
                ans = ans + (nums[i - 1] - nums[i]) + 1;
                nums[i] = nums[i - 1] + 1; // add this operations to nums[i], we
                                           // always change nums[i]
            }
        }
 
        return ans;
       
    }
};