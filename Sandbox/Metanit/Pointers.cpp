#include <iostream>
using std::cout;
using std::endl;

void PointerAriphmetics() {
    int a = 10;

    int* pa = &a;

    cout << "Variable size: " << sizeof(a) << "\t" << "Pointer size: " << sizeof(pa) << endl;

    for (size_t i = 0; i < 4; i++)
    {
        cout << "Address: " << pa << "\t" << "Value: " << *pa << endl;

        pa++;
    }
}

void Array() {

    int a[4] = { 1, 2, 4, 8 };

    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
        cout << "a[" << i << "] address: " << &a[i] << endl;
    }

}

void ArrayPointers() {

    int a[4] = { 1, 2, 4, 8 };

    int* pa = a;

    cout << "Array address:" << a << endl;
    cout << "a[0] = " << *a << endl;

    cout << endl;

    for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << "a[" << i << "] address:" << a + i << "\t" << "value:" << *(a + i) << endl;
    }

    cout << endl;

    int* parr = a;
    cout << "a[2] = " << *(parr + 2) << endl;

}

void TwoDimentionalArrayPointer() {

    int a[3][4] = { {1, 2, 3, 4} , {5, 6, 7, 8}, {9, 10, 11, 12} };
    int n = sizeof(a) / sizeof(a[0]);         // число строк
    int m = sizeof(a[0]) / sizeof(a[0][0]);   // число столбцов

    int* end = a[0] + n * m - 1;    // указатель на самый последний элемент 0 + 3 * 4 - 1 = 11
    for (int* ptr = a[0], i = 1; ptr <= end; ptr++, i++)
    {
        cout << *ptr << "\t";
        // если остаток от целочисленного деления равен 0,
        // переходим на новую строку
        if (i % m == 0)
        {
            cout << endl;
        }
    }
}

void Increment(int* p) {

    (*p)++;

    cout << "Inner value:" << "\t" << *p << endl;

}

void PointerArgument() {

    int a = 7;

    Increment(&a);

    cout << "Outer value:" << "\t" << a << endl;

}

void PrintArray(char* array) {

    for (size_t i = 0; i < array[i] != '\0'; i++)
    {
        cout << array[i] << '\t';
    }

    cout << endl;
}

void PrintArray(int* array, int size) {

    for (size_t i = 0; i < size; i++)
    {
        cout << array[i] << '\t';
    }

    cout << endl;
}

void PrintArray(int* begin, int* end) {

    for (int *p = begin; p != end; p++)
    {
        cout << *p << '\t';
    }

    cout << endl;
}

void ArrayParameter() {

    char text[] = "Hello!";

    PrintArray(text);

    int numbers[] = { 1,2,4,8,16,32 };

    int size = sizeof(numbers) / sizeof(numbers[0]);

    PrintArray(numbers, size);

    PrintArray(std::begin(numbers), std::end(numbers));
}

int Add(int a, int b) {
    return a + b;
}

int Substract(int a, int b) {
    return a - b;
}

int Multiply(int a, int b) {
    return a * b;
}

int Operation(int (*operation)(int a, int b), int a, int b) {
    return operation(a, b);
}

void FunctionPointer() {

    int a = 10;
    int b = 5;

    int (*action)(int a, int b);

    action = Add;
    cout << a << "+" << b << "=" << action(a, b) << endl;

    action = Substract;
    cout << a << "-" << b << "=" << action(a, b) << endl;

    cout << endl;

    int (*actions[3])(int a, int b) = { Add, Substract, Multiply };

    int arraySize = sizeof(actions);
    int elementSize = sizeof(actions[0]);

    int size = arraySize / elementSize;

    for (size_t i = 0; i < size; i++)
    {
        cout << actions[i](a, b) << endl;
    }

    cout << "Functions defenitions:" << endl;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < elementSize; j++)
        {
            cout << *(actions + i * elementSize + j) << ' ';
        }

        cout << endl;
    }

    cout << a << "+" << b << "=" << Operation(Add, a, b) << endl;
    cout << a << "-" << b << "=" << Operation(Substract, a, b) << endl;
    cout << a << "*" << b << "=" << Operation(Multiply, a, b) << endl;
}