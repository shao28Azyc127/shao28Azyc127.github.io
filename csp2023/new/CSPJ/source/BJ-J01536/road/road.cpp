#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d,a[100005],b[100005];
    cin >> n >> d;
    for(int i=1;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    long long s=0,k=0,l=0,q=0,p=0;
    for(long long i=1;i<n;i++){
        if(l>=a[i])l-=a[i];
        else{
            if(b[i]>b[i+1]){
                k = ceil((a[i]-l)*1.0/d);
                s += k*b[i];
                l = k*d-a[i]+l;
                //cout <<l;
                //cout << k;
            }
            else{
                for(long long j=i;j<n;j++){
                    if(b[j] <= b[j+1]){
                        q+=1;
                        p+=a[j];
                    }
                    else{
                        p+=a[j+1];
                        break;
                    }
                }
                k = ceil((p-l)*1.0/d);
                s += k*b[i];
                l = k*d-p+l;
                i+=q;
                //cout <<l;
                //cout << k;
            }
            p=0;
            q=0;
        }
    }
    cout << s;
    return 0;
}
