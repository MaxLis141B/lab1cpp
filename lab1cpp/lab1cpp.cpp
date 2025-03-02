#include <iostream>
#include <vector>
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <algorithm>
using namespace std;

template <typename T>
void InputVector(vector<T>& vec, const wstring& message) {
    wcout << message;
    for (auto& val : vec) {
        wcin >> val;
    }
}

template <typename T>
void PrintVector(const vector<T>& vec, const wstring& message) {
    wcout << message << L": ";
    for (const auto& val : vec) {
        wcout << val << L" ";
    }
    wcout << endl;
}

void Task1() {
    wcout << L"ЗАВДАННЯ 1" << endl;
    int N;
    wcout << L"Введіть розмір масиву: ";
    wcin >> N;

    vector<int> A(N), C(N);
    InputVector(A, L"Введіть елементи масиву A: ");

    for (int i = 0; i < N; ++i) {
        C[i] = pow(2, i) * A[i];
    }

    PrintVector(C, L"Результат (масив C)");
}

void Task2() {
    wcout << L"ЗАВДАННЯ 2" << endl;
    int N;
    wcout << L"Введіть розмір масиву: ";
    wcin >> N;

    vector<int> B(N);
    InputVector(B, L"Введіть елементи масиву B: ");

    int c, d, max = INT_MIN;
    bool found = false;

    wcout << L"Введіть значення c: ";
    wcin >> c;
    wcout << L"Введіть значення d: ";
    wcin >> d;

    for (int i = 0; i < N; ++i) {
        if (B[i] >= c && B[i] <= d) {
            if (B[i] > max) {
                max = B[i];
                found = true;
            }
            if (i < N - 1 && B[i + 1] % 2 == 0) break;
        }
    }

    if (!found) {
        wcout << L"Значення c і d поза межами масиву" << endl;
    }
    else {
        wcout << L"Результат (максимальний елемент): " << max << endl;
    }
}

void Task3() {
    wcout << L"ЗАВДАННЯ 3" << endl;
    int N;
    do {
        wcout << L"Введіть розмір масиву (≤ 500): ";
        wcin >> N;
    } while (N > 500);

    vector<float> A1(N);
    InputVector(A1, L"Введіть елементи масиву A: ");

    sort(A1.begin(), A1.end());

    float sum = 0, mult = 1;
    bool newnum = true;

    for (int i = 0; i < N; ++i) {
        if (i < N - 1 && A1[i] == A1[i + 1]) {
            sum += A1[i];
            newnum = false;
        }
        else {
            if (!newnum) {
                sum += A1[i];
                newnum = true;
            }
            else {
                mult *= A1[i];
            }
        }
    }

    wcout << L"Результат (сума повторень): " << sum << endl;
    wcout << L"Результат (добуток унікальних): " << mult << endl;
}

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    int choice;
    do {
        wcout << L"\nВиберіть завдання (1-3) або 0 для виходу: ";
        wcin >> choice;

        switch (choice) {
        case 1: Task1(); break;
        case 2: Task2(); break;
        case 3: Task3(); break;
        case 0: break;
        default: wcout << L"Невірний вибір!" << endl;
        }
    } while (choice != 0);

    return 0;
}