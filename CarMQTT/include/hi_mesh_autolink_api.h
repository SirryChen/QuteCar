/**
* @file hi_mesh_autolink_api.h
*
* Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved. \n
* Description: header file for mesh autolink api.CNcomment:������Mesh�Զ�����api�ӿ�ͷ�ļ���CNend\n
* Author: Hisilicon \n
* Create: 2020-04-01
*/

/**
 * @defgroup hi_mesh_autolink WiFi Mesh Autolink Settings
 * @ingroup hi_wifi
 */

#ifndef __HI_MESH_AUTOLINK_API_H__
#define __HI_MESH_AUTOLINK_API_H__

#include "hi_wifi_mesh_api.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @ingroup hi_mesh_autolink
 *
 * Auth type of mesh autolink.CNcomment: Mesh�Զ���������֤����.CNend
 */
typedef enum {
    HI_MESH_OPEN,                       /**< OPEN���� */
    HI_MESH_AUTH,                       /**< �������� */

    HI_MESH_AUTH_TYPE_BUTT
}hi_mesh_autolink_auth_type;


/**
 * @ingroup hi_mesh_autolink
 *
 * Node type that usr config of mesh autolink.CNcomment: Mesh�Զ��������û�����ڵ�����.CNend
 */
typedef enum {
    HI_MESH_USRCONFIG_MBR,                  /**< �û�ָ��MBR�ڵ��ɫ */
    HI_MESH_USRCONFIG_MR,                   /**< �û�ָ��MR�ڵ��ɫ */
    HI_MESH_USRCONFIG_MSTA,                 /**< �û�ָ��MSTA�ڵ��ɫ */
    HI_MESH_USRCONFIG_AUTO,                 /**< �Զ���ѡ�ڵ��ɫ(MBR/MR��ѡ��) */

    HI_MESH_AUTOLINK_ROUTER_MSTA,           /**< δ����������ķ��ؽ��(���û����ý�ɫ) */

    HI_MESH_USRCONFIG_BUTT
}hi_mesh_autolink_usrcfg_node_type;


/**
 * @ingroup hi_mesh_autolink
 *
 * Node type information.CNcomment: Mesh�Զ������Ľڵ���Ϣ��.CNend
 */
typedef struct {
    char ifname_first[WIFI_IFNAME_MAX_SIZE + 1];
    int len_first;
    char ifname_second[WIFI_IFNAME_MAX_SIZE + 1];
    int len_second;
}hi_mesh_autolink_role_cb_info;

/**
 * @ingroup hi_mesh_autolink
 *
 * Struct of mesh autolink config.CNcomment:mesh�Զ��������ò���CNend
 *
 */
typedef struct {
    char ssid[HI_WIFI_MAX_SSID_LEN + 1];                   /**< SSID */
    hi_mesh_autolink_auth_type auth;                       /**< Autolink��֤���� */
    char key[HI_WIFI_MESH_KEY_LEN_MAX + 1];                /**< ���� */
    hi_mesh_autolink_usrcfg_node_type usr_cfg_role;        /**< �û����õĽڵ����� */
}hi_mesh_autolink_config;

/**
 * @ingroup hi_mesh_autolink
 *
 * Struct of autolink role callback.CNcomment:Mesh�Զ�������ɫ�ص��ṹ��.CNend
 *
 */
typedef struct {
    hi_mesh_autolink_usrcfg_node_type role;   /**< �ڵ��ɫ */
    hi_mesh_autolink_role_cb_info info;       /**< �¼���Ϣ */
} hi_mesh_autolink_role_cb;

/**
 * @ingroup hi_mesh_autolink
 *
 * callback function definition of mesh autolink result.CNcommment:mesh�Զ���������ص��ӿڶ���.CNend
 */
typedef void (* hi_mesh_autolink_cb)(const hi_mesh_autolink_role_cb *role);

