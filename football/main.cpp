#include <iostream>
#include <vector>


enum Type {index, efficient};

struct Player {
    int index;
    int efficiency;
};

bool CompareByIndex(const Player& a, const Player& b) {
    return a.index < b.index;
}

bool CompareByEfficiency(const Player& a, const Player& b) {
    return a.efficiency < b.efficiency;
}


template<class T_Iterator, class Comp>
void Sort(T_Iterator first, T_Iterator last, Comp comp) {
    if (std::distance(first, last) <= 1) {
        return;
    }
    auto middle = std::next(first, std::distance(first, last) / 2);
    auto first_left_array = first;
    auto last_left_array = middle;
    auto first_right_array = middle;
    auto last_right_array = last;
    Sort(first_left_array, last_left_array, comp);
    Sort(first_right_array, last_right_array, comp);
    std::vector<Player> temp(last - first);
    for (size_t iter = 0; iter < temp.size(); ++iter) {
        if (first_left_array == last_left_array) {
            temp[iter] = *first_right_array;
            ++first_right_array;
        } else if (first_right_array == last_right_array) {
            temp[iter] = *first_left_array;
            ++first_left_array;
        } else if (!comp(*first_left_array, *first_right_array)) {
            temp[iter] = *first_right_array;
            ++first_right_array;
        } else {
            temp[iter] = *first_left_array;
            ++first_left_array;
        }
    }
    for (auto i = first; i < last; ++i) {
        *i = temp[i - first];
    }
    return;
}

bool IsRight(const std::vector<Player>& players,
              size_t start, size_t finish) {
    if (start + 2 == finish) {
        return true;
    }
    return static_cast<int64_t>(players[start].efficiency) +
             players[start + 1].efficiency >=
             players[finish - 1].efficiency;
}

std::vector<int> buildMostEffectiveTeam(std::vector<int> start_players) {
    if (start_players.size() == 1) {
        return {1, 1};
    }
    std::vector<Player> players(start_players.size());
    for (size_t i = 0; i < start_players.size(); ++i) {
        players[i].efficiency = start_players[i];
        players[i].index = i;
    }
    Sort(players.begin(), players.end(), CompareByEfficiency);
    size_t first_max_efficient = 0, last_max_efficient = 2;
    size_t first = 0, last = 2;
    int64_t current_sum = players[0].efficiency + players[1].efficiency;
    int64_t max_sum = players[0].efficiency + players[1].efficiency;
    while (last != players.size()) {
        ++last;
        current_sum += players[last - 1].efficiency;
        while (!IsRight(players, first, last)) {
            current_sum -= players[first].efficiency;
            ++first;
        }
        if (current_sum > max_sum) {
            first_max_efficient = first;
            last_max_efficient = last;
            max_sum = current_sum;
        }
    }
    Sort(players.begin() + first_max_efficient,
         players.begin() + last_max_efficient, CompareByIndex);
    start_players.resize(last_max_efficient - first_max_efficient);
    for (size_t i = 0; i < start_players.size(); ++i) {
        start_players[i] = players[first_max_efficient + i].efficiency;
    }
    return start_players;
}

int64_t Find_max_efficient(std::vector<int> players) {
    int64_t max_efficient = 0;
    for (size_t i = 0; i < players.size(); ++i) {
        max_efficient += players[i];
    }
    return max_efficient;
}

std::vector<int> Enter() {
    int count;
    std::vector<int> players;
    std::cin >> count;
    players.resize(count);
    for (size_t i = 0; i < count; ++i) {
        std::cin >> players[i];
    }
    return players;
}

void Print(const std::vector<int>& result, int64_t  sum) {
    std::cout << sum << "\n";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
}

int main() {
    std::vector<int> players = Enter();
    std::vector<int> result;
    result = buildMostEffectiveTeam(players);
    int64_t  sum = Find_max_efficient(result);
    Print(result, sum);
    return 0;
}
