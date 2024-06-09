#include "python_cplusplus_array.h"
#include <iostream>

using namespace std;

int main()
{
    python_cplusplus_array<int> my_array(5); // array of size 5

    for (int i = 0; i < my_array.get_size(); i++)
    {
        my_array[i] = i + 1;
    }

    my_array.to_string();                   // expect [1, 2, 3, 4, 5]
    cout << "-1: " << my_array[-1] << endl; // this should be the last element which would be: 5
    cout << "-5: " << my_array[-5] << endl; // this should be the first element which would be: 1
    // cout << "-6: " << my_array[-6] << endl; // returns NULL it should crash if you use it

    python_cplusplus_array<int> *my_sub_array = my_array["1:3"];
    my_sub_array->to_string(); // expect [2, 3]

    python_cplusplus_array<int> *my_sub_backwards_array = my_array["-3:-5"];
    my_sub_backwards_array->to_string(); // expect [3, 2]

    // client is responsible for deleting sub arrays
    delete my_sub_array;
    delete my_sub_backwards_array;

    return 0;
}