#include<fstream>

using namespace std;

ifstream cin ("apple.in");
fstream cout ("apple.out");
long long n,m,cnt,ans;
bool f = false;
int main(){
    cin >> n;
    m = n;
    while(true){
        cnt ++;
        if(m % 3 == 1 && f == false){
            ans = cnt;
            f = true;
        }
        if(n % 3 == 0){
            n = m = n - (n / 3);
        } else {
            n = m = n - (n / 3) - 1;
        }
        if(n == 0){
            break;
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
