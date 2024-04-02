#include <stdio.h>
int main(void)
{
    int n, S, x, y;//input
    int reverse = 0, flag = 1;//ubah
    char lock, small = 'z', big = 'A', now, subx, suby;
    char map[105][105];
    scanf("%d", &n);
    scanf("%d", &S);
    scanf("%d %d\n", &x, &y);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c ", &map[i][j]);
        }
        
    }
       printf("%c", map[x][y]);
       int i, j;
       while (S > 0 && flag == 1)
       {
        for (small = 'z', big = 'A', i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (x+i >= 0 && y+i >= 0 && x+i <= n-1 && y+j <= n-1)
                {
                    if (i == 0 && j == 0)
                    {
                        continue;
                    }
                    
                    now = map[x+i][y+j];

                    if ((now <= small && reverse == 0) || (now >= big && reverse == 1))
                    {
                        subx = x+i;
                        suby = y+j;
                        lock = big = small = now;
                    }
                    

                }
                
            }
            
        }
        S--;

        switch (lock)
        {
        case 'a': 
        case 'f':
        case 'k':
        case 'p': 
        case 'E': 
        case 'J': 
        case 'O': 
        case 'T':
            if (y > 0)
            {
                y -= 1;
                printf("%c", map[x][y]);
            }
            else if (y <= 0)
            {
                flag = 0;
            }
            
            break;
        case 'b': 
        case 'g':
        case 'l':
        case 'q': 
        case 'D': 
        case 'I': 
        case 'N': 
        case 'S':
        if (y < n-1)
        {
            y+=1;
            printf("%c", map[x][y]);
        }
        else if (y >= n-1)
        {
            flag = 0;
        }
        break;
        
        case 'c': 
        case 'h':
        case 'm':
        case 'r': 
        case 'C': 
        case 'H': 
        case 'M': 
        case 'R':
        if (x > 0)
        {
            x -= 1;
            printf("%c", map[x][y]);
        }
        else if (x <= 0)
        {
            flag = 0;
        }
        break;

        case 'd': 
        case 'i':
        case 'n':
        case 's': 
        case 'B': 
        case 'G': 
        case 'L': 
        case 'Q':
        if (x < n-1)
        {
            x += 1;
            printf("%c", map[x][y]);
        }
        else if (x >= n-1)
        {
            flag = 0;
        }
        break;
        
        case 'e': 
        case 'j':
        case 'o':
        case 't': 
        case 'A': 
        case 'F': 
        case 'K': 
        case 'P':
        x = subx;
        y = suby;
        printf("%c", map[x][y]);
        if (reverse == 0)
        {
            reverse = 1;
        }
        else {reverse = 0;}
        break;

        default:
        x = subx;
        y = suby;
        printf("%c", map[x][y]);
        break;
        }
       }
       


}