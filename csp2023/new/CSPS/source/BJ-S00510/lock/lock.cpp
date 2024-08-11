#include<bits/stdc++.h>
using namespace std;

int n,cnt=0;
int a[9][6];

int abs(int x,int y)
{
	return max(x,y)-min(x,y);
}

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>a[i][j];
    if(n==1)
    {
        cout<<"81";
        return 0;
    }
    for(int j=1;j<=n;j++)
		for(int i=1;i<=999999;i++)
		{
			int d[6]={0},w=0,w1=0,w2=0,w3=0,w4=0,w5=0;
			w1=i/10000;
			w2=i/1000%10;
			w3=i/100%10;
			w4=i/10%10;
			w5=i%10;
			w=(w1==a[i][1])+(w2==a[i][2])+(w3==a[i][3])+(w4==a[i][4])+(w5==a[i][5]);
			d[1]=abs(a[j][1],w1);
			d[2]=abs(a[j][2],w2);
			d[3]=abs(a[j][3],w3);
			d[4]=abs(a[j][4],w4);
			d[5]=abs(a[j][5],w5);
			if(w<4)
				continue;
			sort(d+1,d+5);
			if(w==4)
				if(d[4]!=d[5])
					continue;
			cnt++;
		}
	cout<<cnt<<endl;
	return 0;
}
