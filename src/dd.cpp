// src/dd.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include "helper.hpp"

using namespace std;

bool is_dangerous(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg.find("/dev/sd") != string::npos || arg.find("/dev/nvme") != string::npos) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (yaud_enabled() && is_dangerous(argc, argv)) {
        cout << "[YAUD]: Uyarı! dd komutu bir sürücüyü silebilir. Uyarıyı/YAUD'u kapamak için yaud --c komtunu kullanın." << endl;
        return 1;
    }

    execvp("/bin/dd", argv);
    perror("execvp failed");
    return 1;
}
