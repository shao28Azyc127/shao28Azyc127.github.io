#include<bits/stdc++.h>
using namespace std;
const int N=3001;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int n,m,a[N],b[N],ct[N][30];
char s[N][N];
struct node{
    int id,cnt[30];
}mx[N];
bool cmpmx(node a,node b){
    for(int i=26;i>=1;i--){
        if(a.cnt[i]>b.cnt[i]) return 0;
        else if(b.cnt[i]>a.cnt[i]) return 1;
    }
    return 1;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        mx[i].id=i;
        for(int j=1;j<=m;j++){
            mx[i].cnt[s[i][j]-'a'+1]++;
            ct[i][s[i][j]-'a'+1]++;
        }
    }
    if(n==1){
        cout<<"1";
        return 0;
    }
    sort(mx+1,mx+n+1,cmpmx);
 /*   for(int i=1;i<=n;i++){
        cout<<mx[i].id<<" ";
    }*/
    for(int i=1;i<=n;i++){
        int id=mx[1].id;
        if(mx[1].id==i){
            id=mx[2].id;
        }
        int tot1=0,tot2=0;
        for(int j=1;j<=26;j++){
            for(int k=1;k<=ct[i][j];k++){
                a[++tot1]=j;
            }
        }
        for(int j=26;j>=1;j--){
            for(int k=1;k<=ct[id][j];k++){
                b[++tot2]=j;
            }
        }
        int fl=0;
      /*  for(int j=1;j<=m;j++){
            cout<<a[j]<<" "<<b[j]<<endl;
        }
        cout<<endl;*/
        for(int j=1;j<=m;j++){
            if(a[j]<b[j]){
                fl=1;
                break;
            }else if(b[j]>a[j]){
                fl=0;
                break;
            }
        }
        if(fl==1) cout<<"1";
        else cout<<"0";
    }
    return 0;
}
