#include<bits/stdc++.h>
#include <iostream>

using namespace std;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
        return b.first>a.first;
}

int main()
{
    map<int,int> mp;
    
    int n,k;
    cin>>n>>k;
    int *a= new int[n];
    int output =0;
    bool ansFound=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>=k){
            ansFound=true;
        }
    }
    if(ansFound==true){
        cout<<output<<endl;
    }else{
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;        
        vector<pair<int,int>> v3;        
      for(auto it = mp.begin();it!=mp.end();it++){
        pair<int,int> p = make_pair((*it).first,(*it).second);
        v1.push_back(p);
      }

    int *aStart = new int[v1.size()];
    int *aEnd = new int[v1.size()];
    //sort(v1.begin(),v1.end(),sortbysec);

    
    for(int i=0;i<v1.size();i++){
        if(i==0)
        {
            v2.push_back(v1[i]);
        }else{
           pair<int,int> p=v2[i-1];
           v2.push_back(make_pair(v1[i].first,p.second+v1[i].second ));
        }
    }
    for(int i=v1.size()-1;i>=0;i--){
        if(i==v1.size()-1)
        {
            v3.push_back(v1[i]);
        }else{
           pair<int,int> p=v1[i];
           v3.push_back(make_pair(p.first,p.second+v3[v3.size()-1].second ) );
        }
    }
    reverse(v3.begin(),v3.end());
    aStart[0]=0;
    for(int i=1;i<v1.size();i++){
        pair<int,int> p1=v1[i-1];
        pair<int,int> p2=v1[i];
        aStart[i]=aStart[i-1]+ (p2.first-p1.first)*v2[i-1].second;
        aStart[i-1]+= (p2.first-p1.first-1)*v2[i-1].second;
    } 
    aEnd[v1.size()-1]=0;
    for(int i=v1.size()-2;i>=0;i--){
        pair<int,int> p1=v1[i+1];
        pair<int,int> p2=v1[i];
        //cout<<p1.first<<p2.first<<v3[i+1].second;
        aEnd[i]=aEnd[i+1]+ (p1.first-p2.first)*v3[i+1].second;
        aEnd[i+1]=(p1.first-p2.first-1)*v3[i+1].second;
    } 
    
    cout<<endl;
    for(auto it=v1.begin();it!=v1.end();it++){
            pair<int,int> p = *it;
            cout<<(*it).first<<" "<<(*it).second<<"  ";
    }
    cout<<endl;
    for(auto it=v2.begin();it!=v2.end();it++){
            pair<int,int> p = *it;
            cout<<(*it).first<<" "<<(*it).second<<"  ";
    }
    cout<<endl;
    for(auto it=v3.begin();it!=v3.end();it++){
            pair<int,int> p = *it;
            cout<<(*it).first<<" "<<(*it).second<<"  ";
    }     
    cout<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<aStart[i]<<" ";  
    }
    cout<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<aEnd[i]<<" ";  
    } 
    int answer= 99999999;
    cout<<endl;
    // for(int i=0;i<v1.size();i++){
    //     if(i==0){
    //         int left= k-v1[i].second;
    //         answer=min(answer,aEnd[i+1]+left*(v1[i+1].first-v1[i].first));
    //     }else if(i==v1.size()-1){
    //         int left=k-v1[i].second;
    //         answer=min(answer,aStart[i-1]+left*(v1[i].first-v1[i-1].first));
    //     }else{
    //         int left= k-v1[i].second;
    //         if(v2[i-1].second>=left){
    //             answer=min(answer,aStart[i-1]+left*(v1[i].first-v1[i-1].first));
    //         }else{
                
    //         }
            
    //         if(v3[i+1].second>=left){
    //             answer=min(answer,aStart[i-1]+left*(v1[i].first-v1[i-1].first));            
                
    //         }else{
                
    //         }
            
    //     }
    //     cout<<answer<<endl;
    // } 
        for(int i=0;i<v1.size();i++){
        if(i==0){
            int left= k-v1[i].second;
            answer=min(answer,aEnd[i+1]+left*(v1[i+1].first-v1[i].first));
        }else if(i==v1.size()-1){
            int left=k-v1[i].second;
            answer=min(answer,aStart[i-1]+left*(v1[i].first-v1[i-1].first));
        }else{
            int left= k-v1[i].second;
            if(v2[i-1].second>=left){
                int aa=aStart[i-1];
                int bb=v2[i-1].second-left;
                int cc=v1[i].first-v1[i-1].first;
                answer=min(answer,aStart[i-1]+(left)*(v1[i].first-v1[i-1].first));
            }else{
                int value= left-v2[i-1].second;
                int aa=aStart[i-1]+aEnd[i+1];
                int bb=v2[i-1].second*(v1[i].first-v1[i-1].first);
                int cc=value*(v1[i+1].first-v1[i].first);
                answer=min(answer,aStart[i-1]+aEnd[i+1]
                + v2[i-1].second*(v1[i].first-v1[i-1].first) 
                + value*(v1[i+1].first-v1[i].first));                
            }
            
            if(v3[i+1].second>=left){
                int aa=aEnd[i+1];
                int bb=v3[i+1].second-left;
                int cc=v1[i+1].first-v1[i].first;
                answer=min(answer,aEnd[i+1]+(left)*(v1[i+1].first-v1[i].first));            
            }else{
                int value= left-v3[i+1].second;
                int aa=aStart[i-1]+aEnd[i+1];
                int bb=v2[i-1].second*(v1[i].first-v1[i-1].first);
                int cc=value*(v1[i+1].first-v1[i].first);
                answer=min(answer,aStart[i-1]+aEnd[i+1]
                + v3[i+1].second*(v1[i+1].first-v1[i].first) 
                + value*(v1[i].first-v1[i-1].first));                
            }
            
        }
        cout<<answer<<endl;
    } 



    }
   
    return 0;
}


/*
19 8 
1 1 4 4 4 8 8 8 8 8 8 9 9 9 9 8 9 9 7


*/