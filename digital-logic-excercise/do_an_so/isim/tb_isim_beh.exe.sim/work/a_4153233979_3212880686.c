/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/Users/VuHaiLong/Desktop/PTIT4/do_an_so/do_an_so/main.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1258338084_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );


static void work_a_4153233979_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    unsigned char t6;
    char *t7;
    int t8;
    int t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 568U);
    t2 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3716);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(51, ng0);
    t3 = (t0 + 1880U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t6 = (t5 < 1);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 3768);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 40U);
    t10 = *((char **)t7);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1972U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t2);
    t1 = (t0 + 3804);
    t4 = (t1 + 32U);
    t7 = *((char **)t4);
    t10 = (t7 + 40U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t6;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 1880U);
    t7 = *((char **)t3);
    t8 = *((int *)t7);
    t9 = (t8 + 1);
    t3 = (t0 + 3768);
    t10 = (t3 + 32U);
    t11 = *((char **)t10);
    t12 = (t11 + 40U);
    t13 = *((char **)t12);
    *((int *)t13) = t9;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

}

static void work_a_4153233979_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    unsigned char t10;
    char *t11;
    int t12;
    int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 3232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1948U);
    t3 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    if (t3 != 0)
        goto LAB4;

LAB6:
LAB5:    goto LAB2;

LAB4:    xsi_set_current_line(64, ng0);
    t4 = (t0 + 868U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    if (t7 != 0)
        goto LAB7;

LAB9:    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)3);
    if (t6 != 0)
        goto LAB16;

LAB17:
LAB8:    goto LAB5;

LAB7:    xsi_set_current_line(65, ng0);
    t4 = (t0 + 2396U);
    t8 = *((char **)t4);
    t9 = *((int *)t8);
    t10 = (t9 == 3);
    if (t10 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2396U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = 1;

LAB11:    goto LAB8;

LAB10:    xsi_set_current_line(66, ng0);
    t4 = (t0 + 2396U);
    t11 = *((char **)t4);
    t4 = (t11 + 0);
    *((int *)t4) = 0;
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t3 = (t9 < 9);
    if (t3 != 0)
        goto LAB13;

LAB15:
LAB14:    goto LAB11;

LAB13:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 1696U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t13 = (t12 + 1);
    t2 = (t0 + 3840);
    t8 = (t2 + 32U);
    t11 = *((char **)t8);
    t14 = (t11 + 40U);
    t15 = *((char **)t14);
    *((int *)t15) = t13;
    xsi_driver_first_trans_fast(t2);
    goto LAB14;

LAB16:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2396U);
    t5 = *((char **)t2);
    t9 = *((int *)t5);
    t7 = (t9 == 1);
    if (t7 != 0)
        goto LAB18;

LAB20:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2396U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = 3;

LAB19:    goto LAB8;

LAB18:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 2396U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = 0;
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t3 = (t9 < 9);
    if (t3 != 0)
        goto LAB21;

LAB23:
LAB22:    goto LAB19;

LAB21:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 1788U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t13 = (t12 + 1);
    t2 = (t0 + 3876);
    t8 = (t2 + 32U);
    t11 = *((char **)t8);
    t14 = (t11 + 40U);
    t15 = *((char **)t14);
    *((int *)t15) = t13;
    xsi_driver_first_trans_fast(t2);
    goto LAB22;

LAB1:    return;
}

static void work_a_4153233979_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    xsi_set_current_line(88, ng0);

LAB3:    t1 = (t0 + 3912);
    t2 = (t1 + 32U);
    t3 = *((char **)t2);
    t4 = (t3 + 40U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_4153233979_3212880686_p_3(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    unsigned char t10;
    char *t11;
    int t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    int t24;

LAB0:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 568U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 3724);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(95, ng0);
    t4 = (t0 + 2464U);
    t8 = *((char **)t4);
    t9 = *((int *)t8);
    t10 = (t9 <= 1000000);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 2464U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t3 = (t9 > 1000000);
    if (t3 == 1)
        goto LAB61;

LAB62:    t1 = (unsigned char)0;

LAB63:    if (t1 != 0)
        goto LAB59;

LAB60:    t2 = (t0 + 2464U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 2000000);
    if (t1 != 0)
        goto LAB64;

LAB65:
LAB9:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 2532U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 <= 5);
    if (t1 != 0)
        goto LAB66;

LAB68:    t2 = (t0 + 2532U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 > 5);
    if (t1 != 0)
        goto LAB69;

LAB70:
LAB67:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 2532U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t2 = (t0 + 2328U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t13 = (t12 + 1);
    t1 = (t9 == t13);
    if (t1 != 0)
        goto LAB71;

LAB73:
LAB72:    goto LAB3;

LAB5:    t4 = (t0 + 592U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(96, ng0);
    t4 = (t0 + 2464U);
    t11 = *((char **)t4);
    t12 = *((int *)t11);
    t13 = (t12 + 1);
    t4 = (t0 + 2464U);
    t14 = *((char **)t4);
    t4 = (t14 + 0);
    *((int *)t4) = t13;
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3948);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 2532U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 6);
    if (t1 != 0)
        goto LAB11;

