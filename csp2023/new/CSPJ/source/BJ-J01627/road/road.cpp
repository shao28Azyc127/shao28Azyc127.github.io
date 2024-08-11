#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    int n,d,res=0,rm=0;

    cin>>n>>d;

    vector<int>v(n+1,0);
    vector<int>a(n+1,0);

    for(int i=1;i<=n-1;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>vec(n+1,0);
	vec=a;

	sort(vec.begin(),vec.end());
	if(vec[1]==a[1]){
		int ans=0;
		for(int i=1;i<n;i++)ans+=v[i];
		if(ans%d!=0)ans=(ans/d+1)*a[1];
		else ans=(ans/d)*a[1];
		cout<<ans;
		return 0;
	}
	
    for(int i=1;i<=n;i++){
		if(i==n-1){
			if(rm<v[i]&&(v[i]-rm)/d*d<v[i])res+=((v[i]-rm)/d+1)*a[i];
			else if(rm<v[i]&&(v[i]-rm)/d*d==v[i])res+=((v[i]-rm)/d)*a[i];
			
			cout<<res;
			return 0;
		}
        if(a[i+1]<a[i]){
            int s=0;
            if(v[i]%d==0&&(v[i]-rm)%d!=0)s=v[i]/d;
            else if(v[i]%d!=0&&v[i]/d*d<v[i]-rm){
				s=(v[i]-rm)/d+1;
				rm=0;
			}
            else {
				s=(v[i]-rm)/d;
				rm=0;
			}

            if(s*d>v[i])rm=s*d-v[i];

            res=res+s*a[i];
         
        }else{
            int s=0;
            int tmp=i;
			while(i<n&&a[i+1]>a[tmp]){
                i++;
                s+=v[i];
              
			}
			i++;
			s+=v[i];

			int x=s;
			if(s%d==0)s=s/d;

			else if(s%d!=0&&s/d*d<s-rm){
				s=(s-rm)/d+1;
				rm=0;
			}
			else {
				s=(s-rm)/d;
				rm=0;
			}

			if(s*d>x)rm=s*d-x;

			res=res+s*a[tmp];
	
		}


    }

    cout<<res;

    return 0;
}
