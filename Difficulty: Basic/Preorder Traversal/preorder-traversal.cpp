/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int>ans;
  void preorder(Node *root)
  {
      if(!root)
      return;
      
      ans.push_back(root->data);
      preorder(root->left);
      preorder(root->right);
      
  }
    vector<int> preOrder(Node* root) {
        // code here
        ans.clear();
        preorder(root);
        return ans;
        
    }
};