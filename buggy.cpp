#include <iostream>

// FIXME: Add appropriate declarative regions to scope and other header files.
// EXPLAIN: Why are these required?
struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    int vertices;
    Point** points;

// FIXME: Add appropriate access modifiers.
// EXPLAIN: Why should we add the access modifier?
    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices+1];
    }

    //FIXME: Fill out the destructor.
    //EXPLAIN: Why should we fill destructors? What will happen if the destroyer is left empty?
    ~Shape () {
    }

    // FIXME
    void addPoints (/* formal parameter for unsized array called pts */) {
        for (int i = 0; i <= vertices; i++) {
            //FIXME: Add an allocation of point
            //EXPLAIN: Why should we add the allocation of point?
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    // FIXME: update the computation
    double* area () {
        int temp = 0;
        // FIXME
        for (int i = 0; i <= vertices; i++) {
            // FIXME: there are two methods to access members of pointers
            //        use one to fix lhs and the other to fix rhs
            int lhs = points[i].x * points[i+1].y;
            int rhs = points[i+1].x * points[i].y;
            temp += (lhs - rhs);
        }
        double area = abs(temp)/2.0;
        return &area;
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)

    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    // FIXME
    tri.addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad.addPoints(quadPts);

    // FIXME: print out area of triangle and area of quad

    // FIXME: clean-up dynamically allocated memory to avoid memory leaks
}