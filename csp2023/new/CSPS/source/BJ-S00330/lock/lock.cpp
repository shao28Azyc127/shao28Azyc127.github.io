#include<bits/stdc++.h>
using namespace std;
int n,num[10],number[10],ans;
bool check[100010][10];
int g() {
    int result=0;
    for (int a=1;a<=5;a++) {
        result*=10;
        result+=number[a];
    }
    return result;
}
int main () {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >>n;
    for (int a=1;a<=n;a++) {
        for (int b=1;b<=5;b++) {
            cin >>num[b];
            number[b]=num[b];
        }
        for (int b=1;b<=5;b++) {//1
            for (int c=0;c<=9;c++) {
                if (num[b]==c) continue;
                number[b]=c;
                check[g()][a]=true;
                //cout <<a<<" "<<b<<" "<<c<<" "<<g()<<endl;
            }
            number[b]=num[b];
        }
        for (int b=1;b<=4;b++) {//2
            for (int c=1;c<=9;c++) {
                number[b]=num[b]+c;
                number[b+1]=num[b+1]+c;
                number[b]%=10;
                number[b+1]%=10;
                check[g()][a]=true;
            }
            number[b]=num[b];
            number[b+1]=number[b+1];
        }
    }
    ans=0;
    for (int a=0;a<=99999;a++) {
        int l=0;
        for (int b=1;b<=5;b++) {
            if (check[a][b]) l++;
            //cout <<check[a][b]<<" ";
        }
        //cout <<endl;
        if (l==n) ans++;
    }
    cout <<ans;
    return 0;
}
