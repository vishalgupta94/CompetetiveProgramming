#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int main(){
    
    int t;
    cin>>t;
    while(t--){
   int n,m;
   cin>>n;
   m=n;
   int *a=new int[n];
   map<int,int> mp;
   map<int,int>::iterator it;
   vector<pair<int,int>> v;
   for(int i=0;i<n;i++){
    cin>>a[i];
    mp[a[i]]++;
   }
   for(it=mp.begin();it!=mp.end();it++){
       //cout<<it->first<<"  "<<it->second<<"  "<<endl;
       v.push_back({it->first,it->second});
   }
   sort(v.begin(), v.end(), sortbysec);
   vector<pair<int,int>>::reverse_iterator it2;
//   for(int i=0;i<v.size();i++){
//       pair<int,int> p=v[i];
//       cout<<p.first<<" : "<<p.second<<endl;
//   }

//   for(it2=v.rbegin();it2!=v.rend();it2++){
//       cout<<"  "<<it2->first<<"  "<<it2->second<<" "<<endl;
//   }



  int ans=0;
  it2 = v.rbegin();
  int highestFrequency;
  highestFrequency = it2->second;
  //cout<<" highestFrequency "<<highestFrequency<<endl;
  it2++;
  m=m-highestFrequency;

  for(;it2!=v.rend();it2++){
     if(highestFrequency==it2->second){
      ans++;
      m=m-highestFrequency;
     }else{
      break;
     }
    // cout<<" loop "<<ans<<"  "<<highestFrequency<<endl;
  }

    int space=highestFrequency-1;  
    //cout<<"space"<<space<<" m "<<m<<endl;
    if(space==1){
        ans+=m;
    }else{
      if(space!=0&&space<=m){
        //cout<<" m "<<m<<space<<"  "<<endl;
      //m=m/space;
      ans+=m/space;
      }     
    } 
    
    cout<<ans<<endl;
}
  return 0;
}
 