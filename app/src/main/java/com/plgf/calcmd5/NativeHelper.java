package com.plgf.calcmd5;

/**
 * 作者：zzz on 2018/5/2 0002 14:25
 * 邮箱：1038883524@qq.com
 * 功能：
 */
public class NativeHelper {
    static {
        // 加载C代码库, 库的名称, 必须是CMakeLists.txt中指定的名称
        System.loadLibrary("native-lib");
    }
    //获取C中隐藏的AppKey
    public static native String getMd5(String userCert,String pwd,String customerId);
}
