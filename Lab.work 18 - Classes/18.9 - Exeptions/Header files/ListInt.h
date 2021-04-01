class ListInt
{
private:
    int* _data;
    int _length;

public:
    ListInt(int length, int fillValue);
    ListInt(const ListInt& copied);
    ~ListInt();

    int& operator [] (int index);
    ListInt& operator = (const ListInt& assigned);
    ListInt operator + (const ListInt& adder);

    int Length() { return _length; }
};