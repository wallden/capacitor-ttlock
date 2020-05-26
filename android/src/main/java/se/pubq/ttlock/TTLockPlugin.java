package se.pubq.ttlock;

import android.Manifest;
import android.util.Log;

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
class LastChanceHandler implements Thread.UncaughtExceptionHandler {

    @Override
    public void uncaughtException(Thread t, Throwable e) {
        // Lets swallow this async exception originating from TTLock SDK and everything else...
    }
}
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
    public void unlock(final PluginCall call) {
        Thread.setDefaultUncaughtExceptionHandler(new LastChanceHandler());

        System.out.println("Ok lets unlock");
        final String lockData = call.getString("lockData");
        final String lockMac = call.getString("lockMac");
        try {

            TTLockClient.getDefault().prepareBTService(getContext());
            TTLockClient.getDefault().controlLock(ControlAction.UNLOCK, lockData, lockMac, new ControlLockCallback() {
                @Override
                public void onControlLockSuccess(int lockAction, int battery, int uniqueId) {
                    final JSObject returnData = new JSObject();
                    returnData.put("uniqueId", uniqueId);
                    call.success(returnData);
                }

                @Override
                public void onFail(LockError error) {
                    call.reject(error.toString());
                }
            });
        } catch (Exception ex) {
            Log.v("a", ex.toString());
        }
    }

    @PluginMethod()
    public void echo(final PluginCall call) {

        System.out.println("Ok lets go");
        final JSObject returnData = new JSObject();

        TTLockClient.getDefault().prepareBTService(getContext());
        TTLockClient.getDefault().startScanLock(new ScanLockCallback() {

            @Override
            public void onScanLockSuccess(final ExtendedBluetoothDevice device) {
                System.out.println("lock scan success");
                TTLockClient.getDefault().initLock(device, new InitLockCallback() {
                    @Override
                    public void onInitLockSuccess(String lockData, int specialValue) {
                        returnData.put("lockData", lockData);
                        returnData.put("specialValue", specialValue);
                        call.resolve(returnData);
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
                        System.out.println(error.toString());

                    }
                });
            }

            //
            @Override
            public void onFail(LockError error) {
                System.out.println(error.toString());
            }
        });
    }

}

