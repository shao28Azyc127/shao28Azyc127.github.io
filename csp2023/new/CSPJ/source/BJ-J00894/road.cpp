#include <bits/stdc++.h>
using namespace std;
long long n,d,v[111111],a[111111],vb[111111],dis=0,minoil=2147483647,minpos,ans=0,mn[111111];
//vb:qianzhuihe mn:zuixiaozhi
void recursive(long long l,long long r,long long cur){
    long long lf,rt;
    //lf=vb[minpos-1];
    //rt=vb[n-1]-vb[minpos];//43:19(16) (04)
    rt=cur-1;
    ans+=a[cur]*ceil((double)((vb[r]-vb[rt-1])/d));
    //cout<<ans<<" ";
    if (rt!=1){
        recursive(1,rt,mn[rt]);

    }


}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for (int i=1;i<=n-1;i++){
        cin>>v[i];
        dis+=v[i];
        vb[i]=vb[i-1]+v[i];
	}
	for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]<minoil){
            minoil=a[i];
            minpos=i;
        }
        mn[i]=minpos;
        //minoil=min(minoil,a[i]);
	}
	if (minpos==1){
        if (dis/d*d==dis){
            ans=dis/d;
        }else{
            ans=dis/d+1;
        }
        ans*=a[minpos];
	}else{
        recursive(1,n-1,mn[n-1]);
	}
	//left:vb[minpos-1]
	//right:vb[n-1]-vb[minpos]
	cout<<ans;
	return 0;
}
//2048(56)*1480(1)(2)
