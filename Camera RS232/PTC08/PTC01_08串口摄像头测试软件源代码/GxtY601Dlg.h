// GxtY601Dlg.h : header file
//

#if !defined(AFX_GXTY601DLG_H__26FA5FAF_0445_4FC3_9876_FCF98E6C2957__INCLUDED_)
#define AFX_GXTY601DLG_H__26FA5FAF_0445_4FC3_9876_FCF98E6C2957__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGxtY601Dlg dialog
#include "resource.h"
#include "ImageStatic.h"
#include "BmpStatic.h"

//拍照的操作间隔5ms
#define OPERATE_INTERVAL		5

#define STEP_START_PHOTO		1
#define STEP_READ_LENGTH		2
#define STEP_READ_BUF			3
#define STEP_STOP_PHOTO			4

class CGxtY601;

class CGxtY601Dlg : public CDialog
{
// Construction
public:
	CGxtY601Dlg(CWnd* pParent = NULL);	// standard constructor
	~CGxtY601Dlg();
// Dialog Data
	//{{AFX_DATA(CGxtY601Dlg)
	enum { IDD = IDD_GXTY601_DIALOG };
	CListBox	m_ListDebug;
	CProgressCtrl	m_Progress;
	CComboBox	m_ComboPhotoBaud;
	CImageStatic m_Picture;
	CComboBox	m_ComboPortNum;
	CComboBox	m_ComboBaud;
	CString		m_strPath;
	int		m_nImageSize;
	int		m_nTransmitByte;
	int		m_nSavePower;
	int		m_nSerialNum;
	CBmpStatic m_Logo;
	CString	m_strDebug;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGxtY601Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InitValue();
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CGxtY601Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSetZipRate();
	afx_msg void OnBtnBrowse();
	afx_msg void OnBtnOnePhoto();
	afx_msg void OnBtnContinuesPhoto();
	afx_msg void OnBtnStopPhoto();
	afx_msg void OnBtnReset();
	afx_msg void OnBtnExit();
	afx_msg void OnBtnClosePort();
	afx_msg void OnBtnOpenPort();
	afx_msg void OnRadioImageSize320x240();
	afx_msg void OnRadioImageSize640x480();
	afx_msg void OnRadioTransmitOnce();
	afx_msg void OnRadioTransmit512byte();
	afx_msg void OnRadioSavePower();
	afx_msg void OnRadioExitSavePower();
	afx_msg void OnSelchangeComboBaud();
	afx_msg void OnBtnModifyBaud();
	afx_msg void OnBtnSavePicture();
	afx_msg void OnBtnClearDebug();
	//}}AFX_MSG
	afx_msg LRESULT OnProcessThread(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:

	CString     m_strCurrentShowPic;

	BOOL		m_bContinueShot;

	BOOL		m_nWorkMode; //正在执行拍照,禁止修改参数

	BOOL		m_bFileClose;
	BOOL		m_bFileOpen;
	BOOL		m_bPortOpen;
	CGxtY601*	m_pGxtY601;

	BOOL		m_bSavePhto;
	void	ReportInfo(CString strInfo);
	void	ReportError(CString strError);

	void	PhotoNext();

	void	SetFileLength(DWORD dwLength);

	/************************************************************************/
	/*文件操作                                                              */
	/************************************************************************/
	//接收到第一帧,开始写文件
	int		CreateWriteFile();

	//写缓冲区数据到文件中
	int		WriteBufToFile(BYTE* pBuf, UINT nBufLen);

	//文件接收完毕
	int		EndWriteFile();

	void	DoShowPicture();
	
	void	DoSendReadLength();


	//通知串口数据到达事件
	void	IndRevJpegData();

	void	PhotoOnce();

	void    PhotoStop();
private:


	void	UpdateControls();

	CFile	m_File;
	CString m_strFileName; //文件名
	BOOL	m_bCreateNewFile; //文件是否创建
	DWORD	m_dwTotalLenth; //文件的长度
	DWORD	m_dwWriteLength; //已经读取的文件长度
	BOOL	m_bWriteFinish;

	void	ShowJpegFile();


	int		m_nCurrentStep;

	static	UINT	ProcessBufProc(LPVOID LParam); //线程函数
	int				StartProcessThread();
	int 			StopProcessThread();

	HANDLE			hEventPhotoNext;	//用于拍摄下一张
	HANDLE          hEventShut;			// close thread handle
	HANDLE			hSendCmd;		// serial data ready handle
	CWinThread		*pProcessThread;	// pointer to thread
	BOOL			bRun;

	CRITICAL_SECTION	m_cs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GXTY601DLG_H__26FA5FAF_0445_4FC3_9876_FCF98E6C2957__INCLUDED_)
