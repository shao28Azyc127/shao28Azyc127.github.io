#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int n,d;
stack<int> point;
void selve(int l,int r,int* a){
    if(l>=r){return;}
    int m = l;
    for(int i=l+1;i<r;++i){
        if(a[i]<a[m]){
            m = i;
        }
    }
    point.push(m);
    selve(l, m, a);
}
int f(unsigned long* v, int* a){
    int v1 = 0, k = 0;
    while(point.size()>1){
        int l = point.top();
        point.pop();
        int r = point.top();
        k = (d - (v[r] - v[l] + k)%d)%d;
        int p =  ceil((v[r] - v[l] - k) / d)* a[l];
        v1 += p;
    }
    return v1;
}
int main(){
    cin>>n>>d;
    unsigned long v[n];
    int a[n];
    v[0] = 0;
    for(int i=1;i<n;++i){ cin>>v[i]; v[i] += v[i-1]; }
    for(int i=0;i<n;++i){ cin>>a[i]; }
    selve(0,n, a);
    cout<<f(v,a);
}