#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <ctime>



enum whi_heap {k_stat, other};


struct items {
    int pos_array;
    int pos_heap;
    int value;
    whi_heap which;
    items() {
        this->pos_array = 0;
        this->pos_heap = 0;
        this->value = 0;
        this->which = other;
    }
    items(int posit_arr, int pos_heap,
          int val, whi_heap whi) {
        this->pos_array = posit_arr;
        this->pos_heap = pos_heap;
        this->value = val;
        this->which = whi;
    }
};


std::vector<items> numbers;

class Heap_min{

private:
    std::vector<items> array;
    int size = 0;
    int real_size;

public:
    explicit Heap_min(int real_size) {
        this->real_size = real_size;
        array.resize(real_size);
    }
    int Heapify(std::size_t ind) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int smallest = ind;
        if (left < size && array[left].value < array[smallest].value)
            smallest = left;
        if (right < size && array[right].value < array[smallest].value)
            smallest = right;
        if (smallest != ind) {
            std::swap(array[ind], array[smallest]);
            array[ind].pos_heap = ind;
            array[smallest].pos_heap = smallest;
            numbers[array[ind].pos_array].pos_heap = ind;
            numbers[array[smallest].pos_array].pos_heap = smallest;
            return Heapify(smallest);
        }
        return ind;
    }
    int AddItemp(items element) {
        array[size] = element;
        array[size].pos_heap = size;
        numbers[array[size].pos_array].pos_heap = size;
        ++size;
        int res = size - 1;
        int ind = size - 1;
        while (ind > 0 && array[(ind - 1)/2].value >= array[ind].value) {
            std::swap(array[ind] , array[(ind - 1)/2]);
            array[ind].pos_heap = ind;
            res = (ind - 1) / 2;
            array[(ind-1)/2].pos_heap = (ind-1)/2;
            numbers[array[(ind-1)/2].pos_array].pos_heap = (ind-1)/2;
            numbers[array[ind].pos_array].pos_heap = ind;
            --ind /= 2;
        }
        return res;
    }
    items MinItem () {
        items result = array[0];
        array[0] = array[--size];
        array[0].pos_heap = 0;
        array[size].pos_heap = size;
        numbers[array[0].pos_array].pos_heap = 0;
        Heapify(0);
        return result;
    }
    items DelItem (int index) {
        items it = array[index];
        array[index] = array[--size];
        array[index].pos_heap = index;
        array[size].pos_heap = size;
        numbers[array[index].pos_array].pos_heap = index;
        int ind = index;
        while (ind > 0 && array[(ind - 1)/2].value > array[ind].value) {
                std::swap(array[ind] , array[(ind - 1)/2]);
                array[ind].pos_heap = ind;
                array[(ind-1)/2].pos_heap = (ind-1)/2;
                numbers[array[(ind-1)/2].pos_array].pos_heap = (ind-1)/2;
                numbers[array[ind].pos_array].pos_heap = ind;
                --ind /= 2;
            }
        Heapify(index);


        return it;
    }
    items MinItemShow () {
        return array[0];
    }
    int he_size(){
        return size;
    }
};

class Heap_max{

private:
    std::vector<items> array;
    int size = 0;
    int real_size;

public:
    explicit Heap_max(int real_size) {
        this->real_size = real_size;
        array.resize(real_size);
    }
    void Heapify(std::size_t ind) {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;
        int smallest = ind;
        if (left < size && array[left].value > array[smallest].value)
            smallest = left;
        if (right < size && array[right].value > array[smallest].value)
            smallest = right;
        if (smallest != ind) {
            std::swap(array[ind], array[smallest]);
            array[ind].pos_heap = ind;
            array[smallest].pos_heap = smallest;
            numbers[array[smallest].pos_array].pos_heap = smallest;
            numbers[array[ind].pos_array].pos_heap = ind;
            Heapify(smallest);
        }
    }
    void AddItemp(items element) {
        array[size] = element;
        array[size].pos_heap = size;
        numbers[array[size].pos_array].pos_heap = size;
        ++size;
        int ind = size - 1;
        while (ind > 0 && array[(ind - 1)/2].value <= array[ind].value) {
            std::swap(array[ind] , array[(ind - 1)/2]);
            array[ind].pos_heap = ind;
            array[(ind-1)/2].pos_heap = (ind-1)/2;
            numbers[array[(ind-1)/2].pos_array].pos_heap = (ind-1)/2;
            numbers[array[ind].pos_array].pos_heap = ind;
            --ind /= 2;
        }
    }
    items MaxItem () {
        items result = array[0];
        array[0] = array[--size];
        array[0].pos_heap = 0;
        array[size].pos_heap = size;
        numbers[array[0].pos_array].pos_heap = 0;
        Heapify(0);
        return result;
    }
    items MaxItemShow () {
        items it = array[0];
        return it;
    }
    items DelItem (int index) {
        items it = array[index];
        array[index] = array[--size];
        array[index].pos_heap = index;
        array[size].pos_heap = size;
        numbers[array[index].pos_array].pos_heap = index;
        int ind = index;
        while (ind > 0 && array[(ind - 1)/2].value <= array[ind].value) {
                std::swap(array[ind] , array[(ind - 1)/2]);
                array[ind].pos_heap = ind;
                array[(ind-1)/2].pos_heap = (ind-1)/2;
                numbers[array[(ind-1)/2].pos_array].pos_heap = (ind-1)/2;
                numbers[array[ind].pos_array].pos_heap = ind;
                --ind /= 2;
            }
        Heapify(index);

        return it;
    }
    int he_size(){
        return size;
    }
};


