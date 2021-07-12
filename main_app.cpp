#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "sha256.h"
#include<iostream>
using namespace std;
//Username Password Login
#include<string>


int main()
{
    int i,ch;char c;
    string val;
    hashtable *a;
    a=init();
    item x;
    //x.value=(char*)malloc(100*sizeof(char));
    //char *y,*hashval;
    //y=(char*)malloc(100*sizeof(char));
    //hashval=(char*)malloc(100*sizeof(char));
    string y,hashval;
    
    do
    {
        printf("Enter 1.Register user 2.Login 3.Display Hash Table 4.Exit:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter number of registrations to be done::");
            scanf("%d",&i);
            while(i--)
            {
                printf("Enter username:");cin>>x.key;
                printf("Enter password:");cin>>x.value;
                x.value = sha256(x.value);
                insert(x,a);//display(a);
            }
            break;
        case 2:
            printf("Enter Username:");cin>>x.key;
            printf("Enter Password:");cin>>val;
            y=find(x.key,a);
            hashval=sha256(val);
            if(hashval==y)
                printf("Login Success!!\n");
            else
                printf("Invalid Login!!\n");
            break;
        case 3:
            display(a);
            break;
        default:
            exit(0);
        }
        printf("Enter y to continue:");
        scanf(" %c",&c);
    }while(c=='y');
    
    return 0;
}
