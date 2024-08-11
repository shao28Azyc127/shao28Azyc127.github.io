#include<bits/stdc++.h>
using namespace std;
long long a[100005],v[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,you,sum = 0,num,cost = 0,costyou = 0,minn = 1e9;
    cin >> n >> you;
    for(long long i = 1;i < n;i++){
        cin >> v[i];
        sum += v[i];
    }
    long long last = sum % you;
    sum -= last;
    num = sum / you;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
        minn = min(minn,a[i]);
    }
    cost = a[1] * num;
    costyou = a[1];
    sum -= v[1];
    //cout << cost << " " << 1 << " " <<  sum << " + " <<  last  << endl;
    for(long long i = 2;i < n;i++)
    {
        int t = (sum - you + (sum - 1) % you + 1) / you;
        if(a[i] <= costyou){
            cost -= t * (costyou - a[i]);
            costyou = a[i];
            //cout << cost << " " << i << " " << sum << " + " <<  last  << endl;
        }
        sum -= v[i];
    }
    if(last != 0)cost += minn;
    cout << cost << endl;
    return 0;
}