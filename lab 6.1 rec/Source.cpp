#include <iostream>
#include <iomanip> // ��� ������������� ���������
#include <cstdlib> // ��� rand() �� srand()
#include <ctime>   // ��� time()
#include <Windows.h>

// ������� ��� ��������� ���������� ����� � ����� 
void generateArray(int arr[], int size, int lowerBound, int upperBound) {
    for (int i = 0; i < size; ++i) {
        arr[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
    }
}

// ���������� ������� ��� ��������� ������
void printArray(const int arr[], int size, int index = 0) {
    if (index == size) {
        std::cout << std::endl;
        return; // ������� �������
    }
    std::cout << std::setw(4) << arr[index];
    printArray(arr, size, index + 1); // ����������� ������ ��� ���������� ��������
}

// ���������� ������� ��� ���������� ������� �� ���� ��������, �� ������������� �������
void countAndSumElements(const int arr[], int size, int& count, int& sum, int index = 0) {
    if (index == size) {
        return; // ������� �������
    }
    if ((arr[index] > 0) && (arr[index] % 3 != 0)) {
        ++count;
        sum += arr[index];
    }
    countAndSumElements(arr, size, count, sum, index + 1); // ����������� ������ ��� ���������� ��������
}

// ���������� ������� ��� ����� ��������, �� ������������� �������, �� ���
void replaceWithZero(int arr[], int size, int index = 0) {
    if (index == size) {
        return; // ������� �������
    }
    if ((arr[index] > 0) && (arr[index] % 3 != 0)) {
        arr[index] = 0;
    }
    replaceWithZero(arr, size, index + 1); // ����������� ������ ��� ���������� ��������
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 22;
    int arr[size];
    int count = 0, sum = 0;

    // ����������� ���������� ���������� �����
    srand(static_cast<unsigned>(time(0)));

    // �������� �����
    generateArray(arr, size, -10, 35);

    // �������� ������������ �����
    std::cout << "������������ �����:\n";
    printArray(arr, size);

    // ���������� ������� �� ���� ��������, �� ������������� �������
    countAndSumElements(arr, size, count, sum);

    // �������� ������� �� ����
    std::cout << "����� ��������: " << count << std::endl;
    std::cout << "C��� ��������: " << sum << std::endl;

    // �������� ��������, �� ������������� �������, �� ���
    replaceWithZero(arr, size);

    // �������� ������������� �����
    std::cout << "������� �����:\n";
    printArray(arr, size);

    return 0;
}
