#include "i2c.hpp"

int main(){  
    auto a = i2c::device(0,0x08);
    a.test();
    
    uint8_t reg2access = 0x01;
    int64_t ret;
    ret = i2c_smbus_read_word_data(a.getfileno(), reg2access);
    //ret = i2c_smbus_write_word_data(a.getfileno(), reg2access,0x3A);
    std::cout  << std::hex << (int)ret << std::endl;
    if(ret < 0){
        std::cerr << "Error in i2c transaction" << std::endl;
    }
    
}