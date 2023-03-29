//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    int revNum=0;
		    int dup=n;
		    while(dup>0){
		        int lastdigit=dup%10;
		        revNum=(revNum*10)+lastdigit;
		        dup=dup/10;
		    }
		    if(revNum==n) return "Yes";
		    else
		    return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends