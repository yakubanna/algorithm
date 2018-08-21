#include <cstdio>
#include <vector>
#include <iostream>
#include <random>

using std::vector;

const int64_t PrimeNum = 2147483647;
std::random_device rd;
std::mt19937 gen(rd());

void createCoefficients(int64_t *a, int64_t *b) {
    std::uniform_int_distribution<> dist(1, PrimeNum);
    *a = dist(gen);
    *b = dist(gen);
}

int64_t hashFunction(int64_t a, int64_t b, int64_t x) {
    return (((a * x + b) % PrimeNum) +
            PrimeNum) % PrimeNum;
}

class MainHashTable {
public:
    void prepareSecondaryHashTables() {
        for (auto &&ind : second_hash_tables_) {
            ind.prepare();
        }
    }

    void clean() {
        for (auto &&sht : second_hash_tables_) {
            sht.clean();
        }
    }

    int64_t allocateMemory() const {
        int64_t result = 0;
        for (auto &&in : second_hash_tables_) {
            result += in.size_elem() * in.size_elem();
        }
        return result;
    }

    void prepareMainHashTable(const vector<int> &numbers) {
        second_hash_tables_.resize(numbers.size());
        do {
            createCoefficients(&a_coefficient, &b_coefficient);
            clean();
            for (auto &&it : numbers) {
                second_hash_tables_[hashFunction(a_coefficient,
                           b_coefficient, it) % numbers.size()].push(it);
            }
        } while (allocateMemory() >
                 2 * numbers.size() );
    }

    void makeHashTable() {
        for (auto &&ind : second_hash_tables_) {
            bool success = false;
            while (!success) {
                success = ind.create_coeff();
            }
        }
    }

    bool Contain(int number, int size) const {
        int number_cur = hashFunction(a_coefficient,
                                      b_coefficient, number) % size;
        if (second_hash_tables_[number_cur].size_elem() == 0) {
            return false;
        }
        return second_hash_tables_[number_cur].ContainsSecond(number);
    }

private:
    class SecondHashTable {
    public:
        SecondHashTable(): a_coefficient(0), b_coefficient(0) {}
        bool ContainsSecond(int number) const {
            int second_hash = hashFunction(a_coefficient,
                        b_coefficient, number) % numbers_to_store.size();
            return (!this->numbers_empty[second_hash] &&
                    this->numbers[second_hash] == number);
        }
        void prepare() {
            numbers.resize(numbers_to_store.size() *
                           numbers_to_store.size());
            numbers_empty.resize(numbers_to_store.size() *
                                 numbers_to_store.size(), true);
            createCoefficients(&a_coefficient, &b_coefficient);
        }
        bool create_coeff() {
            createCoefficients(&a_coefficient, &b_coefficient);
            numbers_empty.assign(numbers_empty.size(), true);
            bool success = true;
            for (auto &&number_iter : numbers_to_store) {
                int64_t hash_ind = hashFunction(a_coefficient, b_coefficient,
                                         number_iter) % numbers_to_store.size();
                if (numbers_empty[hash_ind]) {
                    numbers[hash_ind] = number_iter;
                    numbers_empty[hash_ind] = false;
                } else if (numbers[hash_ind] != number_iter) {
                    success = false;
                    break;
                }
            }
            return success;
        }
        void clean() {
            numbers_to_store.clear();
        }
        int64_t size_elem() const {
            return numbers_to_store.size();
        }
        void push(int elem) {
            numbers_to_store.push_back(elem);
        }

    private:
        int64_t a_coefficient, b_coefficient;
        vector<int> numbers_to_store;
        vector<int> numbers;
        vector<int> numbers_empty;
    };

    int64_t a_coefficient, b_coefficient;

    vector<SecondHashTable> second_hash_tables_;
};



class FixedSet {
public:
    void Initialize(const vector<int> &numbers) {
        total_number_of_numbers_ = numbers.size();
        primary_hash_table_.prepareMainHashTable(numbers);
        primary_hash_table_.prepareSecondaryHashTables();
        primary_hash_table_.makeHashTable();
    }

    explicit FixedSet() {}

    bool Contains(int number) const {
        return primary_hash_table_.Contain(number, total_number_of_numbers_);
    }

private:
    MainHashTable primary_hash_table_;
    int total_number_of_numbers_;
};


int main() {
    int count;
    std::cin >> count;
    std::vector<int32_t> numbers(count);
    for (size_t ind = 0; ind < count; ++ind) {
        int elem;
        std::cin >> elem;
        numbers[ind] = elem;
    }
    FixedSet fix;
    fix.Initialize(numbers);
    int count_check;
    std::cin >> count_check;
    std::vector<int32_t> result(count_check);
    for (size_t ind = 0; ind < count_check; ++ind) {
        int my_elem;
        std::cin >> my_elem;
        bool cont = fix.Contains(my_elem);
        if (cont) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
