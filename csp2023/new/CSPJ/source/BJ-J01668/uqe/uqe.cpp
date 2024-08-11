//tiny hopeless thing--a piece of s**t
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pf push_front
using namespace std;
inline ll read(){
    ll k=0,flag=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-')flag=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=(k<<1)+(k<<3)+(c^48);
        c=getchar();
    }
    return k*flag;
}
inline void print(ll n){
    if(n<0){
        putchar('-');
        n=-n;
    }
    if(n>9)print(n/10);
    putchar(n%10+'0');
    return ;
}
inline void fre(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);//"W"
}
int main(){
    fre();
    int T,M;
    cin>>T>>M;
    while(T--){
	ll a=read(),b=read(),c=read();
	ll k=b*b-4*a*c;
	if(k<0){
	    puts("NO");
	    continue;
	}
	if(k==0){
	    ll zi1=-b,zi2=k,mu1=2*a,Mu=0,zi=0;
	    bool flag=0;
	    if(zi1){
		if((ll)sqrt(zi2)*(ll)sqrt(zi2)==zi2){
		    zi=zi1+sqrt(zi2);
		    Mu=2*a;
		    ll g=__gcd(zi,Mu);
		    zi/=g;
		    Mu/=g;
		    if(Mu<0){
			Mu=-Mu;
			zi=-zi;
		    }
		}
		else{
		    zi=zi1,Mu=mu1;
		    ll g=__gcd(zi,Mu);
		    zi/=g;
		    Mu/=g;
		    if(Mu<0){
			Mu=-Mu;
			zi=-zi;
		    }
		}
	    }
	    //if(Mu==1)printf("%d",zi);
	    //else printf("%d/%d",zi,Mu);
	    if((ll)sqrt(zi2)*(ll)sqrt(zi2)!=zi2){
		ll q;
		for(int i=1;i<=zi2;++i){
		    if(zi2%i==0&&(ll)sqrt(i)*(ll)sqrt(i)==i)q=i*i;
		}
		if(q==1){
		    if(zi==0)printf("sqrt(%lld)",zi2);
		    else{
			if(Mu==1)printf("%lld",zi);
			else printf("%lld/%lld",zi,Mu);
			printf("+sqrt(%lld)",zi2);
		    }
		}
		else{
		     if(zi==0)printf("%lld*sqrt(%lld)",q,zi2);
		    else{
			if(Mu==1)printf("%lld",zi);
			else printf("%lld/%lld",zi,Mu);
			printf("+%lld*sqrt(%lld)",q,zi2);
		    }
		}
		flag=1;
	    }
	    if(!flag){
		if(Mu==1)printf("%lld",zi);
		else printf("%lld/%lld",zi,Mu);
	    }
	}
	else{
	    double x=((double)-b+sqrt((double)k))/(double)a*2;
	    double y=((double)-b-sqrt((double)k))/(double)a*2;
	    if(x>y){
		ll zi1=-b,zi2=k,mu1=2*a,Mu=0,zi=0;
		bool flag=0;
		if(zi1){
		    if((ll)sqrt(zi2)*(ll)sqrt(zi2)==zi2){
			zi=zi1+sqrt(zi2);
			Mu=2*a;
			ll g=__gcd(zi,Mu);
			zi/=g;
			Mu/=g;
			if(Mu<0){
			    Mu=-Mu;
			    zi=-zi;
			}
		    }
		    else{
			zi=zi1,Mu=mu1;
			ll g=__gcd(zi,Mu);
			zi/=g;
			Mu/=g;
			if(Mu<0){
			    Mu=-Mu;
			    zi=-zi;
			}
		    }
		}
		//if(Mu==1)printf("%d",zi);
		//else printf("%d/%d",zi,Mu);
		if((ll)sqrt(zi2)*(ll)sqrt(zi2)!=zi2){
		    ll q;
		    for(int i=1;i<=zi2;++i){
			if(zi2%i==0&&(ll)sqrt(i)*(ll)sqrt(i)==i)q=i*i;
		    }
		    if(q==1){
			if(zi==0)printf("sqrt(%lld)",zi2);
			else{
			    if(Mu==1)printf("%lld",zi);
			    else printf("%lld/%lld",zi,Mu);
			    printf("+sqrt(%lld)",zi2);
			}
		    }
		    else{
			if(zi==0)printf("%lld*sqrt(%lld)",q,zi2);
			else{
			    if(Mu==1)printf("%lld",zi);
			    else printf("%lld/%lld",zi,Mu);
			    printf("+%lld*sqrt(%lld)",q,zi2);
			}
		    }
		    flag=1;
		}
		if(!flag){
		    if(Mu==1)printf("%lld",zi);
		    else printf("%lld/%lld",zi,Mu);
		}
	    }
	    else{
		ll zi1=-b,zi2=k,mu1=2*a,Mu=0,zi=0;
		bool flag=0;
		if(zi1){
		    if((ll)sqrt(zi2)*(ll)sqrt(zi2)==zi2){
			zi=zi1+sqrt(zi2);
			Mu=2*a;
			ll g=__gcd(zi,Mu);
			zi/=g;
			Mu/=g;
			if(Mu<0){
			    Mu=-Mu;
			    zi=-zi;
			}
		    }
		    else{
			zi=zi1,Mu=mu1;
			ll g=__gcd(zi,Mu);
			zi/=g;
			Mu/=g;
			if(Mu<0){
			    Mu=-Mu;
			    zi=-zi;
			}
		    }
		}
		//if(Mu==1)printf("%d",zi);
		//else printf("%d/%d",zi,Mu);
		if((ll)sqrt(zi2)*(ll)sqrt(zi2)!=zi2){
		    ll q;
		    for(int i=1;i<=zi2;++i){
			if(zi2%i==0&&(ll)sqrt(i)*(ll)sqrt(i)==i)q=i*i;
		    }
		    if(q==1){
			if(zi==0)printf("-sqrt(%lld)",zi2);
			else{
			    if(Mu==1)printf("%lld",zi);
			    else printf("%lld/%lld",zi,Mu);
			    printf("-sqrt(%lld)",zi2);
			}
		    }
		    else{
			 if(zi==0)printf("-%lld*sqrt(%lld)",q,zi2);
			else{
			    if(Mu==1)printf("%lld",zi);
			    else printf("%lld/%lld",zi,Mu);
			    printf("-%lld*sqrt(%lld)",q,zi2);
			}
		    }
		    flag=1;
		}
		if(!flag){
		    if(Mu==1)printf("%lld",zi);
		    else printf("%lld/%lld",zi,Mu);
		}
	    }
	}
	putchar('\n');
    }
    return 0;
}
