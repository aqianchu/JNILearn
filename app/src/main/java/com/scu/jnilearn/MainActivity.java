package com.scu.jnilearn;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private TextView tv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
        tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        findViewById(R.id.getperson).setOnClickListener(this);
        findViewById(R.id.getarrayperson).setOnClickListener(this);
        findViewById(R.id.getpersons_ages).setOnClickListener(this);
        findViewById(R.id.getpersons_list).setOnClickListener(this);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.getperson:
                Person p = MyJNI.getPerson();
                if (p==null){
                    return;
                }
                tv.setText("name:"+p.getName()+" \nage:"+p.getAge());
                break;
            case R.id.getarrayperson:
                Person[] ps = MyJNI.getPersonArray();
                StringBuilder sb =new StringBuilder();
                if (ps==null)return;
                for (Person p1:ps){
                    sb.append("name:"+p1.getName()+" age:"+p1.getAge()+"\n");
                }
                tv.setText(sb.toString());
                break;
            case R.id.getpersons_ages:
                Person[] persons = MyJNI.getPersonArray();
                int total = MyJNI.totalAge(persons);
                tv.setText("totalAge:"+total);
                break;
            case R.id.getpersons_list:
                List<Person>personList = MyJNI.getArrayListPerson();
                StringBuilder sb1 = new StringBuilder();
                for (Person p11:personList){
                    sb1.append("name:"+p11.getName()+" age:"+p11.getAge()+"\n");
                }
                tv.setText(sb1.toString());
                break;
        }
    }
}
