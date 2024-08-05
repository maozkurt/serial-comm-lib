#include "uart.hpp"

int main(){
    // int port = open("/dev/pts/3", O_RDWR);
    // if(port < 0){
    //     std::cerr << "Error " << errno << "opening\n" << strerror(errno) << std::endl;
    // }
    
    // I don't know if we have to be async-signal-safe, will find out soon enough.
    std::fstream f;
    try{f.open("/dev/pts/4", std::fstream::out | std::fstream::in);} catch(...){ std::cerr << "AAA\n";}
    f << "cpp test" << std::endl << std::flush;
    std::string inp;
    f >> inp;
    std::cout << "READ: " << inp << std::endl;
}