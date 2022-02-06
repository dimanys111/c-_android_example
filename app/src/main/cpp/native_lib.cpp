#include <jni.h>
#include <string>

#include <decode.h>
#include <fstream>
#include <encode.h>


void test(std::string str) {
    std::ifstream is(str, std::ifstream::binary);
    if (is) {
        is.seekg(0, is.end);
        long length = is.tellg();
        is.seekg(0, is.beg);
        char* buffer = new char[length];
        is.read(buffer, length);
        is.close();

        int width, height;
        auto a = WebPGetInfo((uint8_t*)buffer, length, &width, &height);
        auto b = WebPDecodeRGBA((uint8_t*)buffer, length, &width, &height);

        char* buffer_ = new char[length * 5];
        auto c = WebPEncodeRGBA(b, width, height, width * 4, 50, (uint8_t**)(&buffer_));
        // ...buffer contains the entire file...
        std::ofstream outfile("1.webp", std::ofstream::binary);
        outfile.write(buffer_, c);
        outfile.close();
        delete[] buffer_;

        delete[] buffer;
    }
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_c_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject a, jstring jstr) {
    const char *cstr = env->GetStringUTFChars(jstr, NULL);
    std::string str = std::string(cstr);

    test(str);

    std::string hello = "Hell from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_test_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Helly from C++";
    return env->NewStringUTF(hello.c_str());
}