#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
long long n,ans;
double d;
long long v[100010];
long long a[100010];
stack<int> sta;
long long f[100010];
long long sum[100010];
int main (){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i ++){
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }
    cin >> a[1];
    long long minn = a[1];
    sta.push(1);
    for(int i = 2; i <= n; i ++){
        cin >> a[i];
        minn = min(minn, a[i]);
        if(a[i] > a[sta.top()]){
            if(i != n){
                f[sta.top()] = i + 1;
            }
        }
        else{
            sta.pop();
            sta.push(i);
        }
    }
    int i = 1; 
    double oil = 0;
    while(i < n){
        if(f[i] == 0){
            if(v[i] - d * oil > 0){
                double add = ceil((v[i] - d * oil) / d);
                double have = (v[i] - d * oil) / d;
                ans += add * a[i];
                oil = add - have;
            }
            else{
                oil -= v[i] / d;
            }
            i ++;
        }
        else{
            if((sum[f[i] - 1] - sum[i - 1]) - d * oil > 0){
                double add = ceil(((sum[f[i] - 1] - sum[i - 1]) - d * oil) / d);
                double have = ((sum[f[i] - 1] - sum[i - 1]) - d * oil) / d;
                ans += add * a[i];
                oil = add - have;
            }
            else{
                oil -= (sum[f[i] - 1] - sum[i - 1]) / d;
            }
            i = f[i];
        }
    }
    cout << ans;
    return 0;
}