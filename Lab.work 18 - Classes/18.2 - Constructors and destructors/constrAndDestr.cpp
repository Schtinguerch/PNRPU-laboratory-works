#include <iostream>
#include <string>
using namespace std;

class Auto
{
private:
    string _brand;
    string _model;
    int _cost;

public:
    string Brand() { return _brand; }

    void SetBrand(string brand)
    {
        if (brand.size() > 1)
            _brand = brand;
        else 
           cout << "Error: invalid brand;\n";
    }

    string Model() { return _model; }

    void SetModel(string model)
    {
        if (model.size() > 0 && model != _brand)
            _model = model;
        else
            cout << "Error: invalid model;\n";
    }

    int Cost() { return _cost; }

    void SetCost(int cost)
    {
        if (cost > 0)
            _cost = cost;
        else 
            cout << "Error: invalid cost;\n";
    }

    void PrintData()
    {
        cout << "\nAutomobile:\n";
        cout << " - Brand: " << _brand << ";\n";
        cout << " - Model: " << _model << ";\n";
        cout << " - Cost:  " << _cost << "$;\n";
    }

    Auto()
    {
        _brand = "unknown";
        _model = "not famous";
        _cost = 1;
    }

    Auto(string brand, string model, int cost)
    {
        SetBrand(brand);
        SetModel(model);
        SetCost(cost);
    }

    Auto(Auto& parentAuto) 
    {
        _brand = parentAuto._brand;
        _model = parentAuto._model;
        _cost = parentAuto._cost;
    }

    ~Auto()
    {
        
    }
};

int main()
{
    Auto firstAuto;
    firstAuto.PrintData();

    Auto secondAuto("Jeep", "Cherokee", 30000);
    secondAuto.PrintData();

    Auto thirdAuto(secondAuto);
    thirdAuto.PrintData();

    return 0;
}