package se.pubq.ttlock;

import android.Manifest;

import com.getcapacitor.JSObject;
import com.getcapacitor.NativePlugin;
import com.getcapacitor.Plugin;
import com.getcapacitor.PluginCall;
import com.getcapacitor.PluginMethod;
import com.ttlock.bl.sdk.api.ExtendedBluetoothDevice;
import com.ttlock.bl.sdk.api.TTLockClient;
import com.ttlock.bl.sdk.callback.ControlLockCallback;
import com.ttlock.bl.sdk.callback.InitLockCallback;
import com.ttlock.bl.sdk.callback.ScanLockCallback;
import com.ttlock.bl.sdk.constant.ControlAction;
import com.ttlock.bl.sdk.entity.LockError;

@NativePlugin(
        permissions = {
                Manifest.permission.BLUETOOTH,
                Manifest.permission.BLUETOOTH_ADMIN,
                Manifest.permission.ACCESS_COARSE_LOCATION,
                Manifest.permission.INTERNET,
                Manifest.permission.ACCESS_NETWORK_STATE
        }
)
public class TTLockPlugin extends Plugin {

    @PluginMethod()
    public void echo(final PluginCall call) {
        final JSObject returnData = new JSObject();
        final TTLockClient lockClient = TTLockClient.getDefault();
        lockClient.prepareBTService(getContext());
        lockClient.startScanLock(new ScanLockCallback() {
            @Override
            public void onScanLockSuccess(final ExtendedBluetoothDevice device) {

                lockClient.initLock(device, new InitLockCallback() {
                    @Override
                    public void onInitLockSuccess(String lockData, int specialValue) {
                        returnData.put("lockData",lockData);
                        returnData.put("specialValue",specialValue);
                        call.resolve(returnData);
                        lockClient.stopBTService();
////                        returnObject.put("lockData", lockData);
////                        returnObject.put("specialValue",specialValue);
////                        lockClient.controlLock(ControlAction.UNLOCK, lockData, device.getAddress(), new ControlLockCallback() {
////                            @Override
////                            public void onControlLockSuccess(int lockAction, int battery, int uniqueId) {
////                                returnObject.put("lockAction",lockAction);
////                                returnObject.put("battery",battery);
////                                returnObject.put("uniqueId",uniqueId);
////                                //lockClient.stopBTService();
////                                //call.resolve(returnObject);
////                            }
////                            @Override
////                            public void onFail(LockError error) {
////
////                            }
////                        });
                    }
//
                    @Override
                    public void onFail(LockError error) {

                    }
                });
            }
//
            @Override
            public void onFail(LockError error) {
            }
        });
        }

    }

