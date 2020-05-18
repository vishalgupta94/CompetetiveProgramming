#include <bits/stdc++.h>
using namespace std;


void func(vector<int> v1,vector<int> v2,int& answer){
    // cout<<v1.size()<<end;
    // cout<<v2.size()<<endl;
    int a1=v1.size();
    int a2=v2.size();
    for(int i=0;i<a1/2;i++){
        int aa=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        int bb=upper_bound(v2.begin(),v2.end(),v1[a1-i-1])-v2.begin()-1;
        int ans=(i+1)*2+(bb-aa)+1;
        //cout<<i<<"  "<<a1-i-1<<" "<<v1[i]<<" "<<v1[a1-i-1]<<" aa "<<aa<<" bb "<<bb<<"answer"<<ans<<endl;
        answer=max(answer,ans);
    }
    cout<<endl;
    for(int i=0;i<a2/2;i++){
        int aa=lower_bound(v1.begin(),v1.end(),v2[i])-v1.begin();
        int bb=upper_bound(v1.begin(),v1.end(),v2[a2-i-1])-v1.begin()-1;
        int ans=(i+1)*2+(bb-aa)+1;
        cout<<i<<"  "<<a2-i-1<<" "<<v1[i]<<" "<<v1[a2-i-1]<<" aa "<<aa<<" bb "<<bb<<"answer"<<ans<<endl;
        answer=max(answer,ans);
    }    
}


void ppff(vector<int> *v){
    for(int i=1;i<3;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    
    int n;
    cin>>n;
    int *a= new int[n+1];
    vector<int> v[27];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    //cout<<"hello"<<endl<<v[1].size()<<" "<<v[2].size()<<endl;
    
    //ppff(v);
    // for(int i=1;i<3;i++){
    //     for(int j=1;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int answer=0;
    for(int i=1;i<=26;i++){
        for(int j=i+1;j<=26;j++){
            int aa1=(int)v[i].size();
            int aa2=(int)v[j].size();
            cout<<"aa1  "<<aa1<<" "<<aa2<<endl;
            bool val=(aa1>0)&&(aa2>0);
            cout<<"bool  "<<val<<endl;
            if(v[i].size()){
               // cout<<"main111"<<endl;
                 answer=max(answer,(int)v[i].size());
            }
            if(v[j].size()){
                //cout<<"main222"<<endl;
                 answer=max(answer,(int)v[j].size());                
            }
            if(val){
                //cout<<"hello"<<endl;
                 func(v[i],v[j],answer);   
            }
        }
    }
   
   //cout<<endl;
   cout<<"answer"<<answer;
   
   
//   vector<int> V{1,2,4,5,6,7,8,9,12,13,14,15};
//   cout<< lower_bound(V.begin(),V.end(),13)-V.begin()<<" "<<endl;
//   cout<< upper_bound(V.begin(),V.end(),13)-V.begin()<<" "<<endl; 
//   cout<< lower_bound(v[2].begin(),v[2].end(),25)-v[2].begin()<<" "<<endl;
//   cout<< upper_bound(v[2].begin(),v[2].end(),25)-v[2].begin()<<" "<<endl;   
   
    return 0;
}
