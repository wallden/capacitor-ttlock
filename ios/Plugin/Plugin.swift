import Foundation
import Capacitor

/**
 * Please read the Capacitor iOS Plugin Development Guide
 * here: https://capacitor.ionicframework.com/docs/plugins/ios
 */
@objc(TTLockPlugin)
public class TTLockPlugin: CAPPlugin {
    
    @objc func unlock(_ call: CAPPluginCall) {
        let value = call.getString("value") ?? "";
        let lockData = call.getString("lockData");
        let lockMac = call.getString("lockMac");
        [TTLock setupBluetooth:^(TTBluetoothState state) {
            NSLog(@"##############  TTLock is working, bluetooth state: %ld  ##############",(long)state);
            
            [TTLock controlLockWithControlAction:TTControlActionUnlock lockData:lockData success:^(long long lockTime, NSInteger electricQuantity, long long uniqueId) {
            NSLog(@"##############  Unlock successed power: %ld  ##############",(long)electricQuantity);
             call.success([
            "lockTime": lockTime,
            "uniqueId": uniqueId
                ])
            } failure:^(TTError errorCode, NSString *errorMsg) {
            NSLog(@"##############  Unlock failed errorMsg: %@  ##############",errorMsg);
            call.reject(errorMsg);
            }];
        
        }];
       
    }
}
