#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d,m = 0,y = 0,all = 0,e = 0;
    cin>>n>>d;
    int v[10001],a[10001],b[10001],s[10001];
    for (int i = 0;i < n-1;i++){
        cin>>v[i];
        all += v[i];
    }
    for (int i = 0;i < n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    if (b[0] == a[0]){
        if (all%d) cout<<all/d*a[0]+1<<endl;
        else  cout<<all/d*a[0]<<endl;
        return 0;
    }
    int l = 0,r = n-1,p=n,q = 0;
    while (l < r){
        for (int i = 0;i < p;i++){
            if (b[q] == a[i]){
                r = i;
                break;
            }
        }
        for (int i = r;i < p;i++){
            y = v[i]/d;
            m += y*b[q];
            e += y;
        }
        q++;
        p=r;
    }
    cout<<m<<endl;
    return 0;
}
