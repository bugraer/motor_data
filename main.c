#include "stm32f4xx.h"
unsigned int adc;
float hiz, akim;
int i=0, ih, ia;
int i, j;

int delay(){
	for(i=0;i<=100;i++);
}
int main(void){	
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER |= GPIO_MODER_MODE0_0 | GPIO_MODER_MODE0_1; 
  GPIOA->MODER |= GPIO_MODER_MODE1_0 | GPIO_MODER_MODE1_1; 
	GPIOA->MODER |= GPIO_MODER_MODE2_1; //Tx PA2
	
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; 
	GPIOA->AFR[0] |= GPIO_AFRL_AFSEL2_2 | GPIO_AFRL_AFSEL2_1 | GPIO_AFRL_AFSEL2_0;
	
	ADC1->CR2 |= ADC_CR2_ADON;    	
	ADC1->CR1 |= ADC_CR1_SCAN;		
  ADC1->CR2 |=ADC_CR2_CONT;					
	ADC1->CR2 |=ADC_CR2_EOCS;	
	ADC1->SMPR2 |= ADC_SMPR2_SMP0_0 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_2;	
	ADC1->SMPR2 |= ADC_SMPR2_SMP1_0 | ADC_SMPR2_SMP1_1 | ADC_SMPR2_SMP1_2;		
	ADC1->SQR1 |= ADC_SQR1_L_0;	
	ADC1->SQR3 |= ADC_SQR3_SQ2_0;
	ADC123_COMMON->CCR |= ADC_CCR_ADCPRE_0 | ADC_CCR_ADCPRE_1; 
  ADC1->CR2 |= ADC_CR2_SWSTART;
	
	USART2->BRR =  0x683U; //9600
	USART3->BRR =  0x683U; //9600
	USART2->CR1 |= USART_CR1_UE;
	USART2->CR1 |= USART_CR1_TE;
	USART3->CR1 |= USART_CR1_UE;
	USART3->CR1 |= USART_CR1_TE;

	while(1){		
		while(!(ADC1->SR & ADC_SR_EOC));
			
		if(j%2==0){
			adc=ADC1->DR;
			hiz= ((float)adc/4096.)*3;
			ia = hiz;
			USART2->DR=ia;
			while(!(USART2->SR & USART_SR_TXE));
			while(!(USART2->SR & USART_SR_TC));
		}else{
			adc=ADC1->DR;
			akim= ((float)adc/4096.)*3;
			ih= akim;
			USART3->DR=ih;
			while(!(USART3->SR & USART_SR_TXE));
			while(!(USART3->SR & USART_SR_TC));
		}
		j++;
		delay();				
	}
}
