# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define MAXV 5001

int N, M;
int order[MAXV];
int visited[MAXV];
int ans[MAXV], cnt, tmp[MAXV], cc;
int no;

typedef struct node
{
	int adjvex;
	struct node *next;
}EdgeNode;
typedef struct vnode
{
	EdgeNode *firstedge;
}VertexNode;
typedef VertexNode AdjList[MAXV];
typedef struct ALGraph
{
	AdjList adjlist;
}Graphic;

Graphic GA, GB;
void insert(int u, int v)
{
	EdgeNode *s;

	s = (EdgeNode *)malloc(sizeof(EdgeNode));
	s->adjvex = v;
	s->next = GA.adjlist[u].firstedge;
	GA.adjlist[u].firstedge = s;
	s = (EdgeNode *)malloc(sizeof(EdgeNode));
	s->adjvex = u;
	s->next = GB.adjlist[v].firstedge;
	GB.adjlist[v].firstedge = s;
}

void input()
{
	int u, v, i;

	for(i = 0; i < M; i++)
	{
		scanf("%d%d",&u,&v);
		insert(u-1,v-1);
	}
}

void init()
{
	int i;

	scanf("%d",&M);
	for(i = 0; i < N; i++)
	{
		GA.adjlist[i].firstedge = NULL;
		GB.adjlist[i].firstedge = NULL;
	}
}

void dfs_b(int v)
{
	EdgeNode *s;

	visited[v] = 1;
	s = GB.adjlist[v].firstedge;
	while(s)
	{
		if(!visited[s->adjvex])
			dfs_b(s->adjvex);
		s = s->next;
	}
	order[cnt++] = v;
}

void dfs_a(int v)
{
	EdgeNode *s;

	visited[v] = no;
	tmp[cc++] = v;
	s = GA.adjlist[v].firstedge;
	while(s)
	{
		if(!visited[s->adjvex])
		{
			dfs_a(s->adjvex);
		}
		s = s->next;
	}
}

int cmp(const void *a,const void *b)
{
	int *aa = (int *)a;
	int *bb = (int *)b;

	return (*aa)-(*bb);
}

void solve()
{
	int i, j;
	int error;
	EdgeNode *s;

	cnt = 0;
	memset(visited,0,sizeof(visited));
	for(i = 0; i < N; i++)
		if(!visited[i])
			dfs_b(i);
	cnt = 0;
	memset(visited,0,sizeof(visited));
	no = 1;
	for(i = N-1; i >= 0; i--)
	{
		if(!visited[order[i]])
		{
			cc = 0;
			dfs_a(order[i]);
			error = 0;
			for(j = 0; j < cc; j++)
			{
				s = GA.adjlist[tmp[j]].firstedge;
				while(s)
				{
					if(visited[s->adjvex]!=visited[tmp[j]])
					{
						error = 1;
						break;
					}
					s = s->next;
				}
			}
			if(!error)
			{
				for(j = 0; j < cc; j++)
				{
					ans[cnt++] = tmp[j];
				}
			}
			no++;
		}
	}
	qsort(ans,cnt,sizeof(ans[0]),cmp);
	for(i = 0; i < cnt; i++)
	{
		printf("%d ",ans[i]+1);
	}
	printf("\n");
}

int main()
{
	while(scanf("%d",&N)==1,N)
	{
		init();
		input();
		solve();
	}
	return 1;
}
