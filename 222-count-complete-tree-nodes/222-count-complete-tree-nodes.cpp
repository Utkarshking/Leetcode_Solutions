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
    int  recursion(TreeNode* root,int cnt){
        // inorder traversal
        // if(!root) return;
        // if(root->left) recursion(root->left,cnt);
        // cnt++;
        // if(root->right) recursion(root->right,cnt);
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            // cnt+=size;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left){
                    cnt++;
                q.push(current->left);
                }
                if(current->right){
                    cnt++;
                    q.push(current->right);
                }
            }
        }
        return cnt+1;
    }
    int countNodes(TreeNode* root) {
        // int cnt=0;
        // int nodes=recursion(root,cnt);
        // return nodes;
        if(!root) return 0;
        int lh=leftheighttree(root);
        int rh=rightheighttree(root);
        if(lh==rh)  return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int leftheighttree(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int rightheighttree(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
};