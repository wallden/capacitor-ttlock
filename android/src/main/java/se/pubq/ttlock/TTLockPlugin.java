package se.pubq.ttlock;

import android.Manifest;

import com.getcapacitor.JSObject;
import com.getcapacitor.NativePlugin;
import com.getcapacitor.Plugin;
import com.getcapacitor.PluginCall;
import com.getcapacitor.PluginMethod;
import com.ttlock.bl.sdk.api.ExtendedBluetoothDevice;
import com.ttlock.bl.sdk.api.TTLockClient;
import com.ttlock.bl.sdk.callback.ScanLockCallback;
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
        TTLockClient.getDefault().prepareBTService(getContext());
//https://gitee.com/sciener/Android-TTLock-SDK-V3-Demo
        TTLockClient.getDefault().startScanLock(new ScanLockCallback() {
            @Override
            public void onScanLockSuccess(ExtendedBluetoothDevice device) {
                JSObject returnObject = new JSObject();
                returnObject.put("value", device.toString());
                call.success(returnObject);
            }

            @Override
            public void onFail(LockError error) {
                call.reject("Failed lock scan");
            }
        });

    }
}
