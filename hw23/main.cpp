//
//  main.cpp
//  hw23
//
//  Created by Valeria Dudinova on 14.12.2024.
//

#include <iostream>
using namespace std;

int main()
{
    const int size = 10;
    int arr[size] = {12, -3, 104, 81, -7, 3, 0, 6, 9, -1};
    int sumDigits = 0;
    double sumPositives = 0;
    int countPositives = 0;
    int maxNegative = INT_MIN;
    int maxNegativeIndex = -1;
    int freq[size] = {0};
    int maxFreqNum = arr[0], maxFreq = 1;
    int maxOddDiv3 = INT_MIN;
    int minOdd = INT_MAX, maxEven = INT_MIN;
    bool oddExists = false, evenExists = false;

    for (int i = 0; i < size; ++i) {
        // 1. Сума цифр
        int num = abs(arr[i]);
        while (num > 0) {
            sumDigits += num % 10;
            num /= 10;
        }

        // 2. Середнє арифметичне позитивних
        if (arr[i] > 0) {
            sumPositives += arr[i];
            countPositives++;
        }

        // 3. Максимальний від'ємний елемент
        if (arr[i] < 0 && arr[i] > maxNegative) {
            maxNegative = arr[i];
            maxNegativeIndex = i;
        }

        // 4. Частотність чисел
        for (int j = 0; j < size; ++j) {
            if (arr[i] == arr[j]) {
                freq[i]++;
            }
        }
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxFreqNum = arr[i];
        }

        // 5. Найбільший елемент з непарними індексами, що ділиться на 3
        if (i % 2 != 0 && arr[i] % 3 == 0 && arr[i] > maxOddDiv3) {
            maxOddDiv3 = arr[i];
        }

        // 6. Найбільший парний і найменший непарний
        if (arr[i] % 2 == 0) {
            evenExists = true;
            maxEven = max(maxEven, arr[i]);
        } else {
            oddExists = true;
            minOdd = min(minOdd, arr[i]);
        }
    }

    // Замінити парний і непарний елементи
    if (evenExists && oddExists) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == maxEven) arr[i] = minOdd;
            else if (arr[i] == minOdd) arr[i] = maxEven;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            arr[i] = 0;
        }
    }

    // Вивід результатів
    cout << "The sum of the array digits: " << sumDigits << endl;
    cout << "Arithmetic mean of positives: "
         << (countPositives ? sumPositives / countPositives : 0) << endl;
    if (maxNegativeIndex != -1) {
        cout << "Maximum negative: " << maxNegative
             << " in position " << maxNegativeIndex << endl;
    } else {
        cout << "There are no negative numbers." << endl;
    }
    cout << "The number that occurs most often: " << maxFreqNum
         << " (appears " << maxFreq << " times)" << endl;
    cout << "The largest of the odd indices divisible by 3: "
         << (maxOddDiv3 != INT_MIN ? maxOddDiv3 : 0) << endl;
    cout << "Modified array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
