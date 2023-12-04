#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

// Set an 8-bit register with a value.
void REG_v_Set8BitReg(volatile uint8* pu_reg, uint8 u_val)
{
}

// Get the value of an 8-bit register.
uint8 REG_u_Get8BitReg(volatile uint8* pu_reg)
{
  return 0;
}

// Set specific bits within an 8-bit register.
void REG_v_SetBitsIn8BitReg(volatile uint8* pu_reg, uint8 u_msb, uint8 u_lsb, uint8 u_val)
{
}

// Get the value of a specific bit within an 8-bit register.
uint8 REG_u_GetBitIn8BitReg(volatile uint8* pu_reg, uint8 u_bit)
{
  return 0;
}

// Set a specific bit within an 8-bit register.
void REG_v_SetBitIn8BitReg(volatile uint8* pu_reg, uint8 u_bit)
{
}

// Clear a specific bit within an 8-bit register.
void REG_v_ClearBitIn8BitReg(volatile uint8* pu_reg, uint8 u_bit)
{
}

// Set an 16-bit register with a value.
void REG_v_Set16BitReg(volatile uint16* pu_reg, uint16 u_val)
{
}

// Set a specific bit within an 16-bit register.
void REG_v_SetBitIn16BitReg(volatile uint16* pu_reg, uint8 u_bit)
{
}

// Clear a specific bit within an 16-bit register.
void REG_v_ClearBitIn16BitReg(volatile uint16* pu_reg, uint8 u_bit)
{
}

// Set specific bits within an 16-bit register.
void REG_v_SetBitsIn16BitReg(volatile uint16* pu_reg, uint8 u_msb, uint8 u_lsb, uint16 u_val)
{
}

// Get the value of an 16-bit register.
uint16 REG_u_Get16BitReg(volatile uint16* pu_reg)
{
  return 0;
}

// Get the value of a specific bit within an 16-bit register.
uint16 REG_u_GetBitIn16BitReg(volatile uint16* pu_reg, uint8 u_bit)
{
  return 0;
}

#ifdef __cplusplus
}
#endif
