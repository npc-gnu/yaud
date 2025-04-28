#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>  // geteuid() fonksiyonu için

const std::string status_file = "/tmp/yaud_status";

// Root kontrolü fonksiyonu
inline bool is_root() {
    return geteuid() == 0;
}

inline void show_help() {
    std::cout << "Yet Another User Defender (YAUD)" << std::endl;
    std::cout << "Kullanım: yaud [seçenekler]" << std::endl;
    std::cout << "  --a     YAUD'u ve uyarıları aktifleştir" << std::endl; 
    std::cout << "  --s     Durumu kontrol et (açık mı kapalı mı)" << std::endl;
    std::cout << "  --c     YAUD'u kapat (uyarıları devre dışı bırak)" << std::endl;
    std::cout << "  --h     Yardım menüsünü göster" << std::endl;
}

inline bool yaud_enabled() {
    std::ifstream f(status_file);
    return f.good();
}

#endif
