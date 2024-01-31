#include <stdio.h>
int max = 10;
int isDuplicate(int Uni[], int val, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (Uni[i] == val)
        {
            printf("Duplicate element found!\n");
            return 1;
        }
    }
    return 0;
}

int isUniversal(int Uni[], int val, int max)
{
    int f = 0;
    for (int i = 0; i < max; i++)
    {
        if (Uni[i] == val)
        {
            f = 1;
            return 1;
        }
    }
    if (f == 0)
    {
        printf("\nElement not present in universal set\n");
        return 0;
    }
}

void bit_string(int Uni[], int setA[], int setA_bitsring[], int sizeA)
{
    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < sizeA; j++)
        {
            if (Uni[i] == setA[j])
            {
                setA_bitsring[i] = 1;
                break;
            }
            else
            {
                setA_bitsring[i] = 0;
            }
        }
    }
}

void union_operation(int setA_bitsring[], int setB_bitsring[], int union_set[])
{
    for (int i = 0; i < max; i++)
    {
        if (setA_bitsring[i] == 1 || setB_bitsring[i] == 1)
        {
            union_set[i] = 1;
        }
        else
        {
            union_set[i] = 0;
        }
    }
}

void intersection_operation(int setA_bitsring[], int setB_bitsring[], int intersection_set[])
{
    for (int i = 0; i < max; i++)
    {
        if (setA_bitsring[i] == 1 && setB_bitsring[i] == 1)
        {
            intersection_set[i] = 1;
        }
        else
        {
            intersection_set[i] = 0;
        }
    }
}

void set_difference_a_b(int setA_bitsring[],int setB_bitsring[],int set_difference_a_b_set[]){
    for(int i=0;i<max;i++){
        if(setA_bitsring[i]==1 && setB_bitsring[i]!=1 ){
            set_difference_a_b_set[i]=1;
        }else{
            set_difference_a_b_set[i]=0;
        }
    }
}

void set_difference_b_a(int setA_bitsring[],int setB_bitsring[],int set_difference_b_a_set[]){
    for(int i=0;i<max;i++){
        if(setB_bitsring[i]==1 && setA_bitsring[i]!=1 ){
            set_difference_b_a_set[i]=1;
        }else{
            set_difference_b_a_set[i]=0;
        }
    }
}

int main()
{
    int max, i, val, sizeA, sizeB;
    printf("Enter the size of universal set : ");
    scanf("%d", &max);
    int Uni[max], setA[max], setB[max], setA_bitstring[max], setB_bitstring[max], union_set[max], intersection_set[max],set_difference_a_b_set[max],set_difference_b_a_set[max];
    printf("Enter the universal set elements \n");
    for (i = 0; i < max; i++)
    {
        printf("Enter %dth element : ", (i + 1));
        scanf("%d", &val);
        if (isDuplicate(Uni, val, i) == 0)
        {
            Uni[i] = val;
        }
        else
        {
            i--;
        }
    }
    printf("\nEnter size of Set A : ");
    scanf("%d", &sizeA);
    if (sizeA > max)
    {
        printf("Size of subset cannot be greater than universal set.Size set to %d", max);
        sizeA = max;
    }
    printf("\nEnter Set A elements\n");
    for (i = 0; i < sizeA; i++)
    {
        printf("Enter %dth element : ", (i + 1));
        scanf("%d", &val);
        int a = isDuplicate(setA, val, i);
        int b = isUniversal(Uni, val, max);
        if (a == 0 && b == 1)
        {
            setA[i] = val;
        }
        else
        {
            i--;
        }
    }

    printf("\nEnter size of Set B : ");
    scanf("%d", &sizeB);
    if (sizeB > max)
    {
        printf("Size of subset cannot be greater than universal set.Size set to %d", max);
        sizeB = max;
    }
    printf("\nEnter Set B elements\n");
    for (i = 0; i < sizeB; i++)
    {
        printf("Enter %dth element : ", (i + 1));
        scanf("%d", &val);
        int a = isDuplicate(setB, val, i);
        int b = isUniversal(Uni, val, max);
        if (a == 0 && b == 1)
        {
            setB[i] = val;
        }
        else
        {
            i--;
        }
    }

    bit_string(Uni, setA, setA_bitstring, sizeA);
    bit_string(Uni, setB, setB_bitstring, sizeB);

    union_operation(setA_bitstring, setB_bitstring, union_set);
    intersection_operation(setA_bitstring, setB_bitstring, intersection_set);
    set_difference_a_b(setA_bitstring,setB_bitstring,set_difference_a_b_set);
    set_difference_b_a(setA_bitstring,setB_bitstring,set_difference_b_a_set);

    printf("Universal set elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", Uni[i]);
    }

    printf("\n\nSet A elements are : ");
    for (i = 0; i < sizeA; i++)
    {
        printf("%d ", setA[i]);
    }

    printf("\nSet B elements are : ");
    for (i = 0; i < sizeB; i++)
    {
        printf("%d ", setB[i]);
    }

    printf("\n\nBitsring representation of set A elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", setA_bitstring[i]);
    }
    printf("\nBitsring representation of set B elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", setB_bitstring[i]);
    }
    printf("\n\nUnion of bitsring A and bitsring B elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", union_set[i]);
    }
    printf("\nIntersection of bitsring A and bitsring B elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", intersection_set[i]);
    }
    printf("\n\nSet Difference (Set A - Set B) elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", set_difference_a_b_set[i]);
    }
    printf("\nSet Difference (Set B - Set A) elements are : ");
    for (i = 0; i < max; i++)
    {
        printf("%d ", set_difference_b_a_set[i]);
    }

    return 0;
}
