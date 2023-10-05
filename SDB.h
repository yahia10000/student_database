#ifndef _SDB_H
#define _SDB_H

#include <stdio.h>
#include "platform_types.h"

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    struct student *NodeLink;
} student;

/****************************************/
/**
  * @brief check if the database is full or not
  * @param (list) pointer to struct student
  * @retval if the database is full return true else return false
  */
 bool SDB_IsFull (student *List );

/****************************************/

 /**
  * @brief get how many students in your database have added
  * @param (list) pointer to struct student
  * @retval Return the number of students in the database
  */
  uint8 SDB_GetUsedSize(student *List );

/****************************************/

 /**
  * @brief user chooses to add entry data in the database
           to add one student which is his
           (id, year, Course1_ID, Course1_grade, Course2_ID,
           Course2_grade, Course3_ID, andCourse3_grade)
           and then add to your database
  * @param (list) pointer to struct student
  * @retval return 1 if the data is added successfully return 0 if the data not added
  */
  bool SDB_AddEntry(student **List);

/****************************************/

  /**
  * @brief delete the student data with the given id.
  * @param (id) parameter to pass  student id
  * @param (list) pointer to struct student
  */
  void SDB_DeletEntry (uint32 id,student **List);

  /****************************************/


 /**
  * @brief print the data of the user by searching on his data by the given id
  * @param (id) parameter to pass  student id
  * @param (list) pointer to struct student
  * @retval return 1 if the data is existed return 0 if this id not your database
  */
  bool SDB_ReadEntry (uint32 id,student *List);

  /****************************************/

   /**
  * @brief it gets the number of ids in the count and the list of all ids in list array
  * @param (Count) parameter to get  the number of
  * @param (Ptr_list ) pointer to array to git ids
  * @param (list) pointer to struct student
  */
  void SDB_GetList (uint8 * Count,uint32 *Ptr_list  , student * List);

/****************************************/

 /**
  * @brief Checks if the given id the is Exist
  * @param (id) parameter to pass  student id
  * @param (list) pointer to struct student
  * @retval return 1 if the id is existed and return 0 if the id not found.
  */
  bool SDB_IsIdExist (uint32 id,student *List);


#endif // _SDB_H
