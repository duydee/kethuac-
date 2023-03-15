#include <iostream>

using namespace std;


class ConNguoi
{
    protected:
        string ten;
        int tuoi;
    public:
        ConNguoi(void);
        ConNguoi(string,int);
        void diChuyen(void);
        void anUong(void);
};

class ConTrai:public ConNguoi   //don ke thua
{
    protected:
        int canNang;
        int chieuCao;
    public:
        ConTrai(void);
        ConTrai(string,int,int,int);
        void tostring(void);
};
class BangDiem
{
    protected:
        int diemToan;
        int diemVan;
    public:
        BangDiem();
        BangDiem(int ,int);
        void showDiem(string);
        ~BangDiem();
};

BangDiem::BangDiem()
{
}

void BangDiem::showDiem(string ten)
{
    cout<<"bang diem cua sinh vien "<<ten<<"\n";
    cout<<"diem toan: "<<this->diemToan<<"  diem van: "<<this->diemVan<<endl;
}

BangDiem::~BangDiem()
{
}

class SinhVien:public ConTrai,public BangDiem   //da ke thua
{
    private:
        string khoa;
        string truong;
    public:
        SinhVien(void);
        SinhVien(string,int,int,int,string,string,int ,int);

        void showInfo(void);

        ~SinhVien();
};

SinhVien::SinhVien(void)
{
}

SinhVien::SinhVien(string ten,int tuoi,int canNang,int chieuCao,string khoa,string truong,int diemToan,int diemVan)
{
    this->ten=ten;
    this->tuoi=tuoi;
    this->canNang=canNang;
    this->chieuCao=chieuCao;
    this->khoa=khoa;
    this->truong=truong;
    this->diemToan=diemToan;
    this->diemVan=diemVan;
}

SinhVien::~SinhVien()
{
}

void SinhVien::showInfo(void)
{
    cout<<"sinh vien ten:"<<this->ten<<"\n";
    cout<<this->tuoi<<" tuoi"<<endl;
    cout<<"can nang: "<<this->canNang<<"kg  chieu cao: "<<this->chieuCao<<"cm \n";
    this->showDiem(this->ten);
}

ConNguoi::ConNguoi(void)
{
    this->ten = "";
    this->tuoi=0;
}

ConNguoi::ConNguoi(string ten,int tuoi)
{
    this->ten = ten;
    this->tuoi= tuoi;
}

void ConNguoi::diChuyen(void)
{
    cout <<this->ten<<" dang di chuyen "<< endl;

}

void ConNguoi::anUong(void)
{
    cout <<this->ten<<" dang an uong "<< endl;

}

ConTrai::ConTrai(void)
{
    this->ten="";
    this->tuoi=0;
    this->canNang=0;
    this->chieuCao=0;
}

ConTrai::ConTrai(string ten,int tuoi,int canNang,int chieuCao)
{
    this->ten=ten;
    this->tuoi=tuoi;
    this->canNang=canNang;
    this->chieuCao=chieuCao;
}

void ConTrai::tostring(void)
{
    cout <<this->ten<<"  "<<this->tuoi<<"  "<<this->canNang<<"  "<<this->chieuCao<<"  "<< endl;
}

int main()
{
    //don ke thua
    cout<<"------------------don ke thua--------------------"<<endl;
    ConNguoi nguoi1("duy",22);
    nguoi1.anUong();

    ConTrai contrai1("anh",21,65,170);
    contrai1.tostring();
    contrai1.diChuyen();

    //da ke thua
    cout<<"-----------------da ke thua-----------------"<<endl;
    SinhVien sv1("kien",22,60,170,"CD-CT","dai hoc Lam Nghiep",5,6);
    sv1.showInfo();
    sv1.diChuyen();

    return 0;
}
