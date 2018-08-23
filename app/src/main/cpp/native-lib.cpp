#include <jni.h>
#include <string>
#include "md5.h"



char *Jstring2CStr(JNIEnv *pEnv, jstring pJstring);

std::string jstring2str(JNIEnv* env, jstring jstr)
;

extern "C"
jstring
Java_com_plgf_parking_parking_help_NativeHelper_getMd5( JNIEnv *env, jclass type, jstring userCert,jstring pwd,jstring customerId) {


    std::string hello = CMD5(jstring2str(env,userCert)+ CMD5(jstring2str(env,pwd)).GetMd5()+jstring2str(env,customerId)).GetMd5();
    //std::string hello = jstring2str(env,str);
    return env->NewStringUTF(hello.c_str());
}
std::string jstring2str(JNIEnv* env, jstring jstr)
{
    char*   rtn   =   NULL;
    jclass   clsstring   =   env->FindClass("java/lang/String");
    jstring   strencode   =   env->NewStringUTF("GB2312");
    jmethodID   mid   =   env->GetMethodID(clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
    jbyteArray   barr=   (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
    jsize   alen   =   env->GetArrayLength(barr);
    jbyte*   ba   =   env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen   >   0)
    {
        rtn   =   (char*)malloc(alen+1);
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    env->ReleaseByteArrayElements(barr,ba,0);
    std::string stemp(rtn);
    free(rtn);
    return   stemp;
}



