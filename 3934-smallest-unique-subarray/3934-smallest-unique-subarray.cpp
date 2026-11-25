class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {

            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] +
                              cmp(sa[i - 1], sa[i]);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }


        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        vector<int> lcp(n, 0);

        int k = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0)
                continue;

            int j = sa[r - 1];

            while (i + k < n &&
                   j + k < n &&
                   nums[i + k] == nums[j + k]) {
                k++;
            }

            lcp[r] = k;

            if (k > 0)
                k--;
        }

        int ans = n;

        for (int r = 0; r < n; r++) {

            int leftLCP = (r > 0) ? lcp[r] : 0;
            int rightLCP = (r + 1 < n) ? lcp[r + 1] : 0;

            int maxLCP = max(leftLCP, rightLCP);

            int uniqueLength = maxLCP + 1;

            int remaining = n - sa[r];

            if (uniqueLength <= remaining) {
                ans = min(ans, uniqueLength);
            }
        }

        return ans;
    }
};
