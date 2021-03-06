//***************************************************************************
//
//  Copyright (c) 2001 - 2006 Intel Corporation
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//***************************************************************************

/**
	@file	IFXAuthorLineSetResource.h
*/

#ifndef __IFXAUTHOR_LINESET_RESOURCE_H__
#define __IFXAUTHOR_LINESET_RESOURCE_H__

#include "IFXModifier.h"
#include "IFXMarkerX.h"
#include "IFXGenerator.h" 
#include "IFXDataBlockQueueX.h"
#include "IFXAuthorLineSet.h"
#include "IFXMeshMap.h"
#include "IFXSkeleton.h"

// {1C48C8FD-AA10-4e9b-9D7F-1E7E65ED112B}
IFXDEFINE_GUID(IID_IFXAuthorLineSetResource, 
0x1c48c8fd, 0xaa10, 0x4e9b, 0x9d, 0x7f, 0x1e, 0x7e, 0x65, 0xed, 0x11, 0x2b);


/**
	IFXAuthorLineSetResource that will generate an IFXLineSetGroup renderable.
*/
class IFXAuthorLineSetResource : virtual public IFXModifier,
								 virtual public IFXGenerator, 
								 virtual public IFXMarkerX
{
public:

	virtual IFXRESULT IFXAPI BuildDataBlockQueue() = 0;
	
	virtual void IFXAPI GetDataBlockQueueX(IFXDataBlockQueueX*& rpDataBlockQueueX) = 0;

	/**
	* Retrieves the bounding sphere of the geometry in model space.
	*/
	virtual const IFXVector4& IFXAPI GetBoundingSphere()=0;
	
	/**
	* Sets the current bounding sphere.
	*/
	virtual IFXRESULT IFXAPI SetBoundingSphere(const IFXVector4& rBoundingSphere)=0;
	
	/**
	* Retrieves the resource transform of the object.  The resource
	* transform is applied before the model to world transform.
	*/
	virtual const IFXMatrix4x4& IFXAPI GetTransform()=0;
	
	/**
	Sets the resource transform.  The resource
	transform is applied before the model to world transform.
	*/

	virtual IFXRESULT IFXAPI SetTransform(const IFXMatrix4x4& rTransform)=0;

	/**
	 *	Returns the IFXAuthorLineSet wrapped by this class.
	 *
	 *	@param	rpAuthorLineSet 	The returned reference to the
	 *                              IFXAuthorLineSet
	 *
	 *	@return	An IFXRESULT value.
	 *	@retval	IFX_OK	No error.
	 */
	virtual IFXRESULT IFXAPI GetAuthorLineSet(IFXAuthorLineSet*& rpAuthorLineSet) = 0;
	
	/**
	 *	Sets the IFXAuthorLineSet wrapped by this class.  
	 *
	 *	@param	pAuthorLineSet  	The IFXAuthorLineSet to use for this
	 *                              object.
	 *
	 *	@return	An IFXRESULT value.
	 *	@retval	IFX_OK	No error.
	 */
	virtual IFXRESULT IFXAPI SetAuthorLineSet(IFXAuthorLineSet* pAuthorLineSet) = 0;

	/**
	 *	Retrives the associated IFXMeshGroup   
	 *
	 *	@param	ppMeshGroup  	The IFXMeshGroup pointer  to use for this
	 *                              object.
	 *
	 *	@return	An IFXRESULT value.
	 *	@retval	IFX_OK	No error.
	 */
	virtual IFXRESULT IFXAPI GetMeshGroup(IFXMeshGroup** ppMeshGroup) = 0;

	/**
	*  Currently does nothing.
	*/
	virtual IFXRESULT IFXAPI Transfer() = 0;

	/** @name	Bones support
	 */
	//@{
	virtual IFXSkeleton* IFXAPI GetBones( void ) = 0;
	virtual IFXRESULT IFXAPI SetBones( IFXSkeleton* pBonesGen ) = 0;
	virtual IFXRESULT IFXAPI GetRenderMeshMap(IFXMeshMap** ppRenderLineSetMap) = 0;
	virtual IFXRESULT IFXAPI SetRenderMeshMap(IFXMeshMap* pRenderLineSetMap) = 0;
	//@}
};

#endif
