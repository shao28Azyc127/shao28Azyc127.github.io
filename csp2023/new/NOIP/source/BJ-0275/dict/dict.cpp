#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
const int inf=0x3f3f3f3f;
int n,m;
struct node{
    string s;
    int id;
} w[N];
int a[N];
bool cmp(node a,node b){
    return a.s<b.s;
}
struct note{
    char minc,maxc;
} w2[N];
void check(string s,int id){
    int len=s.size()+1;
    char c[len];
    for(int i=1;i<len;i++){
        c[i]=s[i-1];
    }
    sort(c+1,c+len);
    w2[id].minc=c[1];
    w2[id].maxc=c[len-1];
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>w[i].s;
        w[i].id=i;
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    sort(w+1,w+n+1,cmp);
    a[w[1].id]=1;
    for(int i=1;i<=n;i++){
        check(w[i].s,w[i].id);
    }
    for(int i=2;i<=n;i++){
        bool flag=true;
        for(int j=1;j<i;j++){
            if(w2[w[j].id].maxc<=w2[w[i].id].minc){
                a[w[i].id]=0;
                flag=false;
                break;
            }
        }
        if(flag){
            a[w[i].id]=1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}