#include<fstream>

using namespace std;

ifstream cin ("road.in");
ofstream cout ("road.out");
const int N = 1e5 + 10;
long long mi,n,d,a[N],b[N],ans,cnt;
int main(){
    cin >> n >> d;
    for(int i = 1;i < n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        cin >> b[i];
        mi = max(mi,b[i]);
    }
    mi ++;
    for(int i = 1;i < n;i ++){
        mi = min(mi,b[i]);
        if((a[i] - cnt) % d == 0){
            ans = ans + (mi * (a[i] / d));
            cnt = 0;
        } else {
            a[i] = a[i] - cnt;
            ans = ans + (mi * ((a[i] / d) + 1));
            cnt = (d * ((a[i] / d) + 1)) - a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
