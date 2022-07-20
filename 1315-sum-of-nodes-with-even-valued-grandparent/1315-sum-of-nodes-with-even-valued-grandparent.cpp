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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        // we will create a hashmap that will store all our grand_parent_pointers to their respective grandchilds
        unordered_map<TreeNode*,TreeNode*>grand_parent_pointer;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            // this will ensure if the left->left and left->right is present if yes we fill store its both childs 
            // if possible
            if(node->left){
                q.push(node->left);
                if(node->left->left){
                    grand_parent_pointer[node->left->left]=node;
                }
                if(node->left->right){
                    grand_parent_pointer[node->left->right]=node;
                }
            }
            // this will ensure if the right->left and right->right is present which will have both the grandchild nodes
            if(node->right){
             q.push(node->right);
                if(node->right->right){
                    grand_parent_pointer[node->right->right]=node;
                }
                if(node->right->left){
                    grand_parent_pointer[node->right->left]=node;
                }
            }
        }
        for(auto it:grand_parent_pointer){
            if(it.second->val%2==0){
                ans+=it.first->val;
            }
        }
        return ans;
    }
};