#include <iostream>
#include <cmath>

using namespace std;

// оголошення функцій (до main)
int RootCount(double pA, double pB, double pC); // кількість коренів Proc27
void ResistorParallel(double pR1, double pR2, double &pR); // опір Proc18

bool in_N(int &pN);       // введення з перевіркою Integer13
int shift_left(int pN);   // підрахунок Integer13
void out_res(int pr);     // виведення результатів Integer13

void task_Proc27();       // задача Proc27 цілком
void task_Proc18();       // задача Proc18 цілком
void task_Int13();        // задача Integer13 цілком

int main() {
    int choice; // вибір пункту меню
    cout << "1 - Proc27 (корені квадратного рівняння)" << endl;
    cout << "2 - Proc18 (опір паралельних резисторів)" << endl;
    cout << "3 - Integer13 (перестановка цифри числа)" << endl;
    cout << "Оберіть завдання (1-3): ";
    cin >> choice;

    if (cin.fail()) { // перевірка коректності введення
        cout << "Помилка введення!" << endl;
        return 1;
    }

    switch (choice) { // меню вибору завдання
        case 1:
            task_Proc27();
            break;
        case 2:
            task_Proc18();
            break;
        case 3:
            task_Int13();
            break;
        default:
            cout << "Невірний номер завдання!" << endl;
    }

    return 0;
} // кінець main ()

// визначення функцій - після main ()

int RootCount(double pA, double pB, double pC) {
    double D = pB * pB - 4 * pA * pC; // дискримінант
    if (D > 0) return 2;
    else if (D == 0) return 1;
    else return 0;
} // кінець RootCount ()

void ResistorParallel(double pR1, double pR2, double &pR) {
    pR = (pR1 * pR2) / (pR1 + pR2); // формула паралельного опору
} // кінець ResistorParallel ()

void task_Proc27() {
    double a1, b1, c1, a2, b2, c2, a3, b3, c3; // коефіцієнти трьох рівнянь
    cout << "Proc27. Введіть A, B, C для 3 рівнянь (A != 0, [-100, 100]):" << endl;

    cout << "Рівняння 1: ";
    cin >> a1 >> b1 >> c1;
    if (cin.fail() || a1 == 0 || a1 < -100 || a1 > 100 || b1 < -100 || b1 > 100 || c1 < -100 || c1 > 100) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    cout << "Рівняння 2: ";
    cin >> a2 >> b2 >> c2;
    if (cin.fail() || a2 == 0 || a2 < -100 || a2 > 100 || b2 < -100 || b2 > 100 || c2 < -100 || c2 > 100) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    cout << "Рівняння 3: ";
    cin >> a3 >> b3 >> c3;
    if (cin.fail() || a3 == 0 || a3 < -100 || a3 > 100 || b3 < -100 || b3 > 100 || c3 < -100 || c3 > 100) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    // виклик функції і виведення результату без циклів
    cout << "Кількість коренів: ";
    cout << RootCount(a1, b1, c1) << " ";
    cout << RootCount(a2, b2, c2) << " ";
    cout << RootCount(a3, b3, c3) << endl;
} // кінець task_Proc27 ()

void task_Proc18() {
    double r1_1, r1_2, r1; // перша пара резисторів і результат
    double r2_1, r2_2, r2; // друга пара резисторів і результат
    double r3_1, r3_2, r3; // третя пара резисторів і результат
    cout << "Proc18. Введіть R1 та R2 для 3 пар резисторів ((0, 100]):" << endl;

    cout << "Пара 1: ";
    cin >> r1_1 >> r1_2;
    if (cin.fail() || r1_1 <= 0 || r1_1 > 100 || r1_2 <= 0 || r1_2 > 100) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    cout << "Пара 2: ";
    cin >> r2_1 >> r2_2;
    if (cin.fail() || r2_1 <= 0 || r2_1 > 100 || r2_2 <= 0 || r2_2 > 100) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    cout << "Пара 3: ";
    cin >> r3_1 >> r3_2;
    if (cin.fail() || r3_1 <= 0 || r3_1 > 100 || r3_2 <= 0 || r3_2 > 100) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    // виклик процедури без циклів
    ResistorParallel(r1_1, r1_2, r1);
    ResistorParallel(r2_1, r2_2, r2);
    ResistorParallel(r3_1, r3_2, r3);

    cout << "Загальні опори: " << r1 << " " << r2 << " " << r3 << endl;
} // кінець task_Proc18 ()

void task_Int13() {
    int N; // декларація змінної
    if (in_N(N)) // некоректні дані
        cout << "Помилка: потрібно ввести ціле тризначне число!" << endl;
    else
        // підрахунок і виведення результату
        out_res(shift_left(N));
} // кінець task_Int13 ()

bool in_N(int &pN) {
    cout << "Integer13." << endl;
    cout << "N = ";
    cin >> pN;
    if (cin.fail()) // перевірка помилок консольного введення
        return true;
    int absN = abs(pN);
    if (absN < 100 || absN > 999) // перевірка на тризначність
        return true;
    else
        return false;
} // кінець in_N ()

int shift_left(int pN) {
    int sign = (pN < 0) ? -1 : 1; // знак числа
    int absN = abs(pN);
    return sign * ((absN % 100) * 10 + (absN / 100));
} // кінець shift_left ()

void out_res(int pr) {
    cout << "Результат = " << pr << endl;
} // кінець out_res ()
