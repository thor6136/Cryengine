#ifndef _TutorialCPPEntity_
#define _TutorialCPPEntity_

#include "IGameObject.h"

struct CTutorialCPPEntity : public CGameObjectExtensionHelper<CTutorialCPPEntity, IGameObjectExtension>
{
	CTutorialCPPEntity(){}
	~CTutorialCPPEntity(){}

	// GameObjectExtention

	virtual void GetMemoryUsage(ICrySizer *pSizer) const{}

	// Summary
	//   Initialize the extension
	// Parameters
	//   pGameObject - a pointer to the game object which will use the extension
	// Remarks
	//   IMPORTANT: It's very important that the implementation of this function 
	//   call the protected function SetGameObject() during the execution of the 
	//   Init() function. Unexpected results would happen otherwise.
	virtual bool Init( IGameObject * pGameObject ){ return true;}
	
	// Summary
	//   Post-initialize the extension
	// Description
	//   During the post-initialization, the extension is now contained in the 
	//   game object
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	virtual void PostInit( IGameObject * pGameObject ){}

	// Summary
	//   Initialize the extension (client only)
	// Description
	//   This initialization function should be use to initialize resource only 
	//   used in the client
	// Parameters
	//   channelId - id of the server channel of the client to receive the 
	//               initialization
	virtual void InitClient(int channelId){}

	// Summary
	//   Post-initialize the extension (client only)
	// Description
	//   This initialization function should be use to initialize resource only 
	//   used in the client. During the post-initialization, the extension is now 
	//   contained in the game object
	// Parameters
	//   channelId - id of the server channel of the client to receive the 
	//               initialization
	virtual void PostInitClient(int channelId){}
	
	// Summary
	//   Reload the extension
	// Description
	//   Called when owning entity is reloaded
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	// Returns
	//   TRUE if the extension should be kept, FALSE if it should be removed
	// Remarks
	//   IMPORTANT: It's very important that the implementation of this function 
	//   call the protected function ResetGameObject() during the execution of the 
	//   ReloadExtension() function. Unexpected results would happen otherwise.
	virtual bool ReloadExtension( IGameObject * pGameObject, const SEntitySpawnParams &params ){return true;}
	
	// Summary
	//   Post-reload the extension
	// Description
	//   Called when owning entity is reloaded and all its extensions have either
	//   either been reloaded or destroyed
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	virtual void PostReloadExtension( IGameObject * pGameObject, const SEntitySpawnParams &params ){}
	
	// Summary
	//   Builds a signature to describe the dynamic hierarchy of the parent Entity container
	// Arguments:
	//    signature - the object to serialize with, forming the signature
	// Returns:
	//    true - If the signature is thus far valid
	// Note:
	//    It's the responsibility of the proxy to identify its internal state which may complicate the hierarchy 
	//    of the parent Entity i.e., sub-proxies and which actually exist for this instantiation.
	virtual bool GetEntityPoolSignature( TSerialize signature ){return true;}
	
	// Summary
	//   Releases the resources used by the object
	// Remarks
	//   This function should also take care of freeing the instance once the 
	//   resource are freed.
	virtual void Release(){}

	// Summary
	//   Performs the serialization the extension
	// Parameters
	//   ser - object used to serialize values
	//   aspect - serialization aspect, used for network serialization
	//   profile - which profile to serialize; 255 == don't care
	//   flags - physics flags to be used for serialization
	// See Also
	//   ISerialize
	virtual void FullSerialize( TSerialize ser ){}
	virtual bool NetSerialize( TSerialize ser, EEntityAspects aspect, uint8 profile, int pflags ){return true;}

	// Summary
	//   Return the aspects NetSerialize serializes.
	//   Overriding this to return only the aspects used will speed up the net bind of the object.
	virtual NetworkAspectType GetNetSerializeAspects() { return eEA_All; }

	// Summary
	//   Performs post serialization fixes
	virtual void PostSerialize(){}

	// Summary
	//   Performs the serialization of special spawn information
	// Parameters
	//   ser - object used to serialize values
	// See Also
	//   Serialize, ISerialize
	virtual void SerializeSpawnInfo( TSerialize ser ){}

	virtual ISerializableInfoPtr GetSpawnInfo(){return true;}

	// Summary
	//   Performs frame dependent extension updates
	// Parameters
	//   ctx - Update context
	//   updateSlot - updateSlot
	// See Also
	//   PostUpdate, SEntityUpdateContext, IGameObject::EnableUpdateSlot
	virtual void Update( SEntityUpdateContext& ctx, int updateSlot ){}

	// Summary
	//   Processes game specific events
	// Parameters
	//   event - game event
	// See Also
	//   SGameObjectEvent
	virtual void HandleEvent( const SGameObjectEvent& event ){}

	// Summary
	//   Processes entity specific events
	// Parameters
	//   event - entity event, see SEntityEvent for more information
	virtual void ProcessEvent( SEntityEvent& event ){};

	virtual void SetChannelId(uint16 id){}
	virtual void SetAuthority( bool auth ){}

	// Summary
	//   Performs an additional update
	// Parameters
	//   frameTime - time elapsed since the last frame update
	// See Also
	//   Update, IGameObject::EnablePostUpdates, IGameObject::DisablePostUpdates
	virtual void PostUpdate( float frameTime ){}

	// Summary
	virtual void PostRemoteSpawn(){}
};

#endif