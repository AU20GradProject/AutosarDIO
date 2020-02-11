#ifndef DET_H

#define DET_H

/*********************************************************************/


/* Published information */
#define DIO_MODULE_ID 0x020u
#define DIO_VENDOR_ID 0x002Bu   /* vendor id of NXP */

#define DIO_AR_RELEASE_MAJOR_VERSION 0x01u
#define DIO_AR_RELEASE_MINOR_VERSION 0x00u
#define DIO_AR_RELEASE_REVISION_VERSION 0x00u

#define DIO_SW_MAJOR_VERSION 0x04u
#define DIO_SW_MINOR_VERSION 0x03u
#define DIO_SW_PATCH_VERSION 0x01u


/*********************************************************************/

#include "Std_Types.h"


FUNC(Std_ReturnType, DIO_CODE ) Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ) ;


#endif // DET_H
