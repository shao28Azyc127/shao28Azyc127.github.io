#include<bits/stdc++.h>
using namespace std;
struct node{
    string type,name;
    long long l,r;
}a[1005];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    long long nowd=0;
    int n,k,cnt=0;cin>>n;
    for(int i=1;i<=n;i++){
        int op;cin>>op;
        if(op==1){
            exit(0);
        }
        if(op==2){
            cnt++;
            cin>>a[cnt].type>>a[cnt].name;
            if(a[cnt].type=="byte"){
                a[cnt].l=nowd;a[cnt].r=nowd;nowd++;
            }else if(a[cnt].type=="short"){
                while(nowd%2!=0)nowd++;
                a[cnt].l=nowd;a[cnt].r=nowd+1;nowd++;
            }else if(a[cnt].type=="int"){
                while(nowd%4!=0)nowd++;
                a[cnt].l=nowd;a[cnt].r=nowd+3;nowd++;
            }else if(a[cnt].type=="long"){
                while(nowd%8!=0)nowd++;
                a[cnt].l=nowd;a[cnt].r=nowd+7;nowd++;
            }
            cout<<a[cnt].l<<endl;
        }
        if(op==3){
            string s;cin>>s;
            for(int j=1;j<=cnt;j++){
                if(a[j].name==s){
                    cout<<a[j].l<<endl;break;
                }
            }
        }
        if(op==4){
            long long addr;cin>>addr;
            bool f=0;
            for(int j=1;j<=cnt;j++){
                if(addr>=a[j].l&&addr<=a[j].r){
                    f=1;cout<<a[j].name<<endl;break;
                }
            }
            if(!f){
                cout<<"ERR"<<endl;
            }
        }
    }
}
