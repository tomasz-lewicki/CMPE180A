#include <cstdlib>

class IntArray
{
public:
    IntArray(size_t max_size);
    ~IntArray();
    void print();
    int insertAt(size_t idx, int value);
    int deleteAt(size_t idx);

private:
    int* arr;
    size_t curr_size;
    size_t max_size;

};