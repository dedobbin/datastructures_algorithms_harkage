#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

//forward declaration
class Point;

class Connection {
public:
  Connection(Point * connectee, int distance);

private:
  int distance;
  Point const * connectee;
  friend std::ostream& operator<< (std::ostream& stream, const Connection& connection);
};

class Point {
  public:
    Point(int _id);
    void connect(Point * point, int distance, bool connect_back = true);
    int n_connections();
    const int id;

  private:
    std::vector<Connection*> connections;

  friend std::ostream& operator<<(std::ostream& os, const Point& point);
};


class Graph {
	public:
		Graph(int n_points);
    void print();
    void generate();
  
  private:
    std::vector<Point*> points;

  friend std::ostream& operator<< (std::ostream& stream, const Graph& graph);
};

#endif