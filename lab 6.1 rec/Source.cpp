#include <iostream>
#include <iomanip> // для форматованого виведення
#include <cstdlib> // для rand() та srand()
#include <ctime>   // для time()
#include <Windows.h>

// Функція для генерації випадкових чисел у масиві 
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// Рекурсивна функція для виведення масиву
void printArray(const int arr[], int size, int index = 0) {
    if (index == size) {
        std::cout << std::endl;
        return; // Базовий випадок
    }
    std::cout << std::setw(4) << arr[index];
    printArray(arr, size, index + 1); // Рекурсивний виклик для наступного елемента
}

// Рекурсивна функція для обчислення кількості та суми елементів, які задовольняють критерій
void countAndSumElements(const int arr[], int size, int& count, int& sum, int index = 0) {
    if (index == size) {
        return; // Базовий випадок
    }
    if ((arr[index] > 0) && (arr[index] % 3 != 0)) {
        ++count;
        sum += arr[index];
    }
    countAndSumElements(arr, size, count, sum, index + 1); // Рекурсивний виклик для наступного елемента
}

// Рекурсивна функція для заміни елементів, які задовольняють критерій, на нулі
void replaceWithZero(int arr[], int size, int index = 0) {
    if (index == size) {
        return; // Базовий випадок
    }
    if ((arr[index] > 0) && (arr[index] % 3 != 0)) {
        arr[index] = 0;
    }
    replaceWithZero(arr, size, index + 1); // Рекурсивний виклик для наступного елемента
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 22;
    int arr[size];
    int count = 0, sum = 0;

    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    // Генеруємо масив
    generateArray(arr, size, -10, 35);

    // Виводимо згенерований масив
    std::cout << "Згенерований масив:\n";
    printArray(arr, size);

    // Обчислюємо кількість та суму елементів, що задовольняють критерію
    countAndSumElements(arr, size, count, sum);

    // Виводимо кількість та суму
    std::cout << "Число елементів: " << count << std::endl;
    std::cout << "Cума елементів: " << sum << std::endl;

    // Замінюємо елементи, що задовольняють критерій, на нулі
    replaceWithZero(arr, size);

    // Виводимо модифікований масив
    std::cout << "Змінений масив:\n";
    printArray(arr, size);

    return 0;
}
