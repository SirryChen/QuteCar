/*
* Copyright (c) Huawei Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description: ��������API�ӿ�
* Author: ʯ�� s00490621
* Create: 2019-12-02
*/

/**
* @defgroup hi_wifi_btcoex BTCOEX
* @ingroup hi_wifi
*/

#ifndef __HI_BTCOEX_API_H__
#define __HI_BTCOEX_API_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
* @ingroup  hi_wifi_btcoex
* @brief    Set wifi & bt coexist on/off.
*           CNcomment:���������/�رա�CNend
*
* @par Description:
*           Set wifi & bt coexist on while wifi and bt are both turned on.
*           or set wifi & bt coexist off while bt is turned off.
*           CNcomment:wifi & bt ����ʱ��coexist���棬bt �ر�ʱ�ص�coexist���档CNend
*
* @param  ifname          [IN]     Type  #const char *, device name, e.g. wlan0.CNcomment:�豸���ƣ��� wlan0��CNend
* @param  enable          [IN]     Type  #enable, whether turn wifi & bt coexist on or off, 0:off, 1:on.
*                                        CNcomment:�Ƿ������wifi���棬0:�ر�, 1:�򿪡�CNend
* @param  mode            [IN]     Type  #mode,  wifi & bt coexist mode, 1:2-wired, 2:3-wired.
*                                        CNcomment:����wifi����ģʽ��1:����, 2:���ߡ�CNend
* @param  share_ant       [IN]     Type  #share_ant, whether wifi & bt share ant, 0:no share ant, 1:share ant.
*                                        CNcomment:����wifi�Ƿ������ߣ�0:������,1:���á�CNend
* @param  preempt         [IN]     Type  #preempt, whether send wifi & bt preempt frame (NULL data), 0:no send, 1:send.
*                                        CNcomment:�Ƿ��͹���preemp֡(NULL data)��0:������,1:���͡�CNend
*
* @attention
*    It will occupy some space time for sending preempt frame (NULL data), the performance of not sending preempt frame
*    is better than sending in lab test, while sending preempt frame could tell the peer sta that the bt is working
*    at this moment.CNcomment:���͹���preemp֡(NULL data)����ռ��һ���տ���Դ��ʵ�ⲻ����preemp֡
*    ���ܱȷ���preemp֡���ܸ��ߣ�����preemp֡������ȷ��֪�Զ�AP��ǰwifi�Ĺ���״̬��CNend
*
* @retval #HISI_OK         Excute successfully
* @retval #Other           Error code
* @par Dependency:
*            @li hi_btcoex_api.h: WiFi API
* @see  NULL
* @since Hi3861_V100R001C00
*/
hi_u32 hi_wifi_btcoex_enable(const hi_char *ifname, hi_bool enable, hi_u8 mode, hi_u8 share_ant, hi_u8 preempt);

#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif /* end of hi_btcoex_api.h */
