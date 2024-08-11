#include<fstream>
using namespace std;

int X[500005];
int Y[500005];
int A[500005];
int B[500005];	//Bigger

void init(int n,int m)
{
	for(int i=0;i<n;i++)
		A[i]=X[i];
	for(int i=0;i<m;i++)
		B[i]=Y[i];
}
void exc(int n,int m)
{

	for(int i=0;i<n || i<m;i++)
	{
		int t=A[i];
		A[i]=B[i];
		B[i]=t;
	}


}

int solve(int n,int m,int cur,int sc)
{
	if(cur==n && sc==m)
		return 1;
	if(cur==n || sc==m)
		return 0;
	int ok=0;
	for(int i=0;sc+i<=n;i++)
	{
		if(A[sc+i]>=B[cur])
			break;
		ok=(ok || solve(n,m,cur+1,sc+i));
	}
	return ok;
}

int solve0(int n,int m,int z1,int z2)
{
	if(A[0]<B[0])
		return solve(n,m,0,0);
	exc(n,m);
	return solve(m,n,0,0);
}

int main()
{
	int c,n,m,q;
	ifstream ifile("./expand.in");
	ofstream ofile("./expand.out");
	ifile>>c>>n>>m>>q;
	for(int i=0;i<n;i++)
		ifile>>X[i];
	for(int i=0;i<m;i++)
                ifile>>Y[i];

	init(n,m);
	if(solve0(n,m,0,0))
		ofile<<1;
	else
		ofile<<0;
	for(int i=1;i<=q;i++)
	{
		init(n,m);
		int k;
		ifile>>k;
		for(int j=0;j<k;j++)
		{
			int p,v;
			ifile>>p>>v;
			A[p-1]=v;
		}
		ifile>>k;
                for(int j=0;j<k;j++)
                {
                        int p,v;
                        ifile>>p>>v;
                        B[p-1]=v;
                }
		if(solve0(n,m,0,0))
			ofile<<1;
		else
			ofile<<0;



		
	}
	ofile<<endl;

}