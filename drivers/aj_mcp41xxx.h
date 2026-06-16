#ifndef AJ_MCP41XXX_INCLUDED
#define AJ_MCP41XXX_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "aj_mcp41xxx_type.h"

void AJ_MCP41xxx_Init(aj_mcp41xxx_t *mcp);
void AJ_MCP41xxx_Write(aj_mcp41xxx_t *mcp, uint8_t count);
void AJ_MCP41xxx_Shutdown(aj_mcp41xxx_t *mcp);

#ifdef __cplusplus
}
#endif

#endif
