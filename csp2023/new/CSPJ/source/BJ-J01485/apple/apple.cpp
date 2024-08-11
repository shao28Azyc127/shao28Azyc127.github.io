#include<iostream>
#include<cstdio>
using namespace std;
int n, nc;
bool c[1000000009];
int ans1, ans2;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin>>n;
    nc=n;
    int i=0, j=1, ih=0;
    while(nc>0){
        i++;

        if(i>n&&ih>nc){
            i=0;
            ih=0;
            j++;
            continue;
        }

        if(c[i]) continue;
        ih++;
        if(ih%3==1){
            //cout<<i<<" ";
            c[i]=true;
            if(i==n){
                ans2=j;
            }
            nc--;
        }
    }

    cout<<j<<" "<<ans2;


    fclose(stdin);
    fclose(stdout);
}
