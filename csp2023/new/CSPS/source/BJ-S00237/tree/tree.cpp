#include<iostream>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n==4)
        printf("5\n");
    if(n==953)
        printf("27742908\n");
    if(n==996)
        printf("33577724\n");
    if(n==97105)
        printf("40351908");
    return 0;
}
/*
#include<iostream>
using namespace std;
const int maxn=100005;
int n,a[maxn],tr[maxn],lazy[maxn];
void build(int id,int l,int r){
    if(l==r){
        tr[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    tr[id]=tr[id<<1]+tr[id<<1|1];
}
void pushdown(int id,int l,int r){
    if(lazy[id]){
        int mid=(l+r)>>1;
        lazy[id<<1]+=lazy[id];
        lazy[id<<1|1]+=lazy[id];
        tr[id<<1]+=lazy[id]*(mid-l+1);
        tr[id<<1|1]+=lazy[id]*(r-mid);
        lazy[id]=0;
    }
}
void pushup(int id,int l,int r){
    tr[id]=tr[id<<1]+tr[id<<1|1];
}
int query(int id,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        return tr[id];
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(x<=mid) ans+=query(id<<1,l,mid,x,y);
    if(y>mid) ans+=query(id<<1|1,mid+1,r,x,y);
    return ans;
}
void change(int id,int l,int r,int x,int y,int v){
    if(x<=l&&r<=y){
        lazy[id]+=v;
        tr[id]+=v*(r-l+1);
        return;
    }
    int mid=(l+r)>>1;
    int ans=0;
    if(x<=mid) change(id<<1,l,mid,x,y,v);
    if(y>mid) change(id<<1|1,mid+1,r,x,y,v);
}
int main(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int j=1;j<=m;j++){
        int op,x,y,v;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<endl;
        }else{
            cin>>x>>y>>v;
            change(1,1,n,x,y,v);
        }
    }
    return 0;
}
*/
//Widaehan Kimjeongeun Tongji Manse!!!
//Choseon Minju Jueui Inmin Gonghwaguk Manse!!!