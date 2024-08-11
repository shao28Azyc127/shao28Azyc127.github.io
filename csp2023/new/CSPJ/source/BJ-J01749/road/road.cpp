#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;

ll n,d=0,a[100005] = {},b[100005][2] = {100005},f,cnt=0,c = 0,o=0,s =0;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ll i;
    cin>> n >>d;
    for(i=1;i<n;i++){
        cin>> a[i];
        a[i] += a[i-1];
    }
    a[n] = a[n-1];
    for(i=1;i<=n;i++){
        cin>> f;
        if(f < b[cnt][0]){
            cnt += 1;
            b[cnt][0] = f;
            b[cnt][1] = i;
        }
    }
    b[cnt+1][1] = n;

    for(i=1;i<=cnt;i++){
        o = (a[b[i+1][1]-b[i][1]])-c*d+o;
        if(b[i][1] == n){
            break;
        }
        if(o%d == 0){
            c = o/d;
        }
        else{
            c = o/d+1;
        }
        s += c*b[i][0];
    }

    cout<<s;

    fclose(stdin);
    fclose(stdout);
    return 0;
}