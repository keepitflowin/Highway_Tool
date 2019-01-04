#include "./RAD/Cru_HEADER.h"

// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.
// �ܺ����� ��������

extern Cru_DEBUG   sysDBG;                       // �� DeBUG                   .
extern Cru_PARSiNG sysPAR;                       // �� Parsing                 .
extern Cru_TiMER   sysTMR;                       // �� Timer                   .

extern Cru_SYSTEM xSYS;                          // �ý��� ��ü                .

extern Cru_SCRiPT xSCR;                          // ��ũ��Ʈ ��ü              .

extern void PROC_SHT_Zoom(int iZOOM);
extern void PROC_TBL_Zoom(int iZOOM);

// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.
void Cru_SYSTEM::Reset(void)
{
    char iSQ_FiLE[256];

    int iSQ_ReadCNT;
    int iSQ_stCNT, iSQ_edCNT;

    int iSQ_LineCNT;

    char wSTR[300], fSTR[300];
    HRESULT r;
    int n;

    int w,h,Pw,Ph;

    // ������ ��迭
    srand(GetTickCount());

    // Ÿ�̹� �ʱ�ȭ
    DBG_SetLatency();

    // ���丮 ����
    SET_DiRECTORY();

    /*                                              */ 
    /**/  zALREADY_Kernel_iSQrun = 0x0;           /**/
    /*                                              */
    /*  �� Ŀ�� ��ũ��Ʈ ����                       */
    /*                                              */
    /**/                                          /**/
    /**/  cpSTR(iSQ_FiLE, xSYS.resDiR);           /**/
    /**/  adSTR(iSQ_FiLE, "1_Kernel.isq");        /**/
    /**/                                          /**/
    /**/  iSQ_stCNT = xSCR.scr_readLiNE+1;        /**/
    /**/                                          /**/
    /**/      xSCR.qSCRread(iSQ_FiLE);            /**/
    /**/                                          /**/
    /**/  iSQ_ReadCNT = xSCR.scr_readLiNE         /**/
    /**/              - iSQ_stCNT +1;             /**/
    /**/  iSQ_edCNT = iSQ_stCNT + iSQ_ReadCNT -1; /**/
    /**/                                          /**/
    /**/  cpSTR(xSCR.scr_execSTAT, "Kernel");     /**/
    /**/  xSCR.qSCRexec(iSQ_stCNT, iSQ_edCNT);    /**/
    /**/                                          /**/
    /*                                              */
    /*  �� �����ʵ� ��ũ��Ʈ ����                   */
    /*                                              */
    /**/                                          /**/
    /**/  cpSTR(iSQ_FiLE, xSYS.resDiR);           /**/
    /**/  adSTR(iSQ_FiLE, "2_main_FLDs.isq");     /**/
    /**/                                          /**/
    /**/  iSQ_stCNT = xSCR.scr_readLiNE+1;        /**/
    /**/                                          /**/
    /**/      xSCR.qSCRread(iSQ_FiLE);            /**/
    /**/                                          /**/
    /**/  iSQ_ReadCNT = xSCR.scr_readLiNE         /**/
    /**/              - iSQ_stCNT +1;             /**/
    /**/  iSQ_edCNT = iSQ_stCNT + iSQ_ReadCNT -1; /**/
    /**/                                          /**/
    /**/  cpSTR(xSCR.scr_execSTAT, "main_FLDs");  /**/
    /**/  xSCR.qSCRexec(iSQ_stCNT, iSQ_edCNT);    /**/
    /**/                                          /**/
    /*                                              */
    /*  �� �ڵ������ʵ� ��ũ��Ʈ ����               */
    /*                                              */
    /**/                                          /**/
    /**/  cpSTR(iSQ_FiLE, xSYS.resDiR);           /**/
    /**/  adSTR(iSQ_FiLE, "3_save_FLDs.isq");     /**/
    /**/                                          /**/
    /**/  iSQ_stCNT = xSCR.scr_readLiNE+1;        /**/
    /**/                                          /**/
    /**/      xSCR.qSCRread(iSQ_FiLE);            /**/
    /**/                                          /**/
    /**/  iSQ_ReadCNT = xSCR.scr_readLiNE         /**/
    /**/              - iSQ_stCNT +1;             /**/
    /**/  iSQ_edCNT = iSQ_stCNT + iSQ_ReadCNT -1; /**/
    /**/                                          /**/
    /**/  cpSTR(xSCR.scr_execSTAT, "save_FLDs");  /**/
    /**/  xSCR.qSCRexec(iSQ_stCNT, iSQ_edCNT);    /**/
    /**/                                          /**/
    /*                                              */
    /**/  zALREADY_Kernel_iSQrun = 0x1;           /**/
    /*                                              */

    zGOOGLE_Link = 0x0;
    PGM->uSHT_Show_BTN->Enabled = 0x0;

    PGM->uSHT_Zoom_BTN->Enabled = 0x0;
    PGM->uTBL_Zoom_BTN->Enabled = 0x0;

    PROC_SHT_Zoom(-1);
    PROC_TBL_Zoom(-1);

    // Ÿ�̹� �ʱ�ȭ
    clk          = 000;
    FLiPFLOP     = 000;
    rCLKdir      =  +1;

    tm_FLiPFLOP  = 000;
    tm_rCLKdir   =  +1;

    tm_MAiN.Go(0.100);
}
//==============================================================================
void Cru_SYSTEM::SET_DiRECTORY(void)
{
    char w[256];

    cpSTR(w, "RES/");
    ///////
//    cpSTR(runDiR, GetCurrentDir().c_str());
    _getcwd(runDiR, sizeof(runDiR));

    cpSTR(resDiR, runDiR);
    adSTR(resDiR, "/");
    adSTR(resDiR, w);
    ///////
//    if(!CHECK_FileEXiST(resDiR))
//    adSTR(resDiR, "/");

    ///////
//    SetCurrentDir(runDiR);
    chdir(runDiR);
}
//==============================================================================
void Cru_SYSTEM::KERNEL_CLOCK_Generator(void)
{
    //��������
    // ����Ŀ��Ŭ��
    clk  = (clk<255)? clk+1 : 000;
    // ����Ŀ��Ŭ�� �ø��÷�
    FLiPFLOP = FLiPFLOP + rCLKdir;
    rCLKdir = (clk==000)? -rCLKdir : rCLKdir;
    //��������
    if(tm_MAiN.Reach())
    {
        // ����Ŀ�� Ÿ�̹� �ø��÷�
        tm_FLiPFLOP = tm_FLiPFLOP + tm_rCLKdir;
        tm_rCLKdir = (tm_MAiN.CNT==000)? -tm_rCLKdir : tm_rCLKdir;
    }
    //��������
}
//==============================================================================
char *Cru_SYSTEM::sYMDHMS(void)
{
/*
    char r[300];
    AnsiString sD,sT;
    TDateTime gD,gT;
    //                                                                         .
    gD = Date();
    gT = Time();

    DateTimeToString(sD, "yyyy/mm/dd", gD);
    DateTimeToString(sT, "hh:mm:ss",   gT);
    ///////
    cpSTR(r, sD.c_str());
    adSTR (r, " ");
    adSTR (r, sT.c_str());
    //                                                                         .
    return r;
*/
    return 000;
}
//==============================================================================
char *Cru_SYSTEM::fYMDHMS(void)
{
/*
    char r[300];
    AnsiString sD,sT;
    TDateTime gD,gT;
    //                                                                         .
    gD = Date();
    gT = Time();

    DateTimeToString(sD, "yyyymmdd", gD);
    DateTimeToString(sT, "hhmmss",   gT);
    ///////
    cpSTR(r, sD.c_str());
    adSTR (r, "_");
    adSTR (r, sT.c_str());
    //                                                                         .
    return r;
*/
    return 000;
}
// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.