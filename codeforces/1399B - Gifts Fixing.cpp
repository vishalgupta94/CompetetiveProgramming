#include <bits/stdc++.h>
// #include <map>
// #include <vector>
using namespace std;

int R, C;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll *a=new ll[n];
        ll *b=new ll[n];
        ll aMin=1000000001;
        ll bMin=1000000001; 
        for(ll i=0;i<n;i++){
              cin>>a[i];
              aMin=min(a[i],aMin);
        }

        for(int i=0;i<n;i++){
              cin>>b[i];
              bMin=min(b[i],bMin);              
        }        
         
        //cout<<" aMin "<<aMin<<" bMin "<<bMin<<endl; 
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll aa=a[i]-aMin;
            ll bb=b[i]-bMin;
            ll c=min(aa,bb);
            
            aa=aa-c;
            bb=bb-c;
            ans+=aa+bb+c;
        }

        cout<<ans<<endl;
    }

    return 0;
}