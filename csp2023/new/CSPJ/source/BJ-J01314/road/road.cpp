#include<iostream>
using namespace std;
int n , d , v[100005] , a[100005] , s = 0;
int main () {
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin >> n >> d;
    for (int i = 0 ; i < n-1 ; i++)
        cin >> v[i];
    for (int i = 0 ; i < n ; i++)
        cin >> a[i];
    int sum , res = 0;
    for (int i = 0 ; i < n-1 ; ) {
        sum = 0;
        int j = i;
        while (a[j] >= a[i] && j < n)
            j++;
        for (int k = i ; k < j ; k++)
            sum+=v[k];
        sum-=res;
        res = d - sum%d;
        if (res == 0)
            s+=sum/d*a[i];
        else
            s+=(sum+res)/d*a[i];
        i = j;
    }
    cout << s;
    return 0;
}
