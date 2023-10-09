/**
 * @file hks_device_provision.h
 *
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. \n
 * Description: device pki provision, verify; efuse write, verify function \n
 * Author: Huawei \n
 * Create: 2020-03-26
 */

 /**
 * @defgroup iot_hks
 * @ingroup hks
 */

#ifndef HKS_DEVICE_PROVISION_H
#define HKS_DEVICE_PROVISION_H

#include "hks_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @ingroup  iot_hks
* @brief Production write efuse and certificate import verification function.
  CNcomment:����д��efuse��֤�鵼����֤���ܡ�CNend
*
* @par ����:
*           Production write efuse and certificate import verification function.
  CNcomment:����д��efuse��֤�鵼����֤���ܡ�CNend
*
* @attention None
* @param  cmd       [IN] type #uint32_t��Command word id. CNcomment: ������id��CNend
* @param  input     [IN] type #const struct hks_blob *��keybox data for pki provision function;
  common name information for certificate.
  CNcomment:֤�鵼��keybox���ݻ���Ϊ֤��common name��Ϣ��CNend
* @param  output    [OUT] type #struct hks_blob *��reserved parameters, not used. CNcomment:�����������ݲ�ʹ�á�CNend
* @retval #0       Success.
* @retval #Other   Failure.
* @par ����:
*            @li hks_types.h��describes hks_types SDK interfaces.CNcomment:����hks_types SDK�Ľӿڡ�CNend
* @see hks_pki_provision
* @since Hi3861_V100R001C00
*/
HKS_DLL_API_PUBLIC int32_t hks_pki_provision(uint32_t cmd, const struct hks_blob *input, struct hks_blob *output);

#ifdef __cplusplus
}
#endif

#endif /* HKS_DEVICE_PROVISION_H */
