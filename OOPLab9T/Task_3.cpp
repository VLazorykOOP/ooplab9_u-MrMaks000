#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

struct ClientData {
    int duration;
    int clientCode;
    int year;
    int month;
};

inline bool compareData(const ClientData& data1, const ClientData& data2) {
    if (data1.duration != data2.duration)
        return data1.duration < data2.duration;
    return data1.year < data2.year;
}

inline void Task3() {
    int K;
    std::cout << "Введіть код клієнта K: ";
    std::cin >> K;

    std::vector<ClientData> clientData;

    // Ввід данних про клієнтів
    int duration, clientCode, year, month;
    std::cout << "Введіть дані про клієнтів (тривалість, код клієнта, рік, номер місяця), введення завершиться після введення -1:\n";
    while (true) {
        std::cin >> duration;
        if (duration == -1)
            break;
        std::cin >> clientCode >> year >> month;
        clientData.push_back({ duration, clientCode, year, month });
    }

    // Фільтрування даних для клієнта з кодом K
    std::vector<ClientData> filteredData;
    for (const auto& data : clientData) {
        if (data.clientCode == K)
            filteredData.push_back(data);
    }

    // Перевірка, чи є дані про клієнта з кодом K
    if (filteredData.empty()) {
        std::cout << "Нет данных" << std::endl;
        return;
    }

    // Сортування даних щодо зростання тривалості та року
    std::sort(filteredData.begin(), filteredData.end(), compareData);

    // Пошук місяця з мінімальною тривалістю для кожного року
    std::map<int, std::pair<int, int>> yearData; // year -> (duration, month)
    for (const auto& data : filteredData) {
        if (data.duration > 0) {
            int year = data.year;
            int month = data.month;
            if (yearData.find(year) == yearData.end())
                yearData[year] = { data.duration, month };
        }
    }

    // Вывод результата
    for (const auto& entry : yearData) {
        int duration = entry.second.first;
        int year = entry.first;
        int month = entry.second.second;
        std::cout << "Наименьшая продолжительность занятий: " << duration << ", год: " << year << ", номер месяца: " << month << std::endl;
    }
}