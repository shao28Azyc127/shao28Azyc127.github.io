#include<bits/stdc++.h>
using namespace std;
int a[10];
int tmp1[7],tmp2[7];
bool ok(int x,int y){

    for(int i = 0; i < 5; i++){
        tmp1[i] = x % 10;
        tmp2[i]= y % 10;
        x /= 10;
        y /= 10;
    }

    vector<int> v;
    for(int i = 0; i < 5; i++){
        if(tmp1[i] != tmp2[i])v.push_back(i);
    }
    if(v.size()>2)return false;
    if(!v.size())return false;
    if(v.size() == 1)return true;
    if(v[1]-v[0]>1)return false;
    if((tmp1[v[1]] - tmp2[v[1]]+10)%10 == (tmp1[v[0]] - tmp2[v[0]]+10)%10)return true;
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            int k;
            scanf("%d",&k);
            a[i] = a[i] * 10 + k;

        }
    }

    int ans = 0;
    for(int i = 0; i < 100000; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(!ok(a[j],i)){
                flag = false;
                break;
            }
        }
        //if(flag)cout << i << endl;
        ans+= flag;
    }
    printf("%d\n",ans);
    return 0;
}
