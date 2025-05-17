#include <iostream>
#include <string>
using namespace std;

class dosen;
class universitas;

class mahasiswa{
private :
    string nama;
    int nim;
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

class dosen{
private : 
    string nama;
    int NIDN;
    string pangkat;
    float gaji;
public :
    dosen(string nama, int NIDN, string pangkat, float gaji) : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji){}

    void beriNilai(mahasiswa* M, float nilai) {
        M->nilai = nilai;
    }
    void tampilkanInfo() {
        cout<<"Nama Dosen : "<<nama<<endl;
        cout<<"NIDN : "<<NIDN<<endl;
        cout<<"Pangkat :"<<pangkat<<endl;
    }
    friend void LihatGajiDosen(dosen* d);
    friend class staf;
};

void LihatGajiDosen(dosen* d){
    cout<<"Gaji Dosen :" <<d->gaji<<endl;
}

