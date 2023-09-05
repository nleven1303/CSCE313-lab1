#include <iostream>
#include <string.h>
using namespace std;

// FIXME: Add appropriate declarative regions to scope and other header files.
// EXPLAIN: Why are these required?
struct Point {
    int x, y;

    Point () : x(0), y(0) {} //default constructor to initialize our variables
    Point (int _x, int _y) : x(_x), y(_y) {} //constructor to initialize our variables to their respected values
};

class Shape {
    public:
        int vertices;
        Point **points;
    // FIXME: Add appropriate access modifiers.
    // EXPLAIN: Why should we add the access modifier?
    Shape (int _vertices) : vertices(_vertices){ //the modifiers are used to control 
        points = new Point*[vertices+1];          // how we can access the variables(vertices, area) and the functions
    }

    //FIXME: Fill out the destructor.
    //EXPLAIN: Why should we fill destructors? What will happen if the destroyer is left empty?
    ~Shape () { //the destructor allocates for unwanted memory in our program
        for(int i = 0; i <= vertices; i++) {
            delete[] points[i];
        }
        delete[] points;
    }

    // FIXME
    void addPoints (Point pts[]) {
        for (int i = 0; i <= vertices; i++) {
            //FIXME: Add an allocation of point
            //EXPLAIN: Why should we add the allocation of point?
            points[i] = new Point();
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    // FIXME: update the computation
    double area () {
        int temp = 0;
        // FIXME
        for (int i = 0; i < vertices; i++) {
            // FIXME: there are two methods to access members of pointers
            //        use one to fix lhs and the other to fix rhs
            int lhs = points[i]->x * points[(i+1)]->y;
            int rhs = points[(i+1)]->x * points[i]->y;
            temp += (lhs - rhs);
        }
        double area = abs(temp)/2.0;
        return area;
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)

    // adding points to tri
    Point triPts[3] = {Point(0,0), Point(1,2), Point(2,0)};
    Shape* tri = new Shape(3);
    // FIXME
    tri->addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)

    // adding points to quad
    Point quadPts[4] = {Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0)};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    // FIXME: print out area of triangle and area of quad
    cout << "The area of the triangle is: " << tri->area() << endl;
    cout << "The area of the quad is: " << quad->area() << endl;

    // FIXME: clean-up dynamically allocated memory to avoid memory leaks
   delete[] tri;
   delete[] quad;

   return 0;

    
}