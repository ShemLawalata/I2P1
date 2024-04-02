#include <stdio.h>
int row, col, n;
int snow[500][500] = {0};
int middle[8] = {0,1}; //{0, 1, 2, 5, 12, 29, 70, 169}
int cumulative[8] = {0,1}; //[0, 1, 3, 8, 42, 112, 281]
void initialize_size();
int snowflake_size(int n);

int main(void)
{
    //Input n or "order"
    scanf("%d", &n);
    initialize_size();
    for (int i = 0; i <= 7; i++)
    {
        printf("%d\n", cumulative[i]);
    }
    

    //Print snowflakes (call function)
}



void initialize_size() {

    for(int i = 2; i <= 7; i++) {

        middle[i] = 4 * cumulative[i-2] - middle[i-2] + 2;

        cumulative[i] = cumulative[i-1] + middle[i];

    }

}

int snowflake_size(int n) {
    return cumulative[n] + cumulative[n - 1];
}