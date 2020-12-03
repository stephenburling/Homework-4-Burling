/*

/////////////////////////////////// INPUT FOR PROGRAM ///////////////////////////////////

The program takes a total of 4 inputs, 2 for each hash test. You can copy and paste 2 at a time if you want, or 
you can copy the entire test input and paste into terminal like so:
    EXAMPLE:
    1 2 3 4 5 6
    22 22 23 24 26 29
    1 2 3 4 5 6
    16 56 18 58 20 60
If your tests look like this, just copy the whole thing and paste it in and the program will parse it out.

/////////////////////////////////////////////////////////////////////////////////////////

CONVERTTODLIST
  intialize dlist return_list
  initialize int end
  while stringstream has items left
    push back item onto vector
  return return_list


LISTSIZE
  increment size by one
  if current list is single element
    return list
  else
    call listsize again with reduced list

FIBHASHER
  Initiliaze dlist return_list
  take sum of passed list
  initiliaze ints operand and fib_key
  while passed list is not empty
    make operand equal to first element in passed list
    take fib number of operand
    make operand equal to fib_key plus sum of keys
    push result onto return_list
    decrement input_list by first element
  return return_list

ISPRIME
  if number is less than or equal to 1
    return false
  for 2 to the size of number
    if number mod i is 0(it has a divisor)
      return false
  return true

ODDHASH
  initialize return_list
  int hash
  initialize odd_product to be product of all numbers in list
  while list is not empty
    make hash equal to odd_product plus current key
    if hash key is NOT prime
      insert into return_list
    decrement input_list by first element and continue
  return reversed return_list

EVENHASH
  initialize return_list
  int hash
  while list is not empty
    make hash equal to sum of all odd numbers plus current key
    push hashed key onto return list
    decrement input_list by first element
  return reversed return_list

EVENODDHASHER
  Initilialize oddlist with all of odd items in current list
  initilialize return_list
  make odd_product equal to product of all odd numbers
  hash list of odd keys
  make odd_hash_sum equal to sum of all hashed odd keys
  initialize ints key and hash
  while list is not empty
    make key equal to current key in list
    if key is even
      apply EVENHASHER
    if key is odd
      apply ODDHASHER
    decrement input_list by first element

COMPAREFUNCTIONS
  make dlist diff_list
  make ints comparator one, comparator two, difference
  while lists are not empty
    pull first item from both lists
    obtain difference
    if negative, make positive
    push to diff_list
  reverse diff_list
  print diff_list

COLLISIONCOUNTER
  make dlist list_template
  make ints key, i, collisions equal to 0
  make bool traverser
  make vector of type dlist called hash map
  while list is not empty
    set traverser to false
    set key to current key in list
    set i equal to 0
    while traverser is false
      if current bucket is empty 
        put key in bucket
      else if current bucket equals key
        put key in bucket and increase collisions by 1
      traverse by one
    decrement input_list by first element

HASHTESTONE
  Make dlists list_to_hash and old_hash_input
  obtain input from getline
  ConvertToDlist
  reverse old_hash_output
  apple FibHasher to list of keys
  output lists and collision count

HASHTESTTWO
  Make dlists list_to_hash and old_hash_input
  obtain input from getline
  ConvertToDlist
  reverse old_hash_output
  apple EvenOddHasher to list of keys
  output lists and collision count

MAIN
  call hash test one
  call hash test two
  return
*/

#include <iostream>
#include <vector>
#include <sstream>
#include "recursive.h"
#include "hw4.h"

list_t ConvertToDList(std::stringstream& stream_list) {
  list_t return_list = list_make();
  int end;
  while (stream_list >> end) {
    return_list = list_make(end, return_list);
  }
  return return_list;
}

int ListSize(list_t input_list, int size) {

size = size + 1;

  if (list_isEmpty(list_rest(input_list))) {
    return size;
  }
  else {
    return ListSize(list_rest(input_list), size);
  }

}

list_t FibHasher(list_t input_list) {

  list_t return_list = list_make();

  int sum_keys = sum(input_list);
  int operand, fib_key;

  while (!list_isEmpty(input_list)) {
    operand = list_first(input_list);
    fib_key = fib(operand);
    operand = fib_key + sum_keys;
    return_list = list_make(operand, return_list);
    input_list = list_rest(input_list);
  }

  return return_list;
}

