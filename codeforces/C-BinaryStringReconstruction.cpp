    #include<iostream>
    #include<vector>
     
    using namespace std;
     
     
    int main(){
     
        int t;
        cin>>t;
        while(t--)
        {
        string s;int x;
        cin>>s;
        cin>>x;
        vector<char> v(s.size(),-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(i-x>=0&&i+x<s.size()){
                    v[i-x]='0';
                    v[i+x]='0';
                }else if(i-x<0&&i+x<s.size()){
                    v[i+x]='0';
                }else if(i-x>=0&&i+x>=s.size()){
                    v[i-x]='0';
                }else{
                    v[i]='1';
                }
            }   
        }
        
        
        // for(int i=0;i<s.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
     
        for(int i=0;i<s.size();i++){
             if(v[i]!='0'){
                 v[i]='1';
             }
        }
        string original;
       
        string str;
        
        for(int i=0;i<s.size();i++){
            original.push_back(v[i]);
                if(i-x>=0&&i+x<s.size()){
                   if(v[i-x]=='0'&&v[i+x]=='0'){
                       str.push_back('0');
                   }else{
                       str.push_back('1');
                   }
                }else if(i-x<0&&i+x<s.size()){
                   if(v[i+x]=='0'){
                       str.push_back('0');
                   }else{
                       str.push_back('1');
                   }                
                }else if(i-x>=0&&i+x>=s.size()){
                   if(v[i-x]=='0'){
                       str.push_back('0');
                   }else{
                       str.push_back('1');
                   }                
                }else{
                    str.push_back('0');
                }
        }
        
        if(str==s){
            cout<<original<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
     
    	return 0;
    }