//
// 
//  BTstackCocoa
//
//  Created by TTLock on 13-1-31.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TTMacros : NSObject

UIKIT_EXTERN NSString * const  TTErrorMessageHadReseted;
UIKIT_EXTERN NSString * const  TTErrorMessageCRCError;
UIKIT_EXTERN NSString * const  TTErrorMessageNoPermisstion;
UIKIT_EXTERN NSString * const  TTErrorMessageWrongAdminCode;
UIKIT_EXTERN NSString * const  TTErrorMessageLackOfStorageSpace;
UIKIT_EXTERN NSString * const  TTErrorMessageInSettingMode;
UIKIT_EXTERN NSString * const  TTErrorMessageNoAdmin;
UIKIT_EXTERN NSString * const  TTErrorMessageNotInSettingMode;
UIKIT_EXTERN NSString * const  TTErrorMessageWrongDynamicCode;
UIKIT_EXTERN NSString * const  TTErrorMessageIsNoPower;
UIKIT_EXTERN NSString * const  TTErrorMessageResetPasscode;
UIKIT_EXTERN NSString * const  TTErrorMessageUpdatePasscodeIndex;
UIKIT_EXTERN NSString * const  TTErrorMessageInvalidLockFlagPos;
UIKIT_EXTERN NSString * const  TTErrorMessageEkeyExpired;
UIKIT_EXTERN NSString * const  TTErrorMessagePasscodeLengthInvalid;
UIKIT_EXTERN NSString * const  TTErrorMessageSamePasscodes;
UIKIT_EXTERN NSString * const  TTErrorMessageEkeyInactive;
UIKIT_EXTERN NSString * const  TTErrorMessageAesKey;
UIKIT_EXTERN NSString * const  TTErrorMessageFail;
UIKIT_EXTERN NSString * const  TTErrorMessagePasscodeExist;
UIKIT_EXTERN NSString * const  TTErrorMessagePasscodeNotExist;
UIKIT_EXTERN NSString * const  TTErrorMessageLackOfStorageSpaceWhenAddingPasscodes;
UIKIT_EXTERN NSString * const  TTErrorMessageInvalidParaLength;
UIKIT_EXTERN NSString * const  TTErrorMessageCardNotExist;
UIKIT_EXTERN NSString * const  TTErrorMessageFingerprintDuplication;
UIKIT_EXTERN NSString * const  TTErrorMessageFingerprintNotExist;
UIKIT_EXTERN NSString * const  TTErrorMessageInvalidCommand;
UIKIT_EXTERN NSString * const  TTErrorMessageInFreezeMode;
UIKIT_EXTERN NSString * const  TTErrorMessageInvalidClientPara;
UIKIT_EXTERN NSString * const  TTErrorMessageLockIsLocked;
UIKIT_EXTERN NSString * const  TTErrorMessageRecordNotExist;
UIKIT_EXTERN NSString * const  TTErrorMessageNotSupportModifyPasscode;
UIKIT_EXTERN NSString * const  TTErrorMessageBluetoothPoweredOff;
UIKIT_EXTERN NSString * const  TTErrorMessageConnectionTimeout;
UIKIT_EXTERN NSString * const  TTErrorMessageDisconnection;
UIKIT_EXTERN NSString * const  TTErrorMessageLockIsBusy;
UIKIT_EXTERN NSString * const  TTErrorMessageWrongLockData;
UIKIT_EXTERN NSString * const  TTErrorMessageInvalidParameter;


#define RSSI_SETTING_MAX -65    //Corresponding unlocking distance :0.5m
#define RSSI_SETTING_MIN -140
#define RSSI_SETTING_1m -85     //Corresponding unlocking distance :1m
#define RSSI_SETTING_2m -150    //Corresponding unlocking distance :2m
#define RSSI_SETTING_3m -180    //Corresponding unlocking distance :3m
#define RSSI_SETTING_4m -210    //Corresponding unlocking distance :4m
#define RSSI_SETTING_5m -240    //Corresponding unlocking distance :5m


