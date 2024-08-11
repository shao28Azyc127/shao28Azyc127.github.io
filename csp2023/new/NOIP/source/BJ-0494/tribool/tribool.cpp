#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000],b[110000],c,t;
struct node{
    char ch;
    int x,y;
};
node op[110000];
void change(int k){
    for(int i=1;i<=n;i++){
        a[i]=k%3;
        k/=3;
        b[i]=a[i];
    }
    return ;
}
int o(int a){
    if(a==1) return 0;
    if(a==2) return 2;
    if(a==0) return 1;
    return 0;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    if(c==1||c==2){
        while(t--){
            cin >> n >> m;
            int lim=1,cnt=9999999;
            for(int k=1;k<=n;k++){
                lim*=3;
            }
            for(int i=1;i<=m;i++){
                cin >> op[i].ch;
                if(op[i].ch=='+'||op[i].ch=='-'){
                    cin >> op[i].x >> op[i].y;
                }else{
                    cin >> op[i].x;
                }
            }
            for(int k=0;k<lim;k++){
                change(k);
                int flag=1,ans=0;
                for(int i=1;i<=m;i++){
                    if(op[i].ch=='+') b[op[i].x]=b[op[i].y];
                    if(op[i].ch=='-') b[op[i].x]=o(b[op[i].y]);
                    if(op[i].ch=='T') b[op[i].x]=1;
                    if(op[i].ch=='F') b[op[i].x]=0;
                    if(op[i].ch=='U') b[op[i].x]=2;
                }
                for(int i=1;i<=n;i++){
                    if(a[i]==2) ans++;
                    if(b[i]!=a[i]){
                        flag=0;
                        break;
                    }
                }
                if(flag) cnt=min(cnt,ans);
            }
            cout << cnt << "\n";
        }
    }
    if(c==3||c==4){
        while(t--){
            int cnt=0;
            memset(a,0,sizeof(a));
            cin >> n >> m;
            for(int i=1;i<=m;i++){
                char ch;
                int x;
                cin >> ch >> x;
                if(ch=='T') a[x]=1;
                if(ch=='F') a[x]=0;
                if(ch=='U') a[x]=2;
            }
            for(int i=1;i<=n;i++){
                if(a[i]==2) cnt++;
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}
