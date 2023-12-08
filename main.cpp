#include <string> // Import library string yaitu untuk menggunakan tipe data string
#include <vector> // Import library vector yaitu array dinamis (ukuran array dapat diubah)
#include <iostream> // Import library iostream yaitu untuk input dan output

/**
 * Validasi untuk mengecek apakah program dijalankan di Windows atau Linux
 * Jika program dijalankan di Windows, maka akan menjalankan #include <conio.h>
 */
#ifdef _WIN32
  #include <conio.h> // Import library conio.h yaitu untuk getch() (mengambil inputan user tanpa menampilkan inputan user)
#endif

/**
 * Import beberapa fungsi dari namespace std
 * std::cin = untuk mengambil inputan user
 * std::cout = untuk menampilkan output
 * std::endl = untuk membuat baris baru
 * std::string = untuk membuat string
 * std::vector = untuk membuat vector (array dinamis)
 * std::to_string = untuk mengubah tipe data apapun menjadi string
*/
using std::cin; // Menggunakan std::cin
using std::cout; // Menggunakan std::cout
using std::endl; // Menggunakan std::endl
using std::string; // Menggunakan std::string
using std::vector; // Menggunakan std::vector
using std::to_string; // Menggunakan std::to_string

/**
 * @brief Deklarasi variable global
 * 
 * indexResult = untuk menyimpan index result
 * indexResult digunakan untuk menampilkan hasil konversi
 * indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
 * indexResult = 0 karena indexResult akan direset ketika program dijalankan
 */
int indexResult = 0;

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
 * @brief Mengambil inputan user dan mengembalikan nilai inputan user
 * 
 * @param message pesan yang akan ditampilkan ke user - string
 * 
 * @return int
 */
int inputData(string message);

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

    input = inputData("Masukkan pilihan: "); // Mengambil inputan user dan menyimpannya ke variable input

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
 * @brief Mengambil inputan user dan mengembalikan nilai inputan user
 * 
 * @param message pesan yang akan ditampilkan ke user - string
 * 
 * @return int
 */
