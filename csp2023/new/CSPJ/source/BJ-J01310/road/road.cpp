#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0,y=0,ss=0,dd=0,kk=0;
    scanf("%d %d",&n,&d);
    int v[n+5],a[n+5],b[n+5];
    b[0] = 0;
    v[0] = 0;
    for(int i = 1;i <= n - 1;i ++){
        cin >> v[i];
        b[i] = v[i] + b[i-1];
    }
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    for(int i = 0;i < n-1;i ++){
        dd = dd - v[i];
        if(dd > v[i +1]){
            continue;
        }
        for(int j = 1;j <n;j ++){
            if(a[j] < a[i]){
                y = j - i;
                break;
            }
        }
        if(y == 0){
            y = n-1-i;
        }
        if(y < 0){
            continue;
        }
        ss= ceil(double(b[i+y] - b[i]-dd)/d);
        sum += ss * a[i];
        dd += ss * d;
        y = 0;
    }
    cout << sum;
    return 0;
}
