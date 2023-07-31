/*
= * FIFO.c
 *
 *  Created on: Feb 2, 2023
 *      Author: dell
 */

#include "FIFO.h"


/*
 * ===============================================================
 * 						APIs Function Definition
 * ===============================================================
*/

/**================================================================
 * @Fn			-FIFO_Init
 * @brief 		-Initializes FIFO by setting base,tail and head pointers to start of the buffer.
 * @param [in]	-fifo: pointer that point to structure of type FIFO_Buf_t which holds info about the buffer.
 * @param [in] 	-buf: pointer to buffer of type element_type (Generic configuration).
 * @param [in]	-length: length of the buffer (number of elements).
 * @retval 		-function returns enumeration that represents status of buffer.
 * Note			-
 */

FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf,uint32_t length)
{
	if(buf == NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}

/**================================================================
 * @Fn			-FIFO_Enqueue
 * @brief 		-Function takes item and store it in buffer using FIFO data structure.
 * @param [in]	-fifo: pointer that point to structure of type FIFO_Buf_t which holds info about the buffer.
 * @param [in] 	-item: pointer to item need to be stored in buffer.
 * @retval 		-function returns enumeration that represents status of buffer
 * Note			-
 */
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->head || !fifo->base || !fifo->tail )
		return FIFO_null;
	else if(FIFO_IS_FULL(fifo) == FIFO_full)
		return FIFO_full;
	else
	{
		*(fifo->head) = *(item);
		fifo->count++;
		if(fifo->head == (fifo->base + ((fifo->length)-1) * sizeof(element_type)))
			fifo->head = fifo->base;
		else
			fifo->head++;

		return FIFO_no_error;
	}
}


/**================================================================
 * @Fn			-FIFO_Dequeue
 * @brief 		-Function delete item from buffer using FIFO data structure.
 * @param [in]	-fifo: pointer that point to structure of type FIFO_Buf_t which holds info about the buffer.
 * @param [in] 	-item: pointer to item need to be deleted from buffer.
 * @retval 		-function returns enumeration that represents status of buffer.
 * Note			-
 */
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->head || !fifo->base || !fifo->tail )
		return FIFO_null;
	else if(fifo->count == 0)
		return FIFO_empty;
	else
	{
		*item = *(fifo->tail);
		fifo->count--;
		if(fifo->tail == (fifo->base + ((fifo->length)-1) * sizeof(element_type)))
			fifo->tail = fifo->base;
		else
			fifo->tail++;
		return FIFO_no_error;
	}

}


/**================================================================
 * @Fn			-FIFO_IS_FULL
 * @brief 		-Check if the buffer is full
 * @param [in]	-fifo: pointer that point to structure of type FIFO_Buf_t which holds info about the buffer.
 * @retval 		-function returns enumeration that represents status of buffer.
 * Note			-
 */
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	if(fifo->count == fifo->length)
		return FIFO_full;
	else
		return FIFO_no_error;
}


/**================================================================
 * @Fn			-FIFO_PRINT
 * @brief 		-Print all data stored in buffer
 * @param [in]	-fifo: pointer that point to structure of type FIFO_Buf_t which holds info about the buffer.
 * @retval 		-none
 * Note			-
 */
void FIFO_PRINT(FIFO_Buf_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count==0)
		DPRINTF("FIFO is Empty\n");
	temp = fifo->tail;
	DPRINTF("\n======FIFO_Print======\n");
	for(i=0; i<fifo->count; i++)
	{
		DPRINTF("\t %X \n",*temp);
		if(temp == (fifo->base + ((fifo->length)-1) * sizeof(element_type)))
			temp = fifo->base;
		else
			temp++;
	}
	DPRINTF("==========\n");
}
