declare module "@capacitor/core" {
  interface PluginRegistry {
    TTLockPlugin: TTLockPluginPlugin;
  }
}

export interface TTLockPluginPlugin {
  unlock(options: { lockData: string, lockMac: string }): Promise<{ lockTime: string, uniqueId: string }>;
}
