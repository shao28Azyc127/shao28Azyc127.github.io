#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int k;
int t[100],nn[100];
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,op;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            cout<<s<<" "<<k;
            for(int i=1;i<=k;i++){
                cin>>t[i]>>nn[i];
                cout<<t[i]<<" "<<nn[i];
            }
            cout<<endl;
        }
        if(op==2){
            int nn,tt;
            cin>>nn>>tt;
            cout<<nn<<" "<<tt<<endl;
        }
        if(op==3){
            int ss;
            cin>>ss;
            cout<<ss<<endl;
        }
        if(op==4){
            int addr;
            cin>>addr;
            cout<<addr<<endl;
        }
    }
    return 0;
}
