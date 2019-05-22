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
int predicate_node(struct graph *graph)
{
	int i,count=0,c=0;
	for(i=0;i<graph->v;i++)
	{
		c=0;
		struct adjlistnode *temp=graph->array[i].head;
		while(temp)
		{
			temp=temp->next;
			c++;
		}
		if(c==2)
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
	//print(graph);
	int p=predicate_node(graph);
	printf("Cyclomatic Complexity\t%d",p+1);
	return 0;
}
