#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y,sum;
char a,b[100010];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4){
        while(t--){
            sum=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++)b[i]='T';
            for(int i=1;i<=m;i++){
                cin>>a>>x;
                b[x]=a;
            }
            for(int i=1;i<=n;i++)if(b[i]=='U')sum++;
            cout<<sum<<endl;
        }
    }else{
        while(t--){
            sum=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++)b[i]='T';
            for(int i=1;i<=m;i++){
                cin>>a>>x;
                if(a=='+'||a=='-'){
                    cin>>y;
                    if(a=='+')b[x]=b[y];
                    else{
                        if(b[y]=='T')b[x]='F';
                        if(b[y]=='F')b[x]='T';
                        if(b[y]=='U')b[x]='U';
                    }
                }else{
                    b[x]=a;
                }
            }
            for(int i=1;i<=n;i++){
                if(b[i]=='F')sum++;
                if(b[i]=='U')sum++;
            }
            cout<<sum<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