class Number {
public:
    int value;
    int pos = -1;
    bool is_min_heap = true;

    explicit Number(int value): value(value) {}

    bool operator<(const Number& rhs) {
        return this->value < rhs.value;
    }
};

bool min_cmp(std::vector<Number>::iterator first, std::vector<Number>::iterator second) {
    return *second < *first;
}

bool max_cmp(std::vector<Number>::iterator first, std::vector<Number>::iterator second) {
    return *first < *second;
}

template<class T>
class MinHeap {
private:
    std::vector<T> storage;

public:
    void print() {
        for (int i = 0; i < storage.size(); ++i) {
            std::cout << storage[i]->value << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return storage.empty();
    }

    int size() const {
        return storage.size();
    }

    T getTop() {
        return storage[0];
    }

    void addToHeap(T p) {
        p->is_min_heap = true;
        storage.push_back(p);
        storage.back()->pos = storage.size() - 1;
        siftUp(storage.size() - 1);
    }

    void siftUp(int index) {
        int pos = index;
        int parent = (pos - 1) / 2;
        while ((pos > 0) && min_cmp(storage[pos], storage[parent])) {
            storage[pos]->pos = parent;
            storage[parent]->pos = pos;
            T temp = storage[pos];
            storage[pos] = storage[parent];
            storage[parent] = temp;
            pos = parent;
            parent = (pos - 1) / 2;
        }
    }

    void siftDown(int index) {
        int pos = index;
        bool moved = true;
        while (moved) {
            moved = false;
            int childf = (pos + 1) * 2;
            int childs = (pos + 1) * 2 - 1;
            if (childs >= storage.size()) {
                continue;
            }
            if (childf >= storage.size()) {
                if (min_cmp(storage[childs], storage[pos])) {
                    storage[pos]->pos = childs;
                    storage[childs]->pos = pos;
                    T temp = storage[childs];
                    storage[childs] = storage[pos];
                    storage[pos] = temp;
                    pos = childs;
                    moved = true;
                }
                continue;
            }
            int to_swap = childf;
            if (min_cmp(storage[childs], storage[childf])) {
                to_swap = childs;
            }
            if (min_cmp(storage[to_swap], storage[pos])) {
                storage[pos]->pos = to_swap;
                storage[to_swap]->pos = pos;
                T temp = storage[pos];
                storage[pos] = storage[to_swap];
                storage[to_swap] = temp;
                pos = to_swap;
                moved = true;
            }
        }
    }

    void removeFromHeap(int index) {
        storage[index] = storage[storage.size() - 1];
        storage[index]->pos = index;
        storage.pop_back();
        siftDown(index);
        siftUp(index);
    }

    void removeFromHeap() {
        removeFromHeap(0);
    }
};

template<class T>
class MaxHeap {
private:
    std::vector<T> storage;

public:
    void print() {
        for (int i = 0; i < storage.size(); ++i) {
            std::cout << storage[i]->value << " ";
        }
        std::cout << std::endl;
    }

    bool isEmpty() const {
        return storage.empty();
    }

    int size() const {
        return storage.size();
    }

    T getTop() {
        return storage[0];
    }

    void addToHeap(T element) {
        element->is_min_heap = false;
        storage.push_back(element);
        storage.back()->pos = storage.size() - 1;
        siftUp(storage.size() - 1);
    }

    void siftUp(int index) {
        int pos = index;
        int parent = (pos - 1) / 2;
        while ((pos > 0) && max_cmp(storage[pos], storage[parent])) {
            storage[pos]->pos = parent;
            storage[parent]->pos = pos;
            T temp = storage[pos];
            storage[pos] = storage[parent];
            storage[parent] = temp;
            pos = parent;
            parent = (pos - 1) / 2;
        }
    }

