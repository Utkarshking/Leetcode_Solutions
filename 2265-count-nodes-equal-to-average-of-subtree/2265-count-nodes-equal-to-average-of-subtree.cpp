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
public:
    // time complexity -->O(N^2)
    // space complexity-->O(1)
//     int returnsumheight(TreeNode* root,int &cnt){
//         if(!root) return 0;
//         cnt++;
//         int left=returnsumheight(root->left,cnt);
//         int right=returnsumheight(root->right,cnt);
//         return(root->val+left+right);
//     }
//     void helper(TreeNode* root,int &ans){
//         if(!root) return;
//         int cnt=0;
//         int avg=0;
//         avg=(returnsumheight(root,cnt)/cnt);
//         if(avg==root->val) ans++;
//         helper(root->left,ans);
//         helper(root->right,ans);
      
//         }
    // optimize-1
    // we can have pairs and can store the sum of the left subtree and rightsubtree as well
   pair<int,int> helper(TreeNode* root, int &ans){
        if(!root) return {0,0};
       // pair will calculate the sum and count of nodes 
       // ie.{sum_of_subtree,count_of_nodes_subtree}
        pair<int,int> left=helper(root->left,ans);
        pair<int,int> right=helper(root->right,ans);
       // counting the nodes and calculating the sum for the same
        int sum=left.first+right.first+root->val;
        int cnt=left.second+right.second+1;
        if(sum/cnt==root->val) ans++;
        return{sum,cnt};
       
       
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};