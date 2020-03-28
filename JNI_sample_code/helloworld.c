#include <stdio.h>
#include <jni.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_sayhello(JNIEnv *jni_env, jobject obj)
{
	printf("Hello From C code");
}