    void siftDown(int index) {
        int pos = index;
        bool moved = true;
        while (moved) {
            moved = false;
            int childf = (pos + 1) * 2;
            int childs = (pos + 1) * 2 - 1;
            if (childs >= storage.size()) {
                continue;
            }
            if (childf >= storage.size()) {
                if (max_cmp(storage[childs], storage[pos])) {
                    storage[pos]->pos = childs;
                    storage[childs]->pos = pos;
                    T temp = storage[childs];
                    storage[childs] = storage[pos];
                    storage[pos] = temp;
                    pos = childs;
                    moved = true;
                }
                continue;
            }
            int to_swap = childf;
            if (max_cmp(storage[childs], storage[childf])) {
                to_swap = childs;
            }
            if (max_cmp(storage[to_swap], storage[pos])) {
                storage[pos]->pos = to_swap;
                storage[to_swap]->pos = pos;
                T temp = storage[pos];
                storage[pos] = storage[to_swap];
                storage[to_swap] = temp;
                pos = to_swap;
                moved = true;
            }
        }
    }

    void removeFromHeap(int index) {
        storage[index] = storage[storage.size() - 1];
        storage[index]->pos = index;
        storage.pop_back();
        siftDown(index);
        siftUp(index);
    }

    void removeFromHeap() {
        removeFromHeap(0);
    }
};

class Memory {
public:
    explicit Memory(std::vector<int>& values, int kth): kth(kth) {
        for (int i = 0; i < values.size(); ++i) {
            Number temp(values[i]);
            memory.push_back(temp);
        }
        left = memory.begin();
        right = memory.begin();
        ++right;
        min_elems.addToHeap(left);
    }

    int MoveRight() {
        if (min_elems.size() < kth) {
            min_elems.addToHeap(right);
        } else {
            std::vector<Number>::iterator elem = min_elems.getTop();
            if (elem->value > right->value) {
                min_elems.removeFromHeap();
                min_elems.addToHeap(right);
                max_elems.addToHeap(elem);
            } else {
                max_elems.addToHeap(right);
            }
        }
        ++right;
        return getStatistics();
    }

    int MoveLeft() {
        if (!left->is_min_heap) {
            max_elems.removeFromHeap(left->pos);
        } else {
            if (max_elems.isEmpty()) {
                min_elems.removeFromHeap(left->pos);
            } else {
                min_elems.removeFromHeap(left->pos);
                std::vector<Number>::iterator elem = max_elems.getTop();
                max_elems.removeFromHeap();
                min_elems.addToHeap(elem);
            }
        }
        ++left;
        return getStatistics();
    }

    int getStatistics() {
        if (min_elems.size() < kth) {
            return -1;
        } else {
            return min_elems.getTop()->value;
        }
    }

