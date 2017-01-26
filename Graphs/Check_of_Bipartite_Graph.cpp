#include<iostream>
#define V 5
#include<queue>
using namespace std;

bool isBipartite(int m[][V],int col){
	
	queue<int> q;
	int f=0;
	int i,j;
	int visited[V]={0};
	int color[V]={0};
		
		q.push(0);
		color[0]=1;
		visited[0]=1;
		
		while(!q.empty()){
			
			i=q.front();
			q.pop();
			
		  for(j=0;j<V;j++){
		  
			
			
			if(m[i][j]==1)
			{
				if(!visited[j])
				{
					q.push(j);
					visited[j]=1;
					color[j]=1-color[i];
					
				}
				
				else{
					if(color[i]==color[j])
					{
						f=1;
						break;
					}
					
				}
			
			 	
			}
		  
		}
		if(f==1)
		break;
		
	}
	
	if(f==1)
	return false;
	else
	return true;
	
	
}


int main()
{
int m[][V] = {{0,1,0,0,1},
              {1,0,1,0,0},
		      {0,1,0,1,0},
              {0,0,1,0,1},
              {1,0,0,1,0}};
 
    isBipartite(m, 0) ? cout << "Yes" : cout << "No";
    return 0;
}
