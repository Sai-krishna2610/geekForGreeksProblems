class Solution {
  public:
    int findMin(int N) {
        // code here
        vector<int>coins{10,5,2,1};
        vector<int>an;
        int i=0;
        while(N)
        {
            int count=N/coins[i];
            while(count--){
               an.push_back(coins[i]); 
            }
            N%=coins[i];
            i++;
        }
        return an.size();
    }
};