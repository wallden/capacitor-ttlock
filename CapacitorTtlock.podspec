
  Pod::Spec.new do |s|
    s.name = 'CapacitorTtlock'
    s.version = '0.0.5'
    s.summary = 'Interact with TTLocks'
    s.license = 'MIT'
    s.homepage = 'https://github.com/wallden/capacitor-ttlock.git'
    s.author = 'Henrik Walldén'
    s.source = { :git => 'https://github.com/wallden/capacitor-ttlock.git', :tag => s.version.to_s }
    s.source_files = 'ios/Plugin/**/*.{swift,h,m,c,cc,mm,cpp}'
    s.ios.deployment_target  = '11.0'
    s.static_framework = true
    s.dependency 'Capacitor'
    s.dependency 'TTLock'
  end