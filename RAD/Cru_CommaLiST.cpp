#include "./RAD/Cru_CommaLiST.h"

#include <Windows.h>
// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.
// iList �޸�����Ʈ �ӿ� �Ķ��Ÿ���� s��ġ�� iSTR ���ڿ��� ����
// s��ġ�� 0 �̸�, �������� �߰�
char *ADD_jCOMMA_List(char *iList, int iSEL, char *iSTR)
{
    char rtn[4096];

    int LastSEL;
    int Len,cnt;
    int n;

    char Jam[10];

    char Ruby1[1024];
    char Ruby2[1024];
    //���������������������
    LastSEL = paraCNT_jCOMMA_List(iList);

    Len = lenSTR(iList);

    n = 1;
    cnt = 1;

    memset(Ruby1, 000, sizeof(Ruby1));
    memset(Ruby2, 000, sizeof(Ruby2));

        //�̢̢̢̢̢̢̢̢̢�
        // ������ ��ġ���� �߰��ΰ� ?
        if(iSEL==000)
        {
            if(LastSEL==000) cpSTR(rtn, iSTR);
            else
            {
                cpSTR(rtn, iList);
                adSTR(rtn, ",");
                adSTR(rtn, iSTR);
            }

            return rtn;
        }
        //�̢̢̢̢̢̢̢̢̢�
        while(cnt<iSEL)
        {
            subcpSTR(Jam, iList, n, 1);

            cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

            if(cnt < iSEL)
            {
                cpSTR(Ruby1, adSTR(Ruby1, Jam));
            }

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�
        while(n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            cpSTR(Ruby2, adSTR(Ruby2, Jam));

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�


// ù��° �Ķ��Ÿ ��ġ�� �����ΰ� ?
if(iSEL==1)
{
    if(LastSEL==1) cpSTR(rtn, iSTR);
    else
    {
        cpSTR(rtn, iSTR);
        adSTR(rtn, ",");
        adSTR(rtn, Ruby2);
    }
}
// �߰� or ������ �Ķ��Ÿ ��ġ�� �����ΰ� ?
else
{
    cpSTR(rtn, Ruby1);
    adSTR(rtn, ",");
    adSTR(rtn, iSTR);
    adSTR(rtn, ",");
    adSTR(rtn, Ruby2);
}


    //���������������������
    return rtn;
}
//==============================================================================
// iList �޸�����Ʈ �ӿ� �Ķ��Ÿ���� s��ġ�� iSTR ���ڿ��� ��ü
char *CHG_jCOMMA_List(char *iList, int iSEL, char *iSTR)
{
    char rtn[4096];

    int LastSEL;
    int Len,cnt;
    int n;

    char Jam[10];

    char Ruby1[1024];
    char Ruby2[1024];
    //���������������������
    LastSEL = paraCNT_jCOMMA_List(iList);

    Len = lenSTR(iList);

    n = 1;
    cnt = 1;

    memset(Ruby1, 000, sizeof(Ruby1));
    memset(Ruby2, 000, sizeof(Ruby2));

        //�̢̢̢̢̢̢̢̢̢�
        while(cnt<iSEL)
        {
            subcpSTR(Jam, iList, n, 1);

            cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

            if(cnt < iSEL)
            {
                cpSTR(Ruby1, adSTR(Ruby1, Jam));
            }

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�
        memset(Jam, 000, sizeof(Jam));
        ++n;

        while(!eqSTR(Jam,",") && n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�
        while(n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            cpSTR(Ruby2, adSTR(Ruby2, Jam));

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�


// ù��° �Ķ��Ÿ ��ġ�� ��ü�ΰ� ?
if(iSEL==1)
{
    cpSTR(rtn, iSTR);
    adSTR(rtn, ",");
    adSTR(rtn, Ruby2);
}
// ������ �Ķ��Ÿ ��ġ�� ��ü�ΰ� ?
else if(iSEL==LastSEL)
{
    cpSTR(rtn, Ruby1);
    adSTR(rtn, ",");
    adSTR(rtn, iSTR);
}
// �߰� �Ķ��Ÿ ��ġ�� ��ü�ΰ� ?
else
{
    cpSTR(rtn, Ruby1);
    adSTR(rtn, ",");
    adSTR(rtn, iSTR);
    adSTR(rtn, ",");
    adSTR(rtn, Ruby2);
}

    //���������������������
    return rtn;
}
//==============================================================================
// iList �޸�����Ʈ �ӿ� �Ķ��Ÿ���� s��ġ�� iSTR ���ڿ��� ����
char *DEL_jCOMMA_List(char *iList, int iSEL)
{
    char rtn[4096];

    int LastSEL;
    int Len,cnt;
    int n;

    char Jam[10];

    char Ruby1[1024];
    char Ruby2[1024];
    //���������������������
    LastSEL = paraCNT_jCOMMA_List(iList);

    Len = lenSTR(iList);

    n = 1;
    cnt = 1;

    memset(Ruby1, 000, sizeof(Ruby1));
    memset(Ruby2, 000, sizeof(Ruby2));

        //�̢̢̢̢̢̢̢̢̢�
        while(cnt<iSEL)
        {
            subcpSTR(Jam, iList, n, 1);

            cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

            if(cnt < iSEL)
            {
                cpSTR(Ruby1, adSTR(Ruby1, Jam));
            }

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�
        memset(Jam, 000, sizeof(Jam));
        ++n;

        while(!eqSTR(Jam,",") && n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�
        while(n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            cpSTR(Ruby2, adSTR(Ruby2, Jam));

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�


// ù��° �Ķ��Ÿ ��ġ�� �����ΰ� ?
if(iSEL==1)
{
    cpSTR(rtn, Ruby2);
}
// ������ �Ķ��Ÿ ��ġ�� �����ΰ� ?
else if(iSEL==LastSEL)
{
    cpSTR(rtn, Ruby1);
}
// �߰� �Ķ��Ÿ ��ġ�� �����ΰ� ?
else
{
    cpSTR(rtn, Ruby1);
    adSTR(rtn, ",");
    adSTR(rtn, Ruby2);
}

    //���������������������
    return rtn;
}
//==============================================================================
// iList �޸�����Ʈ �ӿ� iSEL ��ġ�� ���ڿ� ȹ��
char *jCOMMA_List(char *iList, int iSEL)
{
    char rtn[4096];

    int Len,cnt;
    int n;

    char Jam[10];

    char Ruby[1024];
    //���������������������
    Len = lenSTR(iList);

    n = 1;
    cnt = 1;

    memset(Ruby, 000, sizeof(Ruby));

        //�̢̢̢̢̢̢̢̢̢�
        while(n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            if(eqSTR(Jam,","))
            {
                ++cnt;
            }
            else
            {
                //�̢̢̢̢̢̢̢̢̢�
                // �޸�ī��Ʈ�� ��ġ�ϸ� �ܾ�����
                if(cnt==iSEL)
                {
                    cpSTR(Ruby, adSTR(Ruby, Jam));
                }
                //�̢̢̢̢̢̢̢̢̢�
            }

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�

    //���������������������
    cpSTR(rtn, Ruby);

    return rtn;
}
//==============================================================================
// iList �޸�����Ʈ �ӿ� �Ķ��Ÿ ��ü���� ȹ��
int  paraCNT_jCOMMA_List(char *iList)
{
    int rtn;

    int Len,cnt;
    int n;

    char Jam[10];
    //���������������������
    Len = lenSTR(iList);

    n = 1;
    cnt = 1;

        //�̢̢̢̢̢̢̢̢̢�
        while(n<=Len)
        {
            subcpSTR(Jam, iList, n, 1);

            cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�
        if(n==1) cnt = 0;

    //���������������������
    rtn = cnt;

    return rtn;
}
//==============================================================================
// iList �޸�����Ʈ �ӿ� iPARA ���ڿ��� ���° �޸���ġ�� �ִ��� ���
int  SEQ_jCOMMA_List(char *iList, char *iPARA)
{
    int rtn;

    int Len,cnt;
    int n,f;

    char Jam[10];
    //���������������������
    Len = lenSTR(iList);

    f = fdSTR(iList, iPARA);

        if(f==0) return 000;

        n = 1;
        cnt = 1;
        //�̢̢̢̢̢̢̢̢̢�
        while(n<=f)
        {
            subcpSTR(Jam, iList, n, 1);

            cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

            ++n;
        }
        //�̢̢̢̢̢̢̢̢̢�

    //���������������������
    rtn = cnt;

    return rtn;
}
//==============================================================================
// iList �޸�����Ʈ �ӿ� �Ķ��Ÿ���� s1��ġ�� s2��ġ ���ڿ��� ��ȯ
char *SWAP_jCOMMA_List(char *iList, int iSEL1, int iSEL2)
{
    char rtn[4096];

    int LastSEL;

    int  Len,cnt;
    int n,k,p1,p2;

    char Jam[10];
    char kSTR[1024];

    char Gold1[1024];
    char Gold2[1024];

    char Ruby1[1024];
    char Ruby2[1024];
    char Ruby3[1024];
    //���������������������
    LastSEL = paraCNT_jCOMMA_List(iList);

    p1 = iSEL1;
    p2 = iSEL2;

        // �μ� ����
        if(p2 < p1) { k = p1; p1 = p2; p2 = k; }

        // ����ó�� Ʈ��
        memset(rtn, 000, sizeof(rtn));
        memset(Jam, 000, sizeof(Jam));

        if(p1==0) cpSTR(Jam, "$zeroPOS1");
        if(p2==0) cpSTR(Jam, "$zeroPOS2");

        if(LastSEL<p1) cpSTR(Jam, "$overPOS1");
        if(LastSEL<p2) cpSTR(Jam, "$overPOS2");

        if(p1==p2) cpSTR(Jam, "$samePOS");

        if(Jam[0]=='$')
        {
            cpSTR(rtn, Jam);
            goto EXiT_SWAP_jCOMMA_List;
        }

        Len = lenSTR(iList);
        //�̢̢̢̢̢̢̢̢̢�
        // �±�ȯ�� �μ����ڿ� ����

            cpSTR(Gold1, jCOMMA_List(iList, p1));
            cpSTR(Gold2, jCOMMA_List(iList, p2));

        //�̢̢̢̢̢̢̢̢̢�
        memset(Ruby1, 000, sizeof(Ruby1));
        memset(Ruby2, 000, sizeof(Ruby2));
        memset(Ruby3, 000, sizeof(Ruby3));

        //�âââââââââââââââââââ�
        //�âââââââââââââââââââ�
        n = 1;
        cnt = 1;
        //----------
        if(1 < p1)
        {
            while(n<=Len)
            {
                subcpSTR(Jam, iList, n, 1);

                cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

                if(cnt < p1)
                {
                    adSTR(Ruby1, Jam);
                }

                ++n;
            }
        }
        //�âââââââââââââââââââ�
        //�âââââââââââââââââââ�
        n = 1;
        cnt = 1;
        //----------
        if(1 < p2-p1)
        {
            while(n<=Len)
            {
                subcpSTR(Jam, iList, n, 1);

                cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

                if(iBNDchk(p1+1, cnt, p2-1))
                {
                    adSTR(Ruby2, Jam);
                }

                ++n;
            }

            subcpSTR(kSTR, Ruby2, 2, lenSTR(Ruby2)-1);
            cpSTR(Ruby2, kSTR);
        }
        //�âââââââââââââââââââ�
        //�âââââââââââââââââââ�
        n = 1;
        cnt = 1;
        //----------
        if(p2 < LastSEL)
        {
            while(n<=Len)
            {
                subcpSTR(Jam, iList, n, 1);

                cnt = (eqSTR(Jam, ","))? cnt+1 : cnt;

                if(p2 < cnt)
                {
                    adSTR(Ruby3, Jam);
                }

                ++n;
            }

            subcpSTR(kSTR, Ruby3, 2, lenSTR(Ruby3)-1);
            cpSTR(Ruby3, kSTR);
        }
        //�âââââââââââââââââââ�
        //�âââââââââââââââââââ�


//----------
if(p1==1)
{
    if(p2==2)
    {
        cpSTR(rtn, Gold2);
        adSTR(rtn, ",");
        adSTR(rtn, Gold1);
        adSTR(rtn, ",");
        adSTR(rtn, Ruby3);
    }
    else
    {
        if(p2==LastSEL)
        {
            cpSTR(rtn, Gold2);
            adSTR(rtn, ",");
            adSTR(rtn, Ruby2);
            adSTR(rtn, ",");
            adSTR(rtn, Gold1);
        }
        else
        {
            cpSTR(rtn, Gold2);
            adSTR(rtn, ",");
            adSTR(rtn, Ruby2);
            adSTR(rtn, ",");
            adSTR(rtn, Gold1);
            adSTR(rtn, ",");
            adSTR(rtn, Ruby3);
        }
    }
}
//----------
else if(p2==LastSEL)
{
    if(p1==LastSEL-1)
    {
        cpSTR(rtn, Ruby1);
        adSTR(rtn, ",");
        adSTR(rtn, Gold2);
        adSTR(rtn, ",");
        adSTR(rtn, Gold1);
    }
    else
    {
        cpSTR(rtn, Ruby1);
        adSTR(rtn, ",");
        adSTR(rtn, Gold2);
        adSTR(rtn, ",");
        adSTR(rtn, Ruby2);
        adSTR(rtn, ",");
        adSTR(rtn, Gold1);
    }
}
//----------
else
{
    cpSTR(rtn, Ruby1);
    adSTR(rtn, ",");
    adSTR(rtn, Gold2);
    adSTR(rtn, ",");
    adSTR(rtn, Ruby2);
    adSTR(rtn, ",");
    adSTR(rtn, Gold1);
    adSTR(rtn, ",");
    adSTR(rtn, Ruby3);
}
//----------


EXiT_SWAP_jCOMMA_List:

    //���������������������
    return rtn;
}
// ���������������������������������������.
//����������������������������������������
// ���������������������������������������.
