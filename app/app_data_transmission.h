#ifndef APP_DATA_TRANS
#define APP_DATA_TRANS

#include "driver_tool.h"


int32 app_sys_init(void);
int32 app_trans_save_file_data(const char* filename, uint8 *data, uint32 size);
int32 app_trans_start_service(void);
int32 app_trans_reset_service(void);

#endif

