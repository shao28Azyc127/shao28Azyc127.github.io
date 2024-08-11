#include<bits/stdc++.h>
using namespace std;

int t,a[1000010]={-1},k;
map<string,int>mp;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>t;
    int op;
    string s,st;
    while(t--){
        cin>>op;
        if(op==2){
            cin>>s>>st;
            if(s=="byte"){
                ++k;
                a[k]=a[k-1]+1;
                mp[st]=a[k];
            }
            else if(s=="short"){
                ++k;
                a[k]=a[k-1]+2;
                mp[st]=a[k-1]+1;
            }
            else if(s=="int"){
                ++k;
                a[k]=a[k-1]+4;
                mp[st]=a[k-1]+1;
            }
            else if(s=="long"){
                ++k;
                a[k]=a[k-1]+8;
                mp[st]=a[k-1]+1;
            }
            cout<<a[k-1]+1<<endl;
        }
        if(op==3){
            cin>>s;
            cout<<mp[s]<<endl;
        }
        if(op==4){
            int x;
            cin>>x;
            if(!k)cout<<"ERR"<<endl;
            int y=lower_bound(a+1,a+k+1,x)-a;
            cout<<a[y-1]+1<<endl;
        }
    }
    return 0;
}
