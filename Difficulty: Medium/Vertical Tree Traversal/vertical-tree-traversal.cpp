/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:

    void findWidth(Node* root, int &left, int &right, int pos) {
        if (!root)
            return;

        left = min(left, pos);
        right = max(right, pos);

        findWidth(root->left, left, right, pos - 1);
        findWidth(root->right, left, right, pos + 1);
    }

    vector<vector<int>> verticalOrder(Node *root) {

        if (!root)
            return {};

        int left = 0, right = 0;
        findWidth(root, left, right, 0);

        int width = right - left + 1;
        vector<vector<int>> ans(width);
        queue<pair<Node*, int>> q;
        q.push({root, -left});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            Node* node = front.first;
            int col = front.second;
            ans[col].push_back(node->data);
            if (node->left)
                q.push({node->left, col - 1});
            if (node->right)
                q.push({node->right, col + 1});
        }
        return ans;
    }
};