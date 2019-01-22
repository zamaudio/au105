#include "AUEffectBase.h"
#include "dpfpluginVersion.h"

#if AU_DEBUG_DISPATCHER
	#include "AUDebugDispatcher.h"
#endif


#ifndef __dpfplug_h__
#define __dpfplug_h__


#pragma mark ____dpfplug Parameters

// parameters
static const float kDefaultValue_ParamOne = 0.5;

static CFStringRef kParameterOneName = CFSTR("Parameter One");

enum {
	kParam_One =0,
	//Add your parameters here...
	kNumberOfParameters=1
};

#pragma mark ____dpfplug
class dpfplug : public AUEffectBase
{
public:
	dpfplug(AudioUnit component);
#if AU_DEBUG_DISPATCHER
	virtual ~dpfplug () { delete mDebugDispatcher; }
#endif
	
	virtual AUKernelBase *		NewKernel() { return new dpfplugKernel(this); }
	
	virtual	OSStatus			GetParameterValueStrings(AudioUnitScope			inScope,
														 AudioUnitParameterID		inParameterID,
														 CFArrayRef *			outStrings);
    
	virtual	OSStatus			GetParameterInfo(AudioUnitScope			inScope,
												 AudioUnitParameterID	inParameterID,
												 AudioUnitParameterInfo	&outParameterInfo);
    
	virtual OSStatus			GetPropertyInfo(AudioUnitPropertyID		inID,
												AudioUnitScope			inScope,
												AudioUnitElement		inElement,
												UInt32 &			outDataSize,
												Boolean	&			outWritable );
	
	virtual OSStatus			GetProperty(AudioUnitPropertyID inID,
											AudioUnitScope 		inScope,
											AudioUnitElement 		inElement,
											void *			outData);
	
 	virtual	bool				SupportsTail () { return false; }
	
	/*! @method Version */
	virtual OSStatus		Version() { return kdpfplugVersion; }
	
    
	
protected:
		class dpfplugKernel : public AUKernelBase		// most of the real work happens here
	{
public:
		dpfplugKernel(AUEffectBase *inAudioUnit )
		: AUKernelBase(inAudioUnit)
	{
	}
		
		// *Required* overides for the process method for this effect
		// processes one channel of interleaved samples
        virtual void 		Process(	const Float32 	*inSourceP,
										Float32		 	*inDestP,
										UInt32 			inFramesToProcess,
										UInt32			inNumChannels,
										bool			&ioSilence);
		
        virtual void		Reset();
		
		//private: //state variables...
	};
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#endif
