#include<iostream>
using namespace std;


void printDFS(int** edge,int v,bool* visited,int sv)
{
	cout<<sv;
	visited[sv]=true;
	
	for(int i=0;i<v;i++)
	{
		if(i==sv)
		   continue;
		
		if(edge[sv][i]==1 && !visited[i])
		{
			printDFS(edge,v,visited,i);
		}
	}
}

int main()
{
	int v,e;
	cin>>v>>e;
	
	//creating adjecency Matrix
	int** edge=new int*[v];
	
	//initializing 2D array
	for(int i=0;i<v;i++)
	{
		edge[i]=new int[v];
		for(int j=0;j<v;j++)
		{
			edge[i][j]=0;
		}
	}
	
	//adding edges
	for(int i=0;i<e;i++)
	{	
		//which two nodes have edge between them
		int a,b;
		cin>>a>>b;
		
		edge[a][b]=1;
		edge[b][a]=1;
	}

	//maintaning visited array
	bool* visited=new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	
	printDFS(edge,v,visited,0);
	return 0;
}
