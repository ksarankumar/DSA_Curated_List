class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int n = heights.size();
        vector<int> expected = heights;
        sort(heights.begin(), heights.end());

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (heights[i] != expected[i]) {
                ans++;
            }
        }

        return ans;
    }
};