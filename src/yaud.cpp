#include <iostream>
#include <fstream>
#include <cstdio>  // remove fonksiyonu için
#include <unistd.h>  // getuid() fonksiyonu için
#include "helper.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Root kontrolü
    if (getuid() != 0) {
        cerr << "Bu program yalnızca root olarak çalıştırılabilir!" << endl;
        return 1;  // Hata kodu döndürerek çıkış yap
    }

    if (argc < 2) {
        cerr << "Bir argüman girmen gerekiyor. --h ile yardım alabilirsin." << endl;
        return 1;
    }

    string arg = argv[1];

    if (arg == "--s") {
        if (yaud_enabled()) {
            cout << "[YAUD]: Aktif durumda." << endl;
        } else {
            cout << "[YAUD]: Pasif durumda." << endl;
        }
    } else if (arg == "--c") {
        if (remove(status_file.c_str()) == 0) {
            cout << "[YAUD]: Kapatıldı." << endl;
        } else {
            cerr << "[YAUD]: Kapatılamadı. Hata oluştu." << endl;
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

