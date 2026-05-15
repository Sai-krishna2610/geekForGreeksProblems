/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    public:
    void find(Node *root, int &l,int pos)
    {
        if (root==NULL)
        {
            return;
        }
        l=max(pos,l);
        find(root->left,l,pos+1);
        find(root->right,l,pos);
    }
    void findDiag(Node* root,int l, vector<vector<int>>&ans)
    {
        if (root==NULL)
        {
            return;
        }
        ans[l].push_back(root->data);
        findDiag(root->left,l+1,ans);
        findDiag(root->right,l,ans);
    }
    vector<int> diagonal(Node *root)
    {
       int l=0;
       find(root,l,0);
       vector<vector<int>>ans(l+1);
       findDiag(root,0,ans);
       vector<int>temp;
       for(int i=0;i<ans.size();i++)
       {
           for(int j=0;j<ans[i].size();j++)
           {
               temp.push_back(ans[i][j]);
           }
       }
       return temp;
    }
};