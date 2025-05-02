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
    std::cout << "How to use: yaud 'option' ." << std::endl;
    std::cout << "  --a     Activate yaud." << std::endl; 
    std::cout << "  --s     Show it is active or dead." << std::endl;
    std::cout << "  --c     close yaud." << std::endl;
    std::cout << "  --h     Show help menu." << std::endl;
}

inline bool yaud_enabled() {
    std::ifstream f(status_file);
    return f.good();
}

#endif
