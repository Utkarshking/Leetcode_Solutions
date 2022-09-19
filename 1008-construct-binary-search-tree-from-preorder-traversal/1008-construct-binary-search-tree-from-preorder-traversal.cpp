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
    private:
        TreeNode* buildbst(vector<int>&arr,int &index,int high){
            if(index==arr.size() or arr[index]>high) return NULL;
            TreeNode* temp=new TreeNode(arr[index++]);
            temp->left=buildbst(arr,index,temp->val);
            temp->right=buildbst(arr,index,high);
            return temp;
        }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return buildbst(preorder,index,INT_MAX);
    }
};