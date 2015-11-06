/**********************************************************************
 *<
	FILE: iterpik.h

	DESCRIPTION:  Implements IK related methods for interp controllers

	CREATED BY: Rolf Berteig

	HISTORY: created 6/19/95

 *>	Copyright (c) 1994, All Rights Reserved.
 **********************************************************************/

#ifndef __INTERPIK_H__
#define __INTERPIK_H__


#define PROPID_INTERPUI		(PROPID_USER+1)
#define PROPID_JOINTPARAMS	(PROPID_USER+2)
#define PROPID_KEYINFO		(PROPID_USER+3)

// Flags for JointParams
#define JNT_XACTIVE		(1<<0)
#define JNT_YACTIVE		(1<<1)
#define JNT_ZACTIVE		(1<<2)
#define JNT_XLIMITED	(1<<3)
#define JNT_YLIMITED	(1<<4)
#define JNT_ZLIMITED	(1<<5)
#define JNT_XEASE		(1<<6)
#define JNT_YEASE		(1<<6)
#define JNT_ZEASE		(1<<6)

#define JNT_LIMITEXACT	(1<<28)
#define JNT_ROLLOPEN	(1<<29)
#define JNT_ROT			(1<<30) 
#define JNT_POS			(1<<31)


class InterpCtrlUI : public AnimProperty {
	public:
		HWND hParams;
		IObjParam *ip;
		Control *cont;
		
		InterpCtrlUI(HWND h,IObjParam *i,Control *c) 
			{hParams=h;ip=i;cont=c;}
		
		~InterpCtrlUI() {}
		DWORD ID() {return PROPID_INTERPUI;}		
	};

class InterpKeyInfo : public AnimProperty {
	public:
		DWORD ID() {return PROPID_KEYINFO;}
		virtual ~InterpKeyInfo() {}
	};


// IK Joint parameters
class JointParams : public AnimProperty {
	public:
		float *min, *max;
		float *damping;
		float scale;
		DWORD flags;
		int dofs;

		CoreExport JointParams(DWORD type=JNT_POS,int dofs=3,float s=1.0f);
		CoreExport JointParams(const JointParams &j);
		CoreExport ~JointParams();
		DWORD ID() {return PROPID_JOINTPARAMS;}

		CoreExport JointParams&  operator=(JointParams& j);

		// Returns TRUE if the curent state is the default.
		CoreExport BOOL IsDefault();
		
		CoreExport IOResult Save(ISave *isave);
		CoreExport IOResult Load(ILoad *iload);

		// Applies contraints to the given delta based on parameters and the current value v.
		CoreExport float ConstrainInc(int index,float v,float delta);		
		
		// Access bits
		BOOL Active(int i) {return (flags&(JNT_XACTIVE<<i))?TRUE:FALSE;}
		BOOL Limited(int i) {return (flags&(JNT_XLIMITED<<i))?TRUE:FALSE;}
		BOOL Ease(int i) {return (flags&(JNT_XEASE<<i))?TRUE:FALSE;}
		DWORD Type() {return flags & (JNT_POS|JNT_ROT);}
		BOOL RollupOpen() {return (flags&JNT_ROLLOPEN)?TRUE:FALSE;}
		void SetActive(int i,BOOL s) {if (s) flags|=(JNT_XACTIVE<<i); else flags&=~(JNT_XACTIVE<<i);}
		void SetLimited(int i,BOOL s) {if (s) flags|=(JNT_XLIMITED<<i); else flags&=~(JNT_XLIMITED<<i);}
		void SetEase(int i,BOOL s) {if (s) flags|=(JNT_XEASE<<i); else flags&=~(JNT_XEASE<<i);}
		void SetType(DWORD type) {flags&=~(JNT_POS|JNT_ROT);flags|=type;}
		void SetRollOpen(BOOL open) {if (open) flags|=JNT_ROLLOPEN; else flags&= ~JNT_ROLLOPEN;}

		// This is the interactive adjustment of limits
		CoreExport virtual void SpinnerChange(InterpCtrlUI *ui,WORD id,ISpinnerControl *spin,BOOL interactive);

		// These methods manage the joint parameters dialog.
		CoreExport void InitDialog(InterpCtrlUI *ui);
		CoreExport void EndDialog(InterpCtrlUI *ui,BOOL dontDel=FALSE);		
		CoreExport void SpinnerDown(InterpCtrlUI *ui,WORD id,ISpinnerControl *spin);
		CoreExport void SpinnerUp(InterpCtrlUI *ui,WORD id,ISpinnerControl *spin,BOOL accept);
		CoreExport void Command(InterpCtrlUI *ui,WORD notify, WORD id, HWND hCtrl);
		CoreExport void EnableDisable(InterpCtrlUI *ui);
	};


// Just holds a couple of pointers.
class JointDlgData {
	public:
		InterpCtrlUI *ui;
		JointParams *jp;	
		JointDlgData(InterpCtrlUI *ui,JointParams *jp) {this->ui=ui;this->jp=jp;}
	};

// A window proc for handling joint parameters.
CoreExport BOOL CALLBACK JointParamDlgProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);


// Handles the IK functions for all types of point3 and quat key frame controllers.
void QuatEnumIKParams(Control *cont,IKEnumCallback &callback);
BOOL QuatCompDeriv(Control *cont,TimeValue t,Matrix3& ptm,IKDeriv& derivs,DWORD flags);
float QuatIncIKParam(Control *cont,TimeValue t,int index,float delta);
CoreExport void QuatBeginIKParams(Control *cont,IObjParam *ip, ULONG flags,Animatable *prev);
void Point3EnumIKParams(Control *cont,IKEnumCallback &callback);
BOOL Point3CompDeriv(Control *cont,TimeValue t,Matrix3& ptm,IKDeriv& derivs,DWORD flags);
float Point3IncIKParam(Control *cont,TimeValue t,int index,float delta);
CoreExport void Point3BeginIKParams(Control *cont,IObjParam *ip, ULONG flags,Animatable *prev);

CoreExport BOOL CanCopyIKParams(Control *cont,int which);
CoreExport IKClipObject *CopyIKParams(Control *cont,int which);
CoreExport BOOL CanPasteIKParams(Control *cont,IKClipObject *co,int which);
CoreExport void PasteIKParams(Control *cont,IKClipObject *co,int which);

CoreExport void InitIKJointsPos(Control *cont,InitJointData *posData);
CoreExport void InitIKJointsRot(Control *cont,InitJointData *rotData);


#endif //__INTERPIK_H__

