#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Edge {
public:
  
private:
  string dest; //edge's destination
  int weight;
};

class Vertex {
public:
  Vertex(std::string newLabel) {
    label = newLabel;
  }
  string getLabel() {
    return label;
  }
private:
  string label;
  vector<Edge> edgeVect;
};

class Graph {
public:
  void addVert(string);
  void addEdge(string);
  void remVert();
  void remEdge();
  void findSP();
  void print();
private:
  void diAlgo(); //Dijkstra's 
  map<string, Vertex*> vertices;
};

void Graph::addVert(string vertLabel) {
  //Vertex* x = new Vertex(vertLabel);
  vertices[vertLabel] = new Vertex(vertLabel);
}

void Graph::addEdge(string label) {
  
}

void Graph::remVert() {
  
}

void Graph::remEdge() {
  
}

void Graph::findSP() {
  
}

void Graph::diAlgo() {
  //psuedocode from https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
// function Dijkstra(Graph, source): //name it diAlgo
 
   //     for each vertex v in Graph.Vertices:            
   //         dist[v] ← INFINITY                 
   //         prev[v] ← UNDEFINED                
   //         add v to Q                     
   //     dist[source] ← 0                       
      
   //     while Q is not empty:
   //        u ← vertex in Q with min dist[u]   
   //        remove u from Q
                                        
   //        for each neighbor v of u still in Q:
   //            alt ← dist[u] + Graph.Edges(u, v)
   //            if alt < dist[v]:              
   //                dist[v] ← alt
   //                prev[v] ← u

   //    return dist[], prev[]
}

void Graph::print() {
  for (const auto& v : vertices) {
    cout << v.first << ": ";
    cout << v.second->getLabel();
    //print edges
    cout << endl;
  }
}

int main() {
  string usrIn;
  Graph g;
  
  cout << "Commands (Case Sensitive):" << endl;
  cout << "av (Add Vertex): Enter a label for a vertex. Add it to the graph." << endl;
  cout << "rv (Remove Vertex): Enter a vertex label and remove it from the graph. Remove all edges to that vertex." << endl;
  cout << "ae (Add Edge): Enter two node names and a weight (number). Add an edge between them, from the first node to the second node." << endl;
  cout << "re (Remove Edge): Enter two vertex labels, and remove an edge between them." << endl;
  cout << "fsp (Find Shortest Path): Enter two vertex labels, prints shortest bath between them." << endl;
  cout << "p (print): Prints adjacency table" << endl;
  cout << "q (Quit): Exits the program." << endl;

  while (true) {
    cout << "Command: ";
    cin >> usrIn;
    //cout << endl;

    if (usrIn == "av") {
      cout << "Enter name of vertex: " << endl;
      cin >> usrIn;
      g.addVert(usrIn);
      cout << "Vertex added" << endl;
    }
    else if (usrIn == "rv") {
      cout << "Remove Vertex" << endl;
    }
    else if (usrIn == "ae") {
      cout << "Add Edge" << endl;
    }
    else if (usrIn == "re") {
      cout << "Remove Edge" << endl;
    }
    else if (usrIn == "fsp") {
      cout << "Find Shortest Path" << endl;
    }
    else if (usrIn == "q") {
      cout << "Quit" << endl;
      break;
    }
    else if (usrIn == "p") {
      cout << "print" << endl;
      g.print();
    }
  }
}
