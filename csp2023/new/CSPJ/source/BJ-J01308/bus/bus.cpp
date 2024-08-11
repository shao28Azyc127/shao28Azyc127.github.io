#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct dot{
    bool pcan=0,can=0;
    vector<pair<dot*,size_t>> b;
    void make(size_t time){
        for(auto i:b){
            if(i.second<=time){
                i.first->can=1;
            }
        }
    }
}arr[10005];
size_t n,m,k,a,b,c,mc=0;
bool judge;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(size_t i=0;i<m;i++){
        cin>>a>>b>>c;
        mc=max(mc,c);
        arr[a].b.push_back(pair<struct dot*,size_t>(&arr[b],c));
    }
   /* for(size_t i=1;i<=n;i++){
        for(auto j:arr[i].b)
            cout<<j.first-(dot*)arr<<' '<<j.second<<endl;
        cout<<endl;
    }
    exit(0);*/
    for(size_t s=0;s<=mc;s+=k){
        arr[1].pcan=1;
        for(size_t i=s+1;i<10000;i++){
            judge=1;
            for(size_t j=1;j<=n;j++){
                if(arr[j].pcan){
                    arr[j].make(i);
                    judge=0;
                }
            }
            if(judge) break;
            for(size_t j=1;j<=n;j++){
                arr[j].pcan=arr[j].can;
                arr[j].can=0;
                //cout<<arr[j].pcan<<' '<<arr[j].can<<endl;
            }
            //cout<<endl;
            if(i%k==0&&arr[n].pcan){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}