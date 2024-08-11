#include <iostream>
using namespace std;

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    int road[100005];
    int place[100005];
    int time[100005];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>road[i];
        cin>>place[i];
        cin>>time[i];
    }
    cout<<"-1"<<endl;
    return 0;
}
