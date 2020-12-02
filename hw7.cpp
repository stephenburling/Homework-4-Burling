/*

list_t ConvertToDList(stringstream& stream_list) 
    list_t return_list = list_make();
    int end;
    while (stream_list >> end) {
        return_list = list_make(end, return_list);
    }
    return return_list;


int ListSize(list_t input_list, int size) 

    size = size + 1;

    if (list_isEmpty(list_rest(input_list))) {
        return size;
    }
    else {
        return ListSize(list_rest(input_list), size);
    }



list_t FibHasher(list_t input_list) 

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


bool isPrime(int n)

    if (n <= 1) {
        return false;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;


list_t odd_hash(list_t input_list) 

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


list_t even_hash(list_t input_list, int odd_sum) 

    list_t return_list = list_make();
    int hash;

    while (!list_isEmpty(input_list)) {
        hash = odd_sum + list_first(input_list);

        return_list = list_make(hash, return_list);

        input_list = list_rest(input_list);
    }

    return reverse(return_list);


list_t EvenOddHasher(list_t input_list) 

    list_t odd_list = filter_odd(input_list);
    list_t return_list = filter_even(input_list);

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


void CompareFunction(list_t hash_list, list_t old_output) 

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

    cout << "\nFinal diff. output: " << endl;

    list_print(diff_list);



int CollisionCounter(list_t input_list) 

    list_t list_template = list_make();

    int key, i, collisions = 0;

    bool traverser;

    vector<list_t> hash_table(ListSize(input_list, 0), list_template);

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


void HashTestOne() 

    list_t list_to_hash = list_make();
    list_t old_hash_output = list_make();

    string input_list;
    string old_hash_list;

    getline(cin, input_list);
    getline(cin, old_hash_list);

    stringstream input_stream(input_list);
    stringstream old_stream(old_hash_list);

    list_to_hash = ConvertToDList(input_stream);
    old_hash_output = ConvertToDList(old_stream);

    old_hash_output = reverse(old_hash_output);

    list_to_hash = FibHasher(list_to_hash);

    cout << "\nHashed list:" << endl;
    list_print(list_to_hash);
    cout << "\nOld hashed list:" << endl;
    list_print(old_hash_output);

    CompareFunction(list_to_hash, old_hash_output);

    cout << endl << "collision cnt" << endl;

    cout << "\nHash Test 1:" << endl;

    cout << "new_code : " << CollisionCounter(list_to_hash) << endl;

    cout << "old_code : " << CollisionCounter(old_hash_output) << endl;



void HashTestTwo() 

    Same as HashTestOne but calls EvenOddHash instead

}

int main() {
    cout << "------------Input for Hash Test 1------------" << endl;
    HashTestOne();
    cout << "\n------------Input for Hash Test 2------------" << endl;
    HashTestTwo();

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <sstream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

list_t ConvertToDList(stringstream& stream_list) {
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
    list_t return_list = filter_even(input_list);

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
    
    cout << "\nFinal diff. output: " << endl;

    list_print(diff_list);

}

int CollisionCounter(list_t input_list) {

    list_t list_template = list_make();

    int key, i, collisions = 0;

    bool traverser;

    vector<list_t> hash_table(ListSize(input_list, 0), list_template);

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

    string input_list;
    string old_hash_list;

    getline(cin, input_list);
    getline(cin, old_hash_list);

    stringstream input_stream(input_list);
    stringstream old_stream(old_hash_list);

    list_to_hash = ConvertToDList(input_stream);
    old_hash_output = ConvertToDList(old_stream);

    old_hash_output = reverse(old_hash_output);

    list_to_hash = FibHasher(list_to_hash);

    cout << "\nHashed list:" << endl;
    list_print(list_to_hash);
    cout << "\nOld hashed list:" << endl;
    list_print(old_hash_output);

    CompareFunction(list_to_hash, old_hash_output);

    cout << endl << "collision cnt" << endl;

    cout << "\nHash Test 1:" << endl;

    cout << "new_code : " << CollisionCounter(list_to_hash) << endl;

    cout << "old_code : " << CollisionCounter(old_hash_output) << endl;

}

void HashTestTwo() {

    list_t list_to_hash = list_make();
    list_t old_hash_output = list_make();

    string input_list;
    string old_hash_list;

    getline(cin, input_list);
    getline(cin, old_hash_list);

    stringstream input_stream(input_list);
    stringstream old_stream(old_hash_list);

    list_to_hash = ConvertToDList(input_stream);
    old_hash_output = ConvertToDList(old_stream);

    old_hash_output = reverse(old_hash_output);

    list_to_hash = EvenOddHasher(list_to_hash);

    cout << "\nHashed list:" << endl;
    list_print(list_to_hash);
    cout << "\nOld hashed list:" << endl;
    list_print(old_hash_output);

    CompareFunction(list_to_hash, old_hash_output);
    cout << endl;

    cout << endl << "collision cnt" << endl;

    cout << "Hash Test 2:" << endl;

    cout << "new_code : " << CollisionCounter(list_to_hash) << endl;

    cout << "old_code : " << CollisionCounter(old_hash_output) << endl;

}

int main() {
    cout << "------------Input for Hash Test 1------------" << endl;
    HashTestOne();
    cout << "\n------------Input for Hash Test 2------------" << endl;
    HashTestTwo();

    return 0;
}