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
    mahasiswa(string nama, int nim) : nama(nama), nim(nim), nilai(0){}
    
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

class staf{
private: 
    string nama;
    int IDstaf;
    float gaji;
public: 
    staf(string nama, int IDstaf, float gaji) : nama(nama), IDstaf(IDstaf), gaji(gaji){}

    void ubahPangkat(dosen* d, string pangkatBaru){
        d->pangkat = pangkatBaru;
    }
    void tampilkanInfo(){
        cout<<"Nama Staf : "<<nama<<endl;
        cout<<"ID Staf :"<<IDstaf<<endl;
    }
    friend void LihatGajiStaf(staf* s);
};

void LihatGajiStaf(staf* s){
    cout<<"Gaji Staf : "<<s->gaji<<endl;
}

int main(){
    mahasiswa mhs1("Adi", 23456);
    dosen dsn("Budi", 5678, "Asisten Ahli", 10000000);
    staf stf("Tia", 2, 200000);

    dsn.beriNilai(&mhs1, 90);
    mhs1.tampilkanInfo();
    dsn.tampilkanInfo();
    LihatGajiDosen(&dsn);
    stf.ubahPangkat(&dsn, "Lektor");
    dsn.tampilkanInfo();
    stf.tampilkanInfo();
    LihatGajiStaf(&stf);

    return 0;
}
