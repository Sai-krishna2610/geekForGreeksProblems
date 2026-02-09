class Solution {
  public:
    bool canAllocate(const vector<int>& arr, int maxPages, int k) {
        int studentCount = 1; // At least one student
        int currentSum = 0;

        for (int pages : arr) {
            if (pages > maxPages) {
                return false; // A single book exceeds maxPages, invalid allocation
            }

            if (currentSum + pages > maxPages) {
                // Allocate to a new student
                studentCount++;
                currentSum = pages;

                // If student count exceeds `k`, return false
                if (studentCount > k) {
                    return false;
                }
            } else {
                currentSum += pages; // Add pages to the current student
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) {
            return -1; // Not enough books for all students
        }

        // Define the binary search range
        int low = *max_element(arr.begin(), arr.end()); // Minimum possible maxPages
        int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible maxPages
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAllocate(arr, mid, k)) {
                result = mid; // Update result to the lower possible maxPages
                high = mid - 1;
            } else {
                low = mid + 1; // Increase the lower bound
            }
        }

        return result;
    }
};
