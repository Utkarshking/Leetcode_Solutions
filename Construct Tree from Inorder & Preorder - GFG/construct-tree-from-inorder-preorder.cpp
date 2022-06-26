// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {   if(n==0) return NULL;
        // Code here
        map<int,int>inorder_map;
        for(int i=0;i<n;i++){
            // mapping all the inorder element and its index where it is lying
            inorder_map[in[i]]=i;
        }
        Node* node=buildtree(pre,0,n-1,in,0,n-1,inorder_map);
        
        return node;
    }
     Node* buildtree(int preorder[],int preStart,int preEnd,int inorder[],
    int inStart,int inEnd,map<int,int>&inorder_mapping){
        // as long we have elements in an array till then we will make the tree
        if(preStart>preEnd||inStart>inEnd) return NULL;
        // initialising the root node with the root node
        Node* root=new Node(preorder[preStart]);
        // basically will see and identify where is the root in inorder traversal
        int root_index_inorder=inorder_mapping[root->data];
        // number left to be iterated
        int num_left=root_index_inorder-inStart;
        // bui;ding the left subtree
        root->left=buildtree(preorder,preStart+1,preStart+num_left,inorder,
        inStart,root_index_inorder-1,inorder_mapping);
        root->right=buildtree(preorder,preStart+num_left+1,
        preEnd,inorder,root_index_inorder+1,inEnd,inorder_mapping);
        return root;    
    }
   
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends