#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef long long ll;


int main(){
    int t;
    cin>>t;
    while(t--){
   ll n;
   cin>>n;

   ll *a = new ll[n];
   for(ll i=0;i<n;i++){
   	  cin>>a[i];
   }
   
   map<ll,ll> mp_left;
   mp_left[a[0]]++;
   ll answer=0;
   for(ll i=1;i<n-2;i++){
        map<ll,ll> mp_right;   	
        mp_right[a[n-1]]++;
        for(ll j=n-2;j>i;j--){
            answer+=mp_left[a[j]]*mp_right[a[i]];
            mp_right[a[j]]++;
        }

        mp_left[a[i]]++;
   }   

cout<<answer<<endl;
    }
   return 0;
}