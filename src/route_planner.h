#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
    // Add public variables or methods declarations here.
	float GetDistance() const { return distance ;}	
  	void AStarSearch(); 
  
  private:
    // Add private variables or methods declarations here.
  	float CalculateHValue(RouteModel::Node *node); 
  	RouteModel::Node *start_node; 
 	RouteModel::Node *end_node; 
  	float distance; 
  	RouteModel &m_Model;
  	std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *current_node);
  std::vector<RouteModel::Node*>open_list;
  RouteModel::Node *NextNode(); 
  void AddNeighbors(RouteModel::Node *current_node); 
  	
};

#endif