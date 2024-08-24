class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        // we need to identify the the no of elements in the level where label
        // is present , we call it last level value since its a complete binary
        // tree 0th level contains 2^0 = 1 element 1st level contains 2^1 = 2
        // elements

        // 2^x >= label , x >= log2(label)

        vector<int> ans;

        ans.push_back(label);

        while (label != 1) {
         
            int lastlevel = log2(label); // find out the last level

            int lastlevelvalue =
                pow(2, lastlevel); // last level value is nothing but no of
                                   // elements in the last level of label

            // compute start = last level value , end = 2 * last level value  - 1 (2*n-1 property)
            int start = lastlevelvalue;
            int end = (2 * lastlevelvalue) - 1;

            // we need to compute the complement of label

            // end - label = complement  - start
            // complement = end - label + start
            // complement = (3 * last level value) - 1 - label

            int complement = (3 * lastlevelvalue) - 1 - label;

            // now using this complement find the partent of the label , in
            // normal traversal tree parent of node is n/2

            int parent = complement / 2;
            
            ans.push_back(parent);

            // for the next iteration current parent will become label

            label = parent;
        }

        // reverse the ans
        reverse(ans.begin(), ans.end());
        return ans;
    }
};