class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using T = tuple<long long, int, int>; // (freeTime, weight, index)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> freeQ; // (weight, index)
        priority_queue<T, vector<T>, greater<>> busy;
        for (int i = 0; i < (int)servers.size(); i++) freeQ.push({servers[i], i});

        vector<int> ans(tasks.size());
        long long time = 0;
        for (int j = 0; j < (int)tasks.size(); j++) {
            time = max(time, (long long)j);
            if (freeQ.empty()) time = get<0>(busy.top());
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, i] = busy.top(); busy.pop();
                freeQ.push({w, i});
            }
            auto [w, i] = freeQ.top(); freeQ.pop();
            ans[j] = i;
            busy.push({time + tasks[j], w, i});
        }
        return ans;
    }
};
