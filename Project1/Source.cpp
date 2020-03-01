#include<iostream>
#include<ctype.h>
#include<fstream>
#include<string>
#include<istream>
using namespace std;

void ana();
void sil();
void ekle();
void duzenle();
void sirala();
int bul();
void cýkýs();
struct araclar{
	  string marka;
	  string seri;
	  string renk;
	  string model;
	  int km;
	  int fiyat;
	  int kod;
}a[1000];

int main() {
	ana();
	return 0;
}
void ana() {
	char sec;
	int islem;
	do {
		cout << "*******MENU*******" << endl;
		cout << "(1) arac bul " << endl;
		cout << "(2) arac ekle" << endl;
		cout << "(3) arac duzenle" << endl;
		cout << "(4) arac sýrala" << endl;
		cout << "(5) arac sil" << endl;
		cout << "(0) cýkýs" << endl;
		cout << "yapmak istediginiz islemi seciniz:";
		cin >> islem;
		if (islem == 1) {
			bul();
		}
		if (islem == 2) {
			ekle();
		}
		if (islem == 3) {
			duzenle();
		}
		if (islem == 4) {
			sirala();
		}
		if (islem == 5) {
			sil();
		}
		if (islem == 0) {
			cýkýs();
		}
		cout << "devam etmek icin 'e' cýkmak icin 'h' tusuna basiniz." << endl;
	} while (sec == 'e' || sec == 'E');
}
void sil() {
	int sec;
	int kod;
	cout << "silmek istediðiniz arac kodunu giriniz:";
	cin >> kod;
	while (kod < 0 && kod>1000) {
		cout << "hatali kod girdiniz " << endl;
		cout << "silmek istediginiz arac kodunu giriniz:";
		cin >> kod;
	}
	while (a[kod].marka == " ") {
		cout << kod << " kodlu arac bulunmamaktadir" << endl;
		cout << "silmek istediginiz arac kodunu giriniz:";
		cin >> kod;
	}
	a[kod].kod = 1001;
	a[kod].marka = " ";
	a[kod].seri = " ";
	a[kod].model = " ";
	a[kod].km = 0;
	a[kod].fiyat = 2000;
	a[kod].renk = " ";
	int say;
	ofstream o3;
	o3.open("stok.txt", ios::app);
	o3 << a[kod].kod << a[kod].marka << a[kod].model << a[kod].seri << a[kod].km << a[kod].renk << a[kod].fiyat << endl;
	o3.close();
	cout << kod << " kodlu arac silindi" << endl;
	cout << "(1) ana menu" << endl;
	cout << "(0) cýkýs" << endl;
	say = 0;
	cout << "secim yapiniz:";
	cin >> sec;
	if (sec == 1) {
		ana();
	}
	if (sec == 0) {
		cýkýs();
	}
}
void ekle() {
	int sec;
	int kod;
	cout << "eklemek istediginiz aracin:" << endl;
	cout << "kodu:";
	cin >> kod;
	while (kod < 0 && kod>1000) {
		cout << "gecersiz kod girdiniz" << endl;
		cout << "eklemek istediginiz aracin kodunu giriniz:";
		cin >> kod;
	}
	a[kod].kod = kod;
	cout << "aracin markasi:";
	getline(cin, a[kod].marka);
	cout << "\naracin modeli:";
	getline(cin, a[kod].model);
	cout << "\naracin serisi:";
	getline(cin, a[kod].seri);
	cout << "\naracin kilometresi:";
	getline(cin, a[kod].km);
	cout << "\naracin rengi:";
	getline(cin, a[kod].renk);
	cout << "\naracin fiyati";
	getline(cin, a[kod].fiyat);

	int say;
	ofstream o1;
	o1.open("stok.txt", ios::app);
	o1 << a[kod].kod << a[kod].marka << a[kod].model << a[kod].seri << a[kod].km << a[kod].renk << a[kod].fiyat << endl;
	o1.close();

	cout << "(1) ana menu" << endl;
	cout << "(0) cýkýs" << endl;
	say = 0;
	cout << "secim yapiniz:";
	cin >> sec;

	if (sec == 1) {
		ana();
	}
	if (sec == 0) {
		cýkýs();
	}
}
void duzenle() {
	int sec;
	int kod;
	cout << "duzenlemek istediðiniz arac kodunu giriniz:";
	cin >> kod;
	while (kod < 0 && kod>1000) {
		cout << "hatali kod girdiniz " << endl;
		cout << "duzenlemek istediginiz arac kodunu giriniz:";
		cin >> kod;
	}
	while (a[kod].marka == " ") {
		cout << kod << " kodlu arac bulunmamaktadir" << endl;
		cout << "duzenlemek istediginiz arac kodunu giriniz:";
		cin >> kod;
	}
	cout << "eski marka:" a[kod].marka << endl;
	cout << "yeni marka:";
	getline(cin, a[kod].marka);
	cout << "eski model:" << a[kod].model << endl;
	cout << "yeni model:";
	getline(cin, a[kod].model);
	cout << "eski seri:" << a[kod].seri << endl;
	cout << "yeni seri:";
	getline(cin, a[kod].seri);
	cout << "eski renk:" << a[kod].renk << endl;
	cout << "yeni renk:";
	getline(cin, a[kod].renk);
	cout << "eski km:" << a[kod].km << endl;
	cout << "yeni km:";
	getline(cin, a[kod].km);
	cout << "eski fiyat:" << a[kod].fiyat << endl;
	cout << "yeni fiyat:";
	getline(cin, a[kod].fiyat);

	int say;
	ofstream o2;
	o2.open("stok.txt", ios::app);
	o2 << a[kod].kod << a[kod].marka << a[kod].model << a[kod].seri << a[kod].km << a[kod].renk << a[kod].fiyat << endl;
	o2.close();

	cout << "(1) ana menu" << endl;
	cout << "(0) cýkýs" << endl;
	say = 0;
	cout << "secim yapiniz:";
	cin >> sec;
	if (sec == 1) {
		ana();
	}
	if (sec == 0) {
		cýkýs();
	}
}
void sirala() {
	int sec;
	cout << "(1) artan fiyatla sirala" << endl;
	cout << "(2) azalan fiyatla sirala" << endl;
	cout << "(3) fiyat araliginda sirala" << endl;
	cout << "(0) cýkýs" << endl;
	cin >> sec;
	if (sec == 1) {

	}
	if (sec == 2) {

	}
	if (sec == 3) {

	}
	if (sec == 0) {
		cýkýs();
	}

	cout << "(1) ana menu" << endl;
	cout << "(0) cýkýs" << endl;
	int say = 0;
	cout << "secim yapiniz:";
	cin >> sec;
	if (sec == 1) {
		ana();
	}
	if (sec == 0) {
		cýkýs();
	}

}
int bul() {
	int sec;
	int sec1;
	string renk;
	string fiyat;
	string model;
	int say = 0;

	cout << "(1) renge gore arac bul" << endl;
	cout << "(2) fiyata gore arac bul" << endl;
	cout << "(3) modele gore arac bul" << endl;
	cout << "(4) ana menu" << endl;
	cout << "(0) cikis" << endl;
	cout << "secim yapiniz:";
	cin >> sec;
	if (sec == 1) {
		cout << "arac rengini giriniz:";
		getline(cin, renk);
		cout << "KOD		MARKA		MODEL		SERÝ		KM		RENK		FÝYAT" << endl;

		for (int i = 0; i < 1000; i++) {
			if (renk == a[i].renk) {
				cout << a[i].kod << "		" << a[i].marka << "		" << a[i].model << "		" << a[i].seri << "		" << a[i].km << "		" << a[i].renk << "		" << a[i].fiyat << endl;
				say++;
			}
			else
				cout << renk << " renkte arac bulunmamaktadýr";
		}
		if (say != 0) {
			cout << say << " tane arac var" << endl << endl;
		}
		cout << "(1) bir onceki menu" << endl;
		cout << "(2) ana menu" << endl;
		cout << "(0) cýkýs" << endl;
		say = 0;
		cout << "secim yapiniz:";
		cin >> sec1;
		if (sec1 == 1) {
			bul();
		}
		if (sec1 == 2) {
			ana();
		}
		if (sec1 == 0) {
			cýkýs();
		}
	}
	if (sec == 2) {
		cout << "arac fiyatini giriniz:";
		getline(cin, fiyat);
		cout << "KOD		MARKA		MODEL		SERÝ		KM		RENK		FÝYAT" << endl;
		for (int i = 0; i < 1000; i++) {
			if (fiyat == a[i].fiyat) {
				cout << a[i].kod << "		" << a[i].marka << "		" << a[i].model << "		" << a[i].seri << "		" << a[i].km << "		" << a[i].renk << "		" << a[i].fiyat << endl;
				say++;
			}
			else
				cout << fiyat << " fiyatta arac bulunmamaktadýr";
		}
		if (say != 0) {
			cout << say << " tane arac var" << endl << endl;
		}
		cout << "(1) bir onceki menu" << endl;
		cout << "(2) ana menu" << endl;
		cout << "(0) cýkýs" << endl;
		say = 0;
		cout << "secim yapiniz:";
		cin >> sec1;
		if (sec1 == 1) {
			bul();
		}
		if (sec1 == 2) {
			ana();
		}
		if (sec1 == 0) {
			cýkýs();
		}
	}
	if (sec == 3) {
		cout << "arac modelini giriniz:";
		getline(cin, model);
		cout << "KOD		MARKA		MODEL		SERÝ		KM		RENK		FÝYAT" << endl;
		for (int i = 0; i < 1000; i++) {
			if (model == a[i].model) {
				cout << a[i].kod << "		" << a[i].marka << "		" << a[i].model << "		" << a[i].seri << "		" << a[i].km << "		" << a[i].renk << "		" << a[i].fiyat << endl;
				say++;
			}
			else
				cout << model << " modelde arac bulunmamaktadýr";
		}
		if (say != 0) {
			cout << say << " tane arac var" << endl << endl;
		}
		cout << "(1) bir onceki menu" << endl;
		cout << "(2) ana menu" << endl;
		cout << "(0) cýkýs" << endl;
		say = 0;
		cout << "secim yapiniz:";
		cin >> sec1;
		if (sec1 == 1) {
			bul();
		}
		if (sec1 == 2) {
			ana();
		}
		if (sec1 == 0) {
			cýkýs();
		}
	}
	if (sec == 4) {
		ana();
	}
	if (sec == 0) {
		return 0;
	}
}
void cýkýs() {
	return 0;
}
