#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int v[100010], a[100010];
int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
    int n, d;
    cin>>n>>d;
    int s = 0;
    for(int i=1;i<=n-1;i++) {
            cin>>v[i];
            s+=v[i];
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans = 0;
    int need = ceil(s/d);
    ans = need * a[1];
    cout<<ans-1<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
}