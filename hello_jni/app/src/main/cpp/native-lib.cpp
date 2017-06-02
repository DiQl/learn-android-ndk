#include <jni.h>
#include <string>

extern "C" {
    JNIEXPORT jstring JNICALL
    Java_org_diql_hellojni_MainActivity_booleanStrJNI(JNIEnv *env, jobject instance, jboolean test);

    JNIEXPORT jint JNICALL
    Java_org_diql_hellojni_MainActivity_booleanJNI(JNIEnv *env, jobject instance, jboolean test);

    JNIEXPORT jstring JNICALL
    Java_org_diql_hellojni_MainActivity_transString(JNIEnv *env, jobject instance, jstring str_);

    JNIEXPORT jstring JNICALL
    Java_org_diql_hellojni_MainActivity_lalalaJNI(JNIEnv *env, jobject instance);

    JNIEXPORT jstring JNICALL
    Java_org_diql_hellojni_MainActivity_lalalaJNI(JNIEnv *env, jobject instance);

    JNIEXPORT jstring JNICALL
    Java_org_diql_hellojni_MainActivity_stringFromJNI(
            JNIEnv *env,
            jobject /* this */);
}

JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_booleanStrJNI(JNIEnv *env, jobject instance, jboolean test) {
    // TODO 返回的字符串和预想的不一样，会变成这个样子：“alala”
    std::string str = "lalala" + test;
    return env->NewStringUTF(str.c_str());
}

JNIEXPORT jint JNICALL
Java_org_diql_hellojni_MainActivity_booleanJNI(JNIEnv *env, jobject instance, jboolean test) {
    return test;
}

JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_transString(JNIEnv *env, jobject instance, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    env->ReleaseStringUTFChars(str_, str);

    return env->NewStringUTF(str);
}

JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_lalalaJNI(JNIEnv *env, jobject instance) {
    std::string str = "lalala";
    return env->NewStringUTF(str.c_str());
}

JNIEXPORT jstring JNICALL
Java_org_diql_hellojni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
