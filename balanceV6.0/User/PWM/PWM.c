
#include "./PWM/PWM.h" 

static void ADVANCE_TIM1_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // 输出比较通道 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM1_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM1_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM1_CH1_PORT, &GPIO_InitStructure);

  // 输出比较通道 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM1_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM1_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM1_CH4_PORT, &GPIO_InitStructure);

}


///*
// * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
// * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
// * 另外三个成员是通用定时器和高级定时器才有.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            都有
// *	TIM_CounterMode			     TIMx,x[6,7]没有，其他都有
// *  TIM_Period               都有
// *  TIM_ClockDivision        TIMx,x[6,7]没有，其他都有
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]才有
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */

/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = (ARR+1) * (1/CLK_cnt) = (ARR+1)*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)

static void ADVANCE_TIM1_Mode_Config(void)
{
  // 开启定时器时钟,即内部时钟CK_INT=72M
	ADVANCE_TIM1_APBxClock_FUN(ADVANCE_TIM1_CLK,ENABLE);

/*--------------------时基结构体初始化-------------------------*/
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=ADVANCE_TIM1_PERIOD;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= ADVANCE_TIM1_PSC;	
	// 时钟分频因子 ，配置死区时间时需要用到
//	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(ADVANCE_TIM1, &TIM_TimeBaseStructure);

	/*--------------------输出比较结构体初始化-------------------*/		
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 互补输出使能
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable; 
	// 设置占空比大小
	TIM_OCInitStructure.TIM_Pulse = ADVANCE_TIM1_PULSE;
	// 输出通道电平极性配置
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC1Init(ADVANCE_TIM1, &TIM_OCInitStructure);
	TIM_OC4Init(ADVANCE_TIM1, &TIM_OCInitStructure);
	
	TIM_OC1PreloadConfig(ADVANCE_TIM1, TIM_OCPreload_Enable);    //CH1预装载使能
	TIM_OC4PreloadConfig(ADVANCE_TIM1, TIM_OCPreload_Enable);    //CH4预装载使能
	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //使能TIMx在ARR上的预装载寄存器

	
	// 使能计数器
	TIM_Cmd(ADVANCE_TIM1, ENABLE);	
	// 主输出使能，当使用的是通用定时器时，这句不需要
	TIM_CtrlPWMOutputs(ADVANCE_TIM1, ENABLE);
}

void ADVANCE_TIM1_Init(void)
{
	ADVANCE_TIM1_GPIO_Config();
	ADVANCE_TIM1_Mode_Config();		
}

/*********************************************END OF FILE**********************/
