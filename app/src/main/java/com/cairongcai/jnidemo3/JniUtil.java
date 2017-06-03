package com.cairongcai.jnidemo3;

/**
 * Created by HY-IT on 2017/6/3.
 */

public class JniUtil {
    public native int jian(int k,int l);
    public native int cheng(int m,int n);
    public native void callbackvoidmethod();
    public void PrintfHello()
    {
        System.out.println("HELLO JAVA");
    }
}
