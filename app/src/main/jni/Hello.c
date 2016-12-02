//
// Created by Administrator on 2016/12/2.
//

#include "com_lxf_ndkstring_Hello.h"
#include "string.h"


char*   Jstring2CStr(JNIEnv*   env,   jstring   jstr)
{
        char* rtn = NULL;
        jclass clsstring = (*env)->FindClass(env,"java/lang/String");
        jstring strencode = (*env)->NewStringUTF(env,"GB2312");
        jmethodID  mid  = (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
        jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,jstr,mid,strencode); // String .getByte("GB2312");
        jsize alen = (*env)->GetArrayLength(env,barr);
        jbyte* ba = (*env)->GetByteArrayElements(env,barr,JNI_FALSE);
        if(alen   >   0)
        {
                rtn   =   (char*)malloc(alen+1);         //"\0"
                memcpy(rtn,ba,alen);
                rtn[alen]=0;
        }
        (*env)->ReleaseByteArrayElements(env,barr,ba,0);  //
        return rtn;
}

JNIEXPORT jint JNICALL Java_com_lxf_ndkstring_Hello_encode_1int
        (JNIEnv * env, jobject obj, jint jint1){

        return jint1*2;

};


JNIEXPORT jstring JNICALL Java_com_lxf_ndkstring_Hello_encode_1String
        (JNIEnv * env, jobject obj, jstring jstr, jint length){

        char * text=Jstring2CStr(env,jstr);
        for (int j= 0; j <length ; ++j) {
                *(text+j)+=1;
        }

        return (*env)->NewStringUTF(env,text);

};

/*
 * Class:     com_lxf_ndkstring_Hello
 * Method:    decode_String
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_lxf_ndkstring_Hello_decode_1String
        (JNIEnv * env, jobject obj, jstring jstr, jint length){
        char * text=Jstring2CStr(env,jstr);
        for (int j= 0; j <length ; ++j) {
                *(text+j)-=1;
        }

        return (*env)->NewStringUTF(env,text);
};

/**
 * int数组加密
 */
JNIEXPORT void JNICALL Java_com_lxf_ndkstring_Hello_encode_1intArray
        (JNIEnv *env, jobject obj, jintArray jintArray1){

        int  size=(*env)->GetArrayLength(env,jintArray1);
        //jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
        int*  i=(*env)->GetIntArrayElements(env,jintArray1,JNI_FALSE);
        int j;
        for (j = 0; j < size; j++) {
                *(i+j) +=1;

        }
}


