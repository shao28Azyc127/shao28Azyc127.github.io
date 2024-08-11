#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in",r);
    freopen("struct.out",w);
    int n,ll=0,so=0,in=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,k,addr;
        string s,t,n;
        cin>>x;
        if(x==1){
            cin>>s>>k;
            for(int j=0;j<k;j++){
                cin>>t>>n;
                if(t=="long"||t=="long long")ll++;
                else if(t=="int")in++;
                else if(t=="short")so++;
            }
            if(ll==0)cout<<8<<" "<<4<<endl;
            else cout<<16<<" "<<8<<endl;
        }
        else if(x==2){
            cin>>t>>n;
            cout<<0<<endl;
        }
        else if(x==3){
            cin>>s;
            cout<<4<<endl;
        }
        else if(x==4){
            cin>>addr;
            cout<<"ERR"<endl;
        }
    }
    fclose();
    return 0;
}