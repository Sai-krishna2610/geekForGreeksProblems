class Solution {
  public:
 bool isPossible(vector<int>& arr, int maxAllowedSum, int k) {
        int subarrayCount = 1;
        int currentSum = 0;

        for (int num : arr) {
            if (currentSum + num > maxAllowedSum) {
                // Start a new subarray
                subarrayCount++;
                currentSum = num;
                
                // If we need more than k subarrays, it's not possible
                if (subarrayCount > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Start: The largest single element (a subarray must at least hold this)
        // End: The sum of all elements (one single subarray)
        int left = 0, right = 0;
        for (int num : arr) {
            left = max(left, num);
            right += num;
        }

        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(arr, mid, k)) {
                ans = mid;        // Try for an even smaller "largest sum"
                right = mid - 1;
            } else {
                left = mid + 1;   // The limit is too small, increase it
            }
        }
        return ans;
    }
};