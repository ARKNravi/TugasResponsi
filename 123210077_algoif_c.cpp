#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;

char kembali;
int status;

typedef struct
{
	string namabakteri ;
	string ukuran;
    string jumlahanak;

	
}bakteri;

void haldepan();
void menuatas();
void menubawah();
void menuutama();
void daftar(fstream &databakteri, fstream &jumlah, int jumlahbakteri);
void sorting(fstream &databakteri, fstream &jumlah, int jumlahbakteri);
void updatetahap(fstream &databakteri, fstream &jumlah, int jumlahbakteri);
void simulasi(fstream &databakteri, fstream &jumlah, int jumlahbakteri);

int main()
{
    int jumlahbakteri, pilih;
    fstream databakteri, jumlah;

    haldepan();

	do {
	system("CLS");

	jumlah.open("jumlahbakteri.txt");
	jumlah >> jumlahbakteri;
	jumlah.close();
	
    menuatas();
	menuutama();
	cout << "\nMasukkan Pilihan  : ";
	cin >> pilih;
	if (pilih == 1){
		system("CLS");
		daftar(databakteri, jumlah, jumlahbakteri);
	}
	else if (pilih == 2) {
		system("CLS");
		updatetahap(databakteri, jumlah, jumlahbakteri);
	}
	else if (pilih == 3) {
		system("CLS");
		sorting(databakteri, jumlah, jumlahbakteri);
	}
    else if (pilih == 4) {
       system("CLS");
        simulasi(databakteri, jumlah, jumlahbakteri);
    }
	else if (pilih == 5) {
		exit(0);
	}
	else if (pilih == 6) {
	status = remove("databakteri.txt");
	status = remove("jumlahbakteri.txt");
	if(status==0){
        cout<<"\nFile Deleted Successfully!";}
       else{
        cout<<"\nError Occurred!";}
	}
    menubawah();
	} while (kembali == 'y' || kembali == 'Y');   
}

void haldepan()
{
    cout << " =============================================================" << endl;
    cout << "|                                                             |" << endl;
    cout << "|                PROGRAM LABORATORIUM UPN                     |" << endl;
    cout << "|                                                             |" << endl;
    cout << "| ----------------------------------------------------------- |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|     Universitas Pembangunan Nasional Veteran Yogyakarta     |" << endl;
    cout << "|                                                             |" << endl;
    cout << " =============================================================" << endl;
    cout << endl;
	system("PAUSE");
	system("CLS");
}
    
void menuatas()
{
    cout << " _____________________________________________________________" << endl;
    cout << "        Laboratorium Universitas Pembangunan Nasional" << endl;
    cout << " =============================================================" << endl;
}

void menubawah()
{
    cout << endl;
    cout << "=============================================================" << endl;
    cout << " Kembali ke Menu Utama? (y/n) : "; cin >> kembali;
	system("CLS");
}

void menuutama()
{
	cout << "              MENU UTAMA PROGRAM LABORATORIUM UPN";
    cout << "\n ------------------------------------------------------------- \n";
	cout << "\n1. Input Bakteri";
	cout << "\n2. Cari Bakteri";
	cout << "\n3. Cetak Bakteri";
    cout << "\n4. Simulasi Pembelahan";
	cout << "\n5. EXIT";
	cout << "\n5. RESET FILE";

}

void daftar(fstream &databakteri, fstream &jumlah, int jumlahbakteri)
{
    system("CLS");

	bakteri daftar;

	menuatas();
	cin.ignore();
	cout << "\nNama Bakteri       = ";
	getline(cin, daftar.namabakteri );
	cout << "Ukuran               = ";
	getline(cin, daftar.ukuran);
    cout << "Jumlah Anak          = ";
    getline(cin, daftar.jumlahanak);
	cout << endl;
	jumlahbakteri++;

	cout << "Selamat, data anda telah terdaftar!";
	
	databakteri.open("databakteri.txt", ios::app | ios::out);
		databakteri << daftar.namabakteri  << endl;
		databakteri << daftar.ukuran << endl;
        databakteri << daftar.jumlahanak << endl;
	databakteri.close();

	jumlah.open("jumlahbakteri.txt", ios::out | ios::trunc);
	jumlah << jumlahbakteri;
	jumlah.close();

	cout << "\nBerhasil ditambahkan.\n";
}

