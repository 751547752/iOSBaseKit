 
Pod::Spec.new do |s|

    s.name             = 'iOSBaseKit'   
    s.summary          = 'iOS基础组件'
    s.description      = <<-DESC
   			 一个iOS基础组件
  			 DESC
    s.homepage      = "https://github.com/751547752/iOSBaseKit"
    s.license       = { :type => 'MIT', :file => 'LICENSE' }
    s.source        = { :git => "https://github.com/751547752/iOSBaseKit.git", :tag => "#{s.version}" }
    s.platform     = :ios, "9.0"
    s.ios.deployment_target = "9.0"
    s.author        = { "sncoder" => "751547752@qq.com" }
    #s.exclude_files = "Classes/Exclude"


    s.version          = '1.0.2'
    s.source_files  = 'iOSBaseKit/*.{h,m}'  

    s.dependency "YYKit"
    s.dependency 'AFNetworking'
    s.dependency 'IQKeyboardManager'

end

 