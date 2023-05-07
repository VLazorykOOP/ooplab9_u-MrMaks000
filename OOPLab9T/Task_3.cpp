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
    std::cout << "������ ��� �볺��� K: ";
    std::cin >> K;

    std::vector<ClientData> clientData;

    // ��� ������ ��� �볺���
    int duration, clientCode, year, month;
    std::cout << "������ ��� ��� �볺��� (���������, ��� �볺���, ��, ����� �����), �������� ����������� ���� �������� -1:\n";
    while (true) {
        std::cin >> duration;
        if (duration == -1)
            break;
        std::cin >> clientCode >> year >> month;
        clientData.push_back({ duration, clientCode, year, month });
    }

    // Գ���������� ����� ��� �볺��� � ����� K
    std::vector<ClientData> filteredData;
    for (const auto& data : clientData) {
        if (data.clientCode == K)
            filteredData.push_back(data);
    }

    // ��������, �� � ��� ��� �볺��� � ����� K
    if (filteredData.empty()) {
        std::cout << "��� ������" << std::endl;
        return;
    }

    // ���������� ����� ���� ��������� ��������� �� ����
    std::sort(filteredData.begin(), filteredData.end(), compareData);

    // ����� ����� � ��������� ��������� ��� ������� ����
    std::map<int, std::pair<int, int>> yearData; // year -> (duration, month)
    for (const auto& data : filteredData) {
        if (data.duration > 0) {
            int year = data.year;
            int month = data.month;
            if (yearData.find(year) == yearData.end())
                yearData[year] = { data.duration, month };
        }
    }

    // ����� ����������
    for (const auto& entry : yearData) {
        int duration = entry.second.first;
        int year = entry.first;
        int month = entry.second.second;
        std::cout << "���������� ����������������� �������: " << duration << ", ���: " << year << ", ����� ������: " << month << std::endl;
    }
}