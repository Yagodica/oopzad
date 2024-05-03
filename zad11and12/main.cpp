#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base {
public:
    virtual void show() {};
};

template <class T> class Point2D {
protected:
    T x, y;
public:
    Point2D(T x, T y) : x(x), y(y) {}
};

template <class T> class Z {
protected:
    T z;
public:
    Z(T z) : z(z) {}
};

template <class T> class H {
protected:
    T h;
public:
    H(T h) : h(h) {}
};

string getTypeName(const char* typeName) {
    switch (typeName[0]) {
        case 'i':
            return "int";
        case 's':
            return "short";
        case 'd':
            return "double";
        case 'f':
            return "float";
        case 'l':
            return "long";
        default:
            return "unknown";
    }
}

template <class T> class Point3Dh : public Point2D<T>, public Z<T>, public H<T>, public Base {
public:
    Point3Dh(T x, T y, T z, T h) : Point2D<T>(x, y), Z<T>(z), H<T>(h) {}

    void show() override {
        const char* typeName = typeid(T).name();
        T x_real = static_cast<T>(this->x) / this->h;
        T y_real = static_cast<T>(this->y) / this->h;
        T z_real = static_cast<T>(this->z) / this->h;
        cout << getTypeName(typeName) << " coordinates: (" << x_real << ", " << y_real << ", " << z_real << ")" << endl;
    }
};

int main() {
    vector<Base*> v;

    Point3Dh<int> point1(10, 4, 1, 2);
    Point3Dh<short> point2(8, 2, 12, 4);
    Point3Dh<double> point3(1.0, 6.6, 3.0, 3.0);
    Point3Dh<float> point4(2.5f, 2.0f, 1.0f, 1.3f);
    Point3Dh<long> point5(1l, 2l, 3l, 1l);

    v.push_back((Base*)&point1);
    v.push_back((Base*)&point2);
    v.push_back((Base*)&point3);
    v.push_back((Base*)&point4);
    v.push_back((Base*)&point5);

    for (const auto& item : v) {
        item->show();
    }

    return 0;
}
