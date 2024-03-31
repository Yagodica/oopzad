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

    string GetOrg() const { // получение информации о месте работы
        return organization;
    }

    string GetPos() const { // получение занимаемой должности
        return position;
    }

    double GetExp() const { // получение стаже работы
        return experience;
    }

    double GetSal() const { // получение заработной платы
        return salary;
    }

    void SetPos(string pos) {// изменение должности
        position = pos;
    }

    void SetSal(double sal) {// начисление заработной платы
        salary = sal;
    }

    void PrintInfo() { // вывод личных данных
        cout << "\nМесто работы: " << organization << endl
                << " Должность: " << position << endl
                << " Стаж: " << experience << endl
                << " ФИО: " << full_name << endl
                << " Пол: " << sex << endl
                << " Возраст: " << age << endl
                << " Заработная плата: " << salary << endl;
    }


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
    const int Emp_Count = 3;

    auto *obj_array = new Employee [Emp_Count] {
            Employee("мпт", "сис админ", 1, "Иван", "муж", 20, 100000),
            Employee("рэу", "техподдержка", 2, "Даня", "муж", 23, 60000),
            Employee("Пятерочка", "касир", 1, "Настя", "жен", 20, 30000),
    };

    for (int i = 0; i < Emp_Count; ++i) {
        obj_array[i].PrintInfo();
    }

    cout << "Количество сотрудников: " << Employee::GetCount() << endl;

    //  Изменение должности, заработной платы

    obj_array[0].SetPos("Магнит");
    obj_array[0].SetSal(50000);

    cout << endl << obj_array[0].GetPos() << endl;
    cout << obj_array[0].GetSal() << endl;

    delete[] obj_array;
    return 0;
}