//Learned how to do this from geeks4geeks.com, I needed a shorter function than the one I was writing
bool isPrime(int n)
{
  if (n <= 1) {
  return false;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

list_t odd_hash(list_t input_list) {

  list_t return_list = list_make();
  int hash;
  int odd_product = product(input_list);

  while (!list_isEmpty(input_list)) {
    hash = odd_product + list_first(input_list);

    if (!isPrime(hash)) {
      return_list = list_make(hash, return_list);
    }
    input_list = list_rest(input_list);
  }

  return reverse(return_list);
}

list_t even_hash(list_t input_list, int odd_sum) {

  list_t return_list = list_make();
  int hash;

  while (!list_isEmpty(input_list)) {
    hash = odd_sum + list_first(input_list);

    return_list = list_make(hash, return_list);

    input_list = list_rest(input_list);
  }

  return reverse(return_list);
}

list_t EvenOddHasher(list_t input_list) {

  list_t odd_list = filter_odd(input_list);
  list_t return_list = list_make();

  int odd_product = product(odd_list);

  odd_list = odd_hash(odd_list);

  int odd_hash_sum = sum(odd_list);

  int key, hash;

  while (!list_isEmpty(input_list)) {
    key = list_first(input_list);

    if ((key % 2) == 0) {
      hash = odd_hash_sum + key;
      return_list = list_make(hash, return_list);
    }
    else {
      hash = odd_product + key;
      return_list = list_make(hash, return_list);
    }

    input_list = list_rest(input_list);
  }

  return return_list;
}

void CompareFunction(list_t hash_list, list_t old_output) {

  list_t diff_list = list_make();
  int comparator_one, comparator_two, difference;
    
  while (!list_isEmpty(hash_list) && !list_isEmpty(old_output)) {

    comparator_one = list_first(hash_list);
    comparator_two = list_first(old_output);

    difference = comparator_one - comparator_two;

    if (difference < 0) {
      difference = difference * -1;
    }

    diff_list = list_make(difference, diff_list);

    hash_list = list_rest(hash_list);
    old_output = list_rest(old_output);
  }

  diff_list = reverse(diff_list);
    
  std::cout << "\nFinal diff. output: " << std::endl;

  list_print(diff_list);

}

int CollisionCounter(list_t input_list) {

  list_t list_template = list_make();

  int key, i, collisions = 0;

  bool traverser;

  std::vector<list_t> hash_table(ListSize(input_list, 0), list_template);

  while (!list_isEmpty(input_list)) {
    traverser = false;
    key = list_first(input_list);
    i = 0;
    while (!traverser) {
      if (list_isEmpty(hash_table[i])) {
        hash_table[i] = list_make(key, hash_table[i]);
        traverser = true;
      }
      else if (list_first(hash_table[i]) == key) {
        hash_table[i] = list_make(key, hash_table[i]);
        collisions++;
        traverser = true;
      }
      i++;
    }
    input_list = list_rest(input_list);
  }
    
  return collisions;
}

void HashTestOne() {

  list_t list_to_hash = list_make();
  list_t old_hash_output = list_make();

  std::string input_list;
  std::string old_hash_list;

  getline(std::cin, input_list);
  getline(std::cin, old_hash_list);

  std::stringstream input_stream(input_list);
  std::stringstream old_stream(old_hash_list);

  list_to_hash = ConvertToDList(input_stream);
  old_hash_output = ConvertToDList(old_stream);

  old_hash_output = reverse(old_hash_output);

  list_to_hash = FibHasher(list_to_hash);

  std::cout << "\nHashed list:" << std::endl;
  list_print(list_to_hash);
  std::cout << "\nOld hashed list:" << std::endl;
  list_print(old_hash_output);

  CompareFunction(list_to_hash, old_hash_output);

  std::cout << std::endl << "collision cnt" << std::endl;

  std::cout << "\nHash Test 1:" << std::endl;

  std::cout << "new_code : " << CollisionCounter(list_to_hash) << std::endl;

  std::cout << "old_code : " << CollisionCounter(old_hash_output) << std::endl;

}

void HashTestTwo() {
  list_t list_to_hash = list_make();
  list_t old_hash_output = list_make();

  std::string input_list;
  std::string old_hash_list;

  getline(std::cin, input_list);
  getline(std::cin, old_hash_list);

  std::stringstream input_stream(input_list);
  std::stringstream old_stream(old_hash_list);

  list_to_hash = ConvertToDList(input_stream);
  old_hash_output = ConvertToDList(old_stream);

  old_hash_output = reverse(old_hash_output);

  list_to_hash = EvenOddHasher(list_to_hash);

  std::cout << "\nHashed list:" << std::endl;
  list_print(list_to_hash);
  std::cout << "\nOld hashed list:" << std::endl;
  list_print(old_hash_output);

  CompareFunction(list_to_hash, old_hash_output);

  std::cout << std::endl;

  std::cout << std::endl << "collision cnt" << std::endl;

  std::cout << "Hash Test 2:" << std::endl;

  std::cout << "new_code : " << CollisionCounter(list_to_hash) << std::endl;

  std::cout << "old_code : " << CollisionCounter(old_hash_output) << std::endl;

}

int main() {
  std::cout << "------------Input for Hash Test 1------------" << std::endl;
  HashTestOne();
  std::cout << "\n------------Input for Hash Test 2------------" << std::endl;
  HashTestTwo();

  return 0;
}