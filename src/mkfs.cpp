// src/mkfs.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include "helper.hpp"

using namespace std;

bool is_dangerous(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        // Tehlikeli aygıt yollarını kontrol et
        if (arg.find("/dev/sd") != string::npos || arg.find("/dev/nvme") != string::npos) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (yaud_enabled() && is_dangerous(argc, argv)) {
        cout << "[YAUD]: Uyarı! mkfs komutu bir diski biçimlendirir ve içindeki her şeyi siler!" << endl;
        cout << "YAUD'u/uyarıyı kapamak için yaud --c komutunu kullanın." << endl;
        return 1;
    }

    execvp("/bin/mkfs", argv); // Gerçek mkfs komutu çalıştırılıyor
    perror("execvp failed");
    return 1;
}
