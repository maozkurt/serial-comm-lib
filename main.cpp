#include "i2c.hpp"

int main(){  
    auto a = i2c::device(0,0x08);
    a.test();
    
    uint8_t reg2access = 0x01;
    int64_t ret;
    ret = a.read(reg2access);
    a.write(reg2access, 0x2A);
    std::cout  << std::hex << (int)ret << std::endl;
}