#include <iostream>
#include <vector>
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <algorithm>

using namespace std;

template <typename T>
void InputVector(vector<T>& vec, const wstring& message)
{
    wcout << message;
    for (size_t i = 0; i < vec.size(); i++)
    {
        wcin >> vec[i];
    }
}

template <typename T>
void PrintVector(const vector<T>& vec, const wstring& message)
{
    wcout << message << L": ";
    for (const auto& val : vec)
    {
        wcout << val << L" ";
    }
    wcout << endl;
}

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wcout << L"ЗАВДАННЯ 1" << endl;
    wcout << L"Введіть розмір масиву: ";
    int N;
    wcin >> N;

    vector<int> A(N), C(N);
    InputVector(A, L"Введіть елементи масиву A: ");

    for (int i = 0; i < N; i++)
    {
        C[i] = pow(2, i) * A[i];
    }

    PrintVector(C, L"Результат (масив C)");

    wcout << endl << L"ЗАВДАННЯ 2" << endl;
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

    for (int i = 0; i < N; i++)
    {
        if (B[i] >= c && B[i] <= d)
        {
            if (B[i] > max)
            {
                max = B[i];
                found = true;
            }
            if (i < N - 1 && B[i + 1] % 2 == 0)
            {
                break;
            }
        }
    }


    if (!found)
    {
        wcout << L"Значення c і d поза межами масиву" << endl;
    }
    else
    {
        wcout << L"Результат (максимальний елемент): " << max << endl;
    }

    wcout << endl << L"ЗАВДАННЯ 3" << endl;
    wcout << L"Введіть розмір масиву (≤ 500): ";
    do
    {
        wcin >> N;
        if (N > 500)
        {
            wcout << L"Розмір масиву не має перевищувати 500. Введіть ще раз: ";
        }
        else
        {
            break;
        }
    } while (true);

    vector<float> A1(N);
    InputVector(A1, L"Введіть елементи масиву A: ");

    sort(A1.begin(), A1.end());

    float sum = 0, mult = 1;
    bool newnum = true;

    for (int i = 0; i < N; i++)
    {
        if (i < N - 1 && A1[i] == A1[i + 1])
        {
            sum += A1[i];
            newnum = false;
        }
        if (i < N - 1 && A1[i] != A1[i + 1] && !newnum)
        {
            sum += A1[i];
            newnum = true;
        }
        if (i < N - 1 && A1[i] != A1[i + 1])
        {
            mult *= A1[i];
            newnum = true;
        }
    }

    if (newnum)
    {
        mult *= A1[N - 1];
    }
    else
    {
        sum += A1[N - 1];
    }

    wcout << L"Результат (сума): " << sum << endl;
    wcout << L"Результат (добуток): " << mult << endl;

    return 0;
}