/**
* @ingroup  hi_mesh_autolink
* @brief  Mesh start autolink network.CNcomment:mesh�����Զ�������CNend
*
* @par Description:
*          Mesh start autolink network.CNcomment:mesh�����Զ�������CNend
*
* @attention  1. SSID only supports ASCII characters.
*                CNcomment:1. SSID ֻ֧��ASCII�ַ�.CNend
* @param  config [IN]  Type  #hi_mesh_autolink_config * mesh's autolink configuration.CNcomment:mesh�Զ��������á�CNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency:
*            @li hi_wifi_api.h: WiFi API
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_start_autolink(hi_mesh_autolink_config *config);

/**
* @ingroup  hi_mesh_autolink
* @brief  Close mesh autolink.CNcomment:ֹͣmesh�Զ�����ģ�顣CNend
*
* @par Description:
*           Close mesh autolink.CNcomment:ֹͣmesh�Զ�����ģ�顣CNend
*
* @attention  NULL
* @param  NULL
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency:
*            @li hi_wifi_mesh_api.h: WiFi-MESH API
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_exit_autolink(void);

/**
* @ingroup  hi_mesh_autolink
* @brief  Set the rssi threshold of the router when MBR node connect.
*           CNcomment:����MBR�ڵ����·������RSSI��ֵ��CNend
*
* @par Description:
*           Set the router rssi threshold.CNcomment:����·������RSSI��ֵ��CNend
*
* @attention  1. The valid range of RSSI threshold is -127 ~ 127.
*                CNcomment:1. RSSI��ֵ����Ч��Χ��-127         ~ 127.CNend
* @param  router_rssi [IN]  Type  #int * mesh's rssi threshold of mbr connecting to router.
*           CNcomment:MBR������·������RSSI��ֵCNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency: NULL
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_autolink_set_router_rssi_threshold(int router_rssi);

/**
* @ingroup  hi_mesh_autolink
* @brief  Get the rssi threshold of the router when MBR node connect.
*           CNcomment:��ȡMBR�ڵ����·������RSSI��ֵ��CNend
*
* @par Description:
*           Get the router rssi threshold.CNcomment:��ȡ·������RSSI��ֵ��CNend
*
* @attention 1. The memories of <router_rssi> memories are requested by the caller.
*               CNcomment:1. <router_rssi>�ɵ����������ڴ�CNend
* @param  router_rssi [OUT]  Type  #int * mesh's rssi threshold of mbr connecting to router.
*           CNcomment:MBR������·������RSSI��ֵCNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency: NULL
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_autolink_get_router_rssi_threshold(int *router_rssi);

/**
* @ingroup  hi_mesh_autolink
* @brief  Set the bandwidth value of the mesh network. CNcomment:����Mesh����Ĵ���CNend
*
* @par Description:
*           Set the bandwidth value of the mesh network. CNcomment:����Mesh����Ĵ���CNend
*
* @attention 1. Should be called before calling hi_mesh_start_autolink api to establish mesh network.
*            CNcomment:1. ��Ҫ�ڵ���hi_mesh_start_autolink�ӿ��齨����ǰ����CNend
* @param  bw [IN]  Type  #hi_wifi_bw * The bandwidth value of mesh network.
*           CNcomment:Mesh����Ĵ���ֵCNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency: NULL
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_autolink_set_bw(hi_wifi_bw bw);

/**
* @ingroup  hi_mesh_autolink
* @brief  Get the bandwidth value of the mesh network. CNcomment:��ȡMesh����Ĵ���CNend
*
* @par Description:
*           Get the bandwidth value of the mesh network. CNcomment:��ȡMesh����Ĵ���CNend
*
* @attention 1. The memories of <bw> memories are requested by the caller.
*               CNcomment:1. <bw>�ɵ����������ڴ�CNend
* @param  bw [OUT]  Type  #hi_wifi_bw * The bandwidth value of mesh network.
*           CNcomment:Mesh����Ĵ���ֵCNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency: NULL
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_autolink_get_bw(hi_wifi_bw *bw);

/**
* @ingroup  hi_mesh_autolink
* @brief  register mesh autolink user callback interface.CNcomment:ע��Mesh�Զ������ص������ӿ�.CNend
*
* @par Description:
*           register mesh autolink user callback interface.CNcomment:ע��Mesh�Զ������ص������ӿ�.CNend
*
* @attention  NULL
* @param  role_cb  [OUT]    Type #hi_mesh_autolink_cb *, role callback .CNcomment:�ص�����.CNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency: NULL
* @see  NULL
* @since Hi3861_V100R001C00
*/
int hi_mesh_autolink_register_event_callback(hi_mesh_autolink_cb role_cb);

/**
* @ingroup  hi_mesh_autolink
* @brief  set device oui interface.CNcomment:���ò�Ʒ�ĳ���oui����.CNend
*
* @par Description:
*           set device ou interface.CNcomment:���ò�Ʒ�ĳ���oui����.CNend
*
* @attention  NULL
* @param  oui  [IN]    Type #hi_u8 *, oui code .CNcomment:��Ʒ���ұ��룬Ϊ3���ֽ��޷���������Χ0-0XFF.CNend
* @param  oui_len  [IN]    Type #hi_u8 *, oui code lenth .CNcomment:���ұ��볤��,����Ϊ3���ֽ�.CNend
*
* @retval #HISI_OK        Execute successfully.
* @retval #HISI_FAIL      Execute failed.
* @par Dependency: NULL
* @see  NULL
* @since Hi3861_V100R001C00
*/
hi_s8 hi_mesh_set_oui(const hi_u8 *oui, hi_u8 oui_len);


#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif /* end of hi_mesh_autolink_api.h */
