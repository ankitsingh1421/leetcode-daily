
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(m);

        unordered_map<int, int> mp;

        int left = 0, right = 0;

        for (auto &query : q) {

            int start = query.first - x;
            int end = query.first;
            int idx = query.second;

            while (right < logs.size() &&
                   logs[right][1] <= end) {

                mp[logs[right][0]]++;
                right++;
            }
            while (left < right &&
                   logs[left][1] < start) {

                int server = logs[left][0];

                mp[server]--;

                if (mp[server] == 0) {
                    mp.erase(server);
                }

                left++;
            }
            ans[idx] = n - mp.size();
        }

        return ans;
    }
};
