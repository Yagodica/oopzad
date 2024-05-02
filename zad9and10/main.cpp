#include <iostream>

using namespace std;

class Point2D {
protected:
    int x, y;
public:
    Point2D(int x, int y) : x(x), y(y) {}
};

class Z {
protected:
    int z;
public:
    Z(int z) : z(z) {}
};

class H {
protected:
    double h;
public:
    H(double h) : h(h) {}
};

class Point3Dh : public Point2D, public Z, public H {
public:
    Point3Dh(int x, int y, int z, double h) : Point2D(x, y), Z(z), H(h) {
        if (h == 0) {
            throw invalid_argument("Четвертая координата не может быть нулевой");
        }
    }

    void printCoordinates() {
        double x_real = static_cast<double>(x) / h;
        double y_real = static_cast<double>(y) / h;
        double z_real = static_cast<double>(z) / h;
        cout << "Координата: (" << x_real << ", " << y_real << ", " << z_real << ")" << endl;
    }
};

int main() {
    try {
        Point3Dh point1(1, 2, 3, 4.0);
        Point3Dh point2(4, 5, 6, 2.0);

        point1.printCoordinates();
        point2.printCoordinates();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
