#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    vector<ll> v;
    ll *a = new ll[n];
    for(ll i=0;i<n;i++){
         cin>>a[i];
    }
    sort(a,a+n);
    if(n%2){
         ll mid=n/2;
         ll i=mid-1;
         ll j=mid+1;
         v.push_back(a[mid]);
         while(1){
             //cout<<"hello"<<i<<"  "<<j<<endl;
            if(i==-1&&j==n){
             //cout<<"break"<<endl;
                break;
            }
            v.push_back(a[i--]);
            v.push_back(a[j++]);
         }

    }else{
         //even
        ll j=n/2;ll i=j-1;
        while(1){
           //  cout<<"hello "<<i<<"  "<<j<<endl;
            if(i==-1&&j==n){
              //   cout<<"break"<<endl;
                break;
            }
           // cout<<"hello "<<endl;
            v.push_back(a[i]);
            v.push_back(a[j]);
            i--;
            j++;
            //cout<<i<<" "<<j<<" "<<n<<endl;
        }

    }


    for(ll i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
         
   }
   
   return 0; 
}
