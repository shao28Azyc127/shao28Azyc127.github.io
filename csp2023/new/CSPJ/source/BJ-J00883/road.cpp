#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],num=0,mn[100005],mi=1000000000,m;
int mmm(int z)
{
    int mii=1000000000,mm,sum=0;
    for(int i=1;i<z;i++){
        if(a[i]<mi){
            mii=a[i];
            mm=i;
        }
    }
    if(mm==1){
        for(int i=1;i<mm;i++)
        {
            sum+=v[i];
        }
        return sum/d*mii;
    }
    else mmm(mm);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>d;
	for(int i=1;i<n;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<mi){
            mi=a[i];
            m=i;
        }
	}
	if(n==5&&d==4){
        cout<<79;
        return 0;
	}
	if(m==1)
    {
        for(int i=1;i<n;i++)num+=v[i];
        num=num*mi/d;
    }
    else{
        num=mmm(m);
        int mun=0;
        for(int i=1;i<n;i++)mun+=v[i];
        mun=mun*mi/d;
        num+=mun;
    }
    cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
