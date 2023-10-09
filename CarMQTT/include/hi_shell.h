/**
* @file hi_shell.h
*
* Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2020. All rights reserved.  \n
* Description: Shell Interaction APIs. \n
* Author: HiSilicon \n
* Create: 2020-2-16
*/

/** @defgroup iot_shell Shell
 *  @ingroup dfx
 */

#ifndef __HI_SHELL_H__
#define __HI_SHELL_H__

#include <hi_types.h>
#include <hi_uart.h>

typedef  hi_s32 (*hi_shell_input_func)(hi_u8 *data, hi_u32 data_len);
typedef  hi_s32 (*hi_shell_output_func)(const hi_u8 *data, hi_u32 data_len);
typedef hi_u32 (*hi_shell_cmd_callback_func)(hi_u32 argc, hi_char **argv);
/**
* @ingroup  iot_shell
* @brief  Shell initialization function.
CNcomment:SHELL��ʼ��������CNend
*
* @par ����:
*      Shell initialization function.
CNcomment:SHELL��ʼ��������CNend
*
* @attention None.
* @param None.
*
* @retval #0                 Success.
* @retval #Other             Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_shell.h��Describes SHELL APIs.
CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_shell_init(hi_void);

/**
* @ingroup  iot_shell
* @brief  Set taks size of SHELL. CNcomment:����SHELL�������ջ��С��CNend
*
* @par ����:
*         Set taks size of SHELL. CNcomment:����SHELL�������ջ��С��CNend
*
* @attention shell task stack size needs to be set before shell initialization.
CNcomment:shell����ջ��С��Ҫ��shell��ʼ��֮ǰ���á�CNend
* @param  channel_task_size      [IN] type #hi_u16 channel task size,task size should not smaller than 0x600.
CNcomment:ͨ������ջ��С,����ջ��С������0x600��CNend
* @param  process_task_size      [IN] type #hi_u16 process task size,task size should not smaller than 0xc00.
CNcomment:��������ջ��С,����ջ��С������0xc00��CNend
*
* @retval None
* @par ����:
*           @li hi_shell.h��Describes SHELL APIs.
CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @since Hi3861_V100R001C00
*/
hi_void hi_shell_set_task_size(hi_u16 channel_task_size, hi_u16 process_task_size);

/**
* @ingroup  iot_shell
* @brief  Get shell registered output function.
CNcomment:��ȡSHELLע������������CNend
*
* @par ����:
*      Get shell registered output function.
CNcomment:��ȡSHELLע������������CNend
*
* @attention None.
* @param  None.
*
* @retval #g_shell_output_func   Shell output function.
* @par ����:
*           @li hi_shell.h��Describes SHELL APIs.
CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @since Hi3861_V100R001C00
*/
hi_shell_output_func hi_shell_get_register_output_func(hi_void);

/**
* @ingroup  iot_shell
* @brief  Register shell input function to replace uart input.
CNcomment:ע��SHELL���뺯��������Ĭ�ϴ�UART��ȡSHELL�������ݡ�CNend
*
* @par ����:
*      Register shell input function to replace uart input.
CNcomment:ע��SHELL���뺯��������Ĭ�ϴ�UART��ȡSHELL�������ݡ�CNend
*
* @attention Should set suitable task size; input func should not continuous read data with out break. otherwise,
a watchdog may happen.
CNcomment:�������뺯��ʵ�֣����ú��ʵ�ջ��С�����뺯�����ܳ���
������Ч���ݱ��ⴥ�����Ź���CNend
* @param  shell_input_func      [IN] type #hi_shell_input_func��shell input function.
CNcomment:SHELL���뺯����CNend
*
* @retval #0                 Success.
* @retval #Other             Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_shell.h��Describes SHELL APIs.
CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @since Hi3861_V100R001C00
*/
hi_u32 hi_shell_register_input_func(hi_shell_input_func shell_input_func);

/**
* @ingroup  iot_shell
* @brief  Register shell output function to replace uart output.
CNcomment:ע��SHELL�������������Ĭ�ϴ�UART���SHELL������ݡ�CNend
*
* @par ����:
*      Register shell output function to replace uart output.
CNcomment:ע��SHELL�������������Ĭ�ϴ�UART���SHELL������ݡ�CNend
*
* @attention Should set suitable task size according to implementation of output func.
CNcomment:�����������ʵ�֣����ú��ʵ�ջ��С��CNend
* @param  shell_output_func      [IN] type #hi_shell_output_func��shell output function.
CNcomment:SHELL���������CNend
*
* @retval None
* @par ����:
*           @li hi_shell.h��Describes SHELL APIs.
CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @since Hi3861_V100R001C00
*/
hi_void hi_shell_register_output_func(hi_shell_output_func shell_output_func);

/**
* @ingroup  iot_shell
* @brief  Set whether to check the UART busy status when low power vote.
CNcomment:���õ͹���ͶƱʱ�Ƿ���UART busy״̬��CNend
*
* @par ����:
*      Set whether to check the UART busy status when low power vote.
CNcomment:���õ͹���ͶƱʱ�Ƿ���UART busy״̬��CNend
*
* @attention UART busy status is not checked by default.
CNcomment:Ĭ�ϵ͹���˯��ͶƱʱ�����UART busy״̬��CNend
* @param  enable         [IN] type #hi_bool��enable status. CNcomment:�����Ƿ���UART busy״̬��CNend
*
* @retval None
* @par ����:
*           @li hi_diag.h��Describes SHELL APIs.
CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @since Hi3861_V100R001C00
*/
hi_void hi_shell_set_check_uart_busy(hi_bool enable);

/**
* @ingroup  iot_shell
* @brief  Registration shell command processing function.CNcomment:ע��shell���������CNend
*
* @par ����:Registration shell command processing function.CNcomment:ע��shell���������CNend
*
* @attention��Only the first 32 command line arguments are recognized, and the remaining parts are not recognized.
CNcomment:��ʶ��ǰ32��shell�����в�����32��֮��������в���������ʶ��CNend
* @param  cmd_key       [IN] type #hi_char*��Register command name, the length must be less than 16 bytes.
CNcomment:shell�������ƣ�����Ȳ��ܴ���16�ֽڡ�CNend
* @param  cmd_callback  [IN] type #hi_shell_cmd_callback_func��Shell command processing function.
CNcomment:shell���������CNend
*
* @retval #HI_ERR_SUCCESS         Success.
* @retval #Other     Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_shell.h��Describes SHELL APIs. CNcomment:�ļ���������SHELL��ؽӿڡ�CNend
* @see  None
* @since Hi3861_V100R001C00
*/
hi_u32 hi_shell_cmd_register(hi_char *cmd_key, hi_shell_cmd_callback_func cmd_callback);

#endif
