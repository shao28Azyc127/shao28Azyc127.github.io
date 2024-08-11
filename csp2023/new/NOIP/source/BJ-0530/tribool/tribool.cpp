#include<iostream>
using namespace std;
int c,t;
int n,m;
int fa[200010];

//T:-1 F:-2 U:-3;
int rev(int org){
    if(org==-1){
        return -2;

    }
    else if(org==-2){
        return -1;
    }else if(org==-3){
    return -3;
    }
    else if(org<=n){
        return org+n;
    }else{
    return org-n;}
}
int mrk[100001];
int vis[100001];
int val[100001];
int getv(int x,int step){
    // cout << ">"<< x<< ' '<< step << endl;
    if(val[x]!=0){
        return val[x];
    }
    if(fa[x]<0){
        val[x] = fa[x];
        return val[x];
    }
    if(vis[x]){
        if((step-mrk[x])%2==1){
            val[x] = -3;
        }else{
            val[x] = -1;
        }
        return val[x];
    }
    vis[x] = 1;
    mrk[x] = step;
    int f = 0;
    if(fa[x]>n){
        f = 1;
        fa[x]-=n;
    }

    val[x] = getv(fa[x],step+f);
    return val[x];
}

void problem1(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=2*n;i++){
        fa[i] = i;
        if(i<=n){mrk[i] = 0;
        vis[i] = 0;
        val[i] = 0;
      }
    }
    char op;
    int x,y;
    for(int i = 1;i<=m;i++){
        cin >> op;
        scanf("%d",&x);
        if(op=='T'){
            fa[x] = -1;
        }else if(op=='F'){
            fa[x] = -2;
        }else if(op=='U'){
            fa[x] = -3;
        }else if(op=='+'){
            scanf("%d",&y);
            fa[x] = fa[y];
        }else{
            scanf("%d",&y);
            fa[x] = rev(fa[y]);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i])getv(i,0);
     //   if(val[i]==-3)ans++;
    }
    for(int i = 1;i<=n;i++){
        if(val[i]==-3)ans++;
   //cout << i <<' '<< fa[i]<<' '<< val[i]<< endl;

    }
   // cout << endl;
    cout << ans<< endl;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
       //     cout << t << endl;
        problem1();
    }
    return 0;
}
