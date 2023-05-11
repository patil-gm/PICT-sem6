#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

bool isvalid(int row,int col,vector<vector<string>> &temp){

        for(int i=0;i<col;i++){
            if(temp[row][i]=="#")return false;
        }
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(temp[i][j]=="#")return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i<temp.size() && j>=0){
            if(temp[i][j]=="#")return false;
            i++;
            j--;
        }

        return true;
    }
 
    void solve(int col,vector<vector<string>> &temp){
        if(col==temp.size()){
            vector<string> placement;
            for(int i=0;i<temp.size();i++){
                string str="";
                for(int j=0;j<temp[0].size();j++)str+=temp[i][j];
                placement.push_back(str);
            }
            ans.push_back(placement);
            return;
        }

        for(int i=0;i<temp.size();i++){
            if(isvalid(i,col,temp)){
                temp[i][col]="#";
                solve(col+1,temp);
                temp[i][col]=".";
            }
        }
    }

    void solveNQueens(int n) {
        vector<vector<string>> temp(n,vector<string>(n,"."));
        solve(0,temp);
        for(auto it:ans){
            for(auto i:it){
                for(int p=0;p<n;p++)cout<<"--";
                cout<<endl;
                cout<<"|";
                for(int p=0;p<n;p++)cout<<i[p]<<"|";
                cout<<"\n";
            }
            for(int p=0;p<n;p++)cout<<"--";
            cout<<"\n";
            cout<<"<---------------***********--------------->\n";
        }
        
    }


int main(){
    cout<<"Enter the size of square : (1-8)";
    int n;cin>>n;
    solveNQueens(n);
}