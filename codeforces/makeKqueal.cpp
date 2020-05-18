#include<bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
ll main()
{
    map<ll,ll> mp;
    
    ll n,k;
    cin>>n>>k;
    ll *a= new ll[n];
    ll output =0;
    bool ansFound=false;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>=k){
            ansFound=true;
        }
    }
    if(ansFound==true){
        cout<<output<<endl;
    }else{
        vector<pair<ll,ll>> v1;
        vector<pair<ll,ll>> v2;        
        vector<pair<ll,ll>> v3;        
      for(auto it = mp.begin();it!=mp.end();it++){
        pair<ll,ll> p = make_pair((*it).first,(*it).second);
        v1.push_back(p);
      }

    ll *aStart = new ll[v1.size()];
    ll *aEnd = new ll[v1.size()];
    for(ll i=0;i<v1.size();i++){
        if(i==0)
        {
            v2.push_back(v1[i]);
        }else{
           pair<ll,ll> p=v2[i-1];
           v2.push_back(make_pair(v1[i].first,p.second+v1[i].second ));
        }
    }
    for(ll i=v1.size()-1;i>=0;i--){
        if(i==v1.size()-1)
        {
            v3.push_back(v1[i]);
        }else{
           pair<ll,ll> p=v1[i];
           v3.push_back(make_pair(p.first,p.second+v3[v3.size()-1].second ) );
        }
    }
    reverse(v3.begin(),v3.end());
    aStart[0]=0;
    for(ll i=1;i<v1.size();i++){
        pair<ll,ll> p1=v1[i-1];
        pair<ll,ll> p2=v1[i];
        aStart[i]=aStart[i-1]+ (p2.first-p1.first)*v2[i-1].second;
        aStart[i-1]+= (p2.first-p1.first-1)*v2[i-1].second;
    } 
    aEnd[v1.size()-1]=0;
    for(ll i=v1.size()-2;i>=0;i--){
        pair<ll,ll> p1=v1[i+1];
        pair<ll,ll> p2=v1[i];
        aEnd[i]=aEnd[i+1]+ (p1.first-p2.first)*v3[i+1].second;
        aEnd[i+1]=(p1.first-p2.first-1)*v3[i+1].second;
    } 
    
   ll answer= INT_MAX;
        for(ll i=0;i<v1.size();i++){
            if(i==0){
                ll left= k-v1[i].second;
                answer=min(answer,aEnd[i+1]+left);               
            }else if(i==v1.size()-1){
                ll left= k-v1[i].second;
                answer=min(answer,aStart[i-1]+left);
            }else{
            ll left= k-v1[i].second;
            if(v2[i-1].second>=left){
                answer=min(answer,aStart[i-1]+left);
            }else{
                ll value= left-v2[i-1].second;
                answer=min(answer,aStart[i-1]+aEnd[i+1]
                + v2[i-1].second
                + value);                
            }
            
            if(v3[i+1].second>=left){
                answer=min(answer,aEnd[i+1]+left);            
            }else{
                ll value= left-v3[i+1].second;
                answer=min(answer,aStart[i-1]+aEnd[i+1]
                + v3[i+1].second 
                + value);                
            }                
            }
            
        }
    cout<<answer<<endl;


    }
   
    return 0;
}


/*
19 8 
1 1 4 4 4 8 8 8 8 8 8 9 9 9 9 8 9 9 7


*/