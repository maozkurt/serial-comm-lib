/*
    First implementation for i2c.
    Assumes i2c device is on /dev/i2c-0,
            device adress is 0x08,
            register to be read is 0x01.

*/
#include "i2c.hpp"


i2c::device::device(int i2cdeviceno,int deviceaddress){
    i2cfilepath.append(std::to_string(i2cdeviceno));
    this->deviceaddress = deviceaddress;
    
    this->fileno = open(i2cfilepath.c_str(), O_RDWR);
    if(fileno < 0){
        std::cerr << "Error while opening " <<  i2cfilepath << std::endl;
        exit(1);
    }
    if(ioctl(this->fileno, I2C_SLAVE, deviceaddress) < 0){
        std::cerr << "Error" << std::endl;
    }
}

i2c::device::~device(){

}

int main(){
    // Using open to be async-signal-safe
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