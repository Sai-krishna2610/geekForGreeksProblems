class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int N=prices.size();
        sort(prices.begin(),prices.end());
        int i=0;
        int j=N-1;
        int ans=0;
        while(i<=j)
        {
            ans+=prices[i];
            i++;
            j-=k;
        }
        vector<int>res;
        res.push_back(ans);
        i=N-1;j=0;
        ans=0;
        while(i>=j)
        {
            ans+=prices[i];
            i--;
            j+=k;
        }
        res.push_back(ans);
        return res;
    }
};