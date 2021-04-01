#include "..\Header files\ListIterator.h"

void ListIterator::operator+=(int addValue)
{
	for (int i = 0; i < addValue; i++)
		_pointedElement++;
}

void ListIterator::operator-=(int subValue)
{
	for (int i = 0; i < subValue; i--)
		_pointedElement--;
}
