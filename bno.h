// values
#define BNO055_BAUD 115200
#define BNO055_PORT i2c0
#define BNO055_ID 0x28

// operational mode
#define BNO055_OPR_MODE 0x3D
#define BNO055_ACCONLY 0x01

// reset IMU 
#define BNO055_SYS_TRIGGER 0x3F
#define BNO055_RST_INT 0x40

// start of accel data
#define BNO055_ACC_DATA_X_LSB 0x08


// pins
#define BNO055_SDA 0
#define BNO055_SCK 1

// functions

// hey lets initiilize  
void bno055_init();

// read data from acc
void bno055_read_acc();

