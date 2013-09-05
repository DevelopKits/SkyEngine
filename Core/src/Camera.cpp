/*! \file   Camera.cpp
    \brief  Implementation of the CCamera class.
    
    $Id: Camera.cpp 14092 2006-09-12 04:52:56Z eric $
    */
#ifdef __EDITOR
#include "_EngineHeader/EngineMFC.h"
#endif

#include "_EngineHeader/EngineCommon.h"
#include "_EngineHeader/Camera.h"
#ifdef __EDITOR
#include "_EngineHeader/World.h"
#endif


CCamera::CCamera()
{
    m_Mode = BASE_CAMERA;

	m_vEye = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_vLookAt = D3DXVECTOR3(0.0f,0.0f,1.0f);
	m_vUpVec = D3DXVECTOR3(0.0f,1.0f,0.0f);

    // Set attributes for the projection matrix
	m_fFOV = D3DX_PI/4;
	m_fAspect = 1.0f;
	m_fNearPlane = 1.0f;
	m_fFarPlane = 1000.0f;
}

CCamera::~CCamera()
{
}


void CCamera::FrameMove()
{
}

void CCamera::UpdateViewParams()
{
	D3DXMatrixLookAtLH( &m_mView, &m_vEye, &m_vLookAt, &m_vUpVec );
	D3DXMatrixInverse( &m_mBillboard, NULL, &m_mView );
	m_mBillboard._41 = m_mBillboard._42 = m_mBillboard._43 = 0.0f;
}

void CCamera::UpdateProjParams()
{
	D3DXMatrixPerspectiveFovLH( &m_mProj, m_fFOV, m_fAspect, m_fNearPlane, m_fFarPlane );
}



void CCamera::Transform( LPDIRECT3DDEVICE9 pd3dDevice )
{   
    pd3dDevice->SetTransform( D3DTS_VIEW, &m_mView );
    pd3dDevice->SetTransform( D3DTS_PROJECTION, &m_mProj );    
}

LightCoreCamera::LightCoreCamera(){}
LightCoreCamera::~LightCoreCamera(){}

void LightCoreCamera::Transform( LPDIRECT3DDEVICE9 pd3dDevice ){
	UpdateViewParams();
	UpdateProjParams();

	CCamera::Transform( pd3dDevice );    
}

PararrelProjCamera::PararrelProjCamera(){}
PararrelProjCamera::~PararrelProjCamera(){}

void PararrelProjCamera::Transform( LPDIRECT3DDEVICE9 pd3dDevice ){
	UpdateViewParams();
	UpdateProjParams();

	CCamera::Transform( pd3dDevice );
}


void PararrelProjCamera::UpdateProjParams(){
	D3DXMatrixOrthoLH( &m_mProj, m_fWidth, m_fHeight, m_fNearPlane, m_fFarPlane );
}

CCtrlCamera::CCtrlCamera() : m_vCtrl(0,0,0)
{
    m_fYaw = 0.0f;
    m_fPitch = D3DX_PI / 2;
    m_fRoll = 0.0f;

    m_fFOV = D3DX_PI/4;
    m_fZoom = 5.0f;
}


CCtrlCamera::~CCtrlCamera()
{
}

COriginCamera::COriginCamera(){
	m_vLookAt = D3DXVECTOR3( 0.0f, 0.0f, 0.0f );
	m_vUpVec = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
	m_Mode = ORIGIN_CAMERA;
}

COriginCamera::~COriginCamera(){
}


void COriginCamera::FrameMove(){
	m_fZoom = max( m_fZoom, 1.0f );
	m_vEye = D3DXVECTOR3( 0.0f, 0.0f, -m_fZoom );

	// degree(88) ~= 1.536
	D3DXMATRIX m;
	m_fPitch = max( m_fPitch, -1.536f );
	m_fPitch = min( m_fPitch, 1.536f );
	D3DXMatrixRotationYawPitchRoll( &m, m_fYaw, m_fPitch, 0.0f );
	D3DXVec3TransformCoord( &m_vEye, &m_vEye, &m );
	m_vEye += m_vLookAt;
}

void COriginCamera::Transform( LPDIRECT3DDEVICE9 pd3dDevice ){
	UpdateViewParams();
	UpdateProjParams();

	CCamera::Transform( pd3dDevice );    
}



CFirstCamera::CFirstCamera()
{
    m_Mode = FIRST_CAMERA;
    m_vCtrl = m_vEye;
}


CFirstCamera::~CFirstCamera()
{
}


void CFirstCamera::FrameMove()
{
    m_vEye = m_vCtrl;
}


void CFirstCamera::Transform( LPDIRECT3DDEVICE9 pd3dDevice )
{
    D3DXQUATERNION qR;
    D3DXMATRIX matOrientation;
    
    D3DXQuaternionRotationYawPitchRoll( &qR, m_fYaw, m_fPitch, 0.0f );
    D3DXMatrixAffineTransformation( &matOrientation, 1.0f, NULL, &qR, &m_vEye );
    D3DXMatrixInverse( &m_mView, NULL, &matOrientation );
    D3DXMatrixInverse( &m_mBillboard, NULL, &m_mView );
    m_mBillboard._41 = m_mBillboard._42 = m_mBillboard._43 = 0.0f;

    UpdateProjParams();

    CCamera::Transform( pd3dDevice );  
}

//2013 client begin
#ifdef __EDITOR
CToolCamera::CToolCamera()
{
	m_vEye = D3DXVECTOR3( 0.0f, 110.0f, 0.0f);
	m_vVelocity = D3DXVECTOR3( 0,0,0);
	m_fYaw = 0;	
	m_fYawVelocity = 0;
	m_fPitch = 0;
	m_fPitchVelocity = 0;

	m_Mode = TOOL_CAMERA;
}

void CToolCamera::Transform( LPDIRECT3DDEVICE9 pd3dDevice, CWorld* pWorld )
{
	D3DXQUATERNION qR;
	D3DXQuaternionRotationYawPitchRoll( &qR, m_fYaw, m_fPitch, 0.0f );
	D3DXMatrixAffineTransformation( &m_mBillboard, 1.0f, NULL, &qR, &m_vEye );
	D3DXMatrixInverse( &m_mView, NULL, &m_mBillboard );
	m_mBillboard._41 = m_mBillboard._42 = m_mBillboard._43 = 0;
	pd3dDevice->SetTransform( D3DTS_VIEW, &m_mView );
	UpdateProjParams();
}
#endif
//2013 client end