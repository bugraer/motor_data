#include "stm32f4xx.h" 

unsigned int adc;
float voltaj1, voltaj2;
int i=0;

int main ()  { 
      
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    
    
    GPIOA->MODER |= GPIO_MODER_MODE0_0 | GPIO_MODER_MODE0_1; 
    GPIOA->MODER |= GPIO_MODER_MODE1_0 | GPIO_MODER_MODE1_1; 

        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; 
    
	 
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
		
    while(1){	
		while(!(ADC1->SR & ADC_SR_EOC));
			
		if(i%2==0){
			adc=ADC1->DR;
			voltaj1= ((float)adc/4096.)*3;
		}else{
			adc=ADC1->DR;
			voltaj2= ((float)adc/4096.)*3;
		}
		i++;
    }
}

