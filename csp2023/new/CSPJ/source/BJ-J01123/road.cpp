#include <bits/stdc++.h>

using namespace std;

struct zhan{
    int a;
    int v;
    int c;
    int id;
    int cha;
    int nextt;
    bool flag = false;
}z[100005];
zhan temp[100005];
bool cmp(zhan s1,zhan s2){
    return s1.a < s2.a;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    z[1].v=0;
    int n,d;
    cin >> n >> d;
    if(n==1){
        cout << 0;
        return 0;
    }
    long long sum=0;
    for(int i=2;i<=n;i++){
        cin >> z[i].v;
        z[i].c = z[i-1].c+z[i].v;
    }
    for(int i=1;i<=n;i++){
        cin >> z[i].a;
        temp[i].id = i;
        temp[i].a=z[i].a;
        temp[i].v=z[i].v;
        temp[i].c=z[i].c;
    }
    sort(temp+1,temp+n,cmp);
    z[temp[1].id].flag = true;
    for(int i=2;i<=n;i++){
        if(z[temp[1].id].a==z[temp[i].id].a){
            z[temp[1].id].flag = true;
            continue;
        }
        int tt = i-1;
        while(tt>=1&&temp[tt].a==temp[i].a){
            tt--;
        }
        z[temp[i].id].cha = temp[tt].c-temp[i].c;
        z[temp[i].id].nextt = temp[tt].id;
    }int yu=0;
    int i=1;
    while(i<n){
        if(z[i].flag){
            sum+=z[i].a*ceil((z[n].c-z[i].c-yu)*1.0/d);
            break;
        }
        if(yu>=z[n].c-z[i].c)break;
        if(yu>=z[i].cha){
            if(z[i].cha%d==0){
                sum+=z[i].a*z[i].cha/d;
                i = z[i].nextt;
            }else{
                sum+=z[i].a*(z[i].cha/d+1);
                yu = z[i].cha%d;
                i = z[i].nextt;
            }
        }else{
            if((z[i].cha-yu)%d==0){
                sum+=z[i].a*z[i].cha/d;
                i = z[i].nextt;
                yu = 0;
            }else{
                sum+=z[i].a*((z[i].cha-yu)/d+1);
                yu = (z[i].cha-yu)%d;
                i = z[i].nextt;
            }
        }
    }
    cout << sum;
    return 0;
}
