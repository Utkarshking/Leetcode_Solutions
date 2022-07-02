/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current==NULL) s.append("#,");
            else s.append(to_string(current->val)+',');
            if(current!=NULL){
                q.push(current->left);
                q.push(current->right);
            }
            
        }
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        // getline is used for iterating over a particular element and also
        // this will keep in mind over the delimeter
        // this will have the str will have the root node and
        // then it is converted into the the integer which is then the root of the string
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                current->left=NULL;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                current->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
                if(str=="#"){
                    current->right=NULL;
                }
                else{
                    TreeNode* RightNode=new TreeNode(stoi(str));
                    current->right=RightNode;
                    q.push(RightNode);
                }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));