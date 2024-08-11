#include <bits/stdc++.h>
using namespace std;
int upget(int x,int y)
{
    if(x==0 || y==0){
        return 0;
    }
    int a=x/y;
    if(y*a==x){
        return a;
    }
    else{
        return a+1;
    }
}
struct info{
    int cost,tonext;
};
const int MAX=1e5;
info st[MAX];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;//站点数量、车前进距离
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>st[i].tonext;
    }
    for(int i=1;i<=n;i++){
        cin>>st[i].cost;
    }
    int remain=0,allcost=0;//上次剩余，总花费
    for(int i=1;i<=n;i++){
        if(remain<st[i].tonext){//到不了下一站
            int disto=0;
            for(int j=i;j<=n;j++){//计算到比当前站便宜的下一站到本站距离
                if(st[j].cost<st[i].cost){
                    break;
                }
                else{
                    disto+=st[j].tonext;
                }
            }
                int need=upget(disto-remain,d);//需要加油L=到那一站距离 减去上次剩余的距离/车前进距离,
                int have=remain+need*d;//现在能跑:剩余距离+加油的距离
                allcost+=need*st[i].cost;//需要加的油*本站单价=总花费
                remain=have-st[i].tonext;
                //cout<<i<<" "<<need<<" "<<have<<" "<<remain<<endl;
        }
        else{//到的了下一站
            remain-=st[i].tonext;//耗费剩余油
        }
    }
    cout<<allcost;
    return 0;
}
