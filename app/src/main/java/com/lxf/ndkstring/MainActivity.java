package com.lxf.ndkstring;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "thanatos";
    private Hello hello;

    private EditText editText1;
    private EditText editText2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        hello=new Hello();
        editText1 = (EditText) findViewById(R.id.et1);
        editText2 = (EditText) findViewById(R.id.et2);
    }

    /**
     * 密码加密
     * @param view
     */
    public void onClickpwd(View view){
        if (editText1.getText().toString().isEmpty())return;
        String  pwd=editText1.getText().toString();
        int pw=Integer.parseInt(pwd);
        editText1.setText(String.format("%d", hello.encode_int(pw)));

    }

    /**
     * 字符串加密
     * @param view
     */
    public void onClicke(View view){
        String  str=editText2.getText().toString();
        editText2.setText(hello.encode_String(str, str.length()));
    }

    /**
     * 字符串解密
     * @param view
     */
    public void onClickd(View view){
        if (editText2.getText().toString().isEmpty())return;
        String  str=editText2.getText().toString();
        editText2.setText(hello.decode_String(str, str.length()));
    }

    /**
     * 加密数组
     * @param view
     */
    int [] iarr={1,2,3,4,5};
    public void onClickint(View view){

        hello.encode_intArray(iarr);
        for (int j = 0; j < iarr.length; j++) {
            Log.w(TAG, "onClickint:加密后的数组第 "+(j+1)+"个元素："+iarr[j] );
        }

    }
}
