/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*>q;
        vector<int>ans;
        // if(root)
        // return ans;
        q.push(root);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            ans.push_back(temp->data);
        }
        return ans;
    }
};