#include <iostream>
#include <vector>
#include <algorithm>

inline void Task1() {
    int K;
    std::cout << "Введіть число K: ";
    std::cin >> K;

    std::vector<int> V;
    int num;
    std::cout << "Введіть елементи вектора (0 або 1), операція завершиться після ввода -1:\n";
    while (true) {
        std::cin >> num;
        if (num == -1)
            break;
        V.push_back(num);
    }

    // Поиск останнього набора из K нулів
    auto it = std::search_n(V.rbegin(), V.rend(), K, 0);

    if (it != V.rend()) {
        // Використовуємо зворотні ітератори для видалення останніх K нулів
        auto erase_it = it.base();
        V.erase(erase_it - K, erase_it);
    }

    // Вивід результату
    std::cout << "Результат:\n";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


}