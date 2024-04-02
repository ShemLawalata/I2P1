unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
{
    unsigned ***triple_ptr = (unsigned***) malloc(n*sizeof(unsigned**));
    unsigned **double_ptr = (unsigned**) malloc(n*m*sizeof(unsigned*));
    unsigned *single_ptr = (unsigned*) malloc(n*m*k*sizeof(unsigned));

    for (int i = 0; i < n; i++)
    {
        triple_ptr[i] = i*m + double_ptr;
        for (int j = 0; j < m; j++)
        {
            double_ptr[i*m + j] = (i*m+j)*k + single_ptr;
        }
        
    }
    return triple_ptr;
}

void delete_3d_array(unsigned ***arr)
{
    free (arr[0][0]);
    free (arr[0]);
    free (arr);

}




























// unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
// {
//     unsigned***triple_ptr = (unsigned***) malloc(n*sizeof(unsigned**));
//     unsigned**double_ptr = (unsigned**) malloc(n*m*sizeof(unsigned*));
//     unsigned*single_ptr = (unsigned*) malloc(n*m*k*sizeof(unsigned));

//     for (int i = 0; i < n; i++)
//     {
//         triple_ptr[i] = i*m + double_ptr;
//         for (int j = 0; j < m; j++)
//         {
//             double_ptr[i*m+j] = (i*m+j) *k + single_ptr;
//         }
//     }
//        return triple_ptr; 
    
// }
// void delete_3d_array(unsigned ***arr)
// {
//     free(arr[0][0]);
//     free(arr[0]);
//     free(arr);
// }

