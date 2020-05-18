#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){

ll n;
cin>>n;
map<ll,ll> mp;
map<ll,ll> mp2;
ll a[n];
ll sAll=0;
for(ll i=0;i<n;i++){
       cin>>a[i];
       mp[a[i]]++;
       sAll+=a[i];
}
string s="NO";

if(sAll%2==0){
  ll sDash=0;
  ll dVal= sAll>>1;
    for(int i=0;i<n;i++){
      if(sDash<dVal){
        ll check = dVal-sDash;
        
        if(mp[check]>0){
                       s="YES";
                       break;
        }
      }else if(sDash>dVal){
            ll check = sDash-dVal;
            if(mp2[check]>0){
                       s="YES";
                       break; 
            }

      }else if(sDash==dVal) {
                       s="YES";
                       break;       
      }



            mp2[a[i]]++;  
        sDash+=a[i];
        
        mp[a[i]]--;
        if(mp[a[i]]==0){
          mp.erase(a[i]);
        }
    }
}


cout<<s;
return 0;
}