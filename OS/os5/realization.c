#include <stdio.h>
#include <stdlib.h>
#include "myDLL.h"
typedef struct {
INT number, eval;
INT offspring;
INT son;
INT level;
}Node;
typedef struct {
INT q;
Node List;
}Bitree;

VOID  tree()
{
    INT l,q,Rang=2;
    INT i;
    printf("Enter the quantity of node ");
    scanf("%d", &q);
    l=q;
    Bitree L[q-1];
    //Enter tree
    for (i=0;i<q;++i)
    {
       // printf("Begin %d \n",i);
        L[i].List.number=i;
        // printf("Number %d \n",i);
        L[i].List.eval=i;
        // printf("Eval %d \n",i);
        if(i==0)
        {
            L[i].List.son=i+1;
            L[i].List.level=i;
            INT k=1;
           // printf("I give root \n");
            while(k<=Rang)
            {
               // printf("I make sons of root\n");
              L[i+k].List.offspring=i;
              L[i+k].List.level=L[i].List.level+1;
              L[i+k].List.eval=i+k;
              k+=1;
            };
        }
        else
        {
            if ((i%Rang)==0 && i!=q-1)
            {
            L[i].List.son=i+1;
            //printf(" I stay Papa %d \n",i);
            INT k=1;
            while(k<=Rang)
            {
               // printf("I take you parents %d\n", i+k);
                if (i+k>=q)
                {
                    //printf("I BREAK!!!!!!!!!!!!!\n");
                    break;
                };
                // printf("I take offsp %d\n", i+k);
            L[i+k].List.offspring=i;
            L[i+k].List.number=i+k;
            L[i+k].List.eval=i+k;
            // printf("I take you level %d\n", i+1);
            L[i+k].List.level=L[i].List.level+1;
           // printf("I take you eval %d\n", i+k);
            //printf(" I change level %d on %d \n",L[i].level, L[i+k].level);
            k+=1;
            };
            };
        };
    //printf(" here %d \n", i);
    };
    //Draw tree
     INT fakelevel;
     //printf("Q= %d \n", l);
    for (i=0;i<q;++i)
    {
      fakelevel=L[i].List.level;
      while(fakelevel!=0)
      {
          printf("-");
          fakelevel-=1;
      };
      printf(">");
      printf (" %d eval: %d \n", L[i].List.number, L[i].List.eval);
    };

};
