#include <vector>
#include <conio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * @brief Clear screen terminal support windows and linux based
 * 
 * @return void
*/
void clearScreen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

/**
 * @brief Pause program until user press any key
 * 
 * @return void
*/
void pause() {
  cout << "Tekan tombol apapun untuk melanjutkan..." << endl;
  getch();
  clearScreen();
}

/**
 * @brief Konversi suhu
 * 
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 * 
 * @return void
*/
void konversiSuhu(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  while (true) {
    cout << "Konversi Suhu" << endl;
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

    clearScreen();

    if (*input == 7) {
      return;
    }

    cout << "Masukan jumlah data suhu yang akan dikonversi: ";
    cin >> *totalData;

    (*totalData > 1) ? data->resize(*totalData) : data->resize(1);

    switch (*input) {
      case 1:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam celcius: ";
          cin >> (*data)[i];

          result->push_back(((*data)[i] * 9 / 5) + 32);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " C = " << (*result)[i] << " F" << endl;
        }

        pause();
        break;
      case 2:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam celcius: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] + 273.15);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " C = " << (*result)[i] << " K" << endl;
        }

        pause();
        break;
      case 3:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam fahrenheit: ";
          cin >> (*data)[i];

          result->push_back(((*data)[i] - 32) * 5 / 9);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " F = " << (*result)[i] << " C" << endl;
        }

        pause();
        break;
      case 4:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam fahrenheit: ";
          cin >> (*data)[i];

          result->push_back(((*data)[i] - 32) * 5 / 9 + 273.15);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " F = " << (*result)[i] << " K" << endl;
        }

        pause();
        break;
      case 5:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam kelvin: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] - 273.15);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " K = " << (*result)[i] << " C" << endl;
        }

        pause();
        break;
      case 6:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam kelvin: ";
          cin >> (*data)[i];

          result->push_back(((*data)[i] - 273.15) * 9 / 5 + 32);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " K = " << (*result)[i] << " F" << endl;
        }

        pause();
        break;
      case 7:
        clearScreen();
        return;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Konversi panjang
 * 
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 * 
 * @return void
*/
void konversiPanjang(int *input, int *totalData, vector<float> *data, vector<float> *result) {
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

    clearScreen();

    if (*input == 7) {
      return;
    }
    
    cout << "Masukan jumlah data panjang yang akan dikonversi: ";
    cin >> *totalData;

    (*totalData > 1) ? data->resize(*totalData) : data->resize(1);

    switch (*input) {
      case 1:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam kilometer: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] * 1000);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " km = " << (*result)[i] << " m" << endl;
        }

        pause();
        break;
      case 2:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam kilometer: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] * 100000);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " km = " << (*result)[i] << " cm" << endl;
        }

        pause();
        break;
      case 3:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam meter: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] / 1000);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " m = " << (*result)[i] << " km" << endl;
        }

        pause();
        break;
      case 4:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam meter: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] * 100);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " m = " << (*result)[i] << " cm" << endl;
        }

        pause();
        break;
      case 5:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam centimeter: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] / 100000);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " cm = " << (*result)[i] << " km" << endl;
        }

        pause();
        break;
      case 6:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam centimeter: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] / 100);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " cm = " << (*result)[i] << " m" << endl;
        }

        pause();
        break;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Konversi berat
 * 
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 * 
 * @return void
*/
void konversiBerat(int *input, int *totalData, vector<float> *data, vector<float> *result) {
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

    clearScreen();

    if (*input == 7) {
      return;
    }

    cout << "Masukan jumlah data berat yang akan dikonversi: ";
    cin >> *totalData;

    (*totalData > 1) ? data->resize(*totalData) : data->resize(1);

    switch (*input) {
      case 1:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam gram: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] / 1000);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) { 
          cout << (*data)[i] << " g = " << (*result)[i] << " kg" << endl;
        }

        pause();
        break;
      case 2:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam gram: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] / 10);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) { 
          cout << (*data)[i] << " g = " << (*result)[i] << " ons" << endl;
        }

        pause();
        break;
      case 3:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam kilogram: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] * 1000);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) { 
          cout << (*data)[i] << " kg = " << (*result)[i] << " g" << endl;
        }

        pause();
        break;
      case 4:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam kilogram: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] * 10);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) { 
          cout << (*data)[i] << " kg = " << (*result)[i] << " ons" << endl;
        }

        pause();
        break;
      case 5:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam ons: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] * 100);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) { 
          cout << (*data)[i] << " ons = " << (*result)[i] << " g" << endl;
        }

        pause();
        break;
      case 6:
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam ons: ";
          cin >> (*data)[i];

          result->push_back((*data)[i] / 10);
        }

        clearScreen();

        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < *totalData; i++) { 
          cout << (*data)[i] << " ons = " << (*result)[i] << " kg" << endl;
        }

        pause();
        break;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Main program
 * 
 * @return int
*/
int main() {
  int input, totalData;
  bool isOnRepeat = true;
  vector<float> data, result;

  do {
    cout << "Selamat datang di posion (pocket conversion)" << endl;
    cout << "1) Konversi Suhu" << endl;
    cout << "2) Konversi Panjang" << endl;
    cout << "3) Konversi Berat" << endl;
    cout << "4) Keluar" << endl;
    cout << "--------------------------------" << endl;

    cout << "Masukkan pilihan: ";
    cin >> input;

    clearScreen();

    switch (input) {
      case 1:
        konversiSuhu(&input, &totalData, &data, &result);
        break;
      case 2:
        konversiPanjang(&input, &totalData, &data, &result);
        break;
      case 3:
        konversiBerat(&input, &totalData, &data, &result);
        break;
      case 4:
        isOnRepeat = false;
        break;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  } while (isOnRepeat);

  cout << "Terima kasih telah menggunakan posion (pocket conversion)" << endl;

  return 0;
}