/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief CLK ���̣�ͨ�� HW ��ӿ�ʵ��
 *
 * - ʵ������
 *   1. ���ڴ�ӡ������Ƶ�ʣ�
 *   2. �Ͽ�J10����ñ��PLL ʱ�� 2 ��Ƶ��� PIOA_8 �����
 *
 * \note
 *    1. ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_10 �������� PC ���ڵ� TXD��
 *       PIOA_9 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_mm32l373_hw_clk.c src_mm32l373_hw_clk
 *
 * \internal
 * \par Modification History
 * - 1.00 15-7-13  sss, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_mm32l373_hw_clk
 * \copydoc demo_mm32l373_hw_clk.c
 */

/** [src_mm32l373_hw_clk] */
#include "ametal.h"
#include "am_vdebug.h"
#include "am_gpio.h"
#include "am_mm32l373.h"
#include "amhw_mm32l373_rcc.h"
#include "am_mm32l373_inst_init.h"
#include "demo_mm32_entries.h"
#include "demo_mm32l373_core_entries.h"

/** \brief ���õ��Դ�������Ĳ����� */
#define __DEBUG_BAUDRATE        115200

/**
 * \brief ��ʼ������ 2 Ϊ���Դ���
 */
am_local void __uart_init (void)
{
    am_uart_handle_t handle = NULL;

    handle = am_mm32l373_uart2_inst_init();

    /* ���Գ�ʼ�� */
    am_debug_init(handle, __DEBUG_BAUDRATE);
}


/**
 * \brief �������
 */
void demo_mm32l373_core_hw_clk_entry (void)
{
    am_clk_id_t clk_id[] = {CLK_PLLIN,
                            CLK_PLLOUT,
                            CLK_AHB,
                            CLK_APB1,
                            CLK_APB2,
                            CLK_HSEOSC,
                            CLK_LSI,
                            CLK_HSI};

    __uart_init();

    AM_DBG_INFO("demo mm32l373_core hw clk!\r\n");

    am_gpio_pin_cfg(PIOA_8, PIOA_8_MCO | PIOA_8_AF_PP | PIOA_8_SPEED_2MHz);

    amhw_mm32l373_rcc_mco_src_set(7);

    demo_mm32_hw_clk_entry(&clk_id[0], AM_NELEMENTS(clk_id));
												
}
/** [src_mm32l373_hw_clk] */

/* end of file */