package com.scu.jnilearn;

import java.util.ArrayList;

/**
 * Created by zhangqianchu on 2016/12/5.
 */

public class MyJNI {
    public static native Person getPerson();
    public static native Person[] getPersonArray();
    public static native int totalAge(Person[] persons);
    public static native ArrayList<Person>getArrayListPerson();
}
