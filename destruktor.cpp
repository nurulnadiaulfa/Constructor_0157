#include <iostream>
using namespace std;

class angka{
private:
    int *arr;
    int panjang;
public:
    angka(int); //constructor
    ~angka(); //destructor
    void cetakData();
    void isiData();
};
//Definisi member functon
angka::angka(int i){ //Constructor
    panjang = i;
    arr = new int[i];
    isiData();
}