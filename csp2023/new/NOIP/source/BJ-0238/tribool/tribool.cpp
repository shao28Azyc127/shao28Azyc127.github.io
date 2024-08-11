#include<bits/stdc++.h>
using namespace std;
long long  c,t;
bool f[100010];
bool a5[100010];
bool a6[100010];
int a4[100010];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4){
        int n,m;

        char a1[100010];
        int a2[100010];

        char cu[100010];
        while(t--){
            cin>>n>>m;
            int cnt=0;
            for(int i=1;i<=n;i++){
                f[i]=false;
            }
            for(int i=1;i<=m;i++){
                cin>>a1[i]>>a2[i];
            }
            for(int i=m;i>=1;i--){
                if(f[a2[i]]==false&&a1[i]=='U'){
                    cnt++;

                }
                f[a2[i]]=true;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    if(c==5||c==6){
        int n,m;

            char a1[100010];
            int a2[100010],a3[100010];
        while(t--){
            cin>>n>>m;
        for(int i=1;i<=n;i++){
            a5[i]=false;
        }
        int cnt=0;

            for(int i=1;i<=m;i++){
               cin>>a1[i];
               if(a1[i]=='+'){
                cin>>a2[i]>>a3[i];
               } else{
                   cin>>a2[i];
               }
            }
            for(int i=m;i>=1;i--){
                if(a1[i]=='+'&&a5[a2[i]]==false){
                    a4[a3[i]]++;
                    a5[a2[i]]=true;
                }else if(a1[i]=='U'){
                    cnt+=a4[a2[i]];
                    a4[a2[i]]=0;
                }
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    return 0;
}
