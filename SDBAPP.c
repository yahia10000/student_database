#include "SDBAPP.h"

struct Node *ListHead = NULL;

void SDB_APP (){
    uint8 UserChoice = 0;

    printf("-> Welcome to the student database \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("To add entry, enter => 1 \n");
        printf("To get used size in database, enter => 2 \n");
        printf("To read student data, enter => 3\n");
        printf("To get the list of all student IDs, enter => 4\n");
        printf("To check is ID is existed, enter => 5\n");
        printf("To delete student data, enter => 6\n");
        printf("To check is database is full, enter => 7\n");
        printf("To exit enter => 0 \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);
        SDB_action (UserChoice);
    }

}

/****************************************/

void SDB_action (uint8 choice){
    uint32 id=0; /** To enter a value of (id) for the function */
    uint32 ret_value=0;/** To receive the value from the function */
    uint32 Array[10]={0};/** List to reserve ids existing in database */
    bool status=false;/** To take the return value of the function */
    switch(choice){
            case 1:
                while(1){
                    status =SDB_AddEntry(&ListHead);
                    if(1==status){
                        printf("the data is added successfully\n");
                    }else{
                         printf("the data not added !!\n");
                    }
                    /** Check the database whether it is greater than the minimum limit */
                    if(SDB_GetUsedSize(ListHead )>=3){
                        break;
                    }else{
                        printf("your database  minimum 3 students\n");
                        printf("The remainder of [%i] to complete the minimum number of students\n",3-SDB_GetUsedSize(ListHead ));
                    }
                }
            break;
            case 2:
                ret_value= SDB_GetUsedSize( ListHead );
                printf("the number of students in the database => %i\n",ret_value);
            break;
            case 3:
                printf("enter the id to print the data of this id => ");
                scanf("%i",&id);
                status =SDB_ReadEntry ( id,ListHead);
                if(0==status){
                    printf("this id [%i] not your database",id);
                }else{/** Nothing */}
            break;
            case 4:
                SDB_GetList (&ret_value,Array , ListHead);
                 printf("the number of id in the database => %i\n",ret_value);
                 /** print the ids in database */
                 for(uint32 i= 0;i<ret_value;++i){
                     printf("the  id [%i]  => %i\n",i+1,Array[i]);
                 }
            break;
            case 5:
                 printf("enter the id to Check if him is Exist or not => ");
                scanf("%i",&id);
                status =SDB_IsIdExist ( id,ListHead);
                if(1==status){
                      printf(" this id [%i] Exist\n",id);
                }else{
                      printf("not found this id [%i]\n",id);
                }
            break;
            case 6:
                SDB_DeletEntry (id,&ListHead);
            break;
            case 7:
               status=SDB_IsFull (ListHead );
               if(1==status){
                  printf("database is full\n");
               }else{
                  printf("database is not full\n");
               }
            break;
            case 0:
                printf("Quit from application \n");
                exit(0);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }


