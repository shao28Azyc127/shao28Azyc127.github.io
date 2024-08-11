#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+5;

int n,d;
int arr[N], drr[N];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int a = 1;
    cin >>n >>d;
    for(int i=1;i<n;i++) cin >> drr[i];
    for(int i=1;i<=n;i++){
         cin >> arr[i];
    }
    LL dist = drr[1], sum = 0, cost = arr[1], last = 0;
    for(int i=2;i<=n;i++){
        //printf("%lld %lld %lld %lld %d ", dist, sum, cost, last, arr[i]);
        if(arr[i] < cost){

            int sheng = (dist - last) / d;
            if((dist - last) % d != 0) sheng += 1;
            sum += sheng * cost;
            last = last + sheng * d - dist;
            dist = 0;
            cost = arr[i];
            //cout << sheng;
        }
        //cout << endl;
        dist += drr[i];
    }
    cout << sum;



    return 0;
}
