#include <iostream>
#include "recursive.h"
#include "hw4.h"

using std::cout;
using std::endl;

static int list_size(list_t input_list, int size) {

    size = size + 1;

    if (list_isEmpty(list_rest(input_list))) {
        return size;
    }
    else {
        return list_size(list_rest(input_list), size);
    }

}

static list_t splitList(list_t input_list, int split_point) {

    if (split_point > 0) {
        return splitList(list_rest(input_list), (split_point -1));
    }
    else {
        return input_list;
    }
}

static list_t reverseHelper(list_t input_list, list_t saved_list) {

    saved_list = list_make(list_first(input_list), saved_list);
    
    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return reverseHelper(list_rest(input_list), saved_list);
    }
}

static list_t rotateHelper(list_t input_list, list_t saved_list){

    saved_list = list_make(list_first(input_list), saved_list);

    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return rotateHelper(list_rest(input_list), saved_list);
    }

}

static list_t insertlistHelper(list_t input_list, list_t saved_list, unsigned int n) {

    saved_list = list_make(list_first(input_list), saved_list);

    if ((n-1) > 0) {

        return insertlistHelper(list_rest(input_list), saved_list, (n - 1));

    }
    else {
        return saved_list;
    }

}

static int productHelper(int base_a, int base_b) {

    return (base_a * base_b);

}

static int sumHelper(int sum_a, int sum_b) {
    return (sum_a + sum_b);
}

static int fibtailHelper(int n, int a, int b) {

    if (n == 0) {
        return b;
    }
    if (n == 1) {
        return a;
    }
    return fibtailHelper((n - 1), b, (a + b));
}

int accumulate(list_t l, int (*fn)(int, int), int base)
{
    if (list_isEmpty(l)) {
        return base;
    }
    else {
        return accumulate(list_rest(l), fn, fn(base, list_first(l)));
    }
}

list_t reverse(list_t input_list) {

    if (list_isEmpty(input_list)) {

        return input_list;

    }
    list_t temp_list = list_make();

    temp_list = reverseHelper(input_list, temp_list);

    return temp_list;
}

list_t rotate(list_t input_list, unsigned int n) {
    if (n > 0) {

    list_t temp_list = list_make();
    
    temp_list = list_make(list_first(input_list), temp_list);

    temp_list = rotateHelper(reverse(list_rest(input_list)), temp_list);

    return rotate(temp_list, (n - 1));

    }
    else {
        return input_list;
    }
}

list_t chop(list_t input_list, unsigned int n){
  if (n > 0) {
    
    if (!list_isEmpty(input_list)) {

    input_list = reverse(input_list);

    input_list = list_rest(input_list);

    input_list = reverse(input_list);

    return chop(input_list, (n - 1));
    }
    else {
    return input_list;
    }
  }
  else {
    return input_list;
  }
}

list_t append(list_t first_list, list_t second_list) {

    if (list_isEmpty(first_list)) {

        return second_list;

    }
    else if (list_isEmpty(second_list)) {

        return first_list;

    }

    cout << "\nAccessing append(): " << endl;

    list_t return_list = list_make();

    return_list = insertlistHelper(reverse(second_list), return_list, list_size(second_list,0));

    return_list = insertlistHelper(reverse(first_list), return_list, list_size(first_list, 0));

    return return_list;

}

list_t insert_list(list_t first_list, list_t second_list, unsigned int n) {
    
    if (list_isEmpty(first_list)) {

        return second_list;

    }
    else if (list_isEmpty(second_list)) {

        return first_list;

    }
    list_t final_list = list_make();
    int size_first = list_size(first_list, 0);

    int size_second = list_size(second_list, 0);
    if (n >= size_first) {

        final_list = append(first_list, second_list);

        return final_list;
    }
    else if (n <= 0) {

        final_list = append(second_list, first_list);

        return final_list;
    }
    
    size_first = size_first - n;

    first_list = reverse(first_list);
    second_list = reverse(second_list);

    
    list_t new_list = splitList(first_list, size_first);

    int new_list_size = list_size(new_list, 0);

    final_list = insertlistHelper(first_list, final_list, size_first);

    final_list = insertlistHelper(second_list, final_list, size_second);

    final_list = insertlistHelper(new_list, final_list, new_list_size);


    return final_list;
}

int product(list_t input_list) {

    return accumulate(input_list, &productHelper, 1);

}

int sum(list_t input_list) {
    return accumulate(input_list, &sumHelper, 0);
}

int fib_tail(int n) {
    int a = 0;
    int b = 1;
    return fibtailHelper(n, a, b);
}

int fib(int n) {

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);

}
