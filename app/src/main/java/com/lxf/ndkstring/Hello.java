package com.lxf.ndkstring;

/**
 * Created by Administrator on 2016/12/2.
 */
public class Hello {


    static {
            System.loadLibrary("hello");
    }

    public native int encode_int(int pwd);


    public native String encode_String(String text,int length);


    public native String decode_String(String text,int length);

    public native void encode_intArray(int [] i);
}
