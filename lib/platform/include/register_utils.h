#ifndef REGISTER_UTILS_H
#define REGISTER_UTILS_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void REG_v_WriteToReg(volatile uint16* pu_reg, uint16 u_val)
{
  if(pu_reg != NULL)
  {
    *pu_reg = u_val;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
}

static inline void REG_v_WriteOrReg(volatile uint8* pu_reg, uint8 u_val)
{
  if(pu_reg != NULL)
  {
    *pu_reg |= u_val;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
}

static inline uint16 REG_u_ReadFromReg(volatile uint16* pu_reg)
{
  uint16 u_retVal = 0u;
  if(pu_reg != NULL)
  {
    u_retVal = *pu_reg;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
  return u_retVal;
}

static inline void REG_v_SetBit(volatile uint16* pu_reg, uint16 u_bit)
{
  if(pu_reg != NULL)
  {
    uint16 u_mask = 1u << u_bit;
    *pu_reg |= u_mask;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
}

static inline void REG_v_ClearBit(volatile uint16* pu_reg, uint16 u_bit)
{
  if(NULL != pu_reg)
  {
    uint16 u_mask = 1 << u_bit;
    *pu_reg &= ~u_mask;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
}

static inline uint16 REG_u_ReadBit(volatile uint16* pu_reg, uint8 u_bit)
{
  uint16 u_retVal = 0u;
  if(NULL != pu_reg)
  {
    uint16 u_mask = 1 << u_bit;
    u_retVal      = (REG_u_ReadFromReg(pu_reg) & u_mask) >> u_bit;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
  return u_retVal;
}

static inline uint8 REG_u_GetReg8Bits(volatile uint8* pu_reg)
{
  uint8 u_retVal = 0u;
  if(pu_reg != NULL)
  {
    u_retVal = *pu_reg;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
  return u_retVal;
}

static inline void REG_SetReg8Bits(volatile uint8* pu_reg, uint8 u_val)
{
  if(pu_reg != NULL)
  {
    *pu_reg = u_val;
  }
  else
  {
    // IED Implementation Error Detection
    // nullPtr
  }
}

static inline void REG_v_SetBitsReg8Bits(volatile uint8* pu_reg, uint8 u_msb, uint8 u_lsb, uint8 u_val)
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
    // IED Implementation Error Detection
    // nullPtr
  }
}

#ifdef __cplusplus
}
#endif

#endif