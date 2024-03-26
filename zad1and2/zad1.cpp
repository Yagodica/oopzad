#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;    // имя
    int age;        // возраст
    float grade;    // рейтинг

public:
    string GetName() { // получение имени
        return this->name;
    }

    int GetAge() { // получение возраста
        return this->age;
    }

    float GetGrade() { // получение рейтинга
        return this->grade;
    }

    void SetName(string name) { // установка имени
        this->name = name;
    }

    void SetAge(int age) { // установка возраста
        this->age = age;
    }

    void SetGrade(float grade) { // установка рейтинга
        this->grade = grade;
    }

    void Set(string name, int age, float grade) { // установка всех трех полей
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    void Show() { // отображение информации о студенте
        cout << "Имя: " << this->name << ", Возраст: " << this->age << ", Рейтинг: " << this->grade << "\n";
    }
};

void test_SetName_and_GetName() {
    Student student;
    string name = "Иван";

    student.SetName(name);
    if (student.GetName() == name) {
        cout << "test_SetName_and_GetName пройден\n";
    } else {
        cout << "test_SetName_and_GetName не пройден\n";
        exit(-1);
    }
}

void test_SetAge_and_GetAge() {
    Student student;
    int age = 20;
    student.SetAge(age);

    if (student.GetAge() == age) {
        cout << "test_SetAge_and_GetAge пройден\n";
    } else {
        cout << "test_SetAge_and_GetAge не пройден\n";
        exit(-1);
    }
}

void test_SetGrade_and_GetGrade() {
    Student student;
    float grade = 4.5;
    student.SetGrade(grade);

    if (student.GetGrade() == grade) {
        cout << "test_SetGrade_and_GetGrade пройден\n";
    } else {
        cout << "test_SetGrade_and_GetGrade не пройден\n";
        exit(-1);
    }
}

int main() {
    test_SetName_and_GetName();
    test_SetAge_and_GetAge();
    test_SetGrade_and_GetGrade();

    int numStudents;
    cout << "Введите количество студентов: ";
    cin >> numStudents;

    vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; i++) {
        string name;
        int age;
        float grade;

        cout << "\nВведите имя студента " << i + 1 << ": ";
        cin >> name;
        students[i].SetName(name);

        cout << "\nВведите возраст студента " << i + 1 << ": ";
        cin >> age;
        students[i].SetAge(age);

        cout << "\nВведите рейтинг студента " << i + 1 << ": ";
        cin >> grade;
        students[i].SetGrade(grade);
    }

    cout << "Информация о студентах:\n";
    for (int i = 0; i < numStudents; i++) {
        students[i].Show();
    }

    return 0;
}

