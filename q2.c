#include<stdio.h>
#include<stdlib.h>
struct adjlistnode
{
	int dest;
	struct adjlistnode *next;
};
struct adjlist
{
	struct adjlistnode *head;
};
struct graph
{
	int v;
	struct adjlist *array;
};
struct graph *create(int v)
{
	struct graph *graph=(struct graph *)malloc(sizeof(struct graph ));
	graph->v=v;
	graph->array=(struct adjlist *)malloc(sizeof(struct adjlist)*v);
	int i;
	for(i=0;i<v;i++)
	{
		graph->array[i].head=NULL;
	}
	return graph;
}
struct adjlistnode *newnode(int dest)
{
	struct adjlistnode *n=(struct adjlistnode *)malloc(sizeof(struct adjlistnode));
	n->dest=dest;
	n->next=NULL;
	return n;
}
void addedge(struct graph *graph,int src,int dest)
{
	struct adjlistnode *n=newnode(dest);
	n->next=graph->array[src].head;
	graph->array[src].head=n;
	n=newnode(src);
	n->next=graph->array[dest].head;
	graph->array[dest].head=n;	
}
//void print(struct graph *graph)
//{
//	int i;
//	for(i=0;i<graph->v;i++)
//	{
//		printf("%d->",i);
//		struct adjlistnode *temp=graph->array[i].head;
//		while(temp)
//		{
//			printf("%d->",temp->dest);
//			temp=temp->next;
//		}
//		printf("\n");
//	}
//}
int dfs(struct graph *graph,int node,int visited[],int parent[])
{
	int stack[graph->v],top=0;	
	visited[node]=1;
	stack[top++]=node;
	while(top!=0)
	{
		int a=stack[--top];
		struct adjlistnode *temp=graph->array[a].head;
		while(temp)
		{
			if(!visited[temp->dest])
			{
				visited[temp->dest]=1;
				stack[top++]=temp->dest;
				parent[temp->dest]=a;
			}
			else if(temp->dest!=parent[a])
			{
				return 1;
			}
			temp=temp->next;
		}
	}
	return 0;
}
int region(struct graph *graph)
{
	int visited[graph->v],i,parent[graph->v],count=0;
	for(i=0;i<graph->v;i++)
	{
		visited[i]=0;
		parent[i]=-1;
	}
	for(i=0;i<graph->v;i++)
	{
		if(!visited[i]&&dfs(graph,i,visited,parent))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int v,e,i,a,b;
	scanf("%d%d",&v,&e);
	struct graph *graph=create(v);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(graph,a,b);
	}
	int p=region(graph);
	printf("Cyclomatic Complexity\t%d",p+1);
	return 0;
}
