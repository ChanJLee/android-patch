package com.chan.ypatchcore;

/**
 * Created by chan on 16/8/18.
 */
public class YPatch {

    static {
        System.loadLibrary("y-patch-jni");
    }

    public static native void patch(String oldFilePath, String newFilePath, String patchFilePatch);
}
