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

void bubbleSort(vector<ll>& arr, ll n)
{   
    for(int i = 1; i<n; i++) //for round 1 to n-1
    {
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) //process element till n-i th index
        {
            
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}

void solve(){
   ll n;
   cout<<"enter the no of elements in your array : ";
   cin>>n;

   cout<<"enter the elements one by one : ";
   vec(arr,n);

    bubbleSort(arr,n);

    loop(i,0,n)cout<<arr[i]<<" ";


};

signed main(){
    fastio
    ll t=1;
// cin>>t;
while(t--)solve();
    return 0;
}
