/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
    bool p_pathrecursion(TreeNode* root,TreeNode* p,vector<TreeNode*>&p_path){
            if(root==NULL) return false;
            p_path.push_back(root);
            if(root->val==p->val) return true; 
        if(p_pathrecursion(root->left,p,p_path)or p_pathrecursion(root->right,p,p_path) ) return true;
        p_path.pop_back();
        return false;
    }
    bool q_pathrecursion(TreeNode* root,TreeNode* q,vector<TreeNode*>&q_path){
        if(root==NULL) return false;
        q_path.push_back(root);
        if(root->val==q->val) return true;
        if(q_pathrecursion(root->left,q,q_path)or q_pathrecursion(root->right,q,q_path)) return true;
        q_path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // approach 1 :-
        // having two arrays of using node to root path and then eventually we can 
        //  traverse
        vector<TreeNode*>p_path;
        vector<TreeNode*>q_path;
        p_pathrecursion(root,p,p_path);
        q_pathrecursion(root,q,q_path);
        // for(auto it:p_path){
        //     cout<<it->val<<" ";
        // }
        // cout<<endl;
        // for(auto it:q_path){
        //     cout<<it->val<<" ";
        // }
        // cout<<endl;
         TreeNode* node=new TreeNode();
        int size=0;
        if(p_path.size()==q_path.size()){
            size=p_path.size();
        }
        else if(p_path.size()>q_path.size()){
            size=q_path.size();
        }
        else{
            size=p_path.size();
        }
        cout<<p_path[0]->val;
        for(int i=0;i<size;i++){
            if(p_path[i]->val==q_path[i]->val){
              node=p_path[i];         
            }
        }
        return node;
    }
};