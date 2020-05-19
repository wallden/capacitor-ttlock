declare module "@capacitor/core" {
  interface PluginRegistry {
    TTLockPlugin: TTLockPluginPlugin;
  }
}

export interface TTLockPluginPlugin {
  echo(options: { value: string }): Promise<{value: string}>;
}
