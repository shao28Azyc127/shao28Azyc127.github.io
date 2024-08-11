 #include<bits/stdc++.h>
using namespace std;
int n,m;
int tag[100050];
int ans=0;
void init(){
    memset(tag,0,sizeof(tag));
    ans=0;
}int topt(char x){
    if(x=='T') return 1;
    if(x=='F') return 2;
    if(x=='U') return 3;
    if(x=='+') return 4;
    if(x=='-') return 5;
}
void slv1(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        getchar();
        int opt=topt(getchar());
        int x;
        scanf("%d",&x);
        tag[x]=opt;
    }for(int i=1;i<=n;i++){
        if(tag[i]==3) ans++;
    }printf("%d\n",ans);
}int sub;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int _;cin>>sub>>_;
    while(_--){
        init();
        if(sub==3||sub==4) slv1();
    }
    return 0;
}
