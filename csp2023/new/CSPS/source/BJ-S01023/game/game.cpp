#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2000005;
char s[MAXN];
int n,ans=0;
//int h[MAXN]; // highlight the beginning(1) and end(-1)
//int b[MAXN], e[MAXN]; // beginning and ending list
vector<int> b[MAXN]; // reduceable strings beginnings (end with i)
vector<int> e[MAXN];
void mer(int l, int le, int rb, int r, bool deleted){ //merge
    int llen=le-l+1, rlen=r-rb+1;
    if(!llen || !rlen){
        return;
    }
    if(s[le]==s[rb]){
        e[le].push_back(rb),b[rb].push_back(le);
        mer(l,le-1,rb+1,r,true);
    }
    if(deleted){
        {
            for(int j:e[rb]){
                if(j>r) continue;
                mer(l,le,j+1,r,false);
            }
        }
        {
            for(int i:b[le]){
                if(i<l) continue;
                mer(l,i-1,rb,r,false);
            }
        }
        for(int i:b[le]){
            if(i<l) continue;
            for(int j:e[rb]){
                if(j>r) continue;
                e[i].push_back(j),b[j].push_back(i);
                mer(l,i-1,j+1,r,false);
            }
        }
    }
}
void f(int l, int r){ //range:[l,r]
    if(l==r) return;
    if(l+1==r){
        if(s[l]==s[r]){
            e[l].push_back(r),b[r].push_back(l);
        }
        return;
    }
    if(l+2==r){
        if(s[l]==s[l+1]) e[l].push_back(l+1),b[l+1].push_back(l);
        if(s[l+1]==s[r]) e[l+1].push_back(r),b[r].push_back(l+1);
        return;
    }
    int mid=(l+r)>>1;
    f(l,mid);
    f(mid+1,r);
    mer(l,mid,mid+1,r,true);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s);
    f(0,n-1);
    ans=0;
    for(int i=0;i<n;++i){
        sort(e[i].begin(),e[i].end());
        for(int j=0;j<e[i].size();++j){
            if(!j) ++ans;
            else if(e[i][j]!=e[i][j-1]) ++ans;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
