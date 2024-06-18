class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {

        int n = profit.size();
        // create a max heap of pair of <profit and difficulty> //sorted on the
        // profit
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push(make_pair(profit[i], difficulty[i]));
        }

        int maxProfit = 0;

        // iterate throught the worker and take the job he can do
        int w = worker.size();

        // why do we need to sort worker array in reverse order, cos we need
        // highest potential guy to come first and check for the max profit job
        sort(worker.begin(), worker.end(), greater<int>());

        for (int i = 0; i < w; i++) {
            while (!pq.empty()) {
                pair<int, int> maxProfitJob = pq.top();

                if (worker[i] >= maxProfitJob.second) {
                    maxProfit =
                        maxProfit +
                        maxProfitJob
                            .first; // we dont pop out from pq , cos this same
                                    // job can be done by others also
                    break;
                }

                // take out this job , we cant do it
                pq.pop();
            }
        }

        return maxProfit;
    }
};