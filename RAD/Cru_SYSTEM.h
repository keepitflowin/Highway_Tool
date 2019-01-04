#pragma once

#ifndef __Cru_SYSTEM_H
#define __Cru_SYSTEM_H

// Pre-Compiled �����ũ
//#include "./RAD/Pre_Compiled.h"

    #include "./RAD/Cru_DEFiNE.h"

    #include "./RAD/Sys_DEBUG.h"
    #include "./RAD/Sys_PARSiNG.h"
    #include "./RAD/Sys_TiMER.h"

    #include "./RAD/Cru_SCRiPT.h"

// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.
// �ý��� Ŭ����
class Cru_SYSTEM
{
public:

    /* �÷� */
    int FLAG[MAX_FLAG];                          // �����÷� �޸�            .

    /* ���丮 */
    char runDiR[256],                            // PGM ���� - ������        .
         resDiR[256];                            // ���ҽ�   - ���            .

    /* ��ũ��Ʈ */
    int zALREADY_Kernel_iSQrun,                  // Kernel.iSQ �� �̹� �ص����� �÷�
        zALREADY_Game_iSQrun,                    // Game.iSQ   �� �̹� �ص����� �÷�
        zEventSKiP_iSQrun;                       // �̺�Ʈ���� �ΰ� ? �÷�

                                                 //                            .
    char SystemSCR_FiLE[256];                    // �ý��� ��������            .
                                                 //                            .

    int zGOOGLE_Link;                            // ���ۿ��� �÷�

    /* Ÿ�̹� */
                                                 //=====================================
    Cru_TiCK tm_MAiN;                            // ����Ŀ�� Tick                      .
    int clk,                                     // ����Ŀ��Ŭ��                       .
        FLiPFLOP,                                // ����Ŀ��Ŭ��   �ø��÷�            .
        rCLKdir;                                 // ����Ŀ��Ŭ���� �ø��÷� ���̷���   .
                                                 //=====================================
    int tm_FLiPFLOP,                             // ����Ŀ��ƽ   �ø��÷� ī����       .
        tm_rCLKdir;                              // ����Ŀ��ƽ�� �ø��÷� ���̷���     .
                                                 //=====================================
    ///////
    Cru_SYSTEM() { };
    ~Cru_SYSTEM() { };

    void Reset(void);                            // �ý��� ����                .

        void SET_DiRECTORY(void);                // ���丮 ����              .
        void KERNEL_CLOCK_Generator(void);       // Ŀ��Ŭ�� - ���ʷ�����      .

        char *sYMDHMS(void);                     // ���糯¥�� �ð��� ���ڿ��� ���� (ǥ�������)
        char *fYMDHMS(void);                     // ���糯¥�� �ð��� ���ڿ��� ���� (���Ͻ�����)

    ///////
};
// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.
#endif
