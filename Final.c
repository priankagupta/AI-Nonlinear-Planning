/* 
Final AI project for Planning
TWEAK representation of planning using C programming language
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

typedef struct conditions
{
    char r[200];
}cond;

int main()
{
    int b,c,i,j;
    char line[100];
    char str[20];
    char *store;
    pl x[20],y[20];
    steps p[20];
    cond pre[20],post[20];
    
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
    printf("\n-------------------------------Tweak representation-------------------------------\n"); 
    //step 1
    //printf("Step 1: ");
    p[0].q[0]='\0';
    pre[0].r[0]='\0';
    post[0].r[0]='\0';
    for(i=0;i<c;i++)
    {
        if(y[i].z[5]!='T')
        {
            // strcat(pre[0].r,"Precondition: ");
            // strcat(post[0].r,"Postcondition: ");
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store, "Clear(%c) ",y[i].z[5]);
            strcat(pre[0].r,store);
            store[0]='\0';
            sprintf(store, "Holding(%c) || ",y[i].z[3]);
            strcat(pre[0].r,store);
            store[0]='\0';
            sprintf(store, "Stack(%c,%c), ",y[i].z[3],y[i].z[5]);
            strcat(p[0].q,store);
            strcat(post[0].r,"Handempty ");
            store[0]='\0';
            sprintf(store, "on(%c,%c), ",y[i].z[3],y[i].z[5]);
            strcat(post[0].r,store);
            store[0]='\0';
            sprintf(store, "~Clear(%c) ",y[i].z[5]);
            strcat(post[0].r,store);
            store[0]='\0';
            sprintf(store, "~Holding(%c) || ",y[i].z[3]);
            strcat(post[0].r,store);
        }
    }
    j=0;
    printf("        %s\n",pre[0].r);
    printf("Step 1: %s \n",p[0].q);
    printf("        %s\n",post[0].r);
    printf("\n");

    //step 2
    //printf("\nStep 2: ");
    p[1].q[0]='\0';
    pre[1].r[0]='\0';
    post[1].r[0]='\0';
    strcat(pre[1].r,pre[0].r);
    strcat(post[1].r,post[0].r);
    strcat(p[1].q,p[0].q);
    for(i=0;i<c;i++)
    {
        if(y[i].z[5]!='T')
        {
            // strcat(pre[1].r,"Precondition: ");
            // strcat(post[1].r,"Postcondition: ");
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store, "Clear(%c) ",y[i].z[3]);
            strcat(pre[1].r,store);
            store[0]='\0';                                                                              
            sprintf(store, "On(%c,Table) ",y[i].z[3]);
            strcat(pre[1].r,store);
            strcat(pre[1].r,"Handempty || ");
            store[0]='\0';
            sprintf(store,"pickup(%c), ",y[i].z[3]);
            strcat(p[1].q,store);
            store[0]='\0';
            sprintf(store, "Holding(%c), ",y[i].z[3]);
            strcat(post[1].r,store);
            store[0]='\0';
            sprintf(store, "~On(%c,Table) ",y[i].z[3]);
            strcat(post[1].r,store);
            strcat(post[1].r,"~Handempty || ");
        }
    }
    printf("        %s\n",pre[1].r);
    printf("Step 2: %s \n",p[1].q);
    printf("        %s\n",post[1].r);
    printf("\n");

    //step 3
    //printf("\nStep 3: ");
    p[2].q[0]='\0';
    pre[2].r[0]='\0';
    post[2].r[0]='\0';
    for(i=0;i<c;i++)
    {
        if(y[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            sprintf(store, "Clear(%c) ",y[i].z[3]);
            strcat(pre[2].r,store);
            store[0]='\0';                                                                              
            sprintf(store, "On(%c,Table) ",y[i].z[3]);
            strcat(pre[2].r,store);
            strcat(pre[2].r,"Handempty || ");
            store[0]='\0';
            sprintf(store,"pickup(%c), ",y[i].z[3]);
            strcat(p[2].q,store);
            store[0]='\0';
            sprintf(store, "Holding(%c), ",y[i].z[3]);
            strcat(post[2].r,store);
            store[0]='\0';
            sprintf(store, "~On(%c,Table) ",y[i].z[3]);
            strcat(post[2].r,store);
            strcat(post[2].r,"~Handempty || ");

            store[0]='\0';
            sprintf(store, "Clear(%c) ",y[i].z[5]);
            strcat(pre[2].r,store);
            store[0]='\0';
            sprintf(store, "Holding(%c) || ",y[i].z[3]);
            strcat(pre[2].r,store);
            store[0]='\0';
            sprintf(store, "Stack(%c,%c), ",y[i].z[3],y[i].z[5]);
            strcat(p[2].q,store);
            strcat(post[2].r,"Handempty ");
            store[0]='\0';
            sprintf(store, "on(%c,%c), ",y[i].z[3],y[i].z[5]);
            strcat(post[2].r,store);
            store[0]='\0';
            sprintf(store, "~Clear(%c) ",y[i].z[5]);
            strcat(post[2].r,store);
            store[0]='\0';
            sprintf(store, "~Holding(%c) || ",y[i].z[3]);
            strcat(post[2].r,store);
        }
    }
    
    printf("        %s\n",pre[2].r);
    printf("Step 3: %s \n",p[2].q);
    printf("        %s\n",post[2].r);
    printf("\n");

    //step 4
    //printf("\nStep 4: ");
    p[3].q[0]='\0';
    strcat(p[3].q,p[2].q);
    pre[3].r[0]='\0';
    strcat(pre[3].r,pre[2].r);
    post[3].r[0]='\0';
    strcat(post[3].r,post[2].r);
    for(i=0;i<b;i++)
    {
        if(x[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            store[0]='\0';
            sprintf(store, "On(X,%c) ",x[i].z[5]);
            strcat(pre[3].r,store);
            strcat(pre[3].r,"Clear(X) ");
            strcat(pre[3].r,"Handempty || ");
            store[0]='\0';
            sprintf(store,"Unstack(X,%c), ",x[i].z[5]);
            strcat(p[3].q,store);
            strcat(post[3].r,"~Handempty ");
            store[0]='\0';
            sprintf(store,"Clear(%c), ",x[i].z[5]);
            strcat(post[3].r,store);
            strcat(post[3].r,"Holding(X) ");
            store[0]='\0';
            sprintf(store,"~On(X,%c) || ",x[i].z[5]);
            strcat(post[3].r,store);

        }
    }
    printf("        %s\n",pre[3].r);
    printf("Step 4: %s \n",p[3].q);
    printf("        %s\n",post[3].r);
    printf("\n");
    //step 5
    //printf("\nStep 5: ");
    p[4].q[0]='\0';
    pre[4].r[0]='\0';
    post[4].r[0]='\0';
    for(i=b-1;i>=0;i--)
    {
        if(x[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            store[0]='\0';
            sprintf(store, "On(%c,%c) ",x[i].z[3],x[i].z[5]);
            strcat(pre[4].r,store);
            store[0]='\0';
            sprintf(store, "Clear(%c) ",x[i].z[3]);
            strcat(pre[4].r,store);
            strcat(pre[4].r,"Handempty || ");
            store[0]='\0';
            sprintf(store,"Unstack(%c,%c), ",x[i].z[3],x[i].z[5]);
            strcat(p[4].q,store);
            strcat(post[4].r,"~Handempty ");
            store[0]='\0';
            sprintf(store,"Clear(%c), ",x[i].z[5]);
            strcat(post[4].r,store);
            store[0]='\0';
            sprintf(store,"Holding(%c), ",x[i].z[3]);
            strcat(post[4].r,store);
            store[0]='\0';
            sprintf(store,"~On(%c,%c) || ",x[i].z[3],x[i].z[5]);
            strcat(post[4].r,store);
        }
    }
    strcat(p[4].q,p[2].q);
    strcat(pre[4].r,pre[2].r);
    strcat(post[4].r,pre[2].r);

    printf("        %s\n",pre[4].r);
    printf("Step 5: %s \n",p[4].q);
    printf("        %s\n",post[4].r);
    printf("\n");

    //step 6
    //printf("\nStep 6: ");
    p[5].q[0]='\0';
    pre[5].r[0]='\0';
    post[5].r[0]='\0';
    for(i=b-1;i>=0;i--)
    {
        if(x[i].z[5]!='T')
        {
            store = (char*)malloc( 100 * sizeof(char) );
            store[0]='\0';
            sprintf(store, "On(%c,%c) ",x[i].z[3],x[i].z[5]);
            strcat(pre[5].r,store);
            store[0]='\0';
            sprintf(store, "Clear(%c) ",x[i].z[3]);
            strcat(pre[5].r,store);
            strcat(pre[5].r,"Handempty || ");
            store[0]='\0';
            sprintf(store,"Unstack(%c,%c), ",x[i].z[3],x[i].z[5]);
            strcat(p[5].q,store);
            strcat(post[5].r,"~Handempty ");
            store[0]='\0';
            sprintf(store,"Clear(%c), ",x[i].z[5]);
            strcat(post[5].r,store);
            store[0]='\0';
            sprintf(store,"Holding(%c), ",x[i].z[3]);
            strcat(post[5].r,store);
            store[0]='\0';
            sprintf(store,"~On(%c,%c) || ",x[i].z[3],x[i].z[5]);
            strcat(post[5].r,store);            

            store[0]='\0';
            sprintf(store, "Holding(%c) || ",x[i].z[3]);
            strcat(pre[5].r,store);
            store[0]='\0';
            sprintf(store,"putdown(%c), ",x[i].z[3]);
            strcat(p[5].q,store);

            store[0]='\0';
            sprintf(store,"~Holding(%c), ",x[i].z[3]);
            strcat(post[5].r,store);
            store[0]='\0';
            sprintf(store,"On(%c,Table) ",x[i].z[3]);
            strcat(post[5].r,store);   
             strcat(post[5].r,"Handempty || ");
        }
    }
    strcat(p[5].q,p[2].q);
    strcat(pre[5].r,pre[2].r);
    strcat(post[5].r,post[2].r);

    printf("        %s\n",pre[5].r);
    printf("Step 6: %s \n",p[5].q);
    printf("        %s\n",post[5].r);
    printf("\n");
    printf("\n\n");
    return 0;
}