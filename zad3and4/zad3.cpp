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
        organization = "1";    // Место работы
        position = "1";        // Должность
        experience = 1;      // Стаж
        full_name = "1";       // ФИО
        sex = "1";             // Пол
        age = 1;                // Возраст
        salary = 1;          // Заработная плата
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

    bool operator==(const Employee& other) const {
        return organization == other.organization &&
               position == other.position &&
               experience == other.experience &&
               full_name == other.full_name &&
               sex == other.sex &&
               age == other.age &&
               salary == other.salary;
    }

    static int GetCount() {
        return count;
    }

};

int Employee::count = 0;

int main() {
    Employee *obj1 = new Employee();
    Employee *obj2 = new Employee();

    if (obj1 == obj2) {
        cout << "Объекты emp1 и emp2 равны." << endl;
    } else {
        cout << "Объекты emp1 и emp2 не равны." << endl;
    }

    return 0;
}

