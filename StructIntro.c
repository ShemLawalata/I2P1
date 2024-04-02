// 25 December 2022, Sunday
#include <stdio.h>
int main(void)
{
    typedef struct 
    {
        int index;  //(2) di kasus ini kita declare variable baru index, kalau kita pakai .nama_var utk initial jadinya kita gausah ubah seluruh initialize.
        int x;
        int y;
    } Point;

    //Initialize 
    Point sip = {.x = 5, .y = 7};      // (1)initialize value itu pakai .nama_var karena dia seperti akses langsung.
    Point asiap = {.x = 100, .y = 20};                            
    printf("x: %d y: %d \n", sip.x, sip.y);// (3) kalau mau akses x di structnya pakai sip.x atau sip.y

    //(4) Pointer to struct
    Point *pp = &sip;
    pp -> x = 4; //(5) Sama seperti (*pp).x
    printf("x after point: %d\n", sip.x); 

    //(5) Struct inside Struct
    // typedef struct 
    // {
    //      Point sip;
    //      Point asiap;
    // } Allueto;
    // Allueto Christmas;
    // printf("sip.x: %d, asiap.x: %d\n", Christmas.sip.x, Christmas.asiap.x);

    //(6) assignment to struct;
    sip = asiap;
    printf("sipx:%d sipy:%d\n", sip.x, sip.y);

    //(7) array of struct 
    Point arr[10]; 
}