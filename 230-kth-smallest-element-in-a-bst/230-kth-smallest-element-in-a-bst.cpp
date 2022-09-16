/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans;
    void f(TreeNode* root,vector<int>&vec){
        if(root==NULL) return;
        f(root->left,vec);
        vec.push_back(root->val);
        f(root->right,vec);
    }
    void inorder(TreeNode* root,int &cnt,int key){
        if(root==NULL) return;
        inorder(root->left,cnt,key);
        cnt++;
        if(cnt==key)   {
            ans=root->val;
            return;
        }
        inorder(root->right,cnt,key);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // time complexity -->O(N)
        // space complexity -->O(N)
        // vector<int>vec;
        // f(root,vec);
        // return vec[k-1];
        
        // apply inorder traversal
        int cnt=0;
         inorder(root,cnt,k);
        return ans;
    }
};