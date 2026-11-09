class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) available.insert(i);
        // min-heap of (finish time, server id)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> cnt(k, 0);

        for (int i = 0; i < (int)arrival.size(); ++i) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) continue;
            auto it = available.lower_bound(i % k);
            if (it == available.end()) it = available.begin();
            int s = *it;
            available.erase(it);
            cnt[s]++;
            busy.push({(long long)arrival[i] + load[i], s});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; ++i)
            if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};
