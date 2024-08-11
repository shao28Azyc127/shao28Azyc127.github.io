//zyc AK IOI
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a,b,c;
bool flag;
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> n;
    while(t--){
        cin >> a >> b >> c;
        long long x=b*b-4*a*c;
        if (x<0){
            cout << "NO" << endl;
            continue;
        }
        if (x==0){
            cout << sqrt(a) << endl;
            continue;
        }
        int f=-b/a;
        int d=c/a;
        if (c==0) {
                cout << f << endl;
                continue;
        }

        for (int i=-n;i*i>d;i++){
            if (d%i==0&&i+(d/i)==f){
                cout << max(i,d/i) << endl;
                flag=true;
                break;
            }
        }
        if (flag==false)
        for (int i=1;i*i<=d;i++){
            if (d%i==0&&i+(d/i)==f){
                cout << max(i,d/i) << endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}