#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N=100010;
int shu[N][3],fa[N],ving[N];
queue<int> q,qq;
vector<int> vedd[N];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,m;
    for(int k=1;k<=t;k++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            shu[i][0]=0;
            shu[i][1]=0;
            shu[i][2]=0;
        }
        for(int i=1;i<=m;i++){
            char a;
            cin>>a;
            if(a=='T' || a=='F' || a=='U'){
                int x;
                cin>>x;
                if(a=='T')
                    shu[x][1]=1;
                else if(a=='F')
                    shu[x][1]=-1;
                else
                    shu[x][1]=2;
                q.push(x);
            }
            if(a=='+' || a=='-'){
                int x,y;
                cin>>x>>y;
             //   if(shu[y][1]!=0){
             //       if(a=='+')
             //           shu[x][1]=shu[y][1];
             //       else
              //          shu[x][1]=shu[y][1]*(-1);
             //   }
              //  else{
                    if(a=='+')
                        shu[x][0]=1;
                    else
                        shu[x][0]=-1;
                    shu[x][2]=y;
                    ving[x]=y;
                    vedd[y].push_back(x);
              //  }
            }
        }
        while(q.size()){
            int x;
            x=q.front();
            q.pop();
            for(int j=0;j<vedd[x].size();j++){
                if(shu[vedd[x][j]][0]==1)
                    shu[vedd[x][j]][1]=shu[x][1];
                else if(shu[vedd[x][j]][0]==-1)
                    shu[vedd[x][j]][1]=shu[x][1]*(-1);
                q.push(vedd[x][j]);
            }
        }
        for(int i=1;i<=n;i++){
            if(shu[i][1]==0){
                shu[i][1]=1;
                q.push(i);
                qq.push(i);
                while(q.size()){
                    int x;
                    x=q.front();
                    q.pop();
                    for(int j=0;j<vedd[x].size();j++){
                        if(vedd[x][j]==i)
                            continue;
                        if(shu[vedd[x][j]][0]==1)
                            shu[vedd[x][j]][1]=shu[x][1];
                        else if(shu[vedd[x][j]][0]==-1)
                            shu[vedd[x][j]][1]=shu[x][1]*(-1);
                        q.push(vedd[x][j]);
                        qq.push(vedd[x][j]);
                     //   cout<<x<<" "<<vedd[x][j]<<endl;
                    }
                }
                bool flag=false;
                    if(shu[i][1]!=shu[i][0]*shu[ving[i]][i] &&shu[i][0]!=0)
                        flag=true;
                while(qq.size()){
                    int x=qq.front();
                    qq.pop();
                    if(flag)
                        shu[x][1]=2;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(shu[i][1]==2 || shu[i][1]==-2)
               cnt++;
        cout<<cnt<<endl;
        while(q.size())
            q.pop();
        for(int i=1;i<=n;i++){
            ving[i]=0;
            vedd[i].clear();
        }
    }
    return 0;
}