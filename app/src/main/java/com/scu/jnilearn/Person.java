package com.scu.jnilearn;

/**
 * Created by zhangqianchu on 2016/12/5.
 */

public class Person {
    public Person(){}
    private String name;
    private int age;
    public static native Person getPerson();

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }
}
