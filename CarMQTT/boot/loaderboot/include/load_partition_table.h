/*
 * Copyright (c) Hisilicon Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: flash partion table..
 * Author: hisilicon
 * Create: 2020-03-16
 */

#include <hi_types.h>

#define SFC_BUFFER_BASE_ADDRESS 0x400000

/** @defgroup iot_flash_partiton Partition Table APIs
* @ingroup  iot_flashboot
*/
/**
 * @ingroup iot_flash_partiton
 *
 * partition number.
 */
#define HI_FLASH_PARTITON_MAX 12

/**
 * @ingroup iot_flash_partiton
 *
 * partition ID.
 */
typedef enum {
    HI_FLASH_PARTITON_BOOT = 0,    /**< Boot partition ID.CNcomment:BOOT����ID.CNend */
    HI_FLASH_PARTITON_FACTORY_NV,  /**< Factory NV working partition ID.CNcomment:����NV����ID.CNend */
    HI_FLASH_PARTITON_NORMAL_NV,   /**< NORMAL NV partition ID.CNcomment:�ǹ���NV����ID.CNend */
    HI_FLASH_PARTITON_NORMAL_NV_BACKUP,   /**< NORMAL backup NV partition ID.CNcomment:�ǹ���NV���ݷ���ID������ͷǹ���������.CNend */
    HI_FLASH_PARTITON_KERNEL_A,    /**< Kernel A running partition ID.CNcomment:�ں�A��ID.CNend */
    HI_FLASH_PARTITON_KERNEL_B,    /**< Kernel B runing partition ID.CNcomment:�ں�B��ID.CNend */
    HI_FLASH_PARTITON_HILINK,      /**< HILINK partition ID.CNcomment:HILINK����ID(δʹ��HILINK�ɲ���Ҫ).CNend */
    HI_FLASH_PARTITON_FILE_SYSTEM, /**< File system partition ID.CNcomment:�ļ�ϵͳ��ID.CNend */
    HI_FLASH_PARTITON_USR_RESERVE, /**< User Reserved partition.CNcomment:�û�������ID.CNend */
    HI_FLASH_PARTITON_HILINK_PKI,  /**< HiLink PKI partition.CNcomment: HILINK PKI֤��ID(δʹ��HILINK�ɲ���Ҫ). CNend */    
    HI_FLASH_PARTITON_CRASH_INFO,  /**< Crash log partition.CNcomment:�����洢��ID.CNend */
    HI_FLASH_PARTITON_BOOT_BACK,   /**< Boot backup partition.CNcomment:����boot��ID. CNend */
} hi_flash_partition_table_id;

/**
 *  @ingroup iot_flash_partiton
 *
 *  Flash partition management. CNcomment:Flash�������CNend
 */
typedef struct {
    hi_u32  addr    :24;   /* Flash partition address. The value is 16 MB. If the address is in reverse order,
                               the value is the end low address. CNcomment:Flash������ַ������Ϊ16MB��
                               ���Ϊ���򣬴��Ϊ�����ĵ͵�ֵַ CNend */
    hi_u32  id      :7;    /* Flash partition ID. CNcomment:Flash��ID.CNend  */
    hi_u32  dir     :1;    /* Flash area storage direction. 0:regular. 1: reversed.CNcomment:Flash����ŷ���
                               0��������������1������ĩ��ַ CNend */

    hi_u32  size    :24;   /* Size of the parition(Unit:byte). CNcomment:Flash������С����λ��byte��CNend */
    hi_u32  reserve :8;    /* Reserved. CNcomment:������CNend  */

    hi_u32  addition;      /* Supplementary information about the flash partition, such as the address of the Ram.
                              CNcomment:Flash����������Ϣ����Ram��Ӧ��ַ�� CNend */
} hi_flash_partition_info;

/**
 *  @ingroup iot_flash_partiton
 *  Flash partiton table.
 */
typedef struct {
    hi_flash_partition_info table[HI_FLASH_PARTITON_MAX]; /**< Flash������������  */
} hi_flash_partition_table;

/**
* @ingroup  iot_flash_partiton
* @brief  Initialize flash partition table. CNcomment:��ʼ��Flash������CNend
*
* @par ����:
*           Initialize flash partition table. CNcomment:��ʼ��Flash������CNend
*
* @attention None.
* @param  None.
*
* @retval #HI_ERR_FAILURE Failure.
* @retval #HI_ERR_SUCCESS Success.
* @par ����:
*            @li hi_flashboot.h��Describes FlashBoot APIs.CNcomment:�ļ���������Bootģ��ӿڡ�CNend
* @see  hi_get_partition_table��
* @since Hi3861_V100R001C00
*/
hi_u32 hi_flash_partition_init(hi_void);

/**
* @ingroup  iot_flash_partiton
* @brief  Get flash partition table. CNcomment:��ȡFlash������CNend
*
* @par ����:
*           Get flash partition table. CNcomment:��ȡFlash������CNend
*
* @attention None.
* @param  None.
*
* @retval #HI_NULL Failure.
* @retval #Other Success.
* @par ����:
*            @li hi_flashboot.h��Describes FlashBoot APIs.CNcomment:�ļ���������Bootģ��ӿڡ�CNend
* @see  hi_flash_partition_init��
* @since Hi3861_V100R001C00
*/
hi_flash_partition_table* hi_get_partition_table(hi_void);
