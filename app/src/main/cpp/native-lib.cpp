#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jobject JNICALL
Java_com_scu_jnilearn_MyJNI_getArrayListPerson(JNIEnv *env, jclass type) {
    jclass list_cls = env->FindClass("Ljava/util/ArrayList;");
    if (list_cls==NULL){
        return NULL;
    }
    jmethodID list_mid = env->GetMethodID(list_cls,"<init>","()V");
    jobject  list_obj = env->NewObject(list_cls,list_mid);
    jmethodID list_add = env->GetMethodID(list_cls,"add","(Ljava/lang/Object;)Z");
    jclass pclass=env->FindClass("com/scu/jnilearn/Person");
    jmethodID p_consturc = env->GetMethodID(pclass,"<init>","()V");
    jfieldID nameId = env->GetFieldID(pclass,"name","Ljava/lang/String;");
    jfieldID ageId = env->GetFieldID(pclass,"age","I");
    for (int i = 0; i < 4; ++i) {
        jstring jstring1 = env->NewStringUTF("tianyu");
        jobject p_obj = env->NewObject(pclass,p_consturc);
        env->SetObjectField(p_obj,nameId,env->NewStringUTF("tianyu"));
        env->SetIntField(p_obj,ageId,i);
        env->CallBooleanMethod(list_obj,list_add,p_obj);
    }
    return list_obj;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_scu_jnilearn_MyJNI_totalAge(JNIEnv *env, jclass type, jobjectArray persons) {
    jsize len = env->GetArrayLength(persons);
    jint total = 0;
    jclass pclass = env->FindClass("com/scu/jnilearn/Person");
    jfieldID ageId = env->GetFieldID(pclass,"age","I");
    for (int i = 0; i < len; ++i) {
        jobject currObj = env->GetObjectArrayElement(persons,i);
        jint age = env->GetIntField(currObj,ageId);
        total +=age;
    }
    return total;
}

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_scu_jnilearn_MyJNI_getPersonArray(JNIEnv *env, jclass type) {
    jobjectArray array;
    jsize len = 5;
    jclass pclass = env->FindClass("com/scu/jnilearn/Person");
    array = env->NewObjectArray(len,pclass,0);
    jmethodID mid = env->GetMethodID(pclass,"<init>","()V");
    jfieldID nameId = env->GetFieldID(pclass,"name","Ljava/lang/String;");
    jfieldID ageId = env->GetFieldID(pclass,"age","I");
    for (int i = 0; i < len; ++i) {
        jobject pobj = env->NewObject(pclass,mid);
        env->SetObjectField(pobj,nameId,env->NewStringUTF("tianyu"));
        env->SetIntField(pobj,ageId,i+10);
        env->SetObjectArrayElement(array,i,pobj);
    }
    return array;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_scu_jnilearn_Person_getPerson(JNIEnv *env, jclass type) {
    jmethodID mid = env->GetMethodID(type,"<init>","()V");
    if (mid == NULL){
        return NULL;
    }
    jobject obj = env->NewObject(type,mid);
    jfieldID nameId = env->GetFieldID(type,"name","Ljava/lang/String;");
    jfieldID ageId = env->GetFieldID(type,"age","I");
    env->SetObjectField(obj,nameId,env->NewStringUTF("tianyu"));
    env->SetIntField(obj,ageId,18);
    return obj;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_scu_jnilearn_MyJNI_getPerson(JNIEnv *env, jclass type) {
    jclass pclass = env->FindClass("com/scu/jnilearn/Person");
    if (pclass == nullptr){
        return NULL;
    }
    jmethodID mid = env->GetMethodID(pclass,"<init>","()V");
    if (mid== nullptr){
        return NULL;
    }
    jobject obj = env->NewObject(pclass,mid);
    jfieldID nameId = env->GetFieldID(pclass,"name","Ljava/lang/String;");
    jfieldID ageId = env->GetFieldID(pclass,"age","I");
    env->SetObjectField(obj,nameId,env->NewStringUTF("tianyu"));
    env->SetIntField(obj,ageId,18);
    return obj;
}

extern "C"
jstring
Java_com_scu_jnilearn_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
