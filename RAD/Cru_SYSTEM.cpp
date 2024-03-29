#include "./RAD/Cru_HEADER.h"

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■.
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■.
// 외부참조 전역변수

extern Cru_DEBUG   sysDBG;                       // ● DeBUG                   .
extern Cru_PARSiNG sysPAR;                       // ● Parsing                 .
extern Cru_TiMER   sysTMR;                       // ● Timer                   .

extern Cru_SYSTEM xSYS;                          // 시스템 개체                .

extern Cru_SCRiPT xSCR;                          // 스크립트 개체              .

extern void PROC_SHT_Zoom(int iZOOM);
extern void PROC_TBL_Zoom(int iZOOM);

// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■.
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■.
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

    // 난수씨 재배열
    srand(GetTickCount());

    // 타이밍 초기화
    DBG_SetLatency();

    // 디렉토리 설정
    SET_DiRECTORY();

    /*                                              */ 
    /**/  zALREADY_Kernel_iSQrun = 0x0;           /**/
    /*                                              */
    /*  ★ 커널 스크립트 실행                       */
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
    /*  ★ 메인필드 스크립트 실행                   */
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
    /*  ★ 자동저장필드 스크립트 실행               */
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

    // 타이밍 초기화
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
    //■■■■■■■
    // 순차커널클럭
    clk  = (clk<255)? clk+1 : 000;
    // 순차커널클럭 플립플롭
    FLiPFLOP = FLiPFLOP + rCLKdir;
    rCLKdir = (clk==000)? -rCLKdir : rCLKdir;
    //■■■■■■■
    if(tm_MAiN.Reach())
    {
        // 순차커널 타이밍 플립플롭
        tm_FLiPFLOP = tm_FLiPFLOP + tm_rCLKdir;
        tm_rCLKdir = (tm_MAiN.CNT==000)? -tm_rCLKdir : tm_rCLKdir;
    }
    //■■■■■■■
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
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■.
//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
// ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■.
