#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int gold=0,gl=0;
int n,d;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int changdu=0,x=1e9,y=-1e9,j,changdu1;
    cin>>n>>d;
    for(int i=1;i<n;i++) {
        cin>>a[i];
        changdu+=a[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        x=min(x,b[i]);
        y=max(y,b[i]);
    }
    if(x==b[1]) {
        if(changdu%d==0) {
            cout<<changdu/d*b[1];
        }
        else {
            cout<<(changdu/d+1)*b[1];
        }
    }
    else {
        for(int i=1;i<n;i++) {
            if(i!=n) {
                changdu-=a[i];
            }
            if(b[i]==y) {
                if(gl>=a[i]) {
                    gl-=a[i];
                    continue;
                }
                else if((a[i]-gl)%d==0) {
                    gold+=(a[i]-gl)/d*b[i];
                    gl=0;
                }
                else {
                    gold+=((a[i]-gl)/d+1)*b[i];
                    gl=(a[i]-gl)%d+1;
                }
            }
            else if(b[i]==x) {
                if(gl>changdu) {
                    break;
                }
                if((changdu-gl)%d==0) {
                    gold+=(changdu-gl)/d*b[i];
                }
                else {
                    gold+=((changdu-gl)/d+1)*b[i];
                }
                break;
            }
            else {
                changdu1=0;
                for(j=i+1;j<=n;j++) {
                    changdu1+=a[j];
                    if(b[j]<a[i]) {
                        break;
                    }

                }
                if(gl>=changdu1) {
                    gl-=changdu1;
                    continue;
                }
                if((changdu1-gl)%d==0) {
                    gold+=(changdu1-gl)/d*b[i];
                    gl=0;
                }
                else {
                    gold+=((changdu1-gl)/d+1)*b[i];
                    gl=(changdu1-gl)%d+1;
                }
            }
        }
    }
    cout<<gold;
    return 0;
}
