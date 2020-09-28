#include<iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

bool ListEqual(list_t l1, list_t l2)
// EFFECTS: reeturns true of l1 and l2 are equal, false otherwise
{
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
        return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
        return false;
    }
    else {
        return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i)
{
    return (i % 4);
}

int main() {

    list_t original = list_make();
    list_t rotated = list_make();
    list_t testlist;

    
    const int largest = 7;
    const int steps = 4 + largest;

    bool answer = true;

    for (int i = largest + 5; i > 0; i--) {
        original = list_make(i, original);
        rotated = list_make((i + steps) % largest, rotated);
    }


    testlist = chop(original, 2);

    cout << "\nOriginal List: \n" << endl;
    list_print(original);

    cout << "\nChopped List: \n" << endl;
    list_print(testlist);
    //bool results = ListEqual(testlist, rotated);

    //cout << results << endl;
   // list_print(original);
    //list_print(rotated);
    //list_print(testlist);
    return 0;

}