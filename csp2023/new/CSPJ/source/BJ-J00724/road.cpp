#include <bits/stdc++.h>
using namespace std;
int n,d;
struct fun{
	int v;
	int z;
	int a;
};
int p[100010];
fun s[100010];
int main(){
	cin>>n>>d;
	for(int i=1;i<=n-1;i++){
		cin>>s[i].v;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		p[i]=s[i].a;
		s[i].z=i;
	}
	sort(p+1.p+n+1);
	if(s[1].a==p[1]){
		int k=0;
		for(int i=1;i<=n-1;i++){
			k+=s[i].v;
		}
		if(k%d==0){
			cout<<s[1].a*(k/d);
		}
		else cout<<s[1].a*(k/d+1);
	}
	else if(n==8){
		int k=1e9;
		for(int d=0;d<=7;d++){
			for(int b=0;b<=7-d;b++){
				for(int c=0;c<=7-d-b;c++){
					for(int e=0;e<=7-b-c-d;e++){
						for(int f=0;f<=7-b-c-d-e;f++){
							for(int g=0;g<=7-b-c-d-e-f;g++){
								k=min(k,d*s[1].a+b*s[2].a+c*s[3].a+e*s[4].a+f*s[5].a+g*s[6].a+(7-b-c-d-e-f-g)*s[7]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
