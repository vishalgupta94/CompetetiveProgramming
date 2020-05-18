#include <bits/stdc++.h>
using namespace std;


void func(vector<int> v1,vector<int> v2,int& answer){
    int a1=v1.size();
    int a2=v2.size();
    for(int i=0;i<a1/2;i++){
        int aa=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        int bb=upper_bound(v2.begin(),v2.end(),v1[a1-i-1])-v2.begin()-1;
        int ans=(i+1)*2+(bb-aa)+1;
        answer=max(answer,ans);
    }
    for(int i=0;i<a2/2;i++){
        int aa=lower_bound(v1.begin(),v1.end(),v2[i])-v1.begin();
        int bb=upper_bound(v1.begin(),v1.end(),v2[a2-i-1])-v1.begin()-1;
        int ans=(i+1)*2+(bb-aa)+1;
        answer=max(answer,ans);
    }    
}

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int *a= new int[n+1];
    vector<int> v[201];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    int answer=0;
    for(int i=1;i<=200;i++){
        for(int j=i+1;j<=200;j++){
            int aa1=(int)v[i].size();
            int aa2=(int)v[j].size();
            if(v[i].size()){
               answer=max(answer,(int)v[i].size());
            }
            if(v[j].size()){
               answer=max(answer,(int)v[j].size());                
            }
            if((aa1>0)&&(aa2>0)){
               func(v[i],v[j],answer);   
            }
        }
    }
   cout<<answer<<endl; 
   }
   
    return 0;
}
