# serial-comm-lib
## i2c
### Required package
```
i2c-tools
```
### Virtual i2c device
```
sudo modprobe i2c-stub chip_addr=0x08
i2cdetect -l
```
Get i2c device number (0 below)
```
sudo i2cset -y 0 0x08 0x01 0x2A
sudo i2cdump -y -r 0-7 0 0x08 b
```

### Compilation
```
g++ -Wall -Wextra -li2c main.cpp i2c.cpp
```
### Running
```
sudo ./a.out
```