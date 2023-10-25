#include <conio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::pair;

void pause() {
  cout << "Tekan tombol apapun untuk melanjutkan..." << endl;
  getch();
}

void konversiSuhu(int *input) {
  float suhu, hasil;

  while (true) {
    cout << "--------------------------------" << endl;
    cout << "1) Celcius ke Fahrenheit" << endl;
    cout << "2) Celcius ke Kelvin" << endl;
    cout << "3) Fahrenheit ke Celcius" << endl;
    cout << "4) Fahrenheit ke Kelvin" << endl;
    cout << "5) Kelvin ke Celcius" << endl;
    cout << "6) Kelvin ke Fahrenheit" << endl;
    cout << "7) Kembali" << endl;
    cout << "--------------------------------" << endl;

    cout << "Masukkan pilihan: ";
    cin >> *input;

    switch (*input) {
      case 1:
        cout << "Masukan suhu dalam celcius: ";
        cin >> suhu;

        hasil = (suhu * 9 / 5) + 32;
        cout << "Hasil konversi: " << hasil << " F" << endl;

        pause();
        break;
      case 2:
        cout << "Masukan suhu dalam celcius: ";
        cin >> suhu;

        hasil = suhu + 273.15;
        cout << "Hasil konversi: " << hasil << " K" << endl;
        
        pause();
        break;
      case 3:
        cout << "Masukan suhu dalam fahrenheit: ";
        cin >> suhu;

        hasil = (suhu - 32) * 5 / 9;
        cout << "Hasil konversi: " << hasil << " C" << endl;
        
        pause();
        break;
      case 4:
        cout << "Masukan suhu dalam fahrenheit: ";
        cin >> suhu;

        hasil = (suhu - 32) * 5 / 9 + 273.15;
        cout << "Hasil konversi: " << hasil << " K" << endl;
        
        pause();
        break;
      case 5:
        cout << "Masukan suhu dalam kelvin: ";
        cin >> suhu;

        hasil = suhu - 273.15;
        cout << "Hasil konversi: " << hasil << " C" << endl;
        
        pause();
        break;
      case 6:
        cout << "Masukan suhu dalam kelvin: ";
        cin >> suhu;

        hasil = (suhu - 273.15) * 9 / 5 + 32;
        cout << "Hasil konversi: " << hasil << " F" << endl;

        pause();
        break;
      case 7:
        return;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

void konversiPanjang(int *input) {
  float panjang, hasil;

  while (true) {
    cout << "--------------------------------" << endl;
    cout << "1) Kilometer ke Meter" << endl;
    cout << "2) Kilometer ke Centimeter" << endl;
    cout << "3) Meter ke Kilometer" << endl;
    cout << "4) Meter ke Centimeter" << endl;
    cout << "5) Centimeter ke Kilometer" << endl;
    cout << "6) Centimeter ke Meter" << endl;
    cout << "7) Kembali" << endl;
    cout << "--------------------------------" << endl;

    cout << "Masukkan pilihan: ";
    cin >> *input;

    switch (*input) {
      case 1:
        cout << "Masukan panjang dalam kilometer: ";
        cin >> panjang;

        hasil = panjang * 1000;
        cout << "Hasil konversi: " << hasil << " m" << endl;
        
        pause();
        break;
      case 2:
        cout << "Masukan panjang dalam kilometer: ";
        cin >> panjang;

        hasil = panjang * 100000;
        cout << "Hasil konversi: " << hasil << " cm" << endl;
        
        pause();
        break;
      case 3:
        cout << "Masukan panjang dalam meter: ";
        cin >> panjang;

        hasil = panjang / 1000;
        cout << "Hasil konversi: " << hasil << " km" << endl;
        
        pause();
        break;
      case 4:
        cout << "Masukan panjang dalam meter: ";
        cin >> panjang;

        hasil = panjang * 100;
        cout << "Hasil konversi: " << hasil << " cm" << endl;
        
        pause();
        break;
      case 5:
        cout << "Masukan panjang dalam centimeter: ";
        cin >> panjang;

        hasil = panjang / 100000;
        cout << "Hasil konversi: " << hasil << " km" << endl;
        
        pause();
        break;
      case 6:
        cout << "Masukan panjang dalam centimeter: ";
        cin >> panjang;

        hasil = panjang / 100;
        cout << "Hasil konversi: " << hasil << " m" << endl;
        
        pause();
        break;
      case 7:
        return;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

void konversiBerat(int *input) {
  float berat, hasil;

  while (true) {
    cout << "--------------------------------" << endl;
    cout << "1) Gram ke Kilogram" << endl;
    cout << "2) Gram ke Ons" << endl;
    cout << "3) Kilogram ke Gram" << endl;
    cout << "4) Kilogram ke Ons" << endl;
    cout << "5) Ons ke Gram" << endl;
    cout << "6) Ons ke Kilogram" << endl;
    cout << "7) Kembali" << endl;
    cout << "--------------------------------" << endl;	

    cout << "Masukkan pilihan: ";
    cin >> *input;

    switch (*input) {
      case 1:
        cout << "Masukan berat dalam gram: ";
        cin >> berat;

        hasil = berat / 1000;
        cout << "Hasil konversi: " << hasil << " kg" << endl;
        
        pause();
        break;
      case 2:
        cout << "Masukan berat dalam gram: ";
        cin >> berat;

        hasil = berat / 100;
        cout << "Hasil konversi: " << hasil << " ons" << endl;
        
        pause();
        break;
      case 3:
        cout << "Masukan berat dalam kilogram: ";
        cin >> berat;

        hasil = berat * 1000;
        cout << "Hasil konversi: " << hasil << " g" << endl;
        
        pause();
        break;
      case 4:
        cout << "Masukan berat dalam kilogram: ";
        cin >> berat;

        hasil = berat * 10;
        cout << "Hasil konversi: " << hasil << " ons" << endl;
        
        pause();
        break;
      case 5:
        cout << "Masukan berat dalam ons: ";
        cin >> berat;

        hasil = berat * 100;
        cout << "Hasil konversi: " << hasil << " g" << endl;
        
        pause();
        break;
      case 6:
        cout << "Masukan berat dalam ons: ";
        cin >> berat;

        hasil = berat / 10;
        cout << "Hasil konversi: " << hasil << " kg" << endl;
        
        pause();
        break;
      case 7:
        return;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

int main() {
  int input;
  bool isOnRepeat = true;

  while (isOnRepeat) {
    cout << "Selamat datang di posion (pocket conversion)" << endl;
    cout << "1) Konversi Suhu" << endl;
    cout << "2) Konversi Panjang" << endl;
    cout << "3) Konversi Berat" << endl;
    cout << "4) Keluar" << endl;
    cout << "--------------------------------" << endl;

    cout << "Masukkan pilihan: ";
    cin >> input;

    switch (input) {
      case 1:
        konversiSuhu(&input);
        break;
      case 2:
        konversiPanjang(&input);
        break;
      case 3:
        konversiBerat(&input);
        break;
      case 4:
        isOnRepeat = false;
        break;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }

  cout << "Terima kasih telah menggunakan posion (pocket conversion)" << endl;

  return 0;
}