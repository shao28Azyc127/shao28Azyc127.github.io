#include<bits/stdc++.h>
using namespace std;
long long n;
long long ant;
int main(){
    //freopen("apple","w",stdin);
    //freopen("apple","r",stdout);
    cin >>n;
    long long a[1001] = {};
    for(long long i = 0;i<n;i++){
        a[i] = i+1;
    }
    long long k = 0,m=n,w=n;
    while(m>0){
        for(long long i = 0;i<w;i++){
            if(a[i] == n){
                ant = k+1;
            }
            a[i] = 0;
            m--;
            i+=2;
        }
        w=m;
        for(long long i = 0;i<n;i++){
            if(a[i] == 0){
                for(long long j =i;j<n;j++){
                    a[j] = a[j+1];
                }
            }
        }
        k++;
    }
    cout <<k<<" "<<ant;
    return 0;
}