/**
 * @file hks_file_api.h
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2020. All rights reserved. \n
 * Description: Secret key storage use  \n
 * Author: Huawei \n
 * Create: 2019-06-19
 */

/**
 * @defgroup iot_hks
 * @ingroup hks
 */

#ifndef _HKS_FILE_API_H
#define _HKS_FILE_API_H

#include <stdint.h>
#include "hks_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct hks_flash_operation_callbacks {
    /**
     * @ingroup  iot_hks
     * @brief Read data from flash. CNcomment:��flash��ȡ���ݡ�CNend
     *
     * @par ����:
     *           Read data from flash. CNcomment:��flash��ȡ���ݡ�CNend
     *
     * @attention None
     * @param  buf    [OUT] type #uint8_t *��The buffer used to store the content readed from flash.
       CNcomment:���ڴ洢�������ȡ�����ݵĻ�������CNend
     * @param  len    [IN] type #uint32_t��The size count in buffer trying to read from flash.
       CNcomment:���Դ������ȡ�Ļ������еĴ�С������CNend
     * @retval #0       Success.
     * @retval # < 0    Failure.
     * @par ����:
     *            @li hks_file_api.h��describes hks_types SDK interfaces.CNcomment:����hks_types SDK�Ľӿڡ�CNend
     * @see read_flash
     * @since Hi3861_V100R001C00
     */
    int32_t (*read_flash)(uint8_t *buf, uint32_t len);

    /**
     * @ingroup  iot_hks
     * @brief Write data into flash. CNcomment:������д�����档CNend
     *
     * @par ����:
     *           Write data into flash. CNcomment:������д�����档CNend
     *
     * @attention None
     * @param  buf    [IN] type #uint8_t *��The content which you want write into the file.
       CNcomment:Ҫд���ļ������ݡ�CNend
     * @param  len    [IN] type #uint32_t��The size of the content.CNcomment:Ҫд������ݴ�С��CNend
     * @retval #0       Success.
     * @retval # < 0    Failure.
     * @par ����:
     *            @li hks_file_api.h��describes hks_types SDK interfaces.CNcomment:����hks_types SDK�Ľӿڡ�CNend
     * @see read_flash
     * @since Hi3861_V100R001C00
     */
    int32_t (*write_flash)(const uint8_t *buf, uint32_t len);
};

/**
* @ingroup  iot_hks
* @brief register flash operation callbacks. CNcomment:ע��flash�����ص�������CNend
*
* @par ����:
*           register flash operation callbacks. CNcomment:ע��flash�����ص�������CNend
*
* @attention None
* @param  callbacks    [IN] type #struct hks_flash_operation_callbacks *��Registered callback function.
  CNcomment:ע��Ļص�������CNend
* @retval #0       Success.
* @retval #Other   Failure.
* @par ����:
*            @li hks_file_api.h��describes hks_types SDK interfaces.CNcomment:����hks_types SDK�Ľӿڡ�CNend
* @see hks_register_flash_operation_callbacks
* @since Hi3861_V100R001C00
*/
HKS_DLL_API_PUBLIC int32_t hks_register_flash_operation_callbacks(struct hks_flash_operation_callbacks *callbacks);

#ifdef __cplusplus
}
#endif

#endif /* _HKS_FILE_API_H */
