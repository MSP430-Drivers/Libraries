/**********************************************************************************************************************
 * \file gpio.h
 *
 * \author  Marco Aguilar
 *
 * \date Jun-19-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the GPIO Driver
 *********************************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

#include <platform_types.h>
#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  t_Port           e_port;
  t_Pin            e_pin;
  t_PinDir         e_dir;
  t_FunctionSelect e_function;
  t_Ren            e_resistor;
  t_ResType        e_resType;
} t_GPIO_PinDescriptor;

typedef enum
{
  pinNotInit = (uint8)0u,
  pinInit    = (uint8)1u,
  pinConf    = (uint8)2u
} t_PortPinStat;

extern uint8 au_portPinStat[portMax][pinMax];

/*******************************************************************************
 *
 * \brief This function is used to initialize the GPIO module.
 *
 * \param [in] None
 *
 * \return  DataType  =  void \n
 *          Resolution = This function does not return any value.
 *
 * \callgraph
 * \startuml
 *  GPIO_v_Init -> u_DioIsInitialized : Check if GPIO is initialized
 *  activate u_DioIsInitialized
 *  alt GPIO not initialized
 *  Note over GPIO_v_Init : Initialize GPIO
 *  loop Iterate through pins and ports
 *  GPIO_v_Init -> au_portPinStat : Initialize port and pin status
 *  activate au_portPinStat
 *  au_portPinStat --> GPIO_v_Init
 *  deactivate au_portPinStat
 *  end
 *  GPIO_v_Init -> u_DioIsInitialized : Set GPIO as initialized
 *  deactivate u_DioIsInitialized
 *  else GPIO already initialized
 *  Note over GPIO_v_Init : IED Implementation Error Detection\ndioDeinitialized
 *  end
 * \enduml
 *
 ******************************************************************************/
void GPIO_v_Init(void);

void GPIO_v_DeInit(void);

t_GPIO_PinDescriptor GPIO_t_NewInstance(t_Port e_port, t_Pin e_pin, t_PinDir e_pinDir, t_FunctionSelect e_funcSel, t_Ren e_res, t_ResType e_resType);

