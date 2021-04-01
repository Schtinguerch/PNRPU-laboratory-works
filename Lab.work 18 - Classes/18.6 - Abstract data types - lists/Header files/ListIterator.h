#pragma once
class ListIterator
{
	friend class ListInt;

private:
	int* _pointedElement;

public:
	ListIterator() { _pointedElement = nullptr; }
	ListIterator(const ListIterator& copied) { _pointedElement = copied._pointedElement; }

	bool operator == (const ListIterator& compared) { return _pointedElement == compared._pointedElement; }
	bool operator != (const ListIterator& compared) { return _pointedElement != compared._pointedElement; }
	
	int& operator *() const { return *_pointedElement; }
	void operator ++() { ++_pointedElement; }
	void operator --() { --_pointedElement; }
	
	void operator += (int addValue);
	void operator -= (int subValue);
};

