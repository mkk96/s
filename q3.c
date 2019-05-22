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
}
int dfs(struct graph *graph,int node,int visited[],int rec_stack[])
{
		visited[node]=1;
		rec_stack[node]=1;
		struct adjlistnode *temp=graph->array[node].head;
		while(temp)
		{
			if(!visited[temp->dest]&&dfs(graph,temp->dest,visited,rec_stack))
			{
				return 1;
			}
			else if(rec_stack[temp->dest])
			{
				return 1;
			}
			temp=temp->next;
		}
	rec_stack[node]=0;
	return 0;
}
int c_c(struct graph *graph)
{
	int visited[graph->v],rec_stack[graph->v],i,j,count=0;
	for(i=0;i<graph->v;i++)
	{
		visited[i]=0;
		rec_stack[i]=0;
	}
	for(i=0;i<graph->v;i++)
	{
		if(!visited[i]&&dfs(graph,i,visited,rec_stack))
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
	int p=c_c(graph);
	printf("Cyclomatic Complexity\t%d",e-v+2*p);
	return 0;
}
