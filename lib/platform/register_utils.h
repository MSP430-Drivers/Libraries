#ifndef REGISTER_UTILS_H
#define REGISTER_UTILS_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

inline void REG_v_WriteToReg(volatile uint16* pu_reg, uint16 u_val)
{
    if(pu_reg != NULL)
    {
        *pu_reg = u_val;
    }
    else
    {
        //send DEM
    }
}

inline uint16 REG_u_ReadFromReg(volatile uint16* pu_reg)
{
    if(pu_reg != NULL)
    {
        return *pu_reg;
    }
    else
    {
        //send DEM
    }
}

#ifdef __cplusplus
}
#endif

#endif