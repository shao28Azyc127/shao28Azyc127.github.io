#include <bits/stdc++.h>
using namespace std;

int a[100000],b[100000];
int main()
{
    long long n=0,m=0,l=0,now=0,next=1,co=0,h=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m;
    for(int i=0; i<n-1; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    while(now<n)
    {
        if(b[now]>b[next]){
            int ln=a[now]-h;
            h=0;
            if(ln%m==0){
                co+=(ln/m)*b[now];
            }
            else{
                co+=(ln/m)*b[now];
                co+=b[now];
                h+=m-ln%m;
                ln=0;
            }
            now=next;
            next=now+1;
        }
        else{
            while(b[now]<=b[next]&&next<n)next++;
            next--;
            int ln=0;
            for(int i=now;i<next;i++){
                ln+=a[i];
            }
            ln-=h;
            h=0;
            if(ln%m==0){
                co+=(ln/m)*b[now];
            }
            else{
                co+=(ln/m)*b[now];
                co+=b[now];
                h+=m-ln%m;
                ln=0;
            }
            now=next;
            next=now+1;
            if(now==n)break;
        }
    }
    cout << co;
    return 0;
}
