#include<bits/stdc++.h>
using namespace std;

 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    cout<<"No of elements in array : ";
    vector<int> v;
    int n;cin>>n;
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    selectionSort(v,n);
    cout<<"Order of elements after selection sort : ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}