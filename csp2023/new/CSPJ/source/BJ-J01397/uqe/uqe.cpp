#include<bits/stdc++.h>
using namespace std;
struct fc{
	int a=0,b=0,c=0,d=0,e=0;
	bool k=0;
}f[5003];
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t>>m;
	for(int i=0;i<t;i++){
		cin >> f[i].a >> f[i].b >> f[i].c;
		f[i].d=f[i].b*f[i].b-4*f[i].a*f[i].c;
		if(f[i].d>=0){
			f[i].k=1;
			f[i].e=(-f[i].b+sqrt(f[i].d))/(2*f[i].a);
		}
	}
	for(int i=0;i<t;i++){
		if(f[i].k==0){
			cout << "NO"<<endl;
		}else{
			cout << f[i].e;
		}
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
