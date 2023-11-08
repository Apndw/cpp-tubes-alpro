#include <vector>
#include <iostream>

/**
 * Validasi untuk mengecek apakah program dijalankan di Windows atau Linux
 * Jika program dijalankan di Windows, maka akan menjalankan #include <conio.h>
 */
#ifdef _WIN32
  #include <conio.h>
#endif

/**
 * Import beberapa fungsi dari namespace std
 * std::cin = untuk mengambil inputan user
 * std::cout = untuk menampilkan output
 * std::endl = untuk membuat baris baru
 * std::vector = untuk membuat vector (array dinamis)
*/
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * @brief Membersihkan layar terminal (Windows & Linux)
 *
 * @return void
 */
void clearScreen(); // Deklarasi fungsi clearScreen

/**
 * @brief Pause program hingga user menekan tombol apapun
 *
 * @return void
 */
void pauseScreen(); // Deklarasi fungsi pauseScreen

/**
 * @brief Konversi suhu (celcius, fahrenheit, kelvin)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiSuhu(int *input, int *totalData, vector<float> *data, vector<float> *result); // Deklarasi fungsi konversiSuhu

/**
 * @brief Konversi panjang (kilometer, meter, centimeter)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiPanjang(int *input, int *totalData, vector<float> *data, vector<float> *result); // Deklarasi fungsi konversiPanjang

/**
 * @brief Konversi berat (gram, kilogram, ons)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiBerat(int *input, int *totalData, vector<float> *data, vector<float> *result); // Deklarasi fungsi konversiBerat

/**
 * @brief Main program
 *
 * @return int
 */
int main() {
  /**
   * Input = untuk menyimpan inputan user (pilihan menu)
   * totalData = untuk menyimpan jumlah data yang akan dikonversi
   */
  int input, totalData;

  /**
   * isOnRepeat = untuk menyimpan status program (true = program berjalan, false = program berhenti)
   */
  bool isOnRepeat = true;

  /**
   * data = untuk menyimpan data yang akan dikonversi
   * result = untuk menyimpan hasil konversi
   */
  vector<float> data, result;

  /**
   * Looping akan berjalan selama variable isOnRepeat = true
   * Ketika user memilih keluar, maka variable isOnRepeat akan diubah menjadi false
   * 
   * Pada perulangan ini kita menggunakan do while
   * Karena kita ingin menjalankan program terlebih dahulu sebelum melakukan pengecekan kondisi
   */
  do {
    cout << "Selamat datang di posion (pocket conversion)" << endl;
    cout << "1) Konversi Suhu" << endl;
    cout << "2) Konversi Panjang" << endl;
    cout << "3) Konversi Berat" << endl;
    cout << "4) Keluar" << endl;
    cout << "--------------------------------" << endl;

    cout << "Masukkan pilihan: ";
    cin >> input; // Menyimpan inputan user ke variable input

    clearScreen(); // Membersihkan layar terminal

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan fungsi konversi
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 3 karena pilihan 4 adalah untuk keluar (isOnRepeat = false)
     */
    switch (input) {
      case 1:
        // Mengirimkan alamat variable input, totalData, data, result ke fungsi konversiSuhu
        konversiSuhu(&input, &totalData, &data, &result);
        break;
      case 2:
        // Mengirimkan alamat variable input, totalData, data, result ke fungsi konversiPanjang
        konversiPanjang(&input, &totalData, &data, &result);
        break;
      case 3:
        // Mengirimkan alamat variable input, totalData, data, result ke fungsi konversiBerat
        konversiBerat(&input, &totalData, &data, &result);
        break;
      case 4:
        isOnRepeat = false; // Ketika user memilih keluar, variable isOnRepeat akan diubah menjadi false
        break;
      default:
        cout << "Pilihan tidak tersedia" << endl;
    }
  } while (isOnRepeat); // ketika variable isOnRepeat = false maka program akan berhenti

  cout << "Terima kasih telah menggunakan posion (pocket conversion)" << endl;

  return 0; // Keluar dari program dengan status 0 (berhasil)
}

/**
 * @brief Membersihkan layar terminal (Windows & Linux)
 *
 * @return void
 */
