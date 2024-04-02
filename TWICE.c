#include <stdio.h>
#include <math.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int B_start[5000];
        int B_end[5000];
        int store[5000];
        //Input
        int answer = 0;
        int start, end;
        scanf("%d %d", &start, &end);
        int i = -1, j = -1;

        //Change to binary
        while(start || end)
        {
            //Start
            if (start > 0)
            {
                ++i;
                B_start[i] = start%2;
                start = start/2;
            }
            //End
            if (end > 0)
            {
                ++j;
                B_end[j] = end%2;
                end = end/2;
            }   
        }
        
        //Not same
        if (i != j)
         {
            printf("0\n");
            break;
         }
        //Same
        else
        {
            int b = 0;
            for (int a = i; a >= 0; a--) //if it's same then the last element is assigned in the firdt of store
            {
                if (B_start[a] == B_end[a])
                {
                    if(B_start[a] == 1) 
                    {
                        int temp = 1;
                        for (int x = a; x > 0; x--)
                        {
                            temp *= 2;
                        }
                        answer += temp;
                        
                    }
                }

                else break;
                
            }
            printf("%d\n", answer);
            
        }

        
    }
    
}






//#include <stdio.h>
// #include <math.h>

// int main(void)
// {
//     int T;
//     scanf("%d", &T);
//     while (T--)
//     {
//         int B_start[5000];
//         int B_end[5000];
//         int store[5000];
//         //Input
//         int answer = 0;
//         int start, end;
//         scanf("%d %d", &start, &end);
//         int i = -1, j = -1;

//         //Change to binary
//         while(start || end)
//         {
//             //Start
//             if (start > 0)
//             {
//                 ++i;
//                 B_start[i] = start%2;
//                 start = start/2;
//             }
//             //End
//             if (end > 0)
//             {
//                 ++j;
//                 B_end[j] = end%2;
//                 end = end/2;
//             }   
//         }
//         for(int x = 0; x <= j; x++)
//             printf("start :%d end :%d\n", B_start[x], B_end[x]);
//         //Not same
//         if (i != j)
//          {
//             printf("0\n");
//             break;
//          }
//         //Same
//         else
//         {
//             int b = 0;
//             for (int a = i; a >= 0; a--) //if it's same then the last element is assigned in the firdt of store
//             {
//                 if (B_start[a] == B_end[a])
//                 {
//                     store[b] = B_start[a];
//                     ++b;
//                 }

//                 else break;
                
//             }
// //printf("b = %d\n", b);
// //printf("i = %d\n", i);
//             for (int x = 0; x <= b; x++)
//             {
//                 //printf("x%d (%d) ", x, store[x]);
//                 answer += store[x] * pow(2, i);
//                 i--;
//             }
//             printf("%d\n", (int)answer);
            
//         }

        
//     }
    
// }