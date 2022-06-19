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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // ans variable taken to store the width of the tree
        int ans=0;
        // we will take the queue of the pair to store the current node and its index
        queue<pair<TreeNode*,int>>q;
        // initially pushing the root node and its index which is zero
        q.push({root,0});
        // looping around the queue for the traversal
        while(!q.empty()){
            int size=q.size();
            // to make the current node (i) to zer0
            int min_index=q.front().second;
            // taken to store the first index and the last index for the calculation 
            // of the width of the tree which is the answer
            int first,last;
            // taking for iterating over the queue values
            for(int i=0;i<size;i++){
                long long current_index=q.front().second-min_index;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=current_index;
                if(i==size-1) last=current_index;
                if(node->left){
                    q.push({node->left,current_index*2+1});
                }
                if(node->right){
                    q.push({node->right,2*current_index+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};