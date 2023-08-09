package com.awang.jniexample;

import android.content.Context;
import android.os.Bundle;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    // ...

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Panggil metode displayToast untuk menampilkan pesan Toast dari C++
        displayToast(getApplicationContext());
    }

    // Metode untuk memanggil fungsi dari C++ untuk menampilkan pesan Toast
    public native void displayToast(Context context);

    // Load library C++
    static {
        System.loadLibrary("dx4white"); // Ganti dengan nama library C++ Anda
    }
}

