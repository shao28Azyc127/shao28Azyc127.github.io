#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int len=1e5+10;
int c,t;
char value[len][2];//1µ½n
int ans[6];
int vis[len];
int num_u=0;
queue<int> q;
void dfs(int p){
    if(vis[p]>2){
        int f=q.front();
        int tag=1;
        q.pop();
        while(!q.empty()){
            int temp=q.front();
            //printf("front=%c,tag=%c\n",value[f][0],value[f][1]);
            if(value[temp][1]=='-') tag*=-1;
            //printf("value[%d][0]=%c,tag=%d\n",temp,value[temp][0],tag);
            if((value[temp][0]==value[f][0])&&(tag==-1)){
                num_u++;
                break;
            }
            q.pop();
        }
        while(!q.empty()) q.pop();
    }
    else{
        vis[p]++;
        q.push(p);
        if(value[p][0]=='T'||value[p][0]=='F'||value[p][0]=='U') return;
        dfs(value[p][0]-'0');
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){//1
        int n,m;
        num_u=0;
        cin>>n>>m;
        for(int j=1;j<=n;j++){
            char ch=j+'0';
            value[j][0]=ch;
            value[j][1]='+';
        }
        for(int j=0;j<m;j++){
            char v;
            cin>>v;
            int i0,j0;
            if(v=='T'){
                cin>>i0;
                value[i0][0]=v;
                value[i0][1]='+';
            }
            if(v=='F'){
                cin>>i0;
                value[i0][0]=v;
                value[i0][1]='+';
            }
            if(v=='U'){
                cin>>i0;
                value[i0][0]=v;
                value[i0][1]='+';
            }
            if(v=='+'){
                cin>>i0>>j0;
                value[i0][0]=value[j0][0];
                value[i0][1]=value[j0][1];
            }
            if(v=='-'){
                cin>>i0>>j0;
                value[i0][0]=value[j0][0];
                if(value[j0][1]=='+') value[i0][1]='-';
                else value[i0][1]='+';
            }
        }
        if((c==3)||(c==4)){
            for(int j=1;j<=n;j++){
                if(value[j][0]=='U') num_u++;
            }
        }
        else{
            for(int j=1;j<=n;j++){
                memset(vis,0,sizeof(vis));
                dfs(j);
                int pd=0;
                while(!q.empty()){
                    int temp=q.front();
                    if(value[temp][0]=='U') pd=1;
                    q.pop();
                }
                num_u+=pd;
            }
        }
        ans[i]=num_u;
    }
    for(int i=0;i<t;i++) cout<<ans[i]<<endl;
    return 0;
}
