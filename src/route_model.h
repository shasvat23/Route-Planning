#ifndef ROUTE_MODEL_H
#define ROUTE_MODEL_H

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>

class RouteModel : public Model {

  public:
    class Node : public Model::Node {
      public:
        // Add public Node variables and methods here.
      	Node * parent = nullptr; 
  		float h_value = std::numeric_limits<float>::max(); 
  		float g_value = 0.0;
  		bool visited = false ;
  		std::vector<Node *> neighbors;
      	void FindNeighbors();
        float distance(Node other) const {
      		return std::sqrt(std::pow((x-other.x),2) + std::pow((y-other.y),2));
    		}
        Node(){}
        Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}
       
      private:
        // Add private Node variables and methods here.
      	Node * FindNeighbor(std::vector<int> node_indisces);
        int index;
        RouteModel * parent_model = nullptr;
    };
    
    // Add public RouteModel variables and methods here.
  	
  
  	Node &FindClosestNode(float x, float y);
    auto &GetNodeToRoadMap() { return node_to_road;}    
 	std::vector<Node>& SNodes(){return m_Nodes;}
    RouteModel(const std::vector<std::byte> &xml);  
    std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.

  private:
    // Add private RouteModel variables and methods here.
  	void CreateNodeToRoadHashmap();
 	std::vector<Node> m_Nodes;
	 std::unordered_map<int, std::vector<const Model::Road *>> node_to_road;
};

#endif