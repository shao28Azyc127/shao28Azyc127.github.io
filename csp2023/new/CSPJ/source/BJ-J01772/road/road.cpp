#include<bits/stdc++.h>
using namespace std;/*
inline int read(){
	char c=getchar();int s=0,f=1;
	while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
	while(isdigit(c)){s=s*10+c-'0';c=getchar();}
	return s*f;
}*/

struct nb{
	long long  a , num;
}b[100005] , c[100005];
bool cmp(nb a,nb b){
	return a.a < b.a;
}
long long n , d ,sum = 0 , v[100005] , ans = 0;

int main(){
freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>d;
	//long long m;
    for(int i = 1;i<n;i++){
    	cin>>v[i];
    	//c[i].v = b[i].v;

    	sum+=v[i];
	}

	for(int i = 1;i<=n;i++){
		b[i].num = i;
    	c[i].num = i;
    	cin>>b[i].a;
    	c[i].a = b[i].a;
	}
	sort(c + 1,c + n +  1,cmp);
/*	if(c[1].num == 1){
		if(sum%d!=0){
			cout<<c[1].a * (sum/d + 1)<<endl;
			return 0;
		}
		else{cout<<c[1].a * sum/d<<endl;
		return 0;
		}
	}*/
//	find(1,0);
long long x = 1 , yu = 0 ; //bool flag = false;
for(int i = 1;i<=n;i++){
		if(b[i+ 1].a>=b[x].a){

			//flag = true;
			if((v[i]- yu)%d!=0){

            ans+=b[x].a * ((v[i]- yu)/d   + 1);

			yu+=((v[i]-yu)/d + 1)*d - v[i];//cout<<ans<<" "<<yu<<endl;
			}

		else{//flag = true;
		ans+=b[x].a * ((v[i]- yu)/d);
	//	cout<<ans<<endl;
			yu= 0;

		}
		}
		else{

			if((v[i]- yu)%d!=0&&(v[i]- yu)%d>0){
            ans+=b[x].a * ((v[i]- yu)/d   + 1);
			yu+=((v[i]-yu)/d + 1)*d - v[i];}

		else {
		ans+=b[x].a * ((v[i]- yu)/d);
	//	cout<<ans<<endl;
			yu= 0;
			}

			x = i + 1;
		}



	}
	cout<<ans<<endl;
	return 0;
}/*
5 4
10 10 10 10
9 8 9 6 5
*/
