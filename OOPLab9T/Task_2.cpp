#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

inline void Task2() {
    std::vector<int> V;
    int num;
    std::cout << "Введіть елементи вектора, операція завершиться після введення -1:\n";
    while (true) {
        std::cin >> num;
        if (num == -1)
            break;
        V.push_back(num);
    }

    // Пошук мінімального та максимального елементів вектора
    auto min_max = std::minmax_element(V.begin(), V.end());
    int min_element = *min_max.first;
    int max_element = *min_max.second;

    // Створення допоміжної множини для зберігання унікальних елементів, крім мінімальної та максимальної
    std::set<int> unique_elements(V.begin(), V.end());
    unique_elements.erase(min_element);
    unique_elements.erase(max_element);

    // Створення вектора для зберігання унікальних елементів у порядку зменшення
    std::vector<int> result(unique_elements.rbegin(), unique_elements.rend());

    // Вивід результату
    std::cout << "Результат:\n";
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}