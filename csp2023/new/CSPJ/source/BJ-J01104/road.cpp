#include <bits/stdc++.h>
using namespace std;
int cost[100005],dis[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,totalcost=0,totaloil=0,totaldis=0,cur=0;
    cin >> n >> d;
    for (int i = 0;i < n-1;i++) cin >> dis[i];
    for (int i = 0;i < n;i++) cin >> cost[i];
    for (int i = 0;i < n-1;i++){
        if (cost[i] < cost[cur]) cur = i;
        totaldis += dis[i];
        if ((totaldis-totaloil*d)%d == 0){
            totalcost += (totaldis-totaloil*d)/d*cost[cur];
            totaloil += (totaldis-totaloil*d)/d;
        }
        else {
            totalcost += max(((totaldis-totaloil*d)/d+1)*cost[cur],0);
            totaloil += max((totaldis-totaloil*d)/d+1,0);
        }

    }
    cout << totalcost;
    return 0;
}
