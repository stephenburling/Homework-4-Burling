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

static int fibtailHelper(int a, int b, int n) {

    if (n > 0) {
        return fibtailHelper(b, (a+b), (n-1));
    }else {
        return a;
    }
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
    list_t reversed_list = list_make();

    reversed_list = reverseHelper(input_list, reversed_list);

    return reversed_list;
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
    return fibtailHelper(0, 1, n);
}

int fib(int n) {

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

static list_t filterEvenHelper(list_t input_list, list_t saved_list) {

    if ((list_first(input_list) % 2) != 0) {
        saved_list = list_make(list_first(input_list), saved_list);
    }
    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return filterEvenHelper(list_rest(input_list), saved_list);
    }
}

list_t filter_even(list_t input_list) {

    if (list_isEmpty(input_list)) {
        return input_list;
    }

    cout << "filter_even() input: " << endl;

    list_print(input_list);

    list_t even_filter_list = list_make();

    even_filter_list = filterEvenHelper(reverse(input_list), even_filter_list);

    return even_filter_list;
}

static list_t filterOddHelper(list_t input_list, list_t saved_list) {

    if ((list_first(input_list) % 2) == 0) {
        saved_list = list_make(list_first(input_list), saved_list);
    }
    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return filterOddHelper(list_rest(input_list), saved_list);
    }
}

list_t filter_odd(list_t input_list) {

    cout << "filter_odd() input: " << endl;

    if (list_isEmpty(input_list)) {
        return input_list;
    }

    list_print(input_list);

    list_t odd_filter_list = list_make();

    odd_filter_list = filterOddHelper(reverse(input_list), odd_filter_list);

    return odd_filter_list;
}
