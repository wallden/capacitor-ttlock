import TTLock
import Foundation
import Capacitor
/**
 * Please read the Capacitor iOS Plugin Development Guide
 * here: https://capacitor.ionicframework.com/docs/plugins/ios
 */
@objc(TTLockPlugin)
public class TTLockPlugin: CAPPlugin {
    var bluetoothPrepared = false;
    @objc func prepareBluetooth(_ call: CAPPluginCall){
        if self.bluetoothPrepared == false {
            TTLock.setupBluetooth({ state in
            self.bluetoothPrepared = true;
            call.resolve(["msg":"Bluetooth prepared successfully!"]);
        });
        }
        else {
            call.resolve(["msg":"Bluetooth already prepared!"]);
        }
        
    }

    @objc func unlock(_ call: CAPPluginCall) {
        let lockData = call.getString("lockData");
        TTLock.controlLock(with: TTControlAction.actionUnlock, lockData:lockData,success:{lockTime,electricQuantity,uniqueId in
            print(String(format: "###### Unlock success power %ld #####",electricQuantity))
            call.resolve(["uniqueId":uniqueId,"electricQuantity":electricQuantity]);
        }, failure: {
            errorCode,errorMsg in
            print("######## Unlock failed errorMsg: \(errorMsg ?? "") ######");
            call.reject(errorMsg ?? "");
        });
    }
        @objc func initializeLock(_ call: CAPPluginCall) {
            print(String("INITALIZING"));
            TTLock.startScan({ scanModel in
                print(String("scanModel?"));
                if(scanModel?.lockMac){
                    print(String("stopping scan"));
                    TTLock.stopScan();
                    var lockDict = [
                        "lockMac":scanModel?.lockMac,
                        "lockName":scanModel?.lockName,
                        "lockVersion":scanModel?.lockVersion
                    ];
                    TTLock.initLock(withDict: lockDict, success: {lockData, specialValue in
                        print(String("INIT LOCK SUCCESS"));
                        call.resolve(["lockData":lockData,"specialValue":specialValue]);
                    }, failure: {errorCode, errorMsg in
                        call.reject(errorMsg ?? "Failed to init lock");
                    })
                }
                else
                {
                    print(String("No lockmac..."))
                }
                
            });
    }
}
