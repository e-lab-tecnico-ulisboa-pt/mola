//
// hidrostat.c
//
#define LED1_TRIS _TRISB4
#define LED1 _LATB4
#define LED2_TRIS _TRISB5
#define LED2 _LATB5
#define LIGHT_TRIS _TRISB10
#define LIGHT _LATB10
#define ON 1
#define OFF 0

//
// uart.c
//
#define FCY ((long) 29491) //instruction frequency in kHz
#define BAUD_RATE 115200

//
// rec_generic_driver.c
//
#define ID_DO_HARDWARE "ELAB_HIDROSTAT_DSPIC_V1.0"
#define TIME_OUT 180 //* ~0.5s, this value should be relatively well majored (2x higher)

//
// adc.c
//
#define ADC_12_BITS 4096
#define ADC_REF 5.0
#define T1 0
#define T2 1
#define T3 2
#define T4 3
#define DEEP_MAX 1930 //maximum deepness (mm)


//
// step_motor2.c
//
#define CALIBRATE_PORT _RC14  //C32
#define CALIBRATE_TRIS _TRISC14
#define MOTOR2_LAT LATD
#define MOTOR2_TRIS TRISD
#define MOTOR2_FIRST_BIT 0
#define UP_WAY2 0
#define POSITION2_MAX 37806//37610	//maximum allowable position = mmToSteps(DEEP_MAX)
#define POSITION2_MIN 0	//mininum allowable position
#define CALIB_OFFSET 200	//
#define ZERO_POSITION (POSITION2_MIN+CALIB_OFFSET)
#define MOTOR2_SPEED 37

//
// tm1640.c
//
#define TRIS_CLK _TRISF6
#define TRIS_DOUT _TRISF3
#define CLK _RF6
#define DOUT _RF3
#define TWAIT 2 //us (min = 1 us)
#define TLOW 2 //time CLK is LOW
#define THIGH 2 //time CLK is HIGH
