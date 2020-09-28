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

    list_t first = list_make();
    list_t second = list_make();
    list_t test_list = list_make();

    
    const int largest = 3;
    const int steps = 4 + largest;

    bool answer = true;

    for (int i = largest+1; i > 0; i--) {
        //cout << i << endl;
        first = list_make(i, first);
    }

    for (int j = largest + 5; j > 4; j--) {
        //cout << j << endl;
        second = list_make(j,second);
    }


    cout << "\nFirst List: \n" << endl;
    list_print(first);

    //cout << "\nSecond list: \n" << endl;
    //list_print(second);

    //test_list = insert_list(first, second, 0);

    int sumInteger = product(first);

    cout << "Product is equal to: " << sumInteger << endl;

    //cout << "\nTested list: \n" << endl;
    //list_print(first);

    return 0;

}