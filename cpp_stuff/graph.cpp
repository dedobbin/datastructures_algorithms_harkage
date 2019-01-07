#include <iostream>
#include <sstream>
#include "util.h"
#include "graph.h"


/***** public ************************************/
Point::Point(int _id) 
: id(_id) {}

void Point::connect(Point * point, int distance, bool connect_back) {
  Connection * c = new Connection(point, distance);
  this->connections.push_back(c);
  if (connect_back)
    point->connect(this, distance, false);
  return;
}

int Point::n_connections() {
  return this->connections.size();
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
  return os;
}

Connection::Connection(Point * _connectee, int distance) : connectee(_connectee) {
  this->connectee = connectee;
  this->distance = distance;
}

std::ostream& operator<< (std::ostream& os, const Connection& connection) {
  return os;
}

Graph::Graph(int n_points) {
  Util::Random * random = new Util::Random();
  this->points.resize(n_points);
  for (int i = 0; i < n_points; i++) {
    int random_id = random->generate();
    this->points.at(i) = new Point(random_id);
  }
  return;
}


std::ostream& operator<<(std::ostream& os, const Graph& graph){
  return os;
}

void Graph::generate() {
  std::vector<Point*> points = this->points;
  std::unique_ptr<Util::Random> random = std::make_unique<Util::Random>(0, points.size() - 1);
  int connected_points = 0;
  while (connected_points < this->points.size()) {
    Point * a = this->points.at(random->generate());
    Point * b = this->points.at(random->generate());
    if (a == b)
      continue;

    if (a->n_connections() == 0)
      connected_points++;
    if (b->n_connections() == 0)
      connected_points++;

    a->connect(b, 5);
  }
}

void Graph::print() {
  std::cout << "contains " << this->points.size() << " points" << std::endl;
  for(std::vector<Point*>::iterator it = this->points.begin(); it < this->points.end(); it++) {
    std::cout << **it;
  }
}

