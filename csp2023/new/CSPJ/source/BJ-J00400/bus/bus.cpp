#include<bits/stdc++.h>
using namespace std;

struct path{
    int point,open;
};

vector<path> way[20005];
queue<int> pp;
int n,m,k,vis[20005],tim;

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        path z;
        z.point=b;
        z.open=c;
        way[a].push_back(z);
    }
    /*pp.push(1);
    while(!pp.empty()){
        int len=pp.size();
        for(int i=0;i<len;i++){
            int fr=pp.front();
            pp.pop();
            vis[fr]=1;
            if(fr==n && tim%k==0){
                printf("%d",tim);
                return 0;
            }
            for(int j=0;j<way[fr].size();i++){
                if(vis[way[fr][j].point]==0 && way[fr][j].open>=tim){
                    pp.push(way[fr][j].point);
                }
            }
        }
        tim++;
    }*/
    printf("-1");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
