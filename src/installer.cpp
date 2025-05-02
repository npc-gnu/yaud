// src/installer.cpp
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

int main() {
    cout << "[YAUD Installer]: Installer starting..." << endl;

    fs::copy("yaud", "/usr/local/bin/yaud", fs::copy_options::overwrite_existing);
    fs::copy("rm", "/usr/local/bin/rm", fs::copy_options::overwrite_existing);
    fs::copy("dd", "/usr/local/bin/dd", fs::copy_options::overwrite_existing);
    fs::copy("umount", "/usr/local/bin/umount", fs::copy_options::overwrite_existing);
    fs::copy("mkfs", "/usr/local/bin/mkfs", fs::copy_options::overwrite_existing); // yeni eklendi

    // YAUD'u başlangıçta kapalı olarak kuruyoruz
    ofstream status("/tmp/yaud_status");
    status << "inactive";  // Not active when installed
    status.close();

    cout << "[YAUD Installer]: Installation completed. Yaud is not active. To active yaud, run yaud --a ." << endl;
    return 0;
}
