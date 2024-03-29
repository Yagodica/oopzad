#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string organization;    // Место работы
    string position;        // Должность
    double experience;      // Стаж
    string full_name;       // ФИО
    string sex;             // Пол
    int age;                // Возраст
    double salary;          // Заработная плата
    static int count;       // Колво сотрудников

public:
    Employee() {
        count++;
    }

    ~Employee() {
        count--;
    }

    string GetOrg() { // получение информации о месте работы
        return organization;
    }

    string GetPos() { // получение занимаемой должности
        return position;
    }

    double GetExp() { // получение стаже работы
        return experience;
    }

    double GetSal() { // получение заработной платы
        return salary;
    }

    void SetPos(string pos) {// изменение должности
        position = pos;
    }

    void SetSal(double sal) {// начисление заработной платы
        salary = sal;
    }

    void PrintInfo() { // вывод личных данных
        cout << "Место работы: " << organization << endl
                << " Должность: " << position << endl
                << " Стаж: " << experience << endl
                << " ФИО: " << full_name << endl
                << " Пол: " << sex << endl
                << " Возраст: " << age << endl
                << " Заработная плата: " << salary << endl;
    }

    bool operator==(const Employee& lhs) // операции сравнения объектов, присваивание (перегрузка операций)
    {
        return lhs.position == position;
    }

    static int GetCount() {
        return count;
    }

};

}

