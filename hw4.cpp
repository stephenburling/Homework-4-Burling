#include <iostream>
#include "recursive.h"
#include "hw4.h"

using std::cout;
using std::endl;

/*
Pseudocode
                ------HELPERS-------
list_size:
    increments size by one
    if the next node in list is empty:
      return size
    else
      recursively call list_size with the next node and same size
splitList:
    if the int split point is greater than zero
      recursively call splitList with the next node and decremented splitPoint
    else
      return current input_list
reverseHelper:
    push the first node of input_list into saved_list
    if next node is empty in input_list
      return saved_list
    else
      recursively call reverseHelper with next node and saved_list
insertlistHelper:
    push the first node of input_list into saved_list
    if n minus one is greater than zero
      recursively call insertlistHelper with the next
    else
      return saved_list
productHelper:
    return a*b
sumHelper:
    return a+b
fibtailHelper
    if int n is greater than zero
      recursively call fibtailHelper with b, sum of a and b, and decremented n
    else
      return a
filterEvenHelper
    if the first node of the input list is even
      push the first node of input_list into saved_list
    if next node is empty in input_list
      return saved_list
    else
      recursively call filterEvenHelper with next node and saved_list
filterOddHelper
    if the first node of the input list is odd
      push the first node of input_list into saved_list
    if next node is empty in input_list
      return saved_list
    else
      recursively call filterEvenHelper with next node and saved_list
filterHelper
    if boolean of function with first node in input_list is true
      push first node of input_list into saved_list
    if next node is empty in input_list
      return saved_list
    else
      recursively call filterHelper with next node, bool function, and saved_list
*/
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

static list_t filterEvenHelper(list_t input_list, list_t saved_list) {

    if ((list_first(input_list) % 2) == 0) {
        saved_list = list_make(list_first(input_list), saved_list);
    }
    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return filterEvenHelper(list_rest(input_list), saved_list);
    }
}

static list_t filterOddHelper(list_t input_list, list_t saved_list) {

    if ((list_first(input_list) % 2) != 0) {
        saved_list = list_make(list_first(input_list), saved_list);
    }
    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return filterOddHelper(list_rest(input_list), saved_list);
    }
}

static list_t filterHelper(list_t input_list, bool(*fn)(int), list_t saved_list) {

    if (fn(list_first(input_list))) {
        saved_list = list_make(list_first(input_list), saved_list);
    }
    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return filterHelper(list_rest(input_list), fn, saved_list);
    }
}

/*
accumulate:
    if current list is empty
      return base
    else
      recursively call accumulate with the rest of l, fn, and fn(base, first node of l)
reverse
    if input_list is empty, return it back
    create empty list called reversed_list
    set reverse_list equal to returned list from reverseHelper
    return reversed_list
rotate
    if n is greater than 0
      make empty list called temp_list
      set temp_list to  the first node in input_list
      set temp_list to reverseHelper with input_list minus the first node and reversed, and temp_list
      recursively call rotate with temp_list and n-1
    else
      return input_list
chop:
    if n is greater than zero
      if the input list is not empty
        reverse the input list
        take off the first node in reversed list
        reverse new, shorter list back 
        recursively call chop with input_list and n-1
      else
        return input_list
    else
      return input_lsit
append
    if first list is empty
      return second list
    if second list is empty
      return first list
    make empty list called return_list
    set return_list to reverseHelper with reversed second list and return_list
    set return_list to reverseHelper with reversed first list and return_list
    return return_list
insert_list
    if first list is empty
      return second list
    if second list is empty
      return first list
    create empty list called final_list
    take size of first list from list_size
    take size of second list from list_size
    if the given n is greater than or equal to the size of the first list
      append the first list onto the second list
      return that list
    else if the given n is less than or equal to zero
      append the first list onto the second list
      return that list
    subtract given n from size of first list
    reverse first and second list
    create new list equal to splitLIst
    set the new list size equal to size of new list
    insert first list to a certain node into the final list
    insert entire second list final list
    insert entire split list into final list
    return final list
product
    return accumulate with input list, productHelper, and 1
sum
    return accumulate with input list, sumHelper, and 0
fib_tail
    return fibtailHelper with 0,1, and n
fib
    if n is equal to 0
      return 0
    else if n is equal to 1
      return 1
    return sum of fib(n-1) and fib(n-2)
filter_even
    if input list is empty, return it
    create empty list called even_filter_list
    set even_filter_list to filterEvenHelper with reversed input list and even_filter list
    return even_filter_list
filter_odd
    if input list is empty, return it
    create empty list called odd_filter_list
    set odd_filter_list to filterOddHelper with reversed input list and odd_filter list
    return odd_filter_list
filter
    create empty list called temp_list
    return the reversed list from filterHelper with the input list, given function, and temp_list
*/
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
    
    temp_list = reverseHelper(reverse(list_rest(input_list)), temp_list);

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

    return_list = reverseHelper(reverse(second_list), return_list);

    return_list = reverseHelper(reverse(first_list), return_list);

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

list_t filter_even(list_t input_list) {

    if (list_isEmpty(input_list)) {
        return input_list;
    }

    list_t even_filter_list = list_make();

    even_filter_list = filterEvenHelper(reverse(input_list), even_filter_list);

    return even_filter_list;
}

list_t filter_odd(list_t input_list) {

    if (list_isEmpty(input_list)) {
        return input_list;
    }

    list_t odd_filter_list = list_make();

    odd_filter_list = filterOddHelper(reverse(input_list), odd_filter_list);

    return odd_filter_list;
}

list_t filter(list_t input_list, bool (*fn)(int)) {

    list_t temp_list = list_make();

    return reverse(filterHelper(input_list, fn, temp_list));

}
