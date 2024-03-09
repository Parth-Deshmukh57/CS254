#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfsRec(vector<int> adj[],vector<int> &vis,int u,stack<int> &st,int V){
    vis[u]=1;
    for(auto it:adj[u]){
        if(vis[it]==0){
        dfsRec(adj,vis,it,st,V);
        }
    }
    st.push(u);


}

void printDfs(vector<int> adj2[],vector<int> &vis,int u,int V){
    vis[u]=1;
    cout<<u<<" ";

    for(int it:adj2[u]){
        if(vis[it]==0){
        printDfs(adj2,vis,it,V);
        }
    }

}


void stronglyConnectedComp(  vector<int>adj[],int V){
    vector<int> vis(V);
    for(int i=0;i<V;i++){
        vis[i]=0;
    }

    stack<int> st;

    for(int i=0;i<V;i++){
        if(vis[i]==0){
            dfsRec(adj,vis,i,st,V);
        }
    }

     vector<int>adj2[V];

     for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            adj2[it].push_back(i);
        }
     }

      for(int i=0;i<V;i++){
        vis[i]=0;
    }
    

    while(!st.empty()){
        int u=st.top();
        st.pop();
        if(vis[u]==0){
        printDfs(adj2,vis,u,V);
        cout<<endl;
        }
        

    }



}

int main() {
    freopen("input_3.txt","r",stdin);
    freopen("output_3.txt","w",stdout);
    int t;cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        while (E--) {
            int u, v;cin >> u >> v;
            adj[u].push_back(v);
        }
        stronglyConnectedComp(adj, V);
        cout << endl;
    }
    return 0;
}