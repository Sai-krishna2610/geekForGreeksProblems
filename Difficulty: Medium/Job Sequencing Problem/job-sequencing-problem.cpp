class Solution {
public:
    int findParent(int x, vector<int> &parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++)
            jobs.push_back({profit[i], deadline[i]});
        sort(jobs.rbegin(), jobs.rend());
        int maxDead = *max_element(deadline.begin(), deadline.end());
        vector<int> parent(maxDead + 1);
        for (int i = 0; i <= maxDead; i++)
            parent[i] = i;

        int countJobs = 0, totalProfit = 0;
        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int availableSlot = findParent(d, parent);

            if (availableSlot > 0) {
                countJobs++;
                totalProfit += p;
                parent[availableSlot] = findParent(availableSlot - 1, parent);
            }
        }

        return {countJobs, totalProfit};
    }
};
