#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
struct land{
    int a,b,c;
}a[100002];
int h[100002];
vector<int> v[100002];
int num=0;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    int x,y,z;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[i]={x,y,z};
    }
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int maxn=-1;
    for(int i=1;i<=n;++i){
        for(int j=i;;++j){
            h[i]+=max(a[i].b+j*a[i].c,1);
            if(h[i]>=a[i].a){
                maxn=max(maxn,j);
                break;
            }
        }
    }
    printf("%d",maxn);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
