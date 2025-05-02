#include <iostream>
#include <fstream>
#include <cstdio>  // remove fonksiyonu için
#include <unistd.h>  // getuid() fonksiyonu için
#include "helper.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Root control
    if (getuid() != 0) {
        cerr << "This app can only run with sudo!" << endl;
        return 1;  // error
    }

    if (argc < 2) {
        cerr << "Not enough arguments. To get help, run yaud --h ." << endl;
        return 1;
    }

    string arg = argv[1];

    if (arg == "--s") {
        if (yaud_enabled()) {
            cout << "[YAUD]: Active." << endl;
        } else {
            cout << "[YAUD]: Inactive/Dead." << endl;
        }
    } else if (arg == "--c") {
        if (remove(status_file.c_str()) == 0) {
            cout << "[YAUD]: Closed." << endl;
        } else {
            cerr << "[YAUD]: Can't close. Error." << endl;
        }
    } else if (arg == "--a") {
        ofstream status(status_file);
        status << "active";  // YAUD'u aktif hale getir
        status.close();
        cout << "[YAUD]: Aktivasyon tamamlandı. Uyarılar başlatıldı." << endl;
    } else if (arg == "--h") {
        show_help();
    } else {
        cerr << "Geçersiz argüman. --h ile yardım alabilirsin." << endl;
        return 1;
    }
    return 0;
}

