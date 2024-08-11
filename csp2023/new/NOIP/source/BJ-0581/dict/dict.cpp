// prog logic pass optim req

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const int N=3000;

inline void fio(){
    freopen("dict.in","r",stdin); 
    freopen("dict.out","w",stdout);
}

int n,m;
string w[N+5];
struct s{
    string st;
    int ord;
}ww[N+5];
string w1[N+5];

bool cmp(s a,s b){
    return a.st<b.st;
}

void se(int ind){
    int sorted_ind;
    for(int i=1;i<=n;i++){
        if(ww[i].ord==ind){
            sorted_ind=i;
        }
    }
    string cur1=w[ind];
    string cur2=ww[sorted_ind].st;
    sort(cur2.begin(),cur2.end());
    // cout<<cur1<<" "<<cur2<<endl;
    ww[sorted_ind].st=cur2;
    sort(ww+1,ww+1+n,cmp);
    if(ww[1].ord==ind){
        printf("1");
    }
    else{
        printf("0");
    }
    // restore
    for(int i=1;i<=n;i++){
        ww[i].st=w[ww[i].ord];
    }
    return;
}

signed main(){
    fio();
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>w[i];
        ww[i].st=w[i];
        ww[i].ord=i;
    }
    sort(ww+1,ww+1+n,cmp);
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        se(i);
    }
    return 0;
}
