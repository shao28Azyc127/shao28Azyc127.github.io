#include<bits/stdc++.h>
using namespace std;
const int N=2100000,M=131;
unsigned long long h1[N],h2[N],p[N];
int n,cnt,ans,vis[N],cnt2,same[N],pe[N];
char str[N];
struct node{
    int st,ed;
}pos[N];
bool check(int l,int r){
    if(h1[r]-h1[l-1]*p[r-l+1]==h2[l]-h2[r+1]*p[r-l+1]) return 1;
    return 0;
}
int cmp(node a,node b){
    return a.st==b.st ? a.ed<b.ed : a.st<b.st;
}
inline int read(){
    int x=0,w=1;
    char ch=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*w;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    //cout << (sizeof(h1)+sizeof(h2)+sizeof(vis)+sizeof(p)+sizeof(str)+sizeof(pos))/1024/1024;
    n=read();
//    same[1].st=1;
    for(int i=1;i<=n;i++){
        str[i]=getchar();
        h1[i]=h1[i-1]*M+str[i];
    }
    p[0]=1;
    int l=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*M;
        if(str[i+1]!=str[i]){
            same[l]=i;
            l=i+1;
        }
    }
    for(int i=n;i>=1;i--){
        h2[i]=h2[i+1]*M+str[i];
    }
    for(int i=1;i<=n;i++){
        if(str[i]==str[i+1]){
            int r=min(n-i,i),l=1,p=0;
            while(l<=r){
                int mid=l+r>>1;
                if(check(i+1-mid,i+mid)){
                    l=mid+1;
                    p=mid;
                }else{
                    r=mid-1;
                }
             }
             if(p!=0){
                pos[++cnt].st=i-p+1;
                pos[cnt].ed=i+p;
                ans+=pos[cnt].ed-pos[cnt].st+1>>1;
             }
        }
    }
    //cout << ans << endl;
    sort(pos+1,pos+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        //cout << pos[i].st << " " << pos[i].ed << endl;
    }
    for(int i=1;i<=cnt;i++){
        int cnt1=0,flag=i;
        for(int j=i+1;j<=cnt;j++){
            if(pos[j].st<pos[flag].ed) continue;
            if(pos[j].st>pos[flag].ed+1||str[pos[j].st]==str[pos[i].ed]){
                break;
            }
            if(pos[j].st==pos[flag].ed+1){
                if(same[pos[i].st]==0||same[pos[j].st]==0) ans+=1;
                else ans+=((same[pos[i].st]-pos[i].st+1)/2)*((same[pos[j].st]-pos[j].st+1)/2);
                //cout << pos[i].st << " " << pos[i].ed << " " << pos[j].st << " " << ans << endl;
                cnt1++;
                flag=j;
            }
        }
    }
    cout << ans;
    return 0;
}
