class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        // if hand size is not divisible by group size we cant form a group
        if (n % groupSize != 0)
            return false;

        // we need to keep the freq map in a sorted fashion to compare

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        for (auto it : mp) {
            cout << it.first << ":" << it.second << "\n";
        }

        int count = groupSize - 1;

        for (int i = 0; i < groupSize; i++) {

            int numberToCheck = mp.begin()->first;

            while (groupSize--) {

                if (mp.find(numberToCheck + 1) == mp.end()) {
                    return false;
                }

                mp[numberToCheck]--;

                if (mp[numberToCheck] == 0) {
                    mp.erase(numberToCheck);
                }

                numberToCheck = numberToCheck + 1;
            }
        }

        return true;
    }
};