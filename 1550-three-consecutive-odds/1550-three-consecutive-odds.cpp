class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        // we just need a variable count , we iterate through the array and
        // increment count if we find odd numbers , the moment we find a even no
        // count will reset to 0

        int count = 0;
        int n = arr.size();
        bool ans = false;

        for (int i = 0; i < n; i++) {

            if (arr[i] % 2 != 0) // odd
            {
                count++;
            } else {
                count = 0;
            }

            if (count == 3) {
                ans = true;
                break;
            }
        }

        return ans;
    }
};