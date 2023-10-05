#include "SDB.h"
 /**
  * @brief To check if the identifier is not a duplicate
  * @param (id) parameter to pass  student id
  * @param (list) pointer to struct student
  * @retval return 1 if the id is existed and return 0 if the id not found.
  */
static bool ID_CHECK(uint32 id ,student *List){
    bool status=true;
    student *TempNode=List;
    if(NULL==List){
        status=false;
    }else{
        while( (NULL!=TempNode) && (id!=TempNode->Student_ID) ){
            TempNode=TempNode->NodeLink;
        }
        if(NULL == TempNode ){
            status=false;
        }else{
            printf("This ID already exists. Please enter the ID again\n");
        }
    }

    return status;
}
/******************************************/
 bool SDB_IsFull (student *List ){
    bool Status=false;
    student *TempNode=List;
    uint32 counter=0;
    while(NULL!=TempNode){
        counter++;
        TempNode=TempNode->NodeLink;
    }
    if(10<=counter){
        Status=true;
    }else{/** Nothing */}

    return Status;
 }
/******************************************/
 uint8 SDB_GetUsedSize(student *List ){
     student *TempNode=List;
    uint32 Counter=0;
    while(NULL!=TempNode){
        Counter++;
        TempNode=TempNode->NodeLink;
    }
    return Counter;
 }
/******************************************/
 bool SDB_AddEntry(student **List){
    bool Status=false;
    /** Check if database is full */
     if( SDB_IsFull (*List )){
        printf("your database  maximum 10 students\n");
        Status=false;
    }else{/**  database is not full */
        student *TempNode=NULL;
        student *LastNode=NULL;
        TempNode=(student *)malloc(sizeof (student));
        if(NULL!= TempNode){
            printf("--------------------------------------\n");
            while(1){/** To check if the identifier is not a duplicate */
                printf("Enter  Student_ID : ");
                scanf("%i", &TempNode->Student_ID);
                if(0==ID_CHECK( TempNode->Student_ID,*List)){
                    break;
                }else{/** Nothing*/}

            }
            printf("Enter  Student_year : ");
            scanf("%i", &TempNode->Student_year);
            printf("Enter  Course1_ID : ");
            scanf("%i", &TempNode->Course1_ID);
            printf("Enter  Course1_grade : ");
            scanf("%i", &TempNode->Course1_grade);
            printf("Enter  Course2_ID : ");
            scanf("%i", &TempNode->Course2_ID);
            printf("Enter  Course2_grade : ");
            scanf("%i", &TempNode->Course2_grade);
            printf("Enter  Course3_ID : ");
            scanf("%i", &TempNode->Course3_ID);
            printf("Enter  Course3_grade : ");
            scanf("%i", &TempNode->Course3_grade);
            printf("--------------------------------------\n");
            TempNode->NodeLink= NULL;
            /** Check if database is empty */
            if (NULL==*List){
                *List=TempNode;
            }else{/**  database is not empty */
                LastNode=*List;
                while(NULL!=LastNode->NodeLink){
                    LastNode=LastNode->NodeLink;
                }
                LastNode->NodeLink=TempNode;
            }
            Status=true;

        }else{/** Nothing */}
    }
    return Status;
 }
/******************************************/
void SDB_DeletEntry (uint32 id,student **List){
    /** Check if database is empty */
    if(NULL==*List){
        printf("the database is empty\n");
    }
    else{/**  database is not empty */
        student  *TempNode = *List;
        student  *NextNode = TempNode->NodeLink;
        printf("enter the id to delete his data => ");
        scanf("%i",&id);
        if (id==TempNode->Student_ID){
        *List=TempNode->NodeLink;
        free(TempNode);
        }else{
            /** Search in database for the id*/
            while( (NULL!=NextNode)&&  (id!=NextNode->Student_ID) ){
                TempNode=TempNode->NodeLink;
                NextNode=NextNode->NodeLink;
            }
            if(NULL!=NextNode){ /** Check if id exists */
                TempNode->NodeLink=NextNode->NodeLink;
                free(NextNode);
            }else{
                printf("not found this id [%i]\n",id);
            }
        }
    }

}
/******************************************/

bool SDB_ReadEntry (uint32 id,student *List){
    bool status=false;
    uint32 length=SDB_GetUsedSize(List);
    /** Check if database is empty */
    if(0==length){
        printf(" the database is empty\n");
    }else {
        /** Search in database for the id*/
        student  *TempNode = List;
          while( (NULL!=TempNode) && (id!=TempNode->Student_ID)  ){
            TempNode=TempNode->NodeLink;
          }

           if(NULL!=TempNode){ /** Check if id exists */
           printf("==========================================\n");
            printf("Student_ID => %i\n",TempNode->Student_ID);
            printf("Student_year => %i\n",TempNode->Student_year);
            printf("Course1_ID => %i\n",TempNode->Course1_ID);
            printf("Course1_grade => %i\n",TempNode->Course1_grade);
            printf("Course2_ID => %i\n",TempNode->Course2_ID);
            printf("Course2_grade => %i\n",TempNode->Course2_grade);
            printf("Course3_ID => %i\n",TempNode->Course3_ID);
            printf("Course3_grade => %i\n",TempNode->Course3_grade);
            printf("==========================================\n");
          }else{
        printf("not found this id [%i]\n",id);
        }
        status=true;
    }
    return status;
}

/******************************************/

  void SDB_GetList (uint8 * Count,uint32 *Ptr_list  , student * List){
      if(( NULL==Count) || (NULL==Ptr_list) ){
         printf("NULL POINTER !!\n");
      }else if(NULL==List){
        printf("the database is empty\n");
    }else{
       *Count=SDB_GetUsedSize(List );
       uint32 counter=0;
       student  *TempNode = List;
       while(  NULL!=TempNode){
       Ptr_list [counter]=TempNode->Student_ID;
        TempNode=TempNode->NodeLink;
        counter++;
       }

    }
  }

 /******************************************/

 bool SDB_IsIdExist (uint32 id,student *List){
     bool status=false;
    if(NULL==List){
        printf("the database is empty\n");
    }else{
       student  *TempNode = List;
       while( (NULL!=TempNode) && (id!=TempNode->Student_ID) ){
        TempNode=TempNode->NodeLink;
       }
       if(NULL!=TempNode){
            status=true;
       }else{/** Nothing */}
    }
    return status;
 }
 /******************************************/
