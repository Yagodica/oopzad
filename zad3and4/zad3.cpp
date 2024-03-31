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
    Employee(string org, string pos, double exp, string name, string s, int a, double sal)
            : organization(org), position(pos), experience(exp), full_name(name), sex(s), age(a), salary(sal) {
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

//    bool operator==(const Employee& other) // операции сравнения объектов, присваивание (перегрузка операций)
//    {
//        return this->organization == other.organization;
//    }


    bool operator==(const Employee& other)
    {
        return organization == other.organization;
    }


    static int GetCount() {
        return count;
    }

};

int Employee::count = 0;


int main() {

    Employee *obj1 = new Employee("Test org1", "Test pos", 2, "Test name", "male", 20, 100000);
    Employee *obj2 = new Employee("Test org1", "Test pos", 2, "Test name", "male", 20, 100000);


    cout << (*obj1 == *obj2) << endl;


    delete obj1;
    delete obj2;
    return 0;
}