void clearScreen() {
  /**
   * #ifdef adalah preprocessor directive yang digunakan untuk mengecek apakah suatu macro sudah didefinisikan atau belum
   * #endif adalah untuk mengakhiri preprocessor directive 
   * 
   * #ifdef _WIN32 adalah untuk mengecek apakah program dijalankan di Windows atau tidak
   * Jika program dijalankan di Windows, maka akan menjalankan system("cls")
   * Jika program dijalankan di Linux, maka akan menjalankan system("clear")
   * system("cls") digunakan untuk membersihkan layar terminal di Windows
   * system("clear") digunakan untuk membersihkan layar terminal di Linux
   */
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

/**
 * @brief Pause program hingga user menekan tombol apapun
 *
 * @return void
 */
void pauseScreen() {
  cout << "Tekan tombol apapun untuk melanjutkan..." << endl;

  /**
   * #ifdef adalah preprocessor directive yang digunakan untuk mengecek apakah suatu macro sudah didefinisikan atau belum
   * #endif adalah untuk mengakhiri preprocessor directive 
   * 
   * #ifdef _WIN32 adalah untuk mengecek apakah program dijalankan di Windows atau tidak
   * Jika program dijalankan di Windows, maka akan menjalankan getch()
   * Jika program dijalankan di Linux, maka akan menjalankan system("read -n 1 -s -p \"\"")
   * getch() adalah fungsi untuk mengambil inputan user tanpa menampilkan inputan user
   * system("read -n 1 -s -p \"\"") adalah perintah untuk mengambil inputan user tanpa menampilkan inputan user
   */
  #ifdef _WIN32
    /**
     * getch() adalah fungsi untuk mengambil inputan user tanpa menampilkan inputan user
     * Pada kasus ini kita hanya membutuhkan inputan user untuk melanjutkan program
     */
    getch();
  #else
    /**
     * read -n 1 -s -p "" adalah perintah untuk mengambil inputan user tanpa menampilkan inputan user
     * Pada kasus ini kita hanya membutuhkan inputan user untuk melanjutkan program
     */
    system("read -n 1 -s -p \"\"");
  #endif

  clearScreen(); // Membersihkan layar terminal
}

/**
 * @brief Konversi suhu (celcius, fahrenheit, kelvin)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiSuhu(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  /**
   * Looping akan berjalan selama true (selama program berjalan)
   * Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
   * Untuk kembali ke menu utama cukup dengan break untuk menghentikan looping
   */
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
    cin >> *input; // Menyimpan inputan user ke variable input dengan pointer

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 7) break;

    cout << "Masukan jumlah data suhu yang akan dikonversi: ";
    cin >> *totalData; // Menyimpan inputan user ke variable totalData dengan pointer

    // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
    (*totalData > 1) ? data->resize(*totalData) : data->resize(1);

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi suhu
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 6 karena pilihan 7 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam celcius: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] * 9 / 5) + 32);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " C = " << (*result)[i] << " F" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam celcius: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] + 273.15);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " C = " << (*result)[i] << " K" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam fahrenheit: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] - 32) * 5 / 9);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " F = " << (*result)[i] << " C" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam fahrenheit: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] - 32) * 5 / 9 + 273.15);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " F = " << (*result)[i] << " K" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam kelvin: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] - 273.15);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " K = " << (*result)[i] << " C" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan suhu ke-" << i + 1 << " dalam kelvin: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] - 273.15) * 9 / 5 + 32);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " K = " << (*result)[i] << " F" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Konversi panjang (kilometer, meter, centimeter)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiPanjang(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  /**
   * Looping akan berjalan selama true (selama program berjalan)
   * Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
   * Untuk kembali ke menu utama cukup dengan break untuk menghentikan looping
   */
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
    cin >> *input; // Menyimpan inputan user ke variable input dengan pointer

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 7) break;

    cout << "Masukan jumlah data panjang yang akan dikonversi: ";
    cin >> *totalData; // Menyimpan inputan user ke variable totalData dengan pointer

    // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
    (*totalData > 1) ? data->resize(*totalData) : data->resize(1);

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi panjang
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 6 karena pilihan 7 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam kilometer: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++){
          cout << (*data)[i] << " km = " << (*result)[i] << " m" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam kilometer: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 100000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " km = " << (*result)[i] << " cm" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam meter: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " m = " << (*result)[i] << " km" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam meter: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 100);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " m = " << (*result)[i] << " cm" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam centimeter: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 100000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " cm = " << (*result)[i] << " km" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan panjang ke-" << i + 1 << " dalam centimeter: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 100);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " cm = " << (*result)[i] << " m" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}

/**
 * @brief Konversi berat (gram, kilogram, ons)
 *
 * @param input pointer untuk menyimpan inputan user - integer
 * @param totalData pointer untuk menyimpan jumlah data yang akan dikonversi - integer
 * @param data pointer untuk menyimpan data yang akan dikonversi - vector<float>
 * @param result pointer untuk menyimpan hasil konversi - vector<float>
 *
 * @return void
 */
void konversiBerat(int *input, int *totalData, vector<float> *data, vector<float> *result) {
  /**
   * Looping akan berjalan selama true (selama program berjalan)
   * Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
   * Untuk kembali ke menu utama cukup dengan break untuk menghentikan looping
   */
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
    cin >> *input; // Menyimpan inputan user ke variable input dengan pointer

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 7) break;

    cout << "Masukan jumlah data berat yang akan dikonversi: ";
    cin >> *totalData; // Menyimpan inputan user ke variable totalData dengan pointer

    // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
    (*totalData > 1) ? data->resize(*totalData) : data->resize(1);

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi suhu
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 6 karena pilihan 7 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam gram: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " g = " << (*result)[i] << " kg" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam gram: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 10);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " g = " << (*result)[i] << " ons" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam kilogram: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " kg = " << (*result)[i] << " g" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam kilogram: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 10);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " kg = " << (*result)[i] << " ons" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam ons: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 100);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " ons = " << (*result)[i] << " g" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          cout << "Masukan berat ke-" << i + 1 << " dalam ons: ";
          cin >> (*data)[i]; // (*data) yaitu untuk mengambil data dari pointer data

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 10);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " ons = " << (*result)[i] << " kg" << endl;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}