class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> ans;
        if (mat.empty()) return ans;

        int row = mat.size(), col = mat[0].size();
        int top = 0, bottom = row - 1, left = 0, right = col - 1;

        while (left <= right && top <= bottom) {
            // Print the top row
            for (int j = left; j <= right; j++)
                ans.push_back(mat[top][j]);
            top++;

            // Print the right column
            for (int i = top; i <= bottom; i++)
                ans.push_back(mat[i][right]);
            right--;

            if (top <= bottom) {
                // Print the bottom row
                for (int j = right; j >= left; j--)
                    ans.push_back(mat[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                // Print the left column
                for (int i = bottom; i >= top; i--)
                    ans.push_back(mat[i][left]);
                left++;
            }
        }

        return ans;
    

    }
};
