#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

// Set an 8-bit register with a value.
void REG_v_Set8BitReg(volatile uint8* pu_reg, uint8 u_val)
{
  if(pu_reg != NULL)
  {
    *pu_reg = u_val;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Get the value of an 8-bit register.
uint8 REG_u_Get8BitReg(volatile uint8* pu_reg)
{
  uint8 u_retVal = 0u;
  if(pu_reg != NULL)
  {
    u_retVal = *pu_reg;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
  return u_retVal;
}

// Set specific bits within an 8-bit register.
void REG_v_SetBitsIn8BitReg(volatile uint8* pu_reg, uint8 u_msb, uint8 u_lsb, uint8 u_val)
{
  if(pu_reg != NULL)
  {
    // Mask for bits that will be written (all 1s).
    uint8 u_mask = ((1u << (u_msb - u_lsb + 1u)) - 1u) << u_lsb;
    // Clear bits from register.
    *pu_reg &= ~u_mask;
    // Writing bits from u_val to pu_reg.
    u_mask = u_val << u_lsb;
    *pu_reg |= u_mask;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Get the value of a specific bit within an 8-bit register.
uint8 REG_u_GetBitIn8BitReg(volatile uint8* pu_reg, uint8 u_bit)
{
  uint8 u_retVal = 0u;
  if(NULL != pu_reg)
  {
    uint16 u_mask = 1 << u_bit;
    u_retVal      = (REG_u_Get8BitReg(pu_reg) & u_mask) >> u_bit;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
  return u_retVal;
}

// Set a specific bit within an 8-bit register.
void REG_v_SetBitIn8BitReg(volatile uint8* pu_reg, uint8 u_bit)
{
  if(pu_reg != NULL)
  {
    uint8 u_mask = 1u << u_bit;
    *pu_reg |= u_mask;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Clear a specific bit within an 8-bit register.
void REG_v_ClearBitIn8BitReg(volatile uint8* pu_reg, uint8 u_bit)
{
  if(NULL != pu_reg)
  {
    uint8 u_mask = 1 << u_bit;
    *pu_reg &= ~u_mask;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Set an 16-bit register with a value.
void REG_v_Set16BitReg(volatile uint16* pu_reg, uint16 u_val)
{
  if(pu_reg != NULL)
  {
    *pu_reg = u_val;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Set a specific bit within an 16-bit register.
void REG_v_SetBitIn16BitReg(volatile uint16* pu_reg, uint8 u_bit)
{
  if(pu_reg != NULL)
  {
    uint16 u_mask = 1u << u_bit;
    *pu_reg |= u_mask;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Clear a specific bit within an 16-bit register.
void REG_v_ClearBitIn16BitReg(volatile uint16* pu_reg, uint8 u_bit)
{
  if(NULL != pu_reg)
  {
    uint16 u_mask = 1 << u_bit;
    *pu_reg &= ~u_mask;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Set specific bits within an 16-bit register.
void REG_v_SetBitsIn16BitReg(volatile uint16* pu_reg, uint8 u_msb, uint8 u_lsb, uint16 u_val)
{
  if(pu_reg != NULL)
  {
    // Mask for bits that will be written (all 1s).
    uint16 u_mask = ((1u << (u_msb - u_lsb + 1u)) - 1u) << u_lsb;
    // Clear bits from register.
    *pu_reg &= ~u_mask;
    // Writing bits from u_val to pu_reg.
    u_mask = u_val << u_lsb;
    *pu_reg |= u_mask;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
}

// Get the value of an 16-bit register.
uint16 REG_u_Get16BitReg(volatile uint16* pu_reg)
{
  uint16 u_retVal = 0u;
  if(pu_reg != NULL)
  {
    u_retVal = *pu_reg;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
  return u_retVal;
}

// Get the value of a specific bit within an 16-bit register.
uint16 REG_u_GetBitIn16BitReg(volatile uint16* pu_reg, uint8 u_bit)
{
  uint16 u_retVal = 0u;
  if(NULL != pu_reg)
  {
    uint16 u_mask = 1 << u_bit;
    u_retVal      = (REG_u_Get16BitReg(pu_reg) & u_mask) >> u_bit;
  }
  else
  {
    // Handle null pointer error (IED Implementation Error Detection - nullPtr).
  }
  return u_retVal;
}

#ifdef __cplusplus
}
#endif