    void printAll() {
        std::cout << "min ";
        min_elems.print();
        std::cout << "max ";
        max_elems.print();
        std::cout << "l " << left->value << " r " << right->value << std::endl;
    }

private:
    int kth;
    std::vector<Number> memory;
    std::vector<Number>::iterator left, right;
    MinHeap<std::vector<Number>::iterator> min_elems;
    MaxHeap<std::vector<Number>::iterator> max_elems;
};
int count_numbers, count_k_stat, count_shift;

std::vector<char> letters;
int number, nofstr, kth;
std::vector<int>result_my;
std::vector<int>result_your;


bool generation() {

    std::vector<int> numbers_nik;

    count_numbers = rand()%1000;
    count_k_stat = rand()%count_numbers;
    count_shift = count_numbers - rand()%count_numbers;
    numbers.resize(count_numbers);
    letters.resize(count_shift);

    Heap_max hep_k_stat(count_k_stat);
    Heap_min hep_other(100000);

    for (size_t ind = 0; ind < count_numbers; ++ind) {
        int number;
        number = rand()%100;
        numbers_nik.push_back(number);
        numbers[ind] = items(ind, 0, number, other);
    }
    Memory memory(numbers_nik, count_k_stat);
    for (size_t ind = 0; ind < count_shift; ++ind) {
        char cha;
        int t = ind % 3 - 1;
        if (t == 0) {
            cha = 'L';
            result_your.push_back(memory.MoveLeft());
        }
        else {
            cha = 'R';
            result_your.push_back(memory.MoveRight());
        }
        letters[ind] = cha;
    }

    numbers[0].which = k_stat;
    items it(numbers[0]);
    hep_k_stat.AddItemp(it);
    int pos_left = 0, pos_right = 0;
    for (size_t ind = 0; ind < count_shift; ++ind) {
        items my = hep_k_stat.MaxItemShow();
        switch (letters[ind]) {
            case 'R':
                ++pos_right;
                if (numbers[pos_right].value < my.value ||
                    hep_k_stat.he_size() < count_k_stat) {
                    if (hep_k_stat.he_size() >= count_k_stat) {
                        items iteer = hep_k_stat.MaxItem();
                        numbers[iteer.pos_array].which = other;
                        iteer.which = other;
                        hep_other.AddItemp(iteer);
                    }
                    numbers[pos_right].which = k_stat;
                    items ite(numbers[pos_right]);
                    ite.which = k_stat;
                    hep_k_stat.AddItemp(ite);
                } else {
                    items ite(numbers[pos_right]);
                    hep_other.AddItemp(ite);
                }
                break;
            case 'L':
                if (numbers[pos_left].which == k_stat) {
                    hep_k_stat.DelItem(numbers[pos_left].pos_heap);
                    if (hep_other.he_size() > 0) {
                        items iter = hep_other.MinItem();
                        iter.which = k_stat;
                        numbers[iter.pos_array].which = k_stat;
                        hep_k_stat.AddItemp(iter);
                    }
                } else {
                    hep_other.DelItem(numbers[pos_left].pos_heap);
                }
                ++pos_left;
                break;
        }
        if ((pos_right - pos_left + 1) < count_k_stat) {
            result_my.push_back(-1);
            if(result_your[ind] != result_my[ind]){
                std::cout << count_k_stat << "\n";
                for (size_t i =0; i < numbers.size(); ++i) {
                    std::cout << numbers[i].value << " ";
                }
                std::cout << "\n";
                for (size_t i =0; i < letters.size(); ++i) {
                    std::cout << letters[i] << " ";
                }
                for (size_t i = 0; i < result_my.size(); ++i){
                    std::cout << result_my[i] << " " <<result_your[i] << "\n";
                }
                break;
            }
        } else {
            result_my.push_back(hep_k_stat.MaxItemShow().value);
            if(result_your[ind] != result_my[ind]){
                std::cout << count_k_stat << "\n";
                for (size_t i =0; i < numbers.size(); ++i) {
                    std::cout << numbers[i].value << " ";
                }
                std::cout << "\n";
                for (size_t i =0; i < letters.size(); ++i) {
                    std::cout << letters[i] << " ";
                }
                for (size_t i = 0; i < result_my.size(); ++i){
                    std::cout << result_my[i] << " " <<result_your[i] << "\n";
                }
                break;
            }
        }
    }
    if(result_my == result_your) {
        return true;
    }
    else {
        return false;
    }

}

int main() {
    bool t = generation();
    while(t) {
        std::srand(std::time(NULL));
        result_your.resize(0);
        result_my.resize(0);
        t = generation();
    }
    std::cout << count_k_stat << "\n";
    for (size_t i =0; i < numbers.size(); ++i) {
        std::cout << numbers[i].value << " ";
    }
    std::cout << "\n";
    for (size_t i =0; i < letters.size(); ++i) {
        std::cout << letters[i] << " ";
    }
    for (size_t i = 0; i < result_my.size(); ++i){
        std::cout << result_my[i] << " " <<result_your[i] << "\n";
    }
    for (size_t ind = 0; ind < count_numbers; ++ind) {
        numbers[ind].pos_heap = 0;
         numbers[ind].which = other;
        numbers[ind].pos_array = ind;
    }
    Heap_max hep_k_stat(count_k_stat);
    Heap_min hep_other(100000);
    numbers[0].which = k_stat;
    items it(numbers[0]);
    hep_k_stat.AddItemp(it);
    int pos_left = 0, pos_right = 0;
    for (size_t ind = 0; ind < count_shift; ++ind) {
        items my = hep_k_stat.MaxItemShow();
        switch (letters[ind]) {
            case 'R':
                ++pos_right;
                if (numbers[pos_right].value < my.value ||
                    hep_k_stat.he_size() < count_k_stat) {
                    if (hep_k_stat.he_size() >= count_k_stat) {
                        items iteer = hep_k_stat.MaxItem();
                        numbers[iteer.pos_array].which = other;
                        iteer.which = other;
                        hep_other.AddItemp(iteer);
                    }
                    numbers[pos_right].which = k_stat;
                    items ite(numbers[pos_right]);
                    ite.which = k_stat;
                    hep_k_stat.AddItemp(ite);
                } else {
                    items ite(numbers[pos_right]);
                    hep_other.AddItemp(ite);
                }
                break;
            case 'L':
                if (numbers[pos_left].which == k_stat) {
                    hep_k_stat.DelItem(numbers[pos_left].pos_heap);
                    if (hep_other.he_size() > 0) {
                        items iter = hep_other.MinItem();
                        iter.which = k_stat;
                        numbers[iter.pos_array].which = k_stat;
                        hep_k_stat.AddItemp(iter);
                    }
                } else {
                    hep_other.DelItem(numbers[pos_left].pos_heap);
                }
                ++pos_left;
                break;
        }
        if ((pos_right - pos_left + 1) < count_k_stat) {
            result_my.push_back(-1);
        } else {
            result_my.push_back(hep_k_stat.MaxItemShow().value);
        }
    }
}

