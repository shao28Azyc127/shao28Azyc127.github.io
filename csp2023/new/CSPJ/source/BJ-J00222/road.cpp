#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N=1e5+2;
int a[N],hv[N];
int mo=0;
int miid=1;
int y=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >>n>>d;
    for(int i=1 ;i<n;i++)
    {
        int v;
        cin >>v;
        hv[i]=hv[i-1]+v;
    }
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
        if(a[i]<a[miid])
        {
            int dst=hv[i-1]-hv[miid-1];
            
            if((dst)%d!=0){
                mo+=(dst/d+1)*a[miid];
                y+=dst/d+1;
            }
            else{
                mo+=(dst/d)*a[miid];
                y+=dst/d;
            }
            miid=i;
            y-=d;
            //cout <<mo<<endl;
            //minn=a[i];
        }

    }
    if(miid<n)
    {
        int dst=hv[n-1]-hv[miid-1];
        if(dst%d!=0){
            mo+=(dst/d+1)*a[miid];
        }
        else{
            mo+=(dst/d)*a[miid];
        }
        //cout <<mo<<endl;
    }
    /* if(miid==1){
        mo=floor(hv[n]*1.0/d*1.0)*a[1];
    }
    else{
            minn=N,miid=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<minn){
                mo+=floor((hv[i]-hv[miid+1])*1.0/d*1.0)*a[i];
                miid=i;
                minn=a[i];
            }

        }
        if(miid<n)
        {
            mo+=floor((hv[n]-hv[miid+1])*1.0/d*1.0)*minn;
        }

    }*/

    cout <<mo;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
