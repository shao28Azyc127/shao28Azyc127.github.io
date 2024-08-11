#include <iostream>
using namespace std;
int main(){
	freopen("road.in","r",stdin)
	freopen("rode.out","w",stdout)
    int x,y;
    cin >>  x >> y;
    int w;
    int n[x],m[x];
    for (int i=0;i<x-1;i++) cin >> n[i];
    for (int i=0;i<x;i++) cin >> m[i];
    for (int i=0;i<x-1;i++) w += n[i];
    if (w%y) cout << ((w/y)+1) *m[0] << endl;
    else cout << (w/y)*m[0]<< endl;
    return 0;
}