/* Includes ------------------------------------------------------------------*/
#include "hw_config.h"
#include "usart.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void SysTick_Configuration(void);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : System_Init
* Description    : Configures Main system clocks & power
* Input          : None.
* Return         : None.
*******************************************************************************/
void System_Init(void)
{
	uart_init(115200);	 //���ڳ�ʼ��Ϊ9600
	/* Configure the GPIO ports */
	GPIO_Configuration();
}


/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : ����GPIO��
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);
	
	/* ���� PB.15����Ϊ������� */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//ָʾ��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//ָʾ��
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
