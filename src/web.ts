import { WebPlugin } from '@capacitor/core';
import { TTLockPluginPlugin } from './definitions';

export class TTLockPluginWeb extends WebPlugin implements TTLockPluginPlugin {
  constructor() {
    super({
      name: 'TTLockPlugin',
      platforms: ['web']
    });
  }

  async echo(options: { value: string }): Promise<{value: string}> {
    console.log('ECHO', options);
    return options;
  }
}

const TTLockPlugin = new TTLockPluginWeb();

export { TTLockPlugin };

import { registerWebPlugin } from '@capacitor/core';
registerWebPlugin(TTLockPlugin);