/*******************************************************************************
 *
 * \brief This function is used to set up the configuration of a GPIO pin.
 *
 * \param [in] e_port: The GPIO port to which the pin belongs. \n
 *                                  data_type  = t_Port \n
 *                                  resolution = The valid value is one of the enumerated elements in t_Port.
 * \param [in] e_pin: The GPIO pin number to be configured. \n
 *                                  data_type  = t_Pin \n
 *                                  resolution = The valid value is one of the enumerated elements in t_Pin.
 * \param [in] e_dir: The direction to be set for the GPIO pin. \n
 *                      data_type  =  t_PinDir  \n
 *                      resolution =  The valid value is one of the enumerated elements in t_PinDir.
 * \param [in] e_funSel: The function select configuration for the GPIO pin. \n
 *                       data_type  =  t_FunctionSelect  \n
 *                      resolution =  The valid value is one of the enumerated elements in t_FunctionSelect.
 *
 * \return  DataType  = void \n
 *          Resolution = This function does not return any value.
 *
 * \callgraph
 * \startuml
 *   participant "GPIO_v_SetUpPin"
 *   participant "u_DioIsInitialized"
 *   participant "au_portPinStat"
 *   participant "REG_v_ClearBitIn8BitReg"
 *   participant "REG_v_SetBitIn8BitReg"
 *
 *   activate "GPIO_v_SetUpPin"
 *
 *   "GPIO_v_SetUpPin" -> "u_DioIsInitialized": Check if GPIO is initialized
 *   activate "u_DioIsInitialized"
 *   "u_DioIsInitialized" --> "GPIO_v_SetUpPin"
 *   deactivate "u_DioIsInitialized"
 *
 *   alt GPIO initialized
 *     "GPIO_v_SetUpPin" -> "au_portPinStat": Check pin configuration status
 *     activate "au_portPinStat"
 *     "au_portPinStat" --> "GPIO_v_SetUpPin"
 *     deactivate "au_portPinStat"
 *
 *     alt Pin not configured
 *       alt Pin direction is output
 *         Note over "GPIO_v_SetUpPin": Set pin as output
 *         "GPIO_v_SetUpPin" -> "REG_v_ClearBitIn8BitReg": Disable pull-up resistor
 *         activate "REG_v_ClearBitIn8BitReg"
 *         "REG_v_ClearBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_ClearBitIn8BitReg"
 *         "GPIO_v_SetUpPin" -> "REG_v_SetBitIn8BitReg": Set pin direction as output
 *         activate "REG_v_SetBitIn8BitReg"
 *         "REG_v_SetBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_SetBitIn8BitReg"
 *       else Pin direction is not output
 *         Note over "GPIO_v_SetUpPin": Set pin as input
 *         "GPIO_v_SetUpPin" -> "REG_v_ClearBitIn8BitReg": Set pin direction as input
 *         activate "REG_v_ClearBitIn8BitReg"
 *         "REG_v_ClearBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_ClearBitIn8BitReg"
 *       end
 *
 *       Note over "GPIO_v_SetUpPin": Configure function select
 *
 *       alt e_funSel equals e_PIN_PRIMARY
 *         "GPIO_v_SetUpPin" -> "REG_v_ClearBitIn8BitReg": Set e_PIN_PRIMARY function select
 *         activate "REG_v_ClearBitIn8BitReg"
 *         "REG_v_ClearBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_ClearBitIn8BitReg"
 *         "GPIO_v_SetUpPin" -> "REG_v_SetBitIn8BitReg": Enable e_PIN_PRIMARY function select
 *         activate "REG_v_SetBitIn8BitReg"
 *         "REG_v_SetBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_SetBitIn8BitReg"
 *       else e_funSel equals e_PIN_SECONDARY
 *         "GPIO_v_SetUpPin" -> "REG_v_SetBitIn8BitReg": Enable e_PIN_SECONDARY function select
 *         activate "REG_v_SetBitIn8BitReg"
 *         "REG_v_SetBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_SetBitIn8BitReg"
 *         "GPIO_v_SetUpPin" -> "REG_v_SetBitIn8BitReg": Enable e_PIN_PRIMARY function select
 *         activate "REG_v_SetBitIn8BitReg"
 *         "REG_v_SetBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_SetBitIn8BitReg"
 *       else
 *         "GPIO_v_SetUpPin" -> "REG_v_ClearBitIn8BitReg": Disable e_PIN_SECONDARY function select
 *         activate "REG_v_ClearBitIn8BitReg"
 *         "REG_v_ClearBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_ClearBitIn8BitReg"
 *         "GPIO_v_SetUpPin" -> "REG_v_ClearBitIn8BitReg": Disable e_PIN_PRIMARY function select
 *         activate "REG_v_ClearBitIn8BitReg"
 *         "REG_v_ClearBitIn8BitReg" --> "GPIO_v_SetUpPin"
 *         deactivate "REG_v_ClearBitIn8BitReg"
 *       end
 *
 *       "GPIO_v_SetUpPin" -> "au_portPinStat": Update pin configuration status
 *       activate "au_portPinStat"
 *       "au_portPinStat" --> "GPIO_v_SetUpPin"
 *       deactivate "au_portPinStat"
 *
 *     else Pin already configured
 *       Note over "GPIO_v_SetUpPin": IED Implementation Error Detection\npinDeInit
 *     end
 *
 *   else GPIO not initialized
 *     Note over "GPIO_v_SetUpPin": IED Implementation Error Detection\ngpioNotInit
 *   end
 *
 *   deactivate "GPIO_v_SetUpPin"
 * \enduml
 *
 ******************************************************************************/
void GPIO_v_SetUpPin(t_GPIO_PinDescriptor* self);

/*******************************************************************************
 *
 * \brief Function to configure the resistor for a specific pin.
 *
 * \param [in] e_port:       Port where the pin is located. \n
 *                           data_type  = t_Port  \n
 *                           resolution = N/A
 * \param [in] e_pin:        Pin to configure. \n
 *                           data_type  = t_Pin  \n
 *                           resolution = N/A
 * \param [in] e_ren:        Resistor enable option. \n
 *                           data_type  = t_Ren  \n
 *                           resolution = N/A
 * \param [in] e_resType:    Resistor type option. \n
 *                           data_type  = t_ResType  \n
 *                           resolution = N/A
 *
 * \return  DataType  = void \n
 *          Resolution = This function does not return any value.
 *
 * \callgraph
 * \startuml
 *  GPIO_v_ResConf -> au_portPinStat: Check pin configuration status
 *  activate au_portPinStat
 *  au_portPinStat --> GPIO_v_ResConf
 *  alt Pin configured?
 *    au_portPinStat --> GPIO_v_ResConf
 *    alt Pin direction is input?
 *      Note over GPIO_v_ResConf: Configure resistor settings
 *      alt e_ren is enable
 *        GPIO_v_ResConf -> REG_v_SetBitIn8BitReg: Enable pull-up resistor
 *        REG_v_SetBitIn8BitReg --> GPIO_v_ResConf
 *      else e_ren is not enable
 *        GPIO_v_ResConf -> REG_v_ClearBitIn8BitReg: Disable pull-up resistor
 *        REG_v_ClearBitIn8BitReg --> GPIO_v_ResConf
 *      end
 *      alt e_resType is pullUp
 *        GPIO_v_ResConf -> REG_v_SetBitIn8BitReg: Set pin output high for pull-up
 *        REG_v_SetBitIn8BitReg --> GPIO_v_ResConf
 *      else e_resType is not pullUp
 *        GPIO_v_ResConf -> REG_v_ClearBitIn8BitReg: Set pin output low for pull-down
 *        REG_v_ClearBitIn8BitReg --> GPIO_v_ResConf
 *      end
 *    else Pin direction is not input
 *      Note over GPIO_v_ResConf: IED Implementation Error Detection\npinNotInput
 *    end
 *  else Pin not configured
 *    Note over GPIO_v_ResConf: IED Implementation Error Detection\npinNotConf
 *  end
 *  deactivate au_portPinStat
 * \enduml
 *
 ******************************************************************************/

