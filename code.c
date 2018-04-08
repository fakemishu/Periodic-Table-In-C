#include <stdio.h>

struct TableComponents{
int atNum,atMass;

char name[5],fName[15];
};

int main(){
    int n=118,i,j,k,press,value;
    char valueC[15];

    struct TableComponents tc[n],tc2[n];

    FILE *fptr;                    //Creating File

    /* fptr = fopen("data.bin","wb"); // opening binary file

    printf("Give the value\n");
    for(i = 0; i<n;++i){
        fflush(stdin);

        printf("Atomic Num: ");
        scanf("%d",&tc[i].atNum);
        printf("Atomic Name: ");
        scanf("%s",&tc[i].name);
        printf("Atomic Full Name: ");  //Only for input when data store is done then there is no use of this
        scanf("%s",&tc[i].fName);
        printf("Atomic Mass: ");
        scanf("%d",&tc[i].atMass);
    }
    fwrite(tc,sizeof(tc),1,fptr);  //Writing to the file
    fclose(fptr); */

    fptr = fopen("data.bin","rb"); // open file
    fread(tc,sizeof(tc),1,fptr);   //reading from the file

    while(1){
        printf("\n\n           Welcome To Periodic Table\n\n");
    printf("\n What do you want to search now?\n\n** If you want to search by Atomic Number Then press \'1\' \n\n** By Atomic Mass press \'2\'\n\n** Exit \'0\'\n ");
    scanf("%d",&press);
    if(press == 0){
        exit(1);
    }

    switch(press){
    case 1:{
        j=-1;
        printf("\nGive the atomic number : ");
        scanf("%d",&value);
        for(k = 0;k < n;k++){
            if(value == tc[k].atNum){
                printf("\nAtomic Number: %d\nAtom Name: %s\nFull Name: %s\nMass: %d\n\n",tc[k].atNum,tc[k].name,tc[k].fName,tc[k].atMass);
            }
        }
        j = k;
        if(j<0){
            printf("Not found please try again.......");
        }
    }
        break;
    case 2:{
        j =-1;
        printf("\nGive the atomic mass : ");
        scanf("%d",&value);
        for(k = 0;k < n;k++){
            if(value == tc[k].atMass){
                printf("\nAtomic Number: %d\nAtom Name: %s\nFull Name: %s\nMass: %d\n\n",tc[k].atNum,tc[k].name,tc[k].fName,tc[k].atMass);
            }
        }
        j = k;
        if(j<01){
            printf("Not found please try again.............");
        }
    }
        break;

    default :
        printf("Please Give The Correct Option.............");
    }
    }
    fclose(fptr);  //Closing the file
}
