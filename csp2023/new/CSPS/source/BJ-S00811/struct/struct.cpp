#include<bits/stdc++.h>
using namespace std;
string loc[105];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,op;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==2){
            int cl=0;
            string t,m;
            cin>>t>>m;
            if(t[0]=='b'){
                loc[cl]=m;
                cl++;
            }
            if(t[0]=='s'){
                loc[cl]=m;
                cl+=2;
            }
            if(t[0]=='i'){
                loc[cl]=m;
                cl+=4;
            }
            if(t[0]=='l'){
                loc[cl]=m;
                cl+=8;
            }
        }
        if(op==3){
            string s;
            cin>>s;
            for(int i=1;i<=100;i++){
                if(loc[i][0]==s[0]){
                    cout<<i<<endl;
                }
            }
        }
        if(op==4){
            int z;
            cin>>z;
            cout<<loc[z]<<endl;
        }
    }
    return 0;
}
