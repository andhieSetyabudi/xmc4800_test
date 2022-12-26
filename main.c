/*
 * main.c
 *
 *  Created on: 2022 Dec 21 10:32:49
 *  Author: DwiSetyabudi
 */


#include "stdio.h"
#include "stdarg.h""

#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)
/****************************************************************
* LOCAL DATA
***************************************************************/
int8_t rx_buffer[64] = { 0 };

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int	printf (const char *fmt, ...)
{
	if( USBD_VCOM_Connect() == USBD_VCOM_STATUS_SUCCESS )
	{
		size_t len = strlen(fmt);
		char buffer_print[256];
		va_list args;
		va_start(args, fmt);
		vsnprintf(buffer_print, sizeof(buffer_print), fmt, args);
		va_end(args);
		size_t ret = USBD_VCOM_SendData(buffer_print, strlen(buffer_print));
		return ret;
	}
	return 0;
}

int __io_putchar(int ch)
{
	if( USBD_VCOM_Connect() == USBD_VCOM_STATUS_SUCCESS )
		USBD_VCOM_SendByte(ch);
  return ch;
}


int main(void)
{

  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {


    }
  }


  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  if( USBD_VCOM_Connect() == USBD_VCOM_STATUS_SUCCESS )
	  {
//		  while (!USBD_VCOM_IsEnumDone());
		  uint16_t bytes = USBD_VCOM_BytesReceived();
		  if (bytes)
		  {
			/* Get all bytes received and return them to host */
			while(bytes--)
			{
			  USBD_VCOM_ReceiveByte(&rx_buffer[0]);
			  USBD_VCOM_SendByte(rx_buffer[0]);
			}
		  }
		  /* Call general managment task */
		  CDC_Device_USBTask(&USBD_VCOM_cdc_interface);
		  USBD_VCOM_SendString("sdadas");
	  }
	  printf("jalo");
	  if(DIGITAL_IO_GetInput(&button) )
	  {
		  DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
		  for(float i=0; i<9000000; i++); // do nothing, halt for a while
	  }else
	  {
		  DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
		  for(float i=0; i<1000000; i++); // do nothing, halt for a while
	  }

  }
}
