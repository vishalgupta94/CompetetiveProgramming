#include <iostream>
#include <vector>
using namespace std;
int countBits(int n){
    int i=0;
    while(n){
        if(n&1){
            i++;
        }
        n=n>>1;
    }
    return i;
}

int main(){

int t;
cin>>t;
while(t--){
    int p,even=0,odd=0;
	int n,q;
	cin>>n>>q;

	int a[n];
	int count[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		count[i]=countBits(a[i]);
        if(count[i]%2){
            odd++;
        }else{
            even++;
        }
	}

    while(q--){
    	
    	cin>>p;
    	vector<int> v;
    	int index=0;
        int countBitsP=countBits(p);
        if(countBitsP%2){
            cout<<odd<<" "<<even<<endl;
        }else{
            cout<<even<<" "<<odd<<endl;
        }
       
 
    }

}
	return 0;
}

/*
1
6 1
4 2 15 9 8 8
3

*/