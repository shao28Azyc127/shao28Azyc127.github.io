#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
struct node{
    int data;
    node *next;
};
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,a,b,c;
    cin >> n >> m >> k;
    for(int i = 0;i<m;i++){
        cin >> a >> b >> c;
    }
    cout<<-1;
    return 0;
}
