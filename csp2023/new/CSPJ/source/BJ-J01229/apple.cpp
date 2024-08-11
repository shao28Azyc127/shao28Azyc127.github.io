#include<bits/stdc++.h>
using namespace std;

bool a[1000000005];

int main(){

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n;cin>>n;
    int nn = n;
    int day = 0;
    int ntime;
    while(n>0){
        for(int i=1,j=0;i<=nn;i++){
            if(a[i] == true) {continue;}
            else j++;
            if(j%3== 1){
                a[i] = true;
                n--;
                if(i==nn) ntime = day+1;
            }
        }
        day++;
    }

    cout<<day<<" "<<ntime;

    fclose(stdin);
    fclose(stdout);








    return 0;
}
