// src/mkfs.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include "helper.hpp"

using namespace std;

bool is_dangerous(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        // Look out for dangerous drives
        if (arg.find("/dev/sd") != string::npos || arg.find("/dev/nvme") != string::npos) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (yaud_enabled() && is_dangerous(argc, argv)) {
        cout << "[YAUD]: Warning! mkfs command can format an entire drive end delete datas in it." << endl;
        cout << "To close yaud, run yaud --c ." << endl;
        return 1;
    }

    execvp("/bin/mkfs", argv); // Gerçek mkfs komutu çalıştırılıyor
    perror("execvp failed");
    return 1;
}
