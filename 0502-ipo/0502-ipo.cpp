class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        vector<pair<int, int>> works;
        // we need a combine of <captial,profit> in  a sorted order
        for (int i = 0; i < n; i++) {
            works.push_back(make_pair(capital[i], profits[i]));
        }

        sort(works.begin(), works.end()); // sorts the array based on the first
                                          // element of pair, ie capital

        int maximizedProfit = 0;

        // init max heap, cos we need to pick max profit
        priority_queue<int> pq;

        int i = 0; // iterate over our sorted works vector

        // we need to pick k jobs
        for (int j = 0; j < k; j++) {

            // there could be multiple jobs we can afford with the capital,  add
            // all profitable projects that we can affort with the capital
            // pointed by i
            while (i < n && works[i].first <= w) {
                pq.push(works[i].second);
                i++;
            }

            // if no project cant be funded due to insufficent fund , break out

            if (pq.empty()) {
                break;
            }

            // otherwise pick the project with max profit

            w = w + pq.top();
            pq.pop();
        }

        return w;
    }
};