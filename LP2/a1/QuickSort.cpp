//patil_gm
//#include<bits/stdc++.h>
#include<map>
#include<vector>
#include<cmath>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define itoc(c)  ((char)(((int)'0')+c))
#define ctoi(c)  ((int)(((int)c)-'0'))
#define endl '\n'
#define ll long long
#define lld long long double 
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vec(ver, n)  vector<ll> ver(n); for (ll i = 0; i < n; i++) cin >> ver[i];
#define pii pair<ll,ll>
#define fr first
#define sc second
const long long INF=1e18;
const int32_t mod=1e9+7;
const int32_t MM=998244353;


int partition( vector<ll> &arr, int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //handeling left and right part
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(vector<ll> &arr, int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon 
    int p = partition(arr, s, e);

    //sort left part
    quickSort(arr, s, p-1);

    //sort right part
    quickSort(arr, p+1, e);

}

void solve(){
   ll n;
   cout<<"enter the no of elements in your array : ";
   cin>>n;

   cout<<"enter the elements one by one : ";
   vec(arr,n);

    quickSort(arr,0,n-1);

    loop(i,0,n)cout<<arr[i]<<" ";


};

signed main(){
    fastio
    ll t=1;
// cin>>t;
while(t--)solve();
    return 0;
}
