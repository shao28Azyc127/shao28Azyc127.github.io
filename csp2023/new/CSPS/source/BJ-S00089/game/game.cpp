#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int N=810;
struct Node{
    int l,r;
};
//map<Node,bool> mp;
bool vis[N][N];
int e[N],b[N];
int se[N],sb[N];
string s;
int n;
int sum;
void solve(int x,int y){
    if(!vis[x][y]) sum++;
    vis[x][y]=true;
    //cout<<x<<" "<<y<<endl;
    vis[x][y]=true;
    e[y]=x,b[x]=y;
    se[y]++,sb[x]++;
    if(x-1>=1&&y+1<=n&&s[x-1]==s[y+1]) solve(x-1,y+1);
    if(!vis[e[x-1]][y]&&e[x-1]!=0){
        sum+=se[x-1];
        vis[e[x-1]][y]=true;
        //cout<<"left"<<endl;
        solve(e[x-1],y);
    }
    if(!vis[x][b[y+1]]&&b[y+1]!=0){
        sum+=sb[y+1];
        vis[x][b[y+1]]=true;
        //cout<<"right"<<endl;
        solve(x,b[y+1]);
    }
    //cout<<sum<<endl;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s="#"+s;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]==s[i+1]){
            sum=0;
            solve(i,i+1);
            ans+=sum;
        }
    }
    cout<<ans<<endl;
    return 0;
}
