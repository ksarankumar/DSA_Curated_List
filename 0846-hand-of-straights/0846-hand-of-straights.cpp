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

        // if hand of straight is formed properly then all numbers will be used
        // loop till our ordered map is not empty

        while (!mp.empty()) {

            // get the top most element form the map
            int currentElement = mp.begin()->first;

            // try to form a group , how many times do we neeed to iterate to
            // form a group? groupSize times

            for (int i = 0; i < groupSize; i++) {

                // check if currentElement+i is present , its not
                // currentElement+1

                if (mp.find(currentElement + i) ==
                    mp.end()) // couldn't find , simply return
                {
                    return false;
                }

                mp[currentElement + i]--; // cos we used one occurences

                // if freq become 0 we can remove it from the map

                if (mp[currentElement + i] == 0) {
                    mp.erase(currentElement + i);
                }
            }
        }

        return true;
    }
};