/*******************************************************************************
 *
 * \brief Function to read the state of a pin.
 *
 * \param [in] e_port:       Port where the pin is located. \n
 *                           data_type  = t_Port  \n
 *                           resolution = N/A
 * \param [in] e_pin:        Pin to read. \n
 *                           data_type  = t_Pin  \n
 *                           resolution = N/A
 *
 * \return  e_retState:      State of the pin (e_LOW/e_HIGH). \n
 *                           data_type  = t_PinState  \n
 *                           resolution = N/A
 *
 * \callgraph
 * \startuml
 *  GPIO_t_ReadPin -> au_portPinStat: Check pin configuration status
 *  activate au_portPinStat
 *  au_portPinStat --> GPIO_t_ReadPin
 *  alt Pin configured?
 *    au_portPinStat --> GPIO_t_ReadPin
 *    alt Pin direction is input?
 *      GPIO_t_ReadPin -> REG_u_GetBitIn8BitReg: Read pin state
 *      REG_u_GetBitIn8BitReg --> GPIO_t_ReadPin
 *      deactivate REG_u_GetBitIn8BitReg
 *      GPIO_t_ReadPin -> e_retState: Assign pin state to e_retState
 *      e_retState --> GPIO_t_ReadPin
 *    else Pin direction is not input
 *      Note over GPIO_t_ReadPin: IED Implementation Error Detection\npinNotInput
 *    end
 *  else Pin not configured
 *    Note over GPIO_t_ReadPin: IED Implementation Error Detection\npinNotConf
 *  end
 *  deactivate au_portPinStat
 * \enduml
 *
 ******************************************************************************/
t_PinState GPIO_t_ReadPin(t_GPIO_PinDescriptor* self);

/*******************************************************************************
 *
 * \brief This function is used to write the state of a GPIO pin.
 *
 * \param [in] e_port:      The GPIO port to which the pin belongs. \n
 *                          data_type  = t_Port \n
 *                          resolution = The valid value is one of the enumerated elements in t_Port.
 * \param [in] e_pin:       The GPIO pin number to be written. \n
 *                          data_type  = t_Pin \n
 *                          resolution = The valid value is one of the enumerated elements in t_Pin.
 * \param [in] e_pinState:  The state to be written to the GPIO pin. \n
 *                          data_type  = t_PinState \n
 *                          resolution = The valid value is one of the enumerated elements in t_PinState.
 *
 * \return  DataType  =  void \n
 *          Resolution = This function does not return any value.
 *
 * \callgraph
 * \startuml
 *  GPIO_v_WritePin -> REG_u_GetBitIn8BitReg : Read pin direction
 *  REG_u_GetBitIn8BitReg --> GPIO_v_WritePin : Pin direction value
 *  activate REG_u_GetBitIn8BitReg
 *  alt Pin direction equals output
 *  GPIO_v_WritePin -> REG_v_SetBitIn8BitReg : Set pin state
 *  REG_v_SetBitIn8BitReg --> GPIO_v_WritePin : Pin state set
 *  deactivate REG_v_SetBitIn8BitReg
 *  else Pin direction not equals output
 *  Note over GPIO_v_WritePin : IED Implementation Error Detection\npinNotoutput
 *  end
 *  deactivate REG_u_GetBitIn8BitReg
 *  alt Pin and port configured
 *  Note over GPIO_v_WritePin : IED Implementation Error Detection\ne_retVal = pinNotConf
 *  end
 * \enduml
 *
 ******************************************************************************/
void GPIO_v_WritePin(t_GPIO_PinDescriptor* self, t_PinState e_pinState);

void GPIO_v_PinIntEn(t_GPIO_PinDescriptor* self, t_EdgeSelect e_edgeMode);

void GPIO_v_PinIntDis(t_GPIO_PinDescriptor* self);

#ifdef __cplusplus
}
#endif

#endif
