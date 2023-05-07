#include <iostream>
#include <vector>
#include <algorithm>

inline void Task1() {
    int K;
    std::cout << "������ ����� K: ";
    std::cin >> K;

    std::vector<int> V;
    int num;
    std::cout << "������ �������� ������� (0 ��� 1), �������� ����������� ���� ����� -1:\n";
    while (true) {
        std::cin >> num;
        if (num == -1)
            break;
        V.push_back(num);
    }

    // ����� ���������� ������ �� K ����
    auto it = std::search_n(V.rbegin(), V.rend(), K, 0);

    if (it != V.rend()) {
        // ������������� ������� ��������� ��� ��������� ������� K ����
        auto erase_it = it.base();
        V.erase(erase_it - K, erase_it);
    }

    // ���� ����������
    std::cout << "���������:\n";
    for (int num : V) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


}