#include<iostream>
using namespace std;
const int N=1e6+5;
int n,cnt,apples[N];
bool took[N];
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) {
        apples1[i]=i;
    }
    while(took[n]==true) {
        for(int i=1;i<=n;i+=3) {
            took[i]=true;
            apples[i]=0;
        }
        for(int i=1;i<=n;i++) {
            if(apples[i]!=0&&i!=1) {
                if(apples[i-2]==0) {
                    apples[i-2]=apples[i];
                } else if(apples[i-1]==0) {
                    apples[i-1]=apples[i];
                }
            }
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}