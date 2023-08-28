#include<iostream>
using namespace std;
#include<queue>

void printBFS(int** edge,int v,bool* visited,int sv)
{
	queue<int> remaining;
	
	remaining.push(sv);
	
	while(remaining.size()!=0)
	{
		int front=remaining.front();
		remaining.pop();
		
		cout<<front;
		visited[front]=true;

		for(int i=0;i<v;i++)
		{
			if(i==front)
			   continue;
			
			if(edge[front][i]==1)
			{
				if(!visited[i])
					remaining.push(i);
			}
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
	
	printBFS(edge,v,visited,0);
	return 0;
}
