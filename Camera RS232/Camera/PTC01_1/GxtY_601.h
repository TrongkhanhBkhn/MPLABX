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

#define MODE_SAVE_POWER					1 //省电模式 
#define MODE_EXIT_SAVE_POWER			2 //退出省电模式

#define	UM_PROCESS_THREAD				WM_USER+0x1000	
#define THREAD_NORMAL_EXIT				1
#define THREAD_FORCE_EXIT				2
		
#define MODE_PHOTO_INVALID				0  //非法值		
#define MODE_PHOTO_ONCE					1  //拍摄单张模式
#define MODE_PHOTO_CONTINUE				2  //持续拍照模式
		 
#define MODE_TRANSFER_ONCE				0
#define MODE_TRANSFER_512BYTE			1

#define BLOCK_SIZE					  512 //接收到512,就可以开始写文件了

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

	//串口打开和关闭
	BOOL OpenPort(CWnd* pPortOwner, UINT portnr, UINT baud, char parity = 'N', UINT databits = 8, UINT stopsbits = 1, DWORD dwCommEvents = EV_RXCHAR | EV_CTS, UINT nBufferSize = 512);
	void ClosePort();
	BOOL IsPortOpen();

	void Reset();

	void SetSerialNum();

	//数据发送的封装
	void SendReset();
	void SendPhoto();
	void SendReadLength();
	void SendReadBuf(DWORD dwStartAddr, DWORD dwLength, UINT nInterval = 255);
	void SendStopPhoto();
	void SendSetZipRate(int nZipRate);
	void SendImageSize(int nModeImageSize);
	void SendSavePower(int nModePower);
	void SendBaud(UINT nBaud);

	//处理串口数据
	void OnRevSerData();

	//向缓冲区添加串口数据
	void AddSerData(BYTE *pData, WORD wLen);

	//通知串口数据到达事件
	void IndRevSerData();

	//消息队列,有了消息队列可以重发
	void AddCmdToQueue(int nCmd);
	//返回头
	int  QueryCmd();

	void DeleteCmd();

	void DeleteAllCmd();

	BOOL IsCmdEmpty();

	BOOL			m_bRecvFrameHead;
	
	BOOL			m_bFindFrameEnd;

	BOOL			m_bStart;
	//一次读的buf
	DWORD			m_dwRead;
	//文件长度
	DWORD			m_dwTotalLen;
	//已经写入的长度
	DWORD			m_dwWriteLen;

	int				m_nTransmitMode;

	BOOL			m_bWaitThisFrameEnd; //等待该帧结束标识

	BOOL			m_bWaitLastFrame;

private:
	CSerialPort			m_SerialPort;

	CRITICAL_SECTION	m_csBuf;
	CArray<BYTE, BYTE>	m_ArrBuf;

	

	CArray<int, int>    m_ArrCmdQueue;
	CRITICAL_SECTION	m_csCmdQueue;
	//通知父类写文件

	static	UINT	RecvBufProc(LPVOID LParam);	   //接收线程函数
	int				StartProcessThread();
	int 			StopProcessThread();
	
	HANDLE          hEventShut;			// close thread handle
	CWinThread		*pProcessThread;	// pointer to thread
	BOOL			bRun;

	HWND			m_hParentWnd;

	//是否正在写文件,如果是则当前接收串口的数据是文件buf
	BOOL			m_bIsWritingBuf;
	BOOL			m_bFirstFrame;

	BOOL			m_bPortOpen;

};

#endif // !defined(AFX_GXTY6011_H__CAF8F436_A070_4DC4_8E73_1B29FCC8D04B__INCLUDED_)
