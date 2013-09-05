/*! \file   Camera.h
    \brief  Interface of the CCamera class.
    
    $Id: Camera.h 90910 2009-10-15 10:31:25Z terry $
    */
    
#pragma once

#ifndef _BASE_CAMERA_H_
#define _BASE_CAMERA_H_
#include "_EngineHeader/EngineCommon.h"

#include "_EngineHeader/EngineCommon.h"

/*! \enum CAMERAMODE
    types of camera mode, such as base, first-person.
    */
enum CAMERAMODE
{
    BASE_CAMERA,
    FIRST_CAMERA,
    BACK_CAMERA,
    BACK_FLY_CAMERA,
	TOOL_CAMERA,
	ORIGIN_CAMERA,
    MAX_CAMERAMODE
};


/*! \class CCamera
    Base class of camera system. 
    provide basic data and method.
    */
class CCamera
{
public:  
    const CAMERAMODE GetMode() const    { return m_Mode; }

    const D3DXVECTOR3* GetEyePt() const      { return &m_vEye; }
    const D3DXVECTOR3* GetLookAtPt() const   { return &m_vLookAt; }
    const D3DXVECTOR3* GetUpVecPt() const      { return &m_vUpVec; }
    
    float GetFOV() const        { return m_fFOV; }
    float GetAspect() const     { return m_fAspect; }
    float GetNearPlane() const  { return m_fNearPlane; }
    float GetFarPlane() const   { return m_fFarPlane; }
	float GetWidth() const		{ return m_fWidth; }
	float GetHeight() const		{ return m_fHeight; }
    
    const D3DXMATRIX* GetView() const       { return &m_mView; }
    const D3DXMATRIX* GetProj() const       { return &m_mProj; }
    const D3DXMATRIX* GetBillboard() const  { return &m_mBillboard; }

    void SetEye( const D3DXVECTOR3& vEye )          { m_vEye = vEye; }
    void SetLookAt( const D3DXVECTOR3& vLookAt )    { m_vLookAt = vLookAt; }
    void SetUpVec( const D3DXVECTOR3& vUpVec )      { m_vUpVec = vUpVec; }
    
    void SetFOV( float fDiv )   { m_fFOV = D3DX_PI / fDiv; }
    void SetWidthHeight( int nWidth, int nHeight ) { m_fWidth = (float)nWidth; m_fHeight = (float)nHeight; m_fAspect = (float)nWidth / (float)nHeight; }
    void SetPlane( float fNearPlane, float fFarPlane )  { m_fNearPlane = fNearPlane; m_fFarPlane = fFarPlane; }

	void SetProj( D3DXMATRIX& mProj ) { m_mProj = mProj; }
                       
    virtual void UpdateViewParams();
    virtual void UpdateProjParams();

    virtual BOOL IsCtrl() const       { return FALSE; }
    virtual BOOL IsLockable() const   { return FALSE; }
	virtual BOOL Reset() { return TRUE; }

    virtual void FrameMove();
    virtual void Transform( LPDIRECT3DDEVICE9 pd3dDevice );

    
    CCamera();
    virtual ~CCamera();

protected:
	CAMERAMODE  m_Mode;             //!< Camera mode

	D3DXVECTOR3 m_vEye;             //!< Camera eye position
	D3DXVECTOR3 m_vLookAt;          //!< LookAt position
	D3DXVECTOR3 m_vUpVec;           //!< Up dirction

	float       m_fFOV;             //!< Field of view
	float       m_fAspect;          //!< Aspect ratio
	float       m_fNearPlane;       //!< Near plane
	float       m_fFarPlane;        //!< Far plane
	float		m_fWidth;			//!< Camera Width
	float		m_fHeight;			//!< Camera Width

	D3DXMATRIX  m_mView;            //!< View matrix
	D3DXMATRIX  m_mProj;            //!< Projection matrix
	D3DXMATRIX  m_mBillboard;       //!< Special matrix for billboarding effects
};


class CCtrlCamera : public CCamera
{
public:
    float m_fYaw;
    float m_fPitch;
    float m_fRoll;
    
    float m_fZoom;
    D3DXVECTOR3 m_vCtrl;

public:
    BOOL IsCtrl() const   { return TRUE; }    
        
    CCtrlCamera();
    virtual ~CCtrlCamera();
};

class COriginCamera : public  CCtrlCamera
{
public:

	COriginCamera();
	virtual ~COriginCamera();

	virtual void FrameMove();
	virtual void Transform( LPDIRECT3DDEVICE9 pd3dDevice );
};


class CFirstCamera : public CCtrlCamera
{
public:
    virtual void FrameMove();
    virtual void Transform( LPDIRECT3DDEVICE9 pd3dDevice );
    
    CFirstCamera();
    virtual ~CFirstCamera();
};


//TODO: Move Camera To EngineCore
class LightCoreCamera : public CCamera
{
public:
    void Transform( LPDIRECT3DDEVICE9 pd3dDevice );
	LightCoreCamera();
	virtual ~LightCoreCamera();
};


class PararrelProjCamera : public CCamera
{
public:
	void Transform( LPDIRECT3DDEVICE9 pd3dDevice );
	PararrelProjCamera();
	virtual ~PararrelProjCamera();

	virtual void UpdateProjParams();
};

class CWorld;


class CToolCamera : public CCamera
{
public:
	D3DXMATRIX		   m_mInvView;		//!< ±£´æView inverse of a matrix		
	D3DXVECTOR3        m_vVelocity;
	FLOAT              m_fYaw;
	FLOAT              m_fYawVelocity;
	FLOAT              m_fPitch;
	FLOAT              m_fPitchVelocity;
	CToolCamera();
	virtual	void Transform( LPDIRECT3DDEVICE9 pd3dDevice, CWorld* pWorld );

};

#endif  //_BASE_MAMERA_H_