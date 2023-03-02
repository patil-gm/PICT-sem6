#include <bits/stdc++.h>
using namespace std;

#include<iostream>
using namespace std;

class Graph{
    int edges,vertex;
    int **adj_mat;
public:
    Graph(int v,int e){
        vertex = v;
        edges = e;
        adj_mat = new int*[v];
        for(int i = 0;i < v;i++){
            adj_mat[i] = new int[v];
        }
        for(int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                adj_mat[i][j] = -1;
            }
        }
    }

    void insert(){
        for(int k = 0;k < edges;k++){
            int i,j,w;
            cout << "Source :- ";
            cin >> i;
            cout << "Destination :- ";
            cin >> j;
            cout << "Weight :- ";
            cin >> w;
            adj_mat[i][j] = adj_mat[j][i] = w;
        }

    }

    void display(){
        for(int i = 0;i < vertex;i++){
            cout << i << "-> ";
            for(int j = 0;j < vertex;j++){
                cout << adj_mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void prims(){
        bool reached[vertex] = {0};

        // Minimum spanning graph matrix;
        int msg[vertex-1][3];
        int idx = 0;
        for(int i = 0;i < vertex-1;i++){
            msg[i][0] = msg[i][1] = msg[i][2] = -1;
        }

        reached[0] = 1;
        for(int c = 0;c < vertex-1;c++){
            int src,des,minn = 1e5,flag = 0;
            for(int v1 = 0;v1 < vertex;v1++){
                if(reached[v1]){
                    for(int v2 = 0;v2 < vertex;v2++){
                        if(adj_mat[v1][v2] != -1 && adj_mat[v1][v2] <= minn && reached[v2] == 0){
                            minn = adj_mat[v1][v2];
                            src = v1;
                            des = v2;
                            flag = 1;
                        }
                    }
                }
            }

            // Adding edge to msg
            if(flag){
                msg[idx][0] = src;
                msg[idx][1] = des;
                msg[idx][2] = minn;
                reached[des] = 1;
                idx++;
            }
        }

        // Displaying the minimum spanning graph;
        int total_weight = 0;
        for(int i = 0;i < vertex-1;i++){
            cout << msg[i][0] << "->" << msg[i][1] << "(wt : " << msg[i][2] << ")" << "\n";
            total_weight += msg[i][2];
        }
        cout << "Total Weight :- " << total_weight;
    }

    void kruksal(){
        bool taken[vertex] = {0};

        // Minimum spanning graph matrix;
        int msg[vertex-1][3];
        int idx = 0;
        for(int i = 0;i < vertex-1;i++){
            msg[i][0] = msg[i][1] = msg[i][2] = -1;
        }

        taken[0] = 1;
        for(int c = 0;c < vertex-1;c++){
            int src,des,minn = 1e5,flag = 0;
            for(int v1 = 0;v1 < vertex;v1++){
                for(int v2 = 0;v2 < vertex;v2++){
                    if(adj_mat[v1][v2] != -1 && adj_mat[v1][v2] <= minn && taken[v2] == 0 && taken[v1] == 1){
                        flag = 1;
                        minn = adj_mat[v1][v2];
                        src = v1;
                        des = v2;
                    }
                }
            }
            if(flag){
                msg[idx][0] = src;
                msg[idx][1] = des;
                msg[idx][2] = minn;
                taken[des] = 1;
                idx++;
            }
        }

        // Displaying the minimum spanning graph;
        int total_weight = 0;
        for(int i = 0;i < vertex-1;i++){
            cout << msg[i][0] << "->" << msg[i][1] << "(wt : " << msg[i][2] << ")" << "\n";
            total_weight += msg[i][2];
        }
        cout << "Total Weight :- " << total_weight;

    }
};


int main()
{
    int v,e;
    cout<<"\n enter number of vertex and edges";
    cin>>v;
    cin>>e;
    Graph g(v,e);
    g.insert();
    cout<<"\n";     
    g.display();
    cout<<"\n Prims: "<<endl;
    g.prims();
    cout<<"\n Kruskal: "<<endl;
    g.kruksal();
    cout<<"\n";

    return 0;
}

