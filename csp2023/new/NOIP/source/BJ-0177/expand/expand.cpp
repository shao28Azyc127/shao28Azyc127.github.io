#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
int x[100050],y[100050];

    int c,n,m,q;
struct stu{
    int l,r;
    bool operator<(const stu &a)const{
        return l<=a.l;
    }
};
set<stu>st[2];
bool wk(){

    int ad=1;
    while(x[1]-y[ad]>0&&ad<=m)ad++;
    ad--;
    if(ad==0){
        return 0;
    }
    st[1].insert({1,ad});
    for(int i=2;i<=n;i++){
        set<stu>nw;
        for(auto it=st[(i-1)%2].begin();it!=st[(i-1)%2].end();it++){
            int l=it->l,r=min(m,it->r+1);
            for(int k=l;k<=r;){
                int a=k,b=k-1;
                while(k<=r&&x[i]-y[k]>0)k++,b++;
                while(k<=r&&x[i]-y[k]<=0)k++;
                if(a<=b){
                    st[i%2].insert({a,b});
                    auto it=st[i%2].end();it--;
                    auto its=it;
                    if(it==st[i%2].begin())continue;
                    it--;
                    if(its->l==it->r+1){
                        st[i%2].erase(its);
                        st[i%2].erase(it);
                        st[i%2].insert({it->l,its->r});
                    }
                }
            }
            int a=r,b=r-1;
            for(int k=r;k<=m;k++){
                if(x[i]-y[k]<=0)break;
                b++;
            }
            if(a<=b){
                    st[i%2].insert({a,b});
            auto it=st[i%2].end();it--;
                    auto its=it;
                    if(it==st[i%2].begin())continue;
                    it--;
                    if(its->l<=it->r+1){
                        st[i%2].erase(its);
                        st[i%2].erase(it);
                        st[i%2].insert({it->l,its->r});
                    }
            }
        }
        if(st[(i)%2].begin()==st[(i)%2].end()){
            return 0;
        }
        st[(i+1)%2].clear();
    }
    if(st[n%2].end()==st[n%2].begin()){
        return 0;
    }
    auto it=st[n%2].end();it--;
    if(it->r==m)return 1;
    else return 0;
    }
int xx1[10050];int yy1[10050];
int main(){

    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)scanf("%d",&x[i]),xx1[i]=x[i];
    for(int i=1;i<=m;i++)scanf("%d",&y[i]),yy1[i]=y[i];
    bool ans=wk();
    if(!ans){
        for(int i=1;i<=max(n,m);i++)swap(x[i],y[i]);
        swap(n,m);
        ans=wk();
        swap(n,m);
    }
    if(ans)cout<<1;
    else cout<<0;
    //return 0;
    while(q--){
        st[0].clear();
        st[1].clear();
        int xcnt,ycnt;
        scanf("%d%d",&xcnt,&ycnt);
        for(int i=1;i<=max(n,m);i++){
            x[i]=xx1[i];y[i]=yy1[i];
        }
        for(int i=1;i<=xcnt;i++){
            int p,xx;
            scanf("%d%d",&p,&xx);
            x[p]=xx;
        }
        for(int i=1;i<=ycnt;i++){
            int p,xx;
            scanf("%d%d",&p,&xx);
            y[p]=xx;
        }
        bool ans=wk();
    if(!ans){
        for(int i=1;i<=max(n,m);i++)swap(x[i],y[i]);
        swap(n,m);
        ans=wk();
        swap(n,m);
    }
    if(ans)cout<<1;
    else cout<<0;
    }
}
