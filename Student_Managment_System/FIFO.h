/*
 * FIFO.h
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "Student_Cfg.h"

#define DPRINTF(...)	{fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}



//Define structure for buffer info
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

//Define enumeration for buffer status
typedef enum{
	FIFO_full,
	FIFO_empty,
	FIFO_null,
	FIFO_no_error,
}FIFO_Buf_Status;

//Define enumeration for student status
typedef enum
{
	ID_exist,
	no_error
}Student_statues_t;


//APIs
FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf,uint32_t length);
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_PRINT(FIFO_Buf_t* fifo);

//Student_Management_project APIs
//APIs
void setup();
void Add_Student_Details_From_File();
void Add_Student_Details_Manually();
void Find_Student_By_ID();
void Find_Student_By_First_name();
void Find_Students_Registered_In_Course();
void Count_Of_Students();
void Delete_Student();
void Update_Student();
void Show_all_information();


#endif /* FIFO_H_ */
