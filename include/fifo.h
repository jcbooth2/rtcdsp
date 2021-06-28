#include <stdlib.h>

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a FIFO buffer
 */
typedef struct rtfifo_t rtfifo_t;

/*===========================================================================*/
/* Module functions.                                         */
/*===========================================================================*/

/**
 * @brief   Initializes a FIFO Object
 *
 * @param[out] fp       pointer to a @p fifo_t structure
 * @param[in] objbuf    pointer to the buffer of objects, it must be able to 
 *                      hold @p objn objects of @p objsize size
 * @param[in] objsize   size of objects
 * @param[in] objn      number of objects in @p objbuf
 *
 *
 * @init
 */
void rtFifoInit(rtfifo_t *fp, void *objbuf, size_t objsize, size_t objn);

/**
 * @brief   Frees a FIFO buffer structure.
 *
 * @param[in] fp    pointer to a @p fifo_t structure
 */
void rtFifoFree(rtfifo_t *fp);

/**
 * @brief   Reset the FIFO to empty, head == tail
 *
 * @param[in] fp    pointer to @p fifo_t structure
 */
void rtFifoReset(rtfifo_t *fp);

/**
 * @brief   Put data in the FIFO, if full, overwrite oldest data
 *
 * @param[in] fp        pointer to @p fifo_t structure
 * @param[in] data      data to be put in the FIFO, must be of size @p objsize
 */
void rtFifoPut(rtfifo_t *fp, void* data);


/**
 * @brief   Get value from the buffer
 *
 * @param[in] fp        pointer to @p fifo_t structure
 * @param[out] data     pointer to the value retrieved from the FIFO
 */
int rtFifoGet(rtfifo_t *fp, void* data);

/**
 * @brief returns true if buffer is empty
 *
 * @param[in] fp    pointer to @p fifo_t structure
 */
bool rtFifoEmpty(rtfifo_t *fp);

/**
 * @brief returns true if buffer is full
 *
 * @param[in] fp    pointer to @p fifo_t structure
 */
bool rtFifoFull(rtfifo_t *fp);

/**
 * @brief Returns the maximum capacity of the buffer
 *
 * @param[in] fp    pointer to @p fifo_t structure
 */
size_t rtFifoCapacity(rtfifo_t *fp);

/**
 * @brief Returns the current number of elements in the buffer
 *
 * @param[in] fp    pointer to @p fifo_t structure
 */
size_t rtFifoSize(rtfifo_t *fp);
