#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll aa,bool *a,ll N,vector<ll> *v){
	a[aa]=true;
	for(ll i=0;i<v[aa].size();i++){
	    if(!a[v[aa][i]]){
           dfs(v[aa][i],a,N,v);
	    }	
	}
	return;
}


int main(){
ll t;
cin>>t;
while(t--){
ll n,m,aa,bb;
ll v1,v2;
cin>>n>>m>>aa>>bb;

vector<ll> v[n+1];
bool *a= new bool[n+1];
for(ll i=0;i<m;i++){
    cin>>v1>>v2;
    v[v1].push_back(v2);
    v[v2].push_back(v1);
}
for(ll i=1;i<=n;i++){
     a[i]=false;
}
a[bb]=true;
dfs(aa,a,n,v);

ll count=0;
/*for(ll i=1;i<=n;i++){
   cout<<"i"<<i<<" "<<a[i]<<endl;
}*/
for(ll i=1;i<=n;i++){
	if(a[i]){
		count++;
		a[i]=false;
	}	
}

ll countA=n-count;
//cout<<" countA "<<countA<<endl;
count=0;
a[aa]=true;
dfs(bb,a,n,v);
// for(ll i=1;i<=n;i++){
//   cout<<"i"<<i<<" "<<a[i]<<endl;
// }
for(ll i=1;i<=n;i++){
	if(a[i]){
		count++;
		a[i]=false;
	}	
}
ll countB=n-count;
//cout<<" countB "<<countB<<endl;
ll ans=countA*countB;
cout<<ans<<endl;

}
return 0;
}


