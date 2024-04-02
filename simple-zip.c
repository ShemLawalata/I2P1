#include <stdio.h>
#include <string.h>

int main(void)
{
    //input Just string, char array, int count, 
    int count, length, output;
    char string[1000];
    while (scanf("%s", string) != EOF) //Scan string ga usah pakai & adress dan dia langsung susun satu"
    {
        count = 1;
        output = 0;
        length = strlen(string);

        for (int i = 0; i < length; i++)
        {
            if (string[i] == string[i+1])
            {
                count++;
            }

            else if (string[i] != string[i+1])
            {
                printf("%d", count);
                if (string[i] >= 48 && string[i] <= 57)
                {
                    printf("\'%c\'", string[i]);
                    output += 2;
                }
                else 
                {
                    printf("%c", string[i]);
                }
                if (count >= 100)
                {
                    output += 2;
                }
                else if (count >= 10)
                {
                    output += 1;
                }
                 
                output += 2;
                count = 1;
            }
            
        }
        if (output/length < 1)
        {
            printf("\ncompress rate:%6.3f\n", (float)output/length);
        }
        else
        {
            printf("\nthe string can't zip\n");
        }
        
    }
     
    
    //Hitung berapa banyak char dan angka (di hitung sebagai char di ASCII)
        //Cari berapa banyak total char di string menggunakan 'strlen'
        //Bandingkan 1st char dengan next kalau sama set variabel utk tau brp banyak, kalau beda langsung stop!
        //Print tergantung conditionalsnya   
}