LAB13:    t2 = (t0 + 2532U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 7);
    if (t1 != 0)
        goto LAB17;

LAB18:    t2 = (t0 + 2532U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 11);
    if (t1 != 0)
        goto LAB38;

LAB39:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 2064U);
    t4 = *((char **)t2);
    t18 = (7 - 7);
    t19 = (t18 * 1U);
    t2 = (t0 + 2532U);
    t5 = *((char **)t2);
    t9 = *((int *)t5);
    t12 = (t9 - 1);
    t20 = (t12 * 1);
    xsi_vhdl_check_range_of_index(1, 17, 1, t9);
    t21 = (8U * t20);
    t22 = (0 + t21);
    t23 = (t22 + t19);
    t2 = (t4 + t23);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);

LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 1604U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t3 = (t12 < 5);
    if (t3 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 7756);
    t5 = (t0 + 3984);
    t8 = (t5 + 32U);
    t11 = *((char **)t8);
    t14 = (t11 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 8U);
    xsi_driver_first_trans_fast_port(t5);

LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 7748);
    t11 = (t0 + 3984);
    t14 = (t11 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 8U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB15;

LAB17:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 1788U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t3 = (t12 == 1);
    if (t3 != 0)
        goto LAB19;

LAB21:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 2);
    if (t1 != 0)
        goto LAB22;

LAB23:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 3);
    if (t1 != 0)
        goto LAB24;

LAB25:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 4);
    if (t1 != 0)
        goto LAB26;

LAB27:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 5);
    if (t1 != 0)
        goto LAB28;

LAB29:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 6);
    if (t1 != 0)
        goto LAB30;

LAB31:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 7);
    if (t1 != 0)
        goto LAB32;

LAB33:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 8);
    if (t1 != 0)
        goto LAB34;

LAB35:    t2 = (t0 + 1788U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 9);
    if (t1 != 0)
        goto LAB36;

LAB37:
LAB20:    goto LAB12;

LAB19:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 7764);
    t11 = (t0 + 3984);
    t14 = (t11 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 8U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB20;

LAB22:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 7772);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB24:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 7780);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB26:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 7788);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB28:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 7796);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB30:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 7804);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB32:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 7812);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB34:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 7820);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB36:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 7828);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB20;

LAB38:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 1696U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t3 = (t12 == 1);
    if (t3 != 0)
        goto LAB40;

LAB42:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 2);
    if (t1 != 0)
        goto LAB43;

LAB44:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 3);
    if (t1 != 0)
        goto LAB45;

LAB46:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 4);
    if (t1 != 0)
        goto LAB47;

LAB48:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 5);
    if (t1 != 0)
        goto LAB49;

LAB50:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 6);
    if (t1 != 0)
        goto LAB51;

LAB52:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 7);
    if (t1 != 0)
        goto LAB53;

LAB54:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 8);
    if (t1 != 0)
        goto LAB55;

LAB56:    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 == 9);
    if (t1 != 0)
        goto LAB57;

LAB58:
LAB41:    goto LAB12;

LAB40:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 7836);
    t11 = (t0 + 3984);
    t14 = (t11 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 8U);
    xsi_driver_first_trans_fast_port(t11);
    goto LAB41;

LAB43:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 7844);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB45:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 7852);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB47:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 7860);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB49:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 7868);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB51:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 7876);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB53:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 7884);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB55:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 7892);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB57:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 7900);
    t8 = (t0 + 3984);
    t11 = (t8 + 32U);
    t14 = *((char **)t11);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB59:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 2464U);
    t8 = *((char **)t2);
    t13 = *((int *)t8);
    t24 = (t13 + 1);
    t2 = (t0 + 2464U);
    t11 = *((char **)t2);
    t2 = (t11 + 0);
    *((int *)t2) = t24;
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 3948);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    goto LAB9;

LAB61:    t2 = (t0 + 2464U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t6 = (t12 < 2000000);
    t1 = t6;
    goto LAB63;

LAB64:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 2532U);
    t5 = *((char **)t2);
    t12 = *((int *)t5);
    t13 = (t12 + 1);
    t2 = (t0 + 2532U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = t13;
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 2464U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = 0;
    goto LAB9;

LAB66:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 4020);
    t5 = (t2 + 32U);
    t8 = *((char **)t5);
    t11 = (t8 + 40U);
    t14 = *((char **)t11);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    goto LAB67;

LAB69:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 4020);
    t5 = (t2 + 32U);
    t8 = *((char **)t5);
    t11 = (t8 + 40U);
    t14 = *((char **)t11);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    goto LAB67;

LAB71:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 2532U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = 5;
    goto LAB72;

}


extern void work_a_4153233979_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4153233979_3212880686_p_0,(void *)work_a_4153233979_3212880686_p_1,(void *)work_a_4153233979_3212880686_p_2,(void *)work_a_4153233979_3212880686_p_3};
	xsi_register_didat("work_a_4153233979_3212880686", "isim/tb_isim_beh.exe.sim/work/a_4153233979_3212880686.didat");
	xsi_register_executes(pe);
}
