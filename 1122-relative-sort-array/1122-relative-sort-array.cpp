class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr1[i]]++;
        }

        vector<int> ans;
        int m = arr2.size();

        for (int i = 0; i < m;
             i++) // we are sure that all elements in arr2 are in arr1
        {
            int count = mp[arr2[i]];

            while (count--) {
                ans.push_back(arr2[i]);
            }

            mp.erase(arr2[i]);
        }

        while (!mp.empty()) {
            auto it = mp.begin();

            int count = it->second;

            while (count--) {
                ans.push_back(it->first);
            }

            mp.erase(it);
        }

        return ans;
    }
};