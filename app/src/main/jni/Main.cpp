#include <jni.h>
#include <android/log.h>

extern "C" JNIEXPORT void JNICALL
Java_com_awang_jniexample_MainActivity_displayToast(JNIEnv* env, jobject thiz, jobject context) {
    jclass toastClass = env->FindClass("android/widget/Toast");
    jmethodID makeTextMethod = env->GetStaticMethodID(toastClass, "makeText", "(Landroid/content/Context;Ljava/lang/CharSequence;I)Landroid/widget/Toast;");

    jstring message = env->NewStringUTF("Hello im from c++");
    jint duration = 1; // LENGTH_SHORT
    jobject toastObject = env->CallStaticObjectMethod(toastClass, makeTextMethod, context, message, duration);

    jmethodID showMethod = env->GetMethodID(toastClass, "show", "()V");
    env->CallVoidMethod(toastObject, showMethod);

    env->DeleteLocalRef(message);
    env->DeleteLocalRef(toastObject);
}
