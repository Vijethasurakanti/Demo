//
// Created by HY-IT on 2017/6/3.
//
#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}

JNIEXPORT jstring JNICALL
Java_com_cairongcai_jnidemo3_MainActivity_setStringToJNI(JNIEnv *env, jobject instance,
                                                         jstring str_) {

       char* cstr= _JString2CStr(env,str_);
    int length=strlen(cstr);
    int i;
    for(i=0;i<length;i++)
{
    *(cstr+i)+=1;
}
    return (*env)->NewStringUTF(env,cstr);
}
JNIEXPORT jintArray JNICALL
Java_com_cairongcai_jnidemo3_MainActivity_passIntArrayToJNI(JNIEnv *env, jobject instance,
                                                            jintArray array_) {
    jsize length=(*env)->GetArrayLength(env,array_);
    int* arraypointer=(*env)->GetIntArrayElements(env,array_,NULL);//jint类型就是int类型的指针
    int i;
    for(i=0;i<length;i++)
        {
            *(arraypointer+i)+=10;
        }
    return array_;
}

JNIEXPORT void JNICALL
Java_com_cairongcai_jnidemo3_JniUtil_callbackvoidmethod(JNIEnv *env, jobject instance) {
    jclass  clazz=(*env)->FindClass(env,"com/cairongcai/jnidemo3/JniUtil");
    jmethodID  methodID=(*env)->GetMethodID(env,clazz,"PrintfHello","()V");
    (*env)->CallVoidMethod(env,instance,methodID);
}
//把java的字符串类型转化为c的char* 类型
char* _Jstring2CStr(JNIEnv* env,jstring jstr)
{
    //c语言的char类型和java的byte类型所占的内存一样-一位
    char* btn=NULL;
    jclass strclazz=(*env)->FindClass(env,"java/lang/String");
    jstring strencode=(*env)->NewStringUTF(env,"GB2312");
    //getbyte方法
    jmethodID  method=(*env)->GetMethodID(env,strclazz,"getBytes","(Ljava/lang/String;)[B");
    //jstring转化的byte数组
    jbyteArray  jba=(*env)->CallObjectMethod(env,jstr,method,strencode);
    //数组的长度，和数组的首地址
   int length= (*env)->GetArrayLength(env,jba);
    jbyte* ja= (*env)->GetByteArrayElements(env,jba,JNI_FALSE);
    //申请新的char* 的内存空间
    if(length>0)
    {
        //复制byte数组到新的内存空间
       btn=(char*)malloc(length+1);
        memcpy(btn,ja,length);
        btn[length]=0;
    }
    (*env)->ReleaseByteArrayElements(env,jba,ja,0);
    return btn;
    //返回char*
}