typedef NS_ENUM(NSInteger, TTError)
{
   
    TTErrorHadReseted = 0,
    TTErrorCRCError = 0x01,
    TTErrorNoPermisstion = 0x02,
    TTErrorWrongAdminCode = 0x03,
    TTErrorLackOfStorageSpace = 0x04,
    TTErrorInSettingMode = 0x05,
    TTErrorNoAdmin = 0x06,
    TTErrorNotInSettingMode = 0x07,
    TTErrorWrongDynamicCode = 0x08,
    TTErrorIsNoPower = 0x0a,
    TTErrorResetPasscode = 0x0b,
    TTErrorUpdatePasscodeIndex = 0x0c,
    TTErrorInvalidLockFlagPos = 0x0d,
    TTErrorEkeyExpired = 0x0e,
    TTErrorPasscodeLengthInvalid = 0x0f,
    TTErrorSamePasscodes = 0x10,
    TTErrorEkeyInactive = 0x11,
    TTErrorAesKey = 0x12,
    TTErrorFail = 0x13,
    TTErrorPasscodeExist = 0x14,
    TTErrorPasscodeNotExist = 0x15,
    TTErrorLackOfStorageSpaceWhenAddingPasscodes = 0x16,
    TTErrorInvalidParaLength = 0x17,
    TTErrorCardNotExist =    0x18,
    TTErrorFingerprintDuplication =    0x19,
    TTErrorFingerprintNotExist = 0x1A,
    TTErrorInvalidCommand = 0x1B,
    TTErrorInFreezeMode = 0x1C,
    TTErrorInvalidClientPara = 0x1D,
    TTErrorLockIsLocked = 0x1E,
    TTErrorRecordNotExist = 0x1F,
    
    TTErrorNotSupportModifyPasscode = 0x60,
    TTErrorBluetoothPoweredOff = 0x61,
    TTErrorConnectionTimeout = 0x62,
    TTErrorDisconnection = 0x63,
    TTErrorLockIsBusy = 0x64,
    TTErrorWrongLockData = 0x65,
    TTErrorInvalidParameter = 0x66,
};

typedef NS_ENUM(NSInteger, TTControlAction)
{
    TTControlActionUnlock = 0x01,
    TTControlActionLock = 0x02,
    TTControlActionlPause = 0x04,
    TTControlActionHold = 0x08,
};

/*!
 *  @enum TTBluetoothState
 *
 *  @discussion Represents the current state of a Manager.
 *
 *  @constant TTBluetoothStateUnknown       State unknown, update imminent.
 *  @constant TTBluetoothStateResetting     The connection with the system service was momentarily lost, update imminent.
 *  @constant TTBluetoothStateUnsupported   The platform doesn't support the Bluetooth Low Energy Central/Client role.
 *  @constant TTBluetoothStateUnauthorized  The application is not authorized to use the Bluetooth Low Energy role.
 *  @constant TTBluetoothStatePoweredOff    Bluetooth is currently powered off.
 *  @constant TTBluetoothStatePoweredOn     Bluetooth is currently powered on and available to use.
 *
 */
typedef NS_ENUM(NSInteger, TTBluetoothState) {
    TTBluetoothStateUnknown = 0,
    TTBluetoothStateResetting,
    TTBluetoothStateUnsupported,
    TTBluetoothStateUnauthorized,
    TTBluetoothStatePoweredOff,
    TTBluetoothStatePoweredOn,
} ;

/*!
 *  @enum TTLockType
 *
 *  @discussion Different scenes, different locks
 *
 *  @constant GateLockSceneType             Gate lock
 *  @constant SafeLockSceneType             Safe Lock
 *  @constant BicycleLockSceneType          Bicycle Lock
 *  @constant ParkSceneType                 Parking Lock
 *  @constant PadLockSceneType              Pad Lock
 *  @constant CylinderLockSceneType         Cylinder Lock
 *
 */

typedef NS_ENUM(int, TTLockType)
{
    TTLockTypeV2 = 1 ,
    TTLockTypeV2Scene1 ,
    TTLockTypeV2Scene2 ,
    TTLockTypeV2ParkingLock ,
    TTLockTypeV3 ,
    TTLockTypeGateLock ,
    TTLockTypeSafeLock ,
    TTLockTypeBicycleLock ,
    TTLockTypeParkingLock ,
    TTLockTypePadLock ,
    TTLockTypeCylinderLock  ,
    TTLockTypeRemoteControl  ,
    TTLockTypeHotelLock ,
};



/*!
 *  @enum TTPasscodeType
 *
 *  @discussion Keyboard password type
 *
 *  @constant TTPasscodeTypeOnce           One-time
 *  @constant TTPasscodeTypePermanent      Permanent
 *  @constant TTPasscodeTypePeriod         Timed
 *  @constant TTPasscodeTypeCycle          Cyclic
 *
 */
typedef NS_ENUM(NSInteger, TTPasscodeType)
{
    TTPasscodeTypeOnce = 1,
    TTPasscodeTypePermanent = 2,
    TTPasscodeTypePeriod = 3,
    TTPasscodeTypeCycle = 4
};

/*!
 *  @enum Operation type
 *
 *  @constant TTOprationTypeClear           Clear
 *  @constant TTOprationTypeAdd             Add
 *  @constant TTOprationTypeDelete          Delete
 *  @constant TTOprationTypeModify          Modify
 *  @constant TTOprationTypeQuery           Query
 *  @constant TTOprationTypeRecover         Recover
 *
 */
typedef NS_ENUM(NSInteger,TTOprationType)
{
    TTOprationTypeClear = 1,
    TTOprationTypeAdd = 2,
    TTOprationTypeDelete = 3,
    TTOprationTypeModify = 4,
    TTOprationTypeQuery = 5,
    TTOprationTypeRecover = 6,
    TTOprationTypeAddFingerprintData = 7
};

