#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jint JNICALL
Java_com_cairongcai_jnidemo3_MainActivity_chu(JNIEnv *env, jobject instance, jint o, jint p) {

    return o/p;

}


extern "C"
JNIEXPORT jint JNICALL
Java_com_cairongcai_jnidemo3_MainActivity_add(JNIEnv *env, jobject instance, jint i, jint j) {
    return i+j;
    // TODO

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_cairongcai_jnidemo3_MainActivity_getStringFromJNI(JNIEnv *env, jobject instance) {

    return (*env).NewStringUTF("i am crc ");
}

extern "C"
jstring
Java_com_cairongcai_jnidemo3_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
