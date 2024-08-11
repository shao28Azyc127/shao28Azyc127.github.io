#include<bits/stdc++.h>
using namespace std;
int n;
int t[256];
string ad[100];

int cnt=0;
int main(){
freopen("struct.in","r",stdin);
freopen("struct.out","w",stdout);
cin>>n;
for(int i=0;i<n;++i){
    int op;
    cin>>op;
    if(op==2){
        string t,n;
        cin>>t>>n;
        cout<<cnt*8<<endl;
        ad[cnt]=t;
        cnt++;

    }
    if(op==3){
        string s;
        cin>>s;
        for(int i=0;i<cnt;++i){
            if(s==ad[i]){
                cout<<8*i<<endl;
            }
        }
    }
    if(op==4){
        int addr;
        cin>>addr;
        cout<<(addr/8)*8<<endl;
    }
}
}
