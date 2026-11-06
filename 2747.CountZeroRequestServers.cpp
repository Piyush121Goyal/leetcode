class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        // Sort logs by time and process queries offline in increasing order,
        // keeping a sliding window of logs inside [query - x, query].
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(),
             [&](int a, int b) { return queries[a] < queries[b]; });

        vector<int> requestCount(n + 1, 0);
        vector<int> answer(q);
        int activeServers = 0;
        int left = 0, right = 0;
        int m = logs.size();

        for (int idx : order) {
            int end = queries[idx];
            int start = end - x;

            // Expand the window to include logs with time <= end.
            while (right < m && logs[right][1] <= end) {
                if (requestCount[logs[right][0]]++ == 0) {
                    activeServers++;
                }
                right++;
            }

            // Shrink the window to drop logs with time < start.
            while (left < right && logs[left][1] < start) {
                if (--requestCount[logs[left][0]] == 0) {
                    activeServers--;
                }
                left++;
            }

            answer[idx] = n - activeServers;
        }

        return answer;
    }
};
