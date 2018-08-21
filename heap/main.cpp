#include <vector>
#include <iostream>
#include <exception>

struct items{
    int pos;
    int value;
    items() {
        this->pos = 0;
        this->value = 0;
    }
    items(int posit, int val) {
        this->pos = posit;
        this->value = val;
    }
};

class Heap{

private:
    std::vector<items> array;
    int size = 0;
    int real_size;

public:
    Heap(int real_size) {
        this->real_size = real_size;
        array.resize(real_size);
    }
    void Heapify(std::size_t i) {
        std::size_t l = 2 * i + 1;
        std::size_t r = 2 * i + 2;
        std::size_t smallest = i;
        if (l < size && array[l].value < array[smallest].value)
            smallest = l;
        if (r < size && array[r].value < array[smallest].value)
            smallest = r;
        if (smallest != i) {
            std::swap(array[i], array[smallest]);
            Heapify(smallest);
        }
    }
    void AddItemp(items element) {
        array[size] = element;
        ++size;
        std::size_t i = size - 1;
        while (i > 0 && array[(i - 1)/2].value >= array[i].value) {
            std::swap(array[i] , array[(i - 1)/2]);
            --i /= 2;
        }

    }
    items MinItem () {
        items result = array[0];
        array[0] = array[--size];
        Heapify(0);
        return result;
    }
};

int main() {
    int count_sequence, size_sequence;
    std::cin >> count_sequence;
    std::cin >> size_sequence;
    Heap heap(count_sequence);
    std::vector<std::vector<int>> sequences(count_sequence,
                          std::vector<int>(size_sequence));
    for(size_t i = 0; i < count_sequence; ++i) {
        for(size_t j = 0; j < size_sequence; ++j) {
            std::cin >> sequences[i][j];
        }
        items temp(i, sequences[i][0]);
        heap.AddItemp(temp);
    }
    std::vector<int> positions(count_sequence, 0);
    std::vector<int> result(size_sequence *
                                    count_sequence);
    for(size_t i = 0; i < count_sequence *
            size_sequence; ++i) {
        items temp = heap.MinItem();
        result[i] = temp.value;
        if (positions[temp.pos] != size_sequence - 1) {
            ++positions[temp.pos];
            items te(temp.pos,
                sequences[temp.pos][positions[temp.pos]]);
            heap.AddItemp(te);
        }
    }
    for(size_t i = 0; i < count_sequence *
                          size_sequence; ++i) {
        std::cout << result[i] << " ";
    }
}
