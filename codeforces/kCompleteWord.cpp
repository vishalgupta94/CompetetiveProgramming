#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,k;
    string s;
    cin>>n>>k>>s;
   // cout<<s<<endl;
    vector<vector<int>> v(n/k,vector<int>(k)); 
    
    for(int i=0;i<n;i++){
      v[i/k][i%k]=s[i]-'a';
    }
    
    // for(int i=0;i<n;i++){
    //     if(i%k==0){
    //         cout<<endl;
    //     }
    //     cout<<v[i/k][i%k]<<" ";
    // }

    int ans=0;
    for(int i=0;i<k/2;i++){
            //cout<<"values"<<i<<" "<<k-i-1<<"  "<<endl;
            map<int,int> mp;
            int total=0;
            for(int j=0;j<n/k;j++){
                total++;
                mp[v[j][i]]++;
                mp[v[j][k-i-1]]++;
            }
            total=total*2;
            int maxCount=0;
            for(auto it = mp.begin();it!=mp.end();it++){
             //   cout<<(*it).first<<" "<<(*it).second<<endl;
                maxCount=max(maxCount,(*it).second);
            }
            ans+=total-maxCount;
           // cout<<maxCount<<endl;
    }
    if(k%2){
        map<int,int> mpM;
        int totalM=0;
        for(int j=0;j<n/k;j++){
            totalM++;
            mpM[v[j][k/2]]++;
        }
        int maxCountM=0;
        for(auto it = mpM.begin();it!=mpM.end();it++){
         //   cout<<(*it).first<<" "<<(*it).second<<endl;
            maxCountM=max(maxCountM,(*it).second);
        }
        ans+=totalM-maxCountM;
       // cout<<maxCountM<<endl;        
        
    }
    cout <<ans<< endl;
    }
    return 0;

}