void updatetahap(fstream &databakteri, fstream &jumlah, int jumlahbakteri)
{

	system("CLS");

	bakteri update[jumlahbakteri];

	bool found = false;
    int ubah, ubahtahap, pilihan, pilihan2;
	string cari;

	databakteri.open("databakteri.txt");
	for (int i = 0; i < jumlahbakteri; i++)
	{
		getline(databakteri, update[i].namabakteri );
		getline(databakteri, update[i].ukuran);
		getline(databakteri, update[i].jumlahanak);
	}
	databakteri.close();

	menuatas();
	cout << "                   MENCARI DATA Bakteri " << endl;
	cout << " =============================================================" << endl;
	cout << endl;
	cout << " Ingin Mencari data melalui "<<endl;
	cout << " 1. Nama Bakteri "<<endl;
	cout << " 2. Ukuran Bakteri"<< endl;
	cout << " 3. Jumlah Anak"<< endl;
	cin >> pilihan2;
	if (pilihan2 ==1)
    {
      cin.ignore();
	cout << "Cari Nama Bakteri = ";
	getline(cin, cari);

    // updatetahap
    for (int i = 0; i < jumlahbakteri; i++)
    {
        if(update[i].namabakteri  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
		cout << "\n INFORMASI DATA Bakteri" << endl;
		cout << " -------------------------------------------------------------" << endl;
				cout << "Nama Bakteri        = " << update[ubah].namabakteri  << endl;
            	cout << "Ukuran              = " << update[ubah].ukuran << endl;
				cout << "Jumlah Anak         = " << update[ubah].jumlahanak << endl;
                cout << "Apa yang ingin anda lakukan kepada data ?"<<endl;
                cout << "1. Edit"<<endl;
                cout << "2. EXIT"<<endl;
                cin >>pilihan;
                if (pilihan == 1)
                {
                cout << "\n Data Apa Yang ingin diubah ? : \n";
		        cout<<" 1. Ukuran \n";
		        cout<<" 2. Jumlah Anak\n";
		        cout<<" 3. Exit\n";
		        cout<<" Pilih no :";
		        cin >> ubahtahap;

		        if (ubahtahap == 1){
			    cin.ignore();
			    cout<< "Ukuran Bakteri Diubah Menjadi : ";
			    getline(cin, update[ubah].ukuran);
			    }
		        else if (ubahtahap == 2){
			    cin.ignore();
			    cout<< "Jumlah Anak Diubah Menjadi : ";
			    getline(cin, update[ubah].jumlahanak);
			    }
			    else if (ubahtahap == 3){
			    cin.ignore();
			    kembali='y';
			    }  
                }
                else if (pilihan == 2){
                    kembali = 'y';
                }
                
            

        	databakteri.open("databakteri.txt", ios::trunc | ios::out);
			for (int i = 0; i < jumlahbakteri; i++)
			{
				databakteri << update[i].namabakteri  << endl;
				databakteri << update[i].ukuran << endl;
				databakteri << update[i].jumlahanak << endl;
			}
			databakteri.close();
			system("CLS");
			cout << "\nData :" << endl;
            cout << "Nama Bakteri = " << update[ubah].namabakteri  << endl;
        	cout << "Ukuran       = " << update[ubah].ukuran << endl;
			cout << "Jumlah Anak  = " << update[ubah].jumlahanak << endl;

		
    }
   
      
    }
     if (pilihan2 == 2)
    {
        cin.ignore();
	cout << "Cari Ukuran Bakteri = ";
	getline(cin, cari);

    // updatetahap
    for (int i = 0; i < jumlahbakteri; i++)
    {
        if(update[i].ukuran  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
		cout << "\n INFORMASI DATA Bakteri" << endl;
		cout << " -------------------------------------------------------------" << endl;
				cout << "Nama Bakteri        = " << update[ubah].namabakteri  << endl;
            	cout << "Ukuran              = " << update[ubah].ukuran << endl;
				cout << "Jumlah Anak         = " << update[ubah].jumlahanak << endl;
                cout << "Apa yang ingin anda lakukan kepada data ?"<<endl;
                cout << "1. Edit"<<endl;
                cout << "2. EXIT"<<endl;
                cin >>pilihan;
                if (pilihan == 1)
                {
                cout << "\n Data Apa Yang ingin diubah ? : \n";
		        cout<<" 1. Ukuran \n";
		        cout<<" 2. Jumlah Anak\n";
		        cout<<" 3. Exit\n";
		        cout<<" Pilih no :";
		        cin >> ubahtahap;

		        if (ubahtahap == 1){
			    cin.ignore();
			    cout<< "Ukuran Bakteri Diubah Menjadi : ";
			    getline(cin, update[ubah].ukuran);
			    }
		        else if (ubahtahap == 2){
			    cin.ignore();
			    cout<< "Jumlah Anak Diubah Menjadi : ";
			    getline(cin, update[ubah].jumlahanak);
			    }
			    else if (ubahtahap == 3){
			    cin.ignore();
			    kembali='y';
			    }  
                }
                else if (pilihan == 2){
                    kembali = 'y';
                }
                
            

        	databakteri.open("databakteri.txt", ios::trunc | ios::out);
			for (int i = 0; i < jumlahbakteri; i++)
			{
				databakteri << update[i].namabakteri  << endl;
				databakteri << update[i].ukuran << endl;
				databakteri << update[i].jumlahanak << endl;
			}
			databakteri.close();
			system("CLS");
			cout << "\nData :" << endl;
            cout << "Nama Bakteri = " << update[ubah].namabakteri  << endl;
        	cout << "Ukuran       = " << update[ubah].ukuran << endl;
			cout << "Jumlah Anak  = " << update[ubah].jumlahanak << endl;

		
    }
    }
	if (pilihan2 == 3)
    {
        cin.ignore();
	cout << "Cari Jumlah Anak = ";
	getline(cin, cari);

    // updatetahap
    for (int i = 0; i < jumlahbakteri; i++)
    {
        if(update[i].jumlahanak  == cari){
            ubah = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
	else {
		cout << "\n INFORMASI DATA Bakteri" << endl;
		cout << " -------------------------------------------------------------" << endl;
				cout << "Nama Bakteri        = " << update[ubah].namabakteri  << endl;
            	cout << "Ukuran              = " << update[ubah].ukuran << endl;
				cout << "Jumlah Anak         = " << update[ubah].jumlahanak << endl;
                cout << "Apa yang ingin anda lakukan kepada data ?"<<endl;
                cout << "1. Edit"<<endl;
                cout << "2. EXIT"<<endl;
                cin >>pilihan;
                if (pilihan == 1)
                {
                cout << "\n Data Apa Yang ingin diubah ? : \n";
		        cout<<" 1. Ukuran \n";
		        cout<<" 2. Jumlah Anak\n";
		        cout<<" 3. Exit\n";
		        cout<<" Pilih no :";
		        cin >> ubahtahap;

		        if (ubahtahap == 1){
			    cin.ignore();
			    cout<< "Ukuran Bakteri Diubah Menjadi : ";
			    getline(cin, update[ubah].ukuran);
			    }
		        else if (ubahtahap == 2){
			    cin.ignore();
			    cout<< "Jumlah Anak Diubah Menjadi : ";
			    getline(cin, update[ubah].jumlahanak);
			    }
			    else if (ubahtahap == 3){
			    cin.ignore();
			    kembali='y';
			    }  
                }
                else if (pilihan == 2){
                    kembali = 'y';
                }
                
            

        	databakteri.open("databakteri.txt", ios::trunc | ios::out);
			for (int i = 0; i < jumlahbakteri; i++)
			{
				databakteri << update[i].namabakteri  << endl;
				databakteri << update[i].ukuran << endl;
				databakteri << update[i].jumlahanak << endl;
			}
			databakteri.close();
			system("CLS");
			cout << "\nData :" << endl;
            cout << "Nama Bakteri = " << update[ubah].namabakteri  << endl;
        	cout << "Ukuran       = " << update[ubah].ukuran << endl;
			cout << "Jumlah Anak  = " << update[ubah].jumlahanak << endl;

		
    }
    }
	cout << endl;
}

void sorting(fstream &databakteri, fstream &jumlah, int jumlahbakteri)
{
	bakteri sorting[jumlahbakteri], tempat;
	int pilih2, min_in;

	databakteri.open("databakteri.txt");
    for (int i = 0; i < jumlahbakteri; i++)
    {
    getline(databakteri, sorting[i].namabakteri );
	getline(databakteri, sorting[i].ukuran);
	getline(databakteri, sorting[i].jumlahanak);
    }
    databakteri.close();
    
    cout << "            TAMPILAN DATA LABORATORIUM UPN";
	cout << "\n ------------------------------------------------------------- \n";
	cout << endl;
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";

	cout << " Masukkan Pilihan : "; cin >> pilih2; 
	
	if (pilih2 == 1) {
		for(int i=0;i< jumlahbakteri;i++)
    {
        min_in = i;
        for(int j=i+1;j< jumlahbakteri;j++)
            if (sorting[j].namabakteri < sorting[min_in].namabakteri)
                min_in = j;
        swap(sorting[i],sorting[min_in]);
    } } 
                
    else if (pilih2 == 2) {
		for (int i = 0; i < jumlahbakteri; i++) {
			for (int j = i+1; j < jumlahbakteri; j++) {
				if (sorting[i].namabakteri > sorting[j].namabakteri) {
					tempat = sorting[i];
					sorting[i] = sorting[j];
					sorting[j] = tempat; } } } }

	databakteri.open("databakteri.txt", ios::trunc | ios::out);
	for (int i = 0; i < jumlahbakteri; i++)
	{
		databakteri << sorting[i].namabakteri  << endl;
		databakteri << sorting[i].ukuran << endl;
        databakteri << sorting[i].jumlahanak << endl;
	}
	databakteri.close();
	
	for (int i = 0; i < jumlahbakteri; i++)
    {
	cout << "\n ------------------------------------------------------------- \n";
    cout << " Nama Bakteri     = " << sorting[i].namabakteri  << endl;
	cout << " Ukuran           = " << sorting[i].ukuran << endl;
	cout << " Jumlah Anak      = " << sorting[i].jumlahanak << endl;

    }
    
}
	
void simulasi(fstream &databakteri, fstream &jumlah, int jumlahbakteri)
{   
    string cari2;
    int belah, ubah2;
    int kali;
    bool found = false;
    int anak;
    bakteri simulasi[jumlahbakteri];
    system("CLS");
    databakteri.open("databakteri.txt");
    for (int i = 0; i < jumlahbakteri; i++)
    {
    getline(databakteri, simulasi[i].namabakteri );
	getline(databakteri, simulasi[i].ukuran);
	getline(databakteri, simulasi[i].jumlahanak);
    }
    databakteri.close();
    cin.ignore();
	cout << "Cari Nama Bakteri = ";
	getline(cin, cari2);

    for (int i = 0; i < jumlahbakteri; i++)
    {
        if(simulasi[i].namabakteri  == cari2){
            ubah2 = i;
            found = true;
        }
    }

	if(!found){
        cout << "\nData tidak ditemukan!";
		cout << endl;
    } 
    else {
		cout << "\nData :" << endl;
            cout << "Nama Bakteri = " << simulasi[ubah2].namabakteri  << endl;
        	cout << "Ukuran       = " << simulasi[ubah2].ukuran << endl;
			cout << "Jumlah Anak  = " << simulasi[ubah2].jumlahanak << endl;
	cout << " Mau berapa Kali Pembelahan ?\n";
    cin >>belah;
    cout <<" berapa jumlah anak dalam bakteri tersebut?";
    cin >>anak;
    for (int i = 0; i < belah; i++)
	{
		kali = pow(anak,belah);
	}
    cout << " Hasil Pembelahan "<<kali;
    }
    
}
