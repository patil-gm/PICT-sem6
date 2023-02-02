#include<bits/stdc++.h>
using namespace std;

unordered_map< int , vector<int>> adj; 

void BFS(){

        unordered_set <int> visited;
        cout<<"Enter the starting point for BFS ";
        int start;cin>>start;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        cout<<"*********** BFS TRAVERSAL ***********"<<endl;
        while(!q.empty()){
            int curr=q.front();
            cout<<curr<<" ";
            q.pop();
          
            for(int i=0;i<adj[curr].size();i++){
                if(visited.find(adj[curr][i])==visited.end()){q.push(adj[curr][i]); 
                visited.insert(adj[curr][i]);
                }
            }
        }

        cout<<"\n";
}


void DFS(){

        unordered_set <int> visited;
        cout<<"Enter the starting point for DFS ";
        int start;cin>>start;
        stack<int> s;
        s.push(start);
        visited.insert(start);

        cout<<"*********** DFS TRAVERSAL ***********"<<endl;
        while(!s.empty()){
            int curr=s.top();
            cout<<curr<<" ";
            s.pop();
          
            for(int i=0;i<adj[curr].size();i++){
                if(visited.find(adj[curr][i])==visited.end()){s.push(adj[curr][i]); 
                visited.insert(adj[curr][i]);
                }
            }
        }

        cout<<"\n";
}


void dfsRec (int node, unordered_map<int,bool> &visited,vector<int> &ans)
{
  ans.push_back(node);
  visited[node]=true;
  
// for every node making recusive call
for(auto it:adj[node]){
  if(!visited[it]) dfsRec(it,visited,ans);
}
}


int main(){
        unordered_map<int,bool> visited;
        while(1){
            cout<<"Do you wants to add the edge ? (y/n)";
            char c;cin>>c;
            if(c!='y'&& c!='Y')break;

            cout<<"enter the 2 edge points : ";
            int u,v; 
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            visited[u]=false;
            visited[v]=false;
        }
            
            BFS();
            DFS();


    vector<int> recDfs;

    cout<<"*********** RECURSIVE DFS TRAVERSAL ***********"<<endl;
    cout<<"Enter the starting point for DFS ";
    int start;cin>>start;
    
    dfsRec(start,visited,recDfs);
    for(auto i:recDfs)cout<<i<<" ";
    cout<<endl;
}



// y 0 1 y 0 2 y 1 3 y 1 4 y 2 5 y 2 6 n
