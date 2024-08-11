#include<bits/stdc++.h>
using namespace std;
string s;
map<string,int>p;
map<int,int>l,r;
map<string,int>aadd;
map<int,string>id;
int n,op,cnt;
long long addr=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    s="byte";
    p[s]=1;
    s="short";
    p[s]=2;
    s="int";
    p[s]=4;
    s="long";
    p[s]=8;
    while(n--){
        int op;
        cin>>op;
        if(op==2){
            string t,tt;
            cin>>t>>tt;
            cout<<addr<<endl;
            l[++cnt]=addr;
            id[cnt]=tt;
            aadd[tt]=addr;
            addr+=p[t];
            r[cnt]=addr-1;
        }
        if(op==3){
            string t;
            cin>>t;
            cout<<aadd[t]<<endl;
        }
        if(op==4){
            int aska;
            cin>>aska;
            for(int i=1;i<=cnt;i++){
                if(l[i]<=aska&&r[i]>=aska){
                cout<<id[i]<<endl;
                break;}
            }
        }
    }
    return 0;
}/*include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"hello world";//shuchu: nihaoshijie
    return 0;
}*/
