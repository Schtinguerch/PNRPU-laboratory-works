#include <iostream>
#include "NotEqualLengthExeption.h"
#include "IndexAccessExeption.h"
#include "SizeExeption.h"
#include "ListInt.h"

using namespace std;

int main()
{
    ListInt first(10, 5);
    ListInt second (11, 73);

    try
    {
        ListInt summ = first + second; //Equality exeption
    }
    catch (NotEqualLengthExeption e)
    {
        e.Message();
    }
    try {
        ListInt good(23, 22);
        good[-1] = 5;
    }
    catch (IndexAccessExeption e)
    {
        e.Message();
    }

    try
    {
        ListInt longList(100, 4); // SizeExeption
    }
    catch (SizeExeption e)
    {
        e.Message();
    }

    return 0;
}
