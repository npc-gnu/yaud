#include <iostream>
#include <string>  // string türünü kullanmak için
#include <unistd.h>
#include "helper.hpp"

using namespace std;

bool is_dangerous(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];  // string kullanabilmek için gerekli
        if (arg == "/" || arg == "/proc" || arg == "/sys" || arg == "/home" || arg == "/boot") {
            return true;
        }
        if (arg.find("/dev/sd") != string::npos || arg.find("/dev/nvme") != string::npos) {
            return true;
        }
        if (arg.find("UUID=") != string::npos || arg.find("LABEL=") != string::npos) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (yaud_enabled() && is_dangerous(argc, argv)) {
        cout << "[YAUD]: Uyarı! umount komutu kritik bir dizini çıkarmaya çalışıyor. Uyarıyı/YAUD'u kapamak için yaud --c komutunu kullanın." << endl;
        return 1;
    }

    execvp("/bin/umount", argv);
    perror("execvp failed");
    return 1;
}
