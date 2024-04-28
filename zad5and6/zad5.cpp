#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;


class shape {
public:
    virtual void show(HDC hdc) {} // виртуальный метод, позволяющий использовать метод show конкретного класса
}; // базовый класс для фигур

// класс точка
class point : shape {
public:
    int x, y;
    COLORREF color;
    point(int x, int y, COLORREF c = RGB(255, 255, 255)) : x(x), y(y), color(c) {}
    void show(HDC hdc)
    {
        SetPixel(hdc, x, y, color);
    }
};
// класс прямоугольник, использующий класс точка
class rectangle : shape {
    point top_left;
    point bottom_right;
    COLORREF color;
    COLORREF background_color;
    bool filled;
public:
    rectangle(int x1, int y1, int x2, int y2, COLORREF c, bool filled = false, COLORREF bc = 0) : top_left(x1, y1), bottom_right(x2, y2), color(c), background_color(bc), filled(filled) {}
    void show(HDC hdc) {
        SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
        SetDCPenColor(hdc, color); // установка цвета контура фигуры
        SetDCBrushColor(hdc, background_color); // установка цвета закраски
        if (filled)
        {
            SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти
        }
        else
        {
            SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски
        }
        Rectangle(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);
    }
};

class canvas
{
    vector<shape*> figures; // вектор для хранения фигур
    HWND hWnd;
    HDC hdc;
public:
    canvas()
    {
        hWnd = GetConsoleWindow(); // ссылка на окно
        hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
    }
    ~canvas()
    {
        ReleaseDC(hWnd, hdc);		// освобождение контекста устройства вывода
    }
    void add(shape* s)
    {
        figures.push_back(s);
    }
    void clear() //очистка холста
    {
        figures.clear();
    }
    void show() { // отображение графических примитивов вызовом метода show()
        for (size_t i = 0; i < figures.size(); i++)
            figures[i]->show(hdc);
    }
};

int main()
{
    canvas c; // создаем холст

    c.add((shape*)new rectangle(10, 10, 100, 100, RGB(255, 0, 0), true, RGB(255, 255, 0))); // добавление прямоугольника
    c.add((shape*)new rectangle(150, 100, 200, 250, RGB(0, 0, 255), true, RGB(0, 255, 0))); // добавление прямоугольника
    c.add((shape*)new rectangle(10, 100, 200, 150, RGB(255, 100, 0))); // добавление не закрашенного прямоугольника
    c.add((shape*)new point(250, 50)); // добавление точки
    c.add((shape*)new point(200, 50, RGB(255, 0, 255))); // добавление точки

    c.show(); // вывод графических примитивов на холст

    _getch();


    return 0;
}

