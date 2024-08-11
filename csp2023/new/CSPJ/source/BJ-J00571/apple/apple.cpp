#include<iostream>
using namespace std;

int main() {
    int n=0;
    int aa[1000000005];
    int a=0;
    int day=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        aa[i]=1;
    }
    int out=0;
    while(out<n) {
        a++;
        int now=0;
        for(int i=1;i<=n;i++) {
            if(aa[i]==1) {
                now=i;
                break;
            }
        }
        while(now<=n) {
            aa[now]=0;
            if(now==n) {
                day=a;
            }
            int sum=0;
            int num=now;
            while(sum<3) {
			if(a[num]==1) {
				sum++;
				num++;
			}
		}
            now=num;
            out++;
        }
    }

    cout<<a<<" "<<day;
    return 0;
}
