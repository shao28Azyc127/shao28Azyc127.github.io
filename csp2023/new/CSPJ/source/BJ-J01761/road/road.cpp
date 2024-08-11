#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    ll total=0;
    for(int i=0;i<n-1;i++){
        int ls;
        cin>>ls;
        total+=ls;
    }int cost;
    cin>>cost;
    cout<<total/(d+0.0)*cost+(total/d==total/(d+0.0)?0:cost);
    return 0;
}
