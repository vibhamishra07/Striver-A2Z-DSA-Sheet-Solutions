//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> v;
       queue<int>que;
       int visited[V];
       
       que.push(0);
       v.push_back(0);  
       visited[0]=1;   //First node is visited so mark it 1.
       
       while(!que.empty()){
           int node =que.front();
           que.pop();
           
           for(auto i:adj[node]){
               
              if(visited[i]!=1){
                  v.push_back(i);
                  que.push(i);       //pushing node in que.
                  visited[i]=1;      //This node is visited so marking it as 1.
              }
              
           }
           
       }
       return v;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends