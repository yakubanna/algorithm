#include <iostream>
#include <vector>
#include <iterator>

std::vector<int> parent;

void make_set (int v) {
    parent[v] = v;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n_count, m_count;
    std::cin >> n_count >> m_count;
    parent.resize(n_count);
    for (size_t i = 0; i < n_count; ++i) {
        parent[i] = i;
    }

    std::string str;
    std::getline(std::cin, str);
    for (size_t in = 0; in < m_count; ++in) {
        std::getline(std::cin, str);
        auto iter = str.find(" ");
        if (iter == std::string::npos) {
            std::cout << find_set(std::atoi(str.c_str()) - 1) + 1 << "\n";
        } else {
            int first = std::atoi(str.substr(0, ' ').c_str()) - 1;
            int second = std::atoi(str.substr(iter + 1, str.size()).c_str()) - 1;
            if (parent[second] == second && find_set(first) != second) {
                union_sets(first, second);
                std::cout << 1 << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        }
    }
    return 0;
}