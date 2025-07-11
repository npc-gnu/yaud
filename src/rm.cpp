// src/rm.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <filesystem>
#include "helper.hpp"

using namespace std;
namespace fs = std::filesystem;

bool is_dangerous(int argc, char* argv[]) {
    string full_cmd;
    for (int i = 1; i < argc; ++i) {
        full_cmd += string(argv[i]) + " ";
    }

    if (full_cmd.find("-rf /") != string::npos || full_cmd.find("-rf /*") != string::npos ||
        full_cmd.find("-rf /var") != string::npos) {
        return true;
    }

    string cwd = fs::current_path();
    if (cwd == "/" || cwd == "/etc" || cwd == "/root" || cwd == "/boot") {
        return true;
    }

    return false;
}

int main(int argc, char* argv[]) {
    if (yaud_enabled() && is_dangerous(argc, argv)) {
        cout << "[YAUD]: Warning! rm command can delete important OS datas and corrupt system in dangerous directorys." << endl;
        cout << "[YAUD]: To close yaud, run yaud --c ." << endl;
        return 1;
    }

    execvp("/bin/rm", argv);
    perror("execvp failed");
    return 1;
}
