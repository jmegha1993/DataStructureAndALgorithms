#include<iostream>
#include <list>
#include <limits.h>
using namespace std;
class Graph{
	

	public:
			Graph(int);
	
	
	int V;
	list<int> *adj;
	bool iscyclic();
	void addEdge(int ,int);
	bool iscyclicutil(int,bool [],bool []);
	
};


Graph::Graph(int V){
	
	this->V=V;
	adj=new list<int>[V];
	
}

void Graph::addEdge(int src,int des){
	int i;
	
	adj[src].push_back(des);
	
}


bool Graph::iscyclicutil(int i,bool *visited,bool *rec){
	
	
	list<int>::iterator it;

		
	
		visited[i]=true;
		rec[i]=true;
		
	for(it=adj[i].begin();it!=adj[i].end();it++){
		
		if(!visited[*it]){
			if(!rec[*it])
			return iscyclicutil(*it,visited,rec);
			
			else
			return true;
			
		}
		
		else if(rec[*it])
		return true;
		
	}
	  
	    rec[i]=false;
		 
     
		return false;
		
}


bool Graph::iscyclic(){
	int i;
	bool *visited = new bool[V];
	bool *rec = new bool[V];
	
	for(i=0;i<Graph::V;i++){
		visited[i]=false;
		rec[i]=false;
	
    }
	for(i=0;i<Graph::V;i++){
	return iscyclicutil(i,visited,rec);
     }

	
}







int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    //g.addEdge(2, 3);
    //g.addEdge(3, 3);
	cout<<g.iscyclic();
	
	
	
	
	
	return 0;
} 
