#include<bits/stdc++.h>
using namespace std;
long long d(int a,int b,int c,int del){
    return (-b + sqrt(del))*(2*a);
}

int main(){
    freopen("r","uqe.in",stdin);
    freopen("w","uqe.out",stdout);
    int T,M;
    cin >>T>>M;
    for(int i = 1;i <= T;i++){
        int a,b,c;
        cin >> a >>b >> c;
        long long del = pow(b,2) - (4*a*c);
        if(del >= 0){
            cout << d(a,b,c,del) << endl;
        }
        else{
            cot << "NO" << endl;
        }
    }
    return 0;
}
