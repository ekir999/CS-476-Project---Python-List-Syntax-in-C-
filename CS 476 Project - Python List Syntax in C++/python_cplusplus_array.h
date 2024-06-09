#include <iostream>

template <typename T>
class python_cplusplus_array
{
private:
    int size;
    T *my_array;

public:
    python_cplusplus_array<T>(int s)
    {
        this->my_array = new T[s];
        this->size = s;
    }

    ~python_cplusplus_array<T>()
    {
        delete[] my_array;
    }

    int get_size()
    {
        return size;
    }

    void to_string()
    {
        std::cout << "[";
        for (int i = 0; i < this->size - 1; i++)
        {
            std::cout << this->my_array[i] << ", ";
        }
        std::cout << this->my_array[this->size - 1];
        std::cout << "]" << std::endl;
    }

    T &operator[](int i)
    {
        if (i < 0)
        {
            // to prevent underflow
            if (i < (-1 * this->size)) {
                T *ptr = NULL;
                return (*ptr);
            } else {
                return my_array[size + i];
            }
        }
        else
        {
            // to prevent overflow
            if (i > this->size) {
                T *ptr = NULL;
                return (*ptr);
            } else {
                return my_array[i];
            }
            
        }
    }

    python_cplusplus_array<T> *operator[](std::string s)
    {
        int split_position = s.find(":");
        int start = stoi(s.substr(0, split_position));
        int end = stoi(s.substr(split_position + 1));

        python_cplusplus_array<T> *sub_cpp_array = NULL;

        if (end > start && start >= 0 && end > 0)
        {
            if (start > this->size || end > this->size) {
                return sub_cpp_array;
            }
            sub_cpp_array = new python_cplusplus_array<T>(end - start);

            for (int i = 0; i < sub_cpp_array->size; i++)
            {
                sub_cpp_array->my_array[i] = this->my_array[start];
                start++;
            }
        }
        else if (end < start && start < 0 && end < 0)
        {
            if (start < (this->size * -1) || end < (this->size * -1)) {
                return sub_cpp_array;
            }
            sub_cpp_array = new python_cplusplus_array<T>(start - end);

            start = this->size + start;
            for (int i = 0; i < sub_cpp_array->size; i++)
            {
                sub_cpp_array->my_array[i] = this->my_array[start];
                start--;
            }
        }

        return sub_cpp_array;
    }
};