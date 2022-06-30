// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* bfsforparentpointers(Node* root,int target,map<Node*,Node*>&parent_pointers){
        queue<Node*>q;
        q.push(root);
        Node* targetnode;
        while(!q.empty()){
            int size=q.size();
            Node* current=q.front();
            q.pop();
            if(current->data==target) targetnode=current;
            if(current->left){
                parent_pointers[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_pointers[current->right]=current;
                q.push(current->right);
            }
        }
        return targetnode;
  }
  int timetakenforburn(Node* targetnode,map<Node*,Node*>&parent_pointer){
      
      queue<Node*>q;
      int time=0;
      q.push(targetnode);
      map<Node*,int>visited;
      visited[targetnode]=1;
      while(!q.empty()){
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++){
            auto node=q.front();
            q.pop();
            if(node->left and !visited[node->left]){
            q.push(node->left);
            flag=1;
            visited[node->left]=1;
        }
            if(node->right and !visited[node->right]){
                q.push(node->right);
                flag=1;
                visited[node->right]=1;
            }
            if(parent_pointer[node] and !visited[parent_pointer[node]]){
                q.push(parent_pointer[node]);
                flag=1;
                visited[parent_pointer[node]]=1;
            }
         }
           if(flag) time++;
  }
   return time;
 }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        // parent pointers because of keeping the track of the parents 
        // we can actyally tracverse and see on the other side how much time it would take 
        // to basicaly to burn the whole tree
        map<Node*,Node*>parent_pointers;
       Node* targetnode=bfsforparentpointers(root,target,parent_pointers);
       int mini=timetakenforburn(targetnode,parent_pointers);
       return mini;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends