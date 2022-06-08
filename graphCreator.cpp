#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Edge {
public:
  Edge(std::string edgeDest, int edgeWeight) {
    dest = edgeDest;
    weight = edgeWeight;
  }
  void print() {
    cout << '[' << dest << ", " << weight << ']';  
  }
private:
  string dest; //edge's destination
  int weight;
};

class Vertex {
public:
  Vertex(std::string newLabel) {
    label = newLabel;
  }
  void print() {
    for (const auto& e : edgeMap) {
      //cout << e.first << ": "; //debug
      e.second->print();
      //print edges
      cout << endl;
    }  
  }
  string getLabel() {
    return label;
  }
  Edge* getEdge(string dest) {
    auto search = edgeMap.find(dest);
    if (search != edgeMap.end()) {
      return search->second;
    }
    else {
      return NULL;
    }
  }
  void addEdge(string to, int weight) {
    if (getEdge(to) != NULL) {
      cout << "Edge with that destination already exists." << endl;
      return;
    }
    //cout << edgeMap.size() << endl;
    edgeMap[to] = new Edge(to, weight);
    //cout << edgeMap.size() << endl;
  }
private:
  string label;
  map<string, Edge*> edgeMap;
};

class Graph {
public:
  void addVert(string);
  void addEdge(string, string, int);
  void remVert();
  void remEdge();
  void findSP();
  void print();
private:
  Vertex* getVertex(string);
  bool vertexExists(string);
  void diAlgo(); //Dijkstra's 
  map<string, Vertex*> vertices;
};

bool Graph::vertexExists(string label) {
  auto search = vertices.find(label);
  if (search != vertices.end()) {
    return true;
  }
  else {
    return false;
  }
}

Vertex* Graph::getVertex(string label) {
  auto search = vertices.find(label);
  if (search != vertices.end()) {
    return search->second;
  }
  else {
    return NULL;
  }
}

void Graph::addVert(string vertLabel) {
  //Vertex* x = new Vertex(vertLabel);
  if (vertexExists(vertLabel)) {
    cout << "Vertex label already exists." << endl;
    return;
  }
  vertices[vertLabel] = new Vertex(vertLabel);
}

void Graph::addEdge(string from, string to, int weight) {
  Vertex* sourceVert;
  if (!vertexExists(from)) {
    cout << "Edge source doesn't exist." << endl;
    return;
  }
  if (!vertexExists(to)) {
    cout << "Edge destination doesn't exist." << endl;
    return;
  }
  sourceVert = getVertex(from);
  sourceVert->addEdge(to, weight);
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
    //cout << v.second->getLabel();
    v.second->print();
    cout << endl;
  }
}

int main() {
  string usrIn;
  int w;
  string strTwo;
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
      cout << "What vertex does this edge come from?: " << endl;
      cin >> usrIn;
      cout << "What vertex does this go to?: " << endl;
      cin >> strTwo;
      cout << "What is the weight of this edge?: " << endl;
      cin >> w; //type is int
      g.addEdge(usrIn, strTwo, w);
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
