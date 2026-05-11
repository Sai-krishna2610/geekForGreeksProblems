// User function Template for C++

class Solution {
  public:
  vector<int>ans;
  queue<Node*> q;
    vector<int> largestValues(Node* root) {
        // code here
        if(!root)
        return ans;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();int temp11=INT_MIN;
            while(s--)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                temp11=max(temp11,temp->data);
                
            }
            ans.push_back(temp11);
            
        }
        return ans;
    }
};