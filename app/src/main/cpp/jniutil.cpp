//
// Created by HY-IT on 2017/6/3.
//
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern "C"
JNIEXPORT jint JNICALL
Java_com_cairongcai_jnidemo3_JniUtil_cheng(JNIEnv *env, jobject instance, jint m, jint n) {

    return m*n;

}

extern "C"
JNIEXPORT jint JNICALL
Java_com_cairongcai_jnidemo3_JniUtil_jian(JNIEnv *env, jobject instance, jint k, jint l) {

    return k-l;

}
