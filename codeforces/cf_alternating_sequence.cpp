#include<bits/stdc++.h>

using namespace std;

int main(){
   int t;
   cin>>t;

   while(t--){
   	 long long n;
     cin>>n;

     long long *a= new long long[n];
     long long current;
     long long sum=0;
     for(int i=0;i<n;i++){
     	cin>>a[i];
     	if(i!=0){
     		if(a[i-1]>0){
                if(a[i]>0){
                     current=max(current,a[i]);
                }else{
                     sum+=current;
                     current=a[i];
                }
     		}else if(a[i-1]<0){
                if(a[i]<0){
                     current=max(current,a[i]);
                }else{
                     sum+=current;
                     current=a[i];
                } 
     		}
     	}else{
            current=a[i];
     	}
     }
     sum+=current;
     cout<<sum<<endl;



  

   }



	return 0;
}

/*

4
5
1 2 3 -1 -2
4
-1 -2 -1 -3
10
-2 8 3 8 -4 -15 5 -2 -3 1
6
1 -1000000000 1 -1000000000 1 -1000000000


*/