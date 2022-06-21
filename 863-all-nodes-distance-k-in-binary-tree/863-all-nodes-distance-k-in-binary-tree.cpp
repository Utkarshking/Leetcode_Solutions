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
    void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track,
                    TreeNode* target){
        // // we can have a bfs traversal for marking up the parent pointers
        // queue<TreeNode*>q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* current=q.front();
        //     q.pop();
        //     // storing and mapping the parent of the left child
        //     if(current->left!=NULL){
        //         parent_track[current->left]=current;
        //         q.push(current->left);
        //     }
        //     // storing and mapping the parent of the right child
        //     if(current->right!=NULL){
        //         parent_track[current->right]=current;
        //         q.push(current->right);
        //     }
        // }
         queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                TreeNode* current=q.front();
                q.pop();
                if(current->left!=NULL){
                    parent_track[current->left]=current;
                    q.push(current->left);
                    
                }
                if(current->right!=NULL){
                    parent_track[current->right]=current;
                    q.push(current->right);
                }
            }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // approach 
        // the first and foremost thing is to have mark the parent pointers 
        // this is done because you have to move radially updwards and downwards 
        // and for that from any node you must have an incorporation of parent pointers
        // and then we can keep a track of visited nodes and queue also to store its descendants            and parent pointers
        // and we can also have a distance variable which can have a track of the distance of 
//         at which we have to find the nodes
        unordered_map<TreeNode*,TreeNode*>parent_track;
        mark_parent(root,parent_track,target);
        // after the parent is ready we are ready to traverse radially updwards and downwards          // rightwards by a distance 1
        // we are then having a visited node hashmap
        unordered_map<TreeNode*,bool>visited;
        // and similarly having a queue for traversal
        queue<TreeNode*>q;
        // we are pushing the target in the ds
        q.push(target);
        // we are then pushing the target into the visited hashmap
        visited[target]=true;        
        int distance=0;
        while(!q.empty()){
            int size=q.size();
            if(distance ==k) break;
            distance++;
            // iterating on the queue elements
            for(int i=0;i<size;i++){
                TreeNode* node= q.front();
                q.pop();
                // checking on the left child 
                if(node->left and !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                // checking on the right child
                if(node->right and !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                // hence we will check on the parent too
                if(parent_track[node] and !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]]=true;
                    
                }
            }
        }
       
        // storing in an array to return the result
        vector<int>result;
        // iterating on the remaining queue element to store the elements into the array
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};