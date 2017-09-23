// GxtY6011.h: interface for the CGxtY601 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GXTY6011_H__CAF8F436_A070_4DC4_8E73_1B29FCC8D04B__INCLUDED_)
#define AFX_GXTY6011_H__CAF8F436_A070_4DC4_8E73_1B29FCC8D04B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
 
#include <afxtempl.h>
#include "GxtY601Dlg.h"
#include "SerialPort.h"
#include "Config.h"

#define TIME_OUT_PROCESS			   30

#define MIN_ZIP_RATE				   10                       
#define MAX_ZIP_RATE                   50

#define MODE_IMAGE_SIZE_320X240			1 //320*240
#define MODE_IMAGE_SIZE_640X480			2 //640*480

#define MODE_SAVE_POWER					1 //ʡ��ģʽ 
#define MODE_EXIT_SAVE_POWER			2 //�˳�ʡ��ģʽ

#define	UM_PROCESS_THREAD				WM_USER+0x1000	
#define THREAD_NORMAL_EXIT				1
#define THREAD_FORCE_EXIT				2
		
#define MODE_PHOTO_INVALID				0  //�Ƿ�ֵ		
#define MODE_PHOTO_ONCE					1  //���㵥��ģʽ
#define MODE_PHOTO_CONTINUE				2  //��������ģʽ
		 
#define MODE_TRANSFER_ONCE				0
#define MODE_TRANSFER_512BYTE			1

#define BLOCK_SIZE					  512 //���յ�512,�Ϳ��Կ�ʼд�ļ���

#define CMD_INVALID						0
#define CMD_RESET						1
#define CMD_PHOTO						2
#define CMD_STOP_PHOTO					3
#define CMD_READ_LENGTH					4
#define CMD_READ_BUF_512				5
#define CMD_READ_BUF_TOTAL				6
#define CMD_ZIP_RATE					7
#define CMD_SAVE_POWER					8
#define CMD_EXIT_SAVE_POWER				9
#define CMD_MODIFY_BAUD				   10
#define CMD_MODIFY_IMAGE_SIZE			11
					
class CGxtY601 : public CObject  
{
public:
	CGxtY601Dlg* m_pDlg;

	CGxtY601(HWND hParent);
	virtual ~CGxtY601();
	
public:

	//���ڴ򿪺͹ر�
	BOOL OpenPort(CWnd* pPortOwner, UINT portnr, UINT baud, char parity = 'N', UINT databits = 8, UINT stopsbits = 1, DWORD dwCommEvents = EV_RXCHAR | EV_CTS, UINT nBufferSize = 512);
	void ClosePort();
	BOOL IsPortOpen();

	void Reset();

	void SetSerialNum();

	//���ݷ��͵ķ�װ
	void SendReset();
	void SendPhoto();
	void SendReadLength();
	void SendReadBuf(DWORD dwStartAddr, DWORD dwLength, UINT nInterval = 255);
	void SendStopPhoto();
	void SendSetZipRate(int nZipRate);
	void SendImageSize(int nModeImageSize);
	void SendSavePower(int nModePower);
	void SendBaud(UINT nBaud);

	//����������
	void OnRevSerData();

	//�򻺳�����Ӵ�������
	void AddSerData(BYTE *pData, WORD wLen);

	//֪ͨ�������ݵ����¼�
	void IndRevSerData();

	//��Ϣ����,������Ϣ���п����ط�
	void AddCmdToQueue(int nCmd);
	//����ͷ
	int  QueryCmd();

	void DeleteCmd();

	void DeleteAllCmd();

	BOOL IsCmdEmpty();

	BOOL			m_bRecvFrameHead;
	
	BOOL			m_bFindFrameEnd;

	BOOL			m_bStart;
	//һ�ζ���buf
	DWORD			m_dwRead;
	//�ļ�����
	DWORD			m_dwTotalLen;
	//�Ѿ�д��ĳ���
	DWORD			m_dwWriteLen;

	int				m_nTransmitMode;

	BOOL			m_bWaitThisFrameEnd; //�ȴ���֡������ʶ

	BOOL			m_bWaitLastFrame;

private:
	CSerialPort			m_SerialPort;

	CRITICAL_SECTION	m_csBuf;
	CArray<BYTE, BYTE>	m_ArrBuf;

	

	CArray<int, int>    m_ArrCmdQueue;
	CRITICAL_SECTION	m_csCmdQueue;
	//֪ͨ����д�ļ�

	static	UINT	RecvBufProc(LPVOID LParam);	   //�����̺߳���
	int				StartProcessThread();
	int 			StopProcessThread();
	
	HANDLE          hEventShut;			// close thread handle
	CWinThread		*pProcessThread;	// pointer to thread
	BOOL			bRun;

	HWND			m_hParentWnd;

	//�Ƿ�����д�ļ�,�������ǰ���մ��ڵ��������ļ�buf
	BOOL			m_bIsWritingBuf;
	BOOL			m_bFirstFrame;

	BOOL			m_bPortOpen;

};

#endif // !defined(AFX_GXTY6011_H__CAF8F436_A070_4DC4_8E73_1B29FCC8D04B__INCLUDED_)