int inputData(string message) {
  /**
   * Deklarasi variable input
   * Variable bersifat lokal karena dideklarasikan di dalam fungsi
   * Variable input akan menyimpan hasil inputan user
   */
  int input;

  // Menampilkan pesan yang diberikan ke user
  cout << message;

  // Mengambil inputan user dan menyimpannya ke variable input
  cin >> input;

  // Mengembalikan nilai input
  return input;
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

    *input = inputData("Masukkan pilihan: "); // Mengambil inputan user dan menyimpannya ke variable input dengan pointer

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 7) break;
    else if (*input > 0 && *input < 7) {
      // Mengambil inputan user dan menyimpannya ke variable totalData dengan pointer
      *totalData = inputData("Masukan jumlah data suhu yang akan dikonversi2: ");

      // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
      (*totalData > 1) ? data->resize(*totalData) : data->resize(1);
    }

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
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan suhu ke-" + to_string(i + 1) + " dalam celcius: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] * 9 / 5) + 32);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " C = " << (*result)[indexResult] << " F" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan suhu ke-" + to_string(i + 1) + " dalam celcius: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] + 273.15);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " C = " << (*result)[indexResult] << " K" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan suhu ke-" + to_string(i + 1) + " dalam fahrenheit: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] - 32) * 5 / 9);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " F = " << (*result)[indexResult] << " C" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan suhu ke-" + to_string(i + 1) + " dalam fahrenheit: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] - 32) * 5 / 9 + 273.15);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " F = " << (*result)[indexResult] << " K" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan suhu ke-" + to_string(i + 1) + " dalam kelvin: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] - 273.15);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " K = " << (*result)[indexResult] << " C" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan suhu ke-" + to_string(i + 1) + " dalam kelvin: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back(((*data)[i] - 273.15) * 9 / 5 + 32);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " K = " << (*result)[indexResult] << " F" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
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

    // Mengambil inputan user dan menyimpannya ke variable input dengan pointer
    *input = inputData("Masukkan pilihan: ");

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 7) break;
    else if (*input > 0 && *input < 7) {
      // Mengambil inputan user dan menyimpannya ke variable totalData dengan pointer
      *totalData = inputData("Masukan jumlah data panjang yang akan dikonversi2: ");

      // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
      (*totalData > 1) ? data->resize(*totalData) : data->resize(1);
    }

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
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan panjang ke-" + to_string(i + 1) + " dalam kilometer: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++){
          cout << (*data)[i] << " km = " << (*result)[indexResult] << " m" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan panjang ke-" + to_string(i + 1) + " dalam kilometer: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 100000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " km = " << (*result)[indexResult] << " cm" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan panjang ke-" + to_string(i + 1) + " dalam meter: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " m = " << (*result)[indexResult] << " km" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan panjang ke-" + to_string(i + 1) + " dalam meter: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 100);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " m = " << (*result)[indexResult] << " cm" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan panjang ke-" + to_string(i + 1) + " dalam centimeter: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 100000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " cm = " << (*result)[indexResult] << " km" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan panjang ke-" + to_string(i + 1) + " dalam centimeter: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 100);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " cm = " << (*result)[indexResult] << " m" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
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

    // Mengambil inputan user dan menyimpannya ke variable input dengan pointer
    *input = inputData("Masukkan pilihan: ");

    clearScreen(); // Membersihkan layar terminal

    // Ketika user memilih kembali, maka program akan berhenti dan kembali ke menu utama
    if (*input == 7) break;
    else if (*input > 0 && *input < 7) {
      // Mengambil inputan user dan menyimpannya ke variable totalData dengan pointer
      *totalData = inputData("Masukan jumlah data berat yang akan dikonversi2: ");

      // resize adalah fungsi untuk mengubah ukuran vector atau panjang array
      (*totalData > 1) ? data->resize(*totalData) : data->resize(1);
    }

    /**
     * Percabangan untuk menentukan pilihan user
     * Ketika user memilih pilihan yang tersedia, maka program akan menjalankan konversi berat
     * Ketika user memilih pilihan yang tidak tersedia, maka program akan menampilkan pesan "Pilihan tidak tersedia"
     * Range pilihan hanya 1 - 6 karena pilihan 7 adalah untuk kembali ke menu utama (break)
     */
    switch (*input) {
      case 1:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan berat ke-" + to_string(i + 1) + " dalam gram: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " g = " << (*result)[indexResult] << " kg" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 2:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan berat ke-" + to_string(i + 1) + " dalam gram: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 10);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " g = " << (*result)[indexResult] << " ons" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 3:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan berat ke-" + to_string(i + 1) + " dalam kilogram: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 1000);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " kg = " << (*result)[indexResult] << " g" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 4:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan berat ke-" + to_string(i + 1) + " dalam kilogram: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 10);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " kg = " << (*result)[indexResult] << " ons" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 5:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan berat ke-" + to_string(i + 1) + " dalam ons: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] * 100);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " ons = " << (*result)[indexResult] << " g" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      case 6:
        // Looping sebanyak totalData untuk mengambil inputan user
        for (int i = 0; i < *totalData; i++) {
          // (*data) yaitu untuk mengambil data dari pointer data
          (*data)[i] = inputData("Masukan berat ke-" + to_string(i + 1) + " dalam ons: ");

          // tidak menggunakan tanda * karena data adalah pointer
          result->push_back((*data)[i] / 10);
        }

        clearScreen(); // Membersihkan layar terminal
        cout << "Hasil konversi: " << endl;

        // Looping sebanyak totalData untuk menampilkan hasil konversi
        for (int i = 0; i < *totalData; i++) {
          cout << (*data)[i] << " ons = " << (*result)[indexResult] << " kg" << endl;

          // indexResult++ digunakan untuk menambahkan indexResult sebanyak 1
          indexResult++;
        }

        pauseScreen(); // Pause program hingga user menekan tombol apapun
        break;
      default:
        // Ketika user memilih pilihan yang tidak tersedia
        cout << "Pilihan tidak tersedia" << endl;
    }
  }
}