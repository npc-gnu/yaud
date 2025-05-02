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
        cout << "[YAUD]: Warning! dd command can delete an entire drive. To close yaud, run sudo yaud --c ." << endl;
        return 1;
    }

    execvp("/bin/dd", argv);
    perror("execvp failed");
    return 1;
}
