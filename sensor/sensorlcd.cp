#line 1 "C:/Users/j9211/Desktop/sensor/sensorlcd.c"
#line 20 "C:/Users/j9211/Desktop/sensor/sensorlcd.c"
long temp;
long conversion;
long conversion1;
float temo;

unsigned int16 resultado;

float sensor(int8 primero , int8 segundo)
{
while(true)
{
set_adc_channel(primero);
delay_us(10);
conversion=read_adc();
set_adc_channel(segundo);
delay_us(10);

conversion1=read_adc() ;
if(conversion>conversion1)
{
temp=conversion-conversion1;

temo=temp*500/1023 ;
lcd_gotoxy(2,1);
printf(lcd_putc,"Tempera:%f",temo);
printf("%6.2F",temo);
delay_ms(200);

lcd_gotoxy(2,2);
printf(lcd_putc"Grados Celcius");
delay_ms(200);
if(temo>30)
{
OUTPUT_high(PIN_C3);
delay_ms(30);
OUTPUT_low(PIN_C3);
delay_ms(20);
OUTPUT_high(PIN_C3);
delay_ms(20);
OUTPUT_low(PIN_C3);
delay_ms(20);
OUTPUT_high(PIN_C3);
delay_ms(20);
OUTPUT_low(PIN_C3);
delay_ms(20);
OUTPUT_high(PIN_C3);
delay_ms(20);
OUTPUT_low(PIN_C3);
delay_ms(20);
OUTPUT_high(PIN_C3);
OUTPUT_low(PIN_C4);
OUTPUT_low(PIN_C5);
}

if(temo>10 && temo<30 )
{
OUTPUT_high(PIN_C4);
delay_ms(100);
OUTPUT_low(PIN_C4);
delay_ms(100);
OUTPUT_high(PIN_C4);
delay_ms(100);
OUTPUT_low(PIN_C3);
OUTPUT_low(PIN_C5);

}
if(temo>10)
{
OUTPUT_HIGH(PIN_C0);
OUTPUT_LOW(PIN_B6);
}

else
{
OUTPUT_LOW(PIN_C0);
OUTPUT_LOW(PIN_B6);
}

if(temo>40)
{
OUTPUT_HIGH(PIN_B7);
OUTPUT_HIGH(PIN_B6);
}

else
{
OUTPUT_LOW(PIN_B7);
OUTPUT_LOW(PIN_B6);
}

if(temo>0 && temo<10)
{
OUTPUT_high(PIN_C5);
delay_ms(100);
OUTPUT_low(PIN_C5);
delay_ms(100);
OUTPUT_high(PIN_C5);
delay_ms(100);
OUTPUT_low(PIN_C3);
OUTPUT_low(PIN_C4);
}
}

if(conversion1>conversion)
{
temp=conversion1-conversion;
temo=temp*500/1023 ;
lcd_gotoxy(2,1);
printf(lcd_putc,"Tempera:-%f",temo);
lcd_gotoxy(2,2);
printf(lcd_putc"Grados Celcius");
delay_ms(200);

delay_ms(200);
if(temo>0)
{
OUTPUT_high(PIN_C5);
delay_ms(100);
OUTPUT_low(PIN_C5);
delay_ms(100);
OUTPUT_high(PIN_C5);
delay_ms(100);
OUTPUT_low(PIN_C3);
OUTPUT_low(PIN_C4);
}
}
delay_ms(800);
}
return temo;
}

void main ()
{
set_tris_b(0x0C);
set_tris_c(0x00);

setup_adc(ADC_CLOCK_DIV_32);
setup_adc_ports(sAN0| sAN1| sAN5|sAN6);
delay_ms(100);
lcd_init();

delay_ms(500);

delay_ms(200);
printf(lcd_putc,"UNAM INGENIERIA\n MECATRONICA FI");
delay_ms(2000);
printf(lcd_putc,"\f");
printf(lcd_putc,"  Control de  \n  temperatura");
delay_ms(1000);
printf(lcd_putc,"\f");
printf(lcd_putc,"  Circuitos\n  Digitales");
delay_ms(1000);
printf(lcd_putc,"\f");
printf(lcd_putc," DanielMendez\n Carlos Chavez");
delay_ms(1000);

lcd_init();

while(true)
{
if(input(PIN_A2)==0 && input(PIN_A2)==0 )
{
printf(lcd_putc,"Presione\n un boton");
delay_ms(3000);
printf(lcd_putc,"\f");

OUTPUT_LOW(PIN_B7);
OUTPUT_LOW(PIN_C0);
}

if(input(PIN_A2)==1)
{
printf(lcd_putc,"Sensor 1");
delay_ms(500);
printf(lcd_putc,"\f");
delay_ms(500);
sensor(5,6);
DELAY_MS(200);
}

if(input(PIN_A3)==1)
{
printf(lcd_putc,"Sensor 2");
delay_ms(500);
printf(lcd_putc,"\f");
delay_ms(500);
sensor(0,1);
}
}
}
