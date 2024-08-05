#ifndef SCL_UART_HPP
#define SCL_UART_HPP

#include <iostream>
#include <string>
#include <fstream>

extern "C"{
    #include <fcntl.h>
    #include <errno.h>
    #include <cstring>
}

namespace uart {
    class device {
        private:
        std::string path = "";
        std::fstream file;

        public:
        device(std::string path){
            this->path = path;
            
            file.open(path, std::fstream::in | std::fstream::out);
        }
    };
}

#endif