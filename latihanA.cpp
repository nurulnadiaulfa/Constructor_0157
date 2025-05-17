#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
private :
    string nama;
    string nim;
    float nilai;
public:
    mahasiswa(string nama, string nim) : nama(nama), nim(nim), nilai(0){}
    
    void tampilkanInfo(){
        cout <<"Nama Mahasiswa : " <<nama <<endl;
        cout <<"NIM : " <<nim <<endl;
        cout <<"Nilai : " <<nilai <<endl;
    }
    friend class dosen;
};



