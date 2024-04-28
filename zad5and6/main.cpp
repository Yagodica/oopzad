#include <conio.h>
#include <vector>
#include <string>
#include "Canvas.h"
#include <iostream>


using namespace std;

int main() {
    canvas c; // создаем холст
    
    while (true)
    {
        int x1{}, y1{}, x2{}, y2{}, colvo{};
        int r{}, g{}, b{}, br{}, bg{}, bb{};
        bool filled;
        string switch_shape;

        //c.add((shape*)new rectangle(10, 10, 100, 100, RGB(255, 0, 0), true, RGB(255, 255, 0)));
        
        cout << "Введите название примитива (point, line, ellipse, rectangle, polygon, refresh): ";
        cin >> switch_shape;

        if (switch_shape == "point") {
            cout << "Введите координаты точки (x, y): ";
            cin >> x1 >> y1;
            cout << "Введите цвет (r, g, b): ";
            cin >> r >> g >> b;
            c.add((shape*)new point(x1, y1, RGB(r, g, b))); // добавление точки
        }
        else if (switch_shape == "line") {
            cout << "Введите координаты линии (x1, y1, x2, y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Введите цвет (r, g, b): ";
            cin >> r >> g >> b;
            c.add((shape*)new line(x1, y1, x2, y2, RGB(r, g, b))); // добавление линии
        }
        else if (switch_shape == "ellipse") {
            cout << "Введите координаты линии (x1, y1, x2, y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Введите цвет (r, g, b): ";
            cin >> r >> g >> b;
            cout << "Заполненный или нет (1 или 0): ";
            cin >> filled;
            cout << "Введите цвет (r, g, b): ";
            cin >> br >> bg >> bb;
            c.add((shape*)new ellipse(x1, y1, x2, y2, RGB(r, g, b), filled, RGB(br, bg, bb))); // добавление элипса
        }
        else if (switch_shape == "rectangle") {
            cout << "Введите координаты линии (x1, y1, x2, y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            cout << "Введите цвет (r, g, b): ";
            cin >> r >> g >> b;
            cout << "Заполненный или нет (1 или 0): ";
            cin >> filled;
            cout << "Введите цвет (r, g, b): ";
            cin >> br >> bg >> bb;
            c.add((shape*)new rectangle(x1, y1, x2, y2, RGB(r, g, b), filled, RGB(br, bg, bb)));
        }
        else if (switch_shape == "polygon") {
            
            vector <point> coordinates{};
            int input;

            cout << "Введите координаты линии: ";

            while ((cin >> input) && input != 9999) {
                point p{};
                p.x = input;
                cin >> p.y;
                coordinates.push_back(p);
                cout << "Введите координаты линии: ";
            }

            cout << "Введите цвет (r, g, b): ";
            cin >> r >> g >> b;
            cout << "Заполненный или нет (1 или 0): ";
            cin >> filled;
            cout << "Введите цвет (r, g, b): ";
            cin >> br >> bg >> bb;
            c.add((shape*)new polygon(coordinates, RGB(r, g, b), filled, RGB(br, bg, bb)));
        } 
        else if (switch_shape == "refresh") {
            
        }
        else {
            break;
        }

        c.show();
    }

    _getch();
   
    return 0;
}
