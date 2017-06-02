#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_transString(JNIEnv *env, jobject instance, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    env->ReleaseStringUTFChars(str_, str);

    return env->NewStringUTF(str);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_lalalaJNI(JNIEnv *env, jobject instance) {
    std::string str = "lalala";
    return env->NewStringUTF(str.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
