#include<bits/stdc++.h>
using namespace std;
int nodesnum, speed;
int pos=1, rem, cnt=0;
struct node
{
    int len;
    int price;
}nodes[100100];

const int numinf = 0x3f3f3f3f;
const node inf= {0,numinf};

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    nodes[0] = inf;
    cin>> nodesnum >> speed;
    for(int i=1;i<nodesnum;i++)
    {
        cin>>nodes[i].len;
    }
    nodes[nodesnum].len = 0;
    for(int i=1;i<=nodesnum;i++)
    {
        cin>>nodes[i].price;
    }
    int last = nodes[0].price;
    while(pos <= nodesnum)
    {
        int length = nodes[pos].len;
        int pres_oil = (length - rem) / speed + (((length-rem) % speed) != 0);  //min(nodes[pos].price , nodes[pos-1].price)
        rem = pres_oil*speed - (length - rem);
        last = min(nodes[pos].price , last);
        cnt += last * pres_oil;
        pos++;
        //cout<<pres_oil<<endl;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);/**/
    return 0;
}