/*!
 *  @enum TTLockSwitchState
 *
 *  @discussion Lock Switch State
 *
 *  @constant LockStateLock       Lock
 *  @constant LockStateUnlock     Unlock
 *  @constant LockStateUnknown    Unknown
 *  @constant LockStateUnlockHasCar  Unlock，Has Car
 *
 */
typedef NS_ENUM(NSInteger,TTLockSwitchState)
{
    TTLockSwitchStateLock = 0,
    TTLockSwitchStateUnlock = 1,
    TTLockSwitchStateUnknown = 2,
    TTLockSwitchStateUnlockHasCar = 3,
};
/*!
 *  @enum TTDoorSensorState
 *
 *  @discussion Door Sensor State
 *
 *  @constant TTDoorSensorStateOff    No door sensor was detected
 *  @constant TTDoorSensorStateOn     Detection of door sensor
 *
 */
typedef NS_ENUM(NSInteger,TTDoorSensorState)
{
    TTDoorSensorStateOff = 0,
    TTDoorSensorStateOn = 1,
};

/*!
 *  @enum AddICState
 *
 *  @discussion State type returned
 *
 *  @constant AddICStateHadAdd    Identify IC card and add successfully
 *  @constant AddICStateCanAdd    Successfully start adding IC card mode
 *
 */
typedef NS_ENUM(NSInteger,TTAddICState)
{
    TTAddICStateHadAdd = 1,
    TTAddICStateCanAdd = 2,
    
};

/*!
 *  @enum AddFingerprintState
 *
 *  @discussion State type returned by adding a fingerprint
 *
 *  @constant TTAddFingerprintCollectSuccess     Add fingerprint successfully
 *  @constant TTAddFingerprintCanCollect         Start adding fingerprint mode Successfully
 *  @constant TTAddFingerprintCanCollectAgain    Start the second collection
 *
 */
typedef NS_ENUM(NSInteger,TTAddFingerprintState)
{
    TTAddFingerprintCollectSuccess = 1,
    TTAddFingerprintCanCollect = 2,
    TTAddFingerprintCanCollectAgain = 3,
};
/**
 OperateLog Type
 
 - OperateLogTypeNew: Read new records in the lock
 - TTOperateLogTypeAll: Read all records in the lock
 */
typedef NS_ENUM(NSInteger, TTOperateLogType)
{
    TTOperateLogTypeLatest = 1,
    TTOperateLogTypeAll = 2,
};
/**
 Passage Mode Type
 */
typedef NS_ENUM(NSInteger, TTPassageModeType)
{
    TTPassageModeTypeWeekly = 1,
    TTPassageModeTypeMonthly = 2,
};

typedef NS_ENUM(NSInteger,TTDeviceInfoType) {
    TTDeviceInfoTypeOfProductionModel = 1,
    TTDeviceInfoTypeOfHardwareVersion = 2,
    TTDeviceInfoTypeOfFirmwareVersion = 3,
    TTDeviceInfoTypeOfProductionDate = 4,
    TTDeviceInfoTypeOfProductionMac = 5,
    TTDeviceInfoTypeOfProductionClock = 6,
    TTDeviceInfoTypeOfNBOperator = 7,
    TTDeviceInfoTypeOfNbNodeId = 8,
    TTDeviceInfoTypeOfNbCardNumber = 9,
    TTDeviceInfoTypeOfNbRssi = 10,
};

typedef NS_ENUM(long long, TTLockSpecialFunction)
{
    TTLockSpecialFunctionPasscode = 1 << 0,
    TTLockSpecialFunctionICCard = 1 << 1,
    TTLockSpecialFunctionFingerprint = 1 << 2,
    TTLockSpecialFunctionWristband = 1 << 3,
    TTLockSpecialFunctionAutoLock = 1 << 4,
    TTLockSpecialFunctionDeletePasscode = 1 << 5,
    TTLockSpecialFunctionManagePasscode = 1 << 7,
    TTLockSpecialFunctionLocking = 1 << 8,
    TTLockSpecialFunctionPasscodeVisible = 1 << 9,
    TTLockSpecialFunctionGatewayUnlock = 1 << 10,
    TTLockSpecialFunctionLockFreeze = 1 << 11,
    TTLockSpecialFunctionCyclePassword = 1 << 12,
    TTLockSpecialFunctionDoorSensor = 1 << 13,
    TTLockSpecialFunctionRemoteUnlockSwicth = 1 << 14,
    TTLockSpecialFunctionAudioSwitch = 1 << 15,
    TTLockSpecialFunctionNBIoT = 1 << 16,
    TTLockSpecialFunctionGetAdminPasscode = 1 << 18,
    TTLockSpecialFunctionHotelCard = 1 << 19,
    TTLockSpecialFunctionNoClock = 1 << 20,
    TTLockSpecialFunctionNoBroadcastInNormal = 1 << 21,
    TTLockSpecialFunctionPassageMode = 1 << 22,
    TTLockSpecialFunctionTurnOffAutoLock = 1 << 23,
    TTLockSpecialFunctionWirelessKeypad = 1 << 24,
     TTLockSpecialFunctionLight = 1 << 25,
};

@end