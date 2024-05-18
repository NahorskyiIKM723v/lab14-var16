#include <iostream>
#include <Windows.h>
using namespace std;

bool isPrime(int num) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void fillPrimes(int arr[], int size) {
    int count = 0;
    int num = 2;
    while (count < size) {
        if (isPrime(num)) {
            arr[count] = num;
            count++;
        }
        num++;
    }
}

bool linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    const int SIZE = 15;
    int primes[SIZE];

    fillPrimes(primes, SIZE);

    cout << "Масив простих чисел: ";
    for (int i = 0; i < SIZE; i++) {
        cout << primes[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Введіть число для пошуку: ";
    cin >> target;

    if (linearSearch(primes, SIZE, target)) {
        cout << "Число " << target << " знайдено в масиві." << endl;
    }
    else {
        cout << "Число " << target << " не знайдено в масиві." << endl;
    }

    return 0;
}
