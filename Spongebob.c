#include<stdio.h>
int main ()
    {
        int n;
        int q;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &q);

        for (int A = 0; A < q; A++)
        {
            int f,l;
            scanf("%d %d", &f, &l); 
            f=f-1, l=l-1;
            int frq=0;
            int menu=0;

            for (int i = f; i <=l; i++)
            {
                int hitung=1;
                for ( int j = f; j <= l; j++)
                {
                    if (a[i]==a[j])
                    {
                        hitung++;
                    }
                }
            
                if (hitung>frq)
                    {
                        frq=hitung;
                        menu=a[i];
                    }
                    else if (hitung==frq)
                    {
                        if (a[i]<menu)
                        {
                            menu=a[i];
            
                        }
                        
                    }
            }
            
            printf("%d\n", menu);

        
        
        }
        
        

    }