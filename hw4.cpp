#include <iostream>
#include "recursive.h"
#include "hw4.h"

using std::cout;
using std::endl;

int accumulate(list_t l, int (*fn)(int, int), int base)
{
    if (list_isEmpty(l)) {
        return base;
    }
    else {
        return accumulate(list_rest(l), fn, fn(base, list_first(l)));
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

list_t reverse(list_t input_list) {

    list_t temp_list = list_make();

    temp_list = reverseHelper(input_list, temp_list);

    return temp_list;
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
  }
  else {
    return input_list;
  }
}