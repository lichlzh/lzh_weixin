#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
using namespace std;
int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
long long READ(){
    long long xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
    return xx*ff;
}
char one(){
	char ch=getchar();
	while(ch==' '||ch=='\n')
		ch=getchar();
	return ch;
}
const int maxn=5010,maxm=10000010;
int N,M;
int lin[maxn],len;
struct edge{
	int y,next,v;
}e[maxm];
inline void insert(int xx,int yy,int vv){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
	e[len].v=vv;
}
void floyd(){
	static int dis[maxn][maxn];
	N=read(),M=read();
	memset(dis,10,sizeof(dis));
	memset(lin,0,sizeof(lin));len=0;
	for(int i=1;i<=M;i++){
		int t1=read(),t2=read(),t=read();
		if(dis[t1][t2]>t)
			dis[t1][t2]=t;
	}
	int tim1=clock(),tim2;
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	tim2=clock();
	printf("%d\n",tim2-tim1);
}
int main(){
	freopen("in","r",stdin);
	floyd();
	return 0;
}

