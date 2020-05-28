import TTLock
import Foundation
import Capacitor
/**
 * Please read the Capacitor iOS Plugin Development Guide
 * here: https://capacitor.ionicframework.com/docs/plugins/ios
 */
@objc(TTLockPlugin)
public class TTLockPlugin: CAPPlugin {
    @objc func setupBluetooth(_ call: CAPPluginCall){
        TTLock.setupBluetooth({ state in
            print(String(format: "###### TTLock is working, bluetooth state: %ld ######", Int(state)))
            call.resolve("Bluetooth working!");    
        })
    }

    @objc func unlock(_ call: CAPPluginCall) {
        let value = call.getString("value") ?? "";
        let lockData = call.getString("lockData");
        let lockMac = call.getString("lockMac");
        TTlock.controlLock(withControlAction: TTControlActionUnlock, lockData:lockData,success:{lockTime,electricQuantity,uniqueId in
            print(String(format: "###### Unlock success power %ld #####",electricQuantity))
            call.resolve([uniqueId:uniqueId,electricQuantity:electricQuantity]);
        }, failure: {
            errorCode,errorMsg in
            print("######## Unlock failed errorMsg: \(errorMsg ?? "") ######");
        });
    }
}
