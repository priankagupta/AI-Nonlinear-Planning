/* 
AI project for Planning
TWEAK representation using C programming language
Name: Priyanka Krishnakumar Gupta
MIS: 122122005
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct initial   
{
    char z[20];
}pl;

typedef struct goal
{
    char q[200];
}steps;

int main()
{
    int b,c,i,j;
    char line[100];
    char str[20];
    char *store;
    pl x[20],y[20];
    steps p[20];
    
    //Take user input on number of blocks
    printf("Enter number of blocks\n");
    scanf("%d",&b);
    char *var;
    var = malloc(sizeof(char) * b);
    for(i=0;i<b;i++)
    {
        var[i]= 65+i;
    }

    //Tell user the block names
    printf("These are your blocks: ");
    for(i=0;i<b;i++)
    printf("%c ",var[i]);

    //ask user to enter the initial states of the blocks
    printf("\n\nEnter the initial state of the blocks: \n");
    fflush(stdin);
    scanf("%[^\n]", line); 
    j=0;
    b=0;
    while(line[j]!='\0')
    {
        if(line[j]==' ')
            b++;
        j++;
    }
    //No. of words in the initial state of the blocks
    //printf("No of words are %d\n",b);

    //store initial state in the structure of arrays x[i].z
    store = (char*)malloc( 10 * sizeof(char) );
    i=0;
    j=0;
    str[0]='\0';
    while(line[j]!='\0')
    {
        while(line[j]!=' ')
    {
        store[0]='\0';
        sprintf(store,"%c",line[j]);
        strcat(str,store);
        j++;
    }
    //printf("%s ",str);
    j++;
    x[i].z[0]='\0';
    strcpy(x[i].z,str);
    i++;
    str[0]='\0';
    }

    // printf("printing from structures\n");
    // for(i=0;i<b;i++)
    // {
    //     printf("%s ",x[i].z);
    // }

    //ask user to enter the goal state of the blocks
    line[0]='\0';
    printf("\nEnter the goal state of the blocks:\n");
    fflush(stdin);
    scanf("%[^\n]", line); 
    j=0;
    c=0;
    while(line[j]!='\0')
    {
        if(line[j]==' ')
            c++;
        j++;
    }
    //printf("No of words are %d\n",c);

    //store the goal state in the structure of arrays y[i].z
    store = (char*)malloc( 10 * sizeof(char) );
    i=0;
    j=0;
    str[0]='\0';
    while(line[j]!='\0')
    {
        while(line[j]!=' ')
    {
        store[0]='\0';
        sprintf(store,"%c",line[j]);
        strcat(str,store);
        j++;
    }
    //printf("%s ",str);
    j++;
    y[i].z[0]='\0';
    strcpy(y[i].z,str);
    i++;
    str[0]='\0';
    }

    // printf("printing from structures\n");
    // for(i=0;i<c;i++)
    // {
    //     printf("%s ",y[i].z);
    // }

    // printf("\n");
    // for(i=0;i<c;i++)
    // {
    //     printf("%s",y[i].z);
    // }
    printf("\nTweak representation:\n"); 
    //step 1
    printf("Step 1: ");
    p[0].q[0]='\0';
    for(i=0;i<c;i++)
    {
        if(y[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store, "Stack(%c,%c), ",y[i].z[3],y[i].z[5]);
            strcat(p[0].q,store);

        }
    }
    printf("%s",p[0].q);
    printf("\n");
    //step 2
    printf("\nStep 2: ");
    p[1].q[0]='\0';
    strcat(p[1].q,p[0].q);
    for(i=0;i<c;i++)
    {
        if(y[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store,"pickup(%c), ",y[i].z[3]);
            strcat(p[1].q,store);
        }
    }
    printf("%s",p[1].q);
    printf("\n");

    //step 3
    printf("\nStep 3: ");
    p[2].q[0]='\0';
    for(i=0;i<c;i++)
    {
        if(y[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store,"pickup(%c), ",y[i].z[3]);
            strcat(p[2].q,store);
            store[0]='\0';
            sprintf(store,"Stack(%c,%c), ",y[i].z[3],y[i].z[5]);
            strcat(p[2].q,store);
        }
    }
    printf("%s",p[2].q);
    printf("\n");
    //step 4
    printf("\nStep 4: ");
    p[3].q[0]='\0';
    strcat(p[3].q,p[2].q);
    for(i=0;i<b;i++)
    {
        if(x[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store,"Unstack(X,%c), ",x[i].z[5]);
            strcat(p[3].q,store);
        }
    }
    printf("%s",p[3].q);
    printf("\n");
    //step 5
    printf("\nStep 5: ");
    p[4].q[0]='\0';
    for(i=b-1;i>=0;i--)
    {
        if(x[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store,"Unstack(%c,%c), ",x[i].z[3],x[i].z[5]);
            strcat(p[4].q,store);
        }
    }
    strcat(p[4].q,p[2].q);
    printf("%s",p[4].q);
    printf("\n");
     //step 6
    printf("\nStep 6: ");
    p[5].q[0]='\0';
    for(i=b-1;i>=0;i--)
    {
        if(x[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store,"Unstack(%c,%c), ",x[i].z[3],x[i].z[5]);
            strcat(p[5].q,store);
            store[0]='\0';
            sprintf(store,"putdown(%c), ",x[i].z[3]);
            strcat(p[5].q,store);
        }
    }
    strcat(p[5].q,p[2].q);
    printf("%s",p[5].q);
    printf("\n\n");
    //printf("Stack(%c,%c), Stack(%c,%c)",y[0].z[3],y[0].z[5],y[1].z[3],y[1].z[5]);

//     printf("\nEnter number of blocks that are on table: ");
//     scanf("%d",ont);
//     ontlist = malloc(sizeof(char) * ont);
//     printf("Enter %d blocks which are on the table: ",ont);
//     for(i=0;i<ont;i++)
//     scanf("%c",ontlist[i]);
//     printf("Enter which block is stacked");
//     for(i=0;i<2;i++)
//     scanf("%c",stack[i]);

// for(i=0;i<b;i++)
//     printf("%c ",ontlist[i]);
// for(i=0;i<b;i++)
//     printf("%c ",stack[i]);

return